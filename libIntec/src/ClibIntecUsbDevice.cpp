/*
 * ClibIntecUsbDevice.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#include "ClibIntecUsbDevice.h"

ClibIntecUsbDevice::ClibIntecUsbDevice()
{
}

ClibIntecUsbDevice::ClibIntecUsbDevice(IntecUsbDeviceType devType, uint32_t devIndex,IntecDeviceOperationMode mode,IntecDeviceDriverType driverType)
{
	m_DeviceType = devType;
	m_DeviceIndex = devIndex;
	m_DriverType = driverType;
}

int32_t ClibIntecUsbDevice::Open()
{__TRACE
	if (m_usb_device == NULL)
		throw ClibIntecException("error at USB device open. libusb device not present");

	int rc;
	if (libusb_open(m_usb_device, &m_usb_device_handle) == 0)
	{
		//reseting the device
		m_device_open_flag = true;
		rc = libusb_reset_device(m_usb_device_handle);
		if (rc != 0)
			return ERROR_FAIL;

//		rc = libusb_set_configuration(m_usb_device_handle, 1);
//		if (rc != 0)
//			return ERROR_FAIL;
		return STATUS_OK;
	}
	else
	{
		return ERROR_USB_OPEN_FAIL;
	}
}

int32_t ClibIntecUsbDevice::Close()
{
	if (m_device_open_flag == true)
	{
		if (m_usb_device_handle != NULL)
		{
			libusb_close(m_usb_device_handle);
			m_device_open_flag = false;
			return STATUS_OK;
		}
	}
	return ERROR_FAIL;
}

int32_t ClibIntecUsbDevice::Connect()
{
	if (m_usb_device_handle == NULL)
		throw ClibIntecException("could not connect usb handle not preset");

//	if (libusb_kernel_driver_active(m_usb_device_handle, m_interface_nubmer) == LIBUSB_SUCCESS)
//	{
//		return ERROR_FAIL;
//	}
	else if (libusb_set_auto_detach_kernel_driver(m_usb_device_handle, m_interface_nubmer) == LIBUSB_SUCCESS)
	{
		if (libusb_claim_interface(m_usb_device_handle, m_interface_nubmer) == LIBUSB_SUCCESS)
		{
			m_device_connect_flag = true;
			return STATUS_OK;
		}
		else
			return ERROR_FAIL;
	}
	return ERROR_FAIL;
}

int32_t ClibIntecUsbDevice::Diconnect()
{
	if (m_device_connect_flag == true)
	{
		if (m_usb_device_handle != NULL)
		{
			if (libusb_release_interface(m_usb_device_handle, m_interface_nubmer) == 0)
			{
				m_device_connect_flag = false;
				return STATUS_OK;
			}
			else
				return ERROR_FAIL;
		}
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

void printbuffer(unsigned char * buffer, int size)
{
	for (int i=0; i < size; i++)
	{
		printf("%02hhx", buffer[i]);
		if (i%80==0 && i!=0)
			printf("\n");
	}
	printf("\n");
}
int32_t ClibIntecUsbDevice::Write(unsigned char *szBuffer, unsigned int cbWrite)
{
	if (m_usb_device_handle == NULL)
	{
		return ERROR_FAIL;
	}
	int actual_transffer=0;
	int status = libusb_bulk_transfer(m_usb_device_handle, m_usb_out_endpoint_addr, szBuffer, (int)cbWrite, &actual_transffer, DEFAULT_TX_TIMEOUT_MS);

	if (status !=0)
	{
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

int32_t ClibIntecUsbDevice::Read(unsigned char *szBuffer, unsigned int *cbRead)
{
	if (m_usb_device_handle == NULL)
	{
		return ERROR_FAIL;
	}
	int length = (int)*cbRead;
	int  transferred = 0;
	int rc = libusb_bulk_transfer(m_usb_device_handle, m_usb_in_endpoint_addr, szBuffer, length, &transferred, DEFAULT_RX_TIMEOUT_MS);
	if (rc != 0)
		return rc;
	*cbRead = transferred;
	return STATUS_OK;
}

int32_t ClibIntecUsbDevice::Write(unsigned int addr, unsigned char *szBuffer, unsigned int cbSize)
{
	//Host to device write command
	//Cmd Type	          Register Address 				   DataLen	 			Data
	//0x01 (Wr)		       ID [31:16], Offset [15:0]
    //1Byte	                4 Bytes							1 Byte	          �DataLen� Bytes

	unsigned int currIndex = 0;
	unsigned char sendBuffer[MAX_WRITE_PKT_SIZE];
	// Split data to 64 bytes sized packets (Microchip f/w limitation)
	while (currIndex < cbSize)
	{
		unsigned char currPktSize = (unsigned char)((PKT_HEADER_LENGTH + cbSize - currIndex >= MAX_WRITE_PKT_SIZE) ? MAX_WRITE_PKT_SIZE :
		PKT_HEADER_LENGTH + cbSize - currIndex);

		// Prepare data for sending

		sendBuffer[0] = USB_WRITE_WORD_COMMAND;
		memcpy(&sendBuffer[1], (unsigned char*)&addr,REG_WIDTH);
		sendBuffer[5] = *(unsigned char*)&currPktSize-PKT_HEADER_LENGTH;

		memcpy(sendBuffer+PKT_HEADER_LENGTH,szBuffer+currIndex,currPktSize - PKT_HEADER_LENGTH);
		if(Write(sendBuffer, currPktSize) ==  STATUS_OK)
			currIndex += currPktSize-PKT_HEADER_LENGTH;
		else
			return ERROR_FAIL;
	}
	return STATUS_OK;
}

int32_t ClibIntecUsbDevice::Read(unsigned int addr, unsigned char *szBuffer, unsigned int *cbSize)
{
	unsigned int actualTReadSize = m_usb_max_in_packet_size;
	unsigned char sendBuffer[PKT_HEADER_LENGTH];
	sendBuffer[0] = USB_READ_WORD_COMMAND;
	memcpy(&sendBuffer[1], (unsigned char*)&addr, REG_WIDTH);
	sendBuffer[5] = *cbSize;
	unsigned char internalReadBuff[MAX_READ_PKT_SIZE];
	if (WriteAndRead(sendBuffer, PKT_HEADER_LENGTH, internalReadBuff, &actualTReadSize) != STATUS_OK)
	{
		return ERROR_FAIL;
	}
	else
	{
		memcpy(szBuffer, internalReadBuff, min(*cbSize, actualTReadSize)); // take the min to preven memory crash
		return STATUS_OK;
	}
}

int32_t ClibIntecUsbDevice::WriteAndRead(unsigned char *writeBuffer,unsigned int writeSize, unsigned char *readBuffer, unsigned int * readSize)
{
	unsigned int reqToRead = *readSize;
	int rc;
	rc = Write(writeBuffer, writeSize);
	if (rc != STATUS_OK)
		return rc;

	usleep(1);
	rc = Read(readBuffer, &reqToRead);
	if (rc != STATUS_OK)
		return rc;

	unsigned char status = readBuffer[0];
	if(!(status &0x1))
	{
		return ERROR_FAIL;
	}

	if((status &0x4))
	{
		return ERROR_FAIL;
	}
	if (!(status &0x2))
	{
		// status 0x2 data not ready
		rc = Write(writeBuffer, writeSize);
		if (rc != STATUS_OK)
			return rc;

		usleep(5);
		rc = Read(readBuffer, &reqToRead);
		if (rc != STATUS_OK)
			return rc;
	}
	*readSize = readBuffer[PKT_HEADER_LENGTH-1];
	// copy only the DATA - remove the header
	memcpy(readBuffer,&readBuffer[PKT_HEADER_LENGTH], min(*readSize, MAX_READ_PKT_SIZE-PKT_HEADER_LENGTH));

	return STATUS_OK;
}

ClibIntecUsbDevice::~ClibIntecUsbDevice()
{
	libusb_free_config_descriptor(m_usb_config_desc);
}

int32_t ClibIntecUsbDevice::InitializeDevice(unsigned int devIndex)
{
	m_DeviceIndex = devIndex;
	if (m_usb_device != NULL)
	{
		m_usb_bus_number = libusb_get_bus_number(m_usb_device);
		m_usb_port_number = libusb_get_port_number(m_usb_device);
		m_usb_port_numbers_len = libusb_get_port_numbers(m_usb_device, m_usb_port_numbers, MAX_PORT_DEPTH);
		m_usb_device_address = libusb_get_device_address(m_usb_device);
		m_usb_device_speed = libusb_get_device_speed(m_usb_device);

		if (libusb_get_device_descriptor(m_usb_device, &m_usb_device_desc) != 0)
			return ERROR_FAIL;

		m_vid = m_usb_device_desc.idVendor;
		m_pid = m_usb_device_desc.idProduct;
		//iterating over the usb device tree
		if (libusb_get_config_descriptor(m_usb_device, 0, &m_usb_config_desc) != 0)
		{
			return ERROR_FAIL;
		}
		uint8_t m_bNumInterfaces = 0;
		//iterating over the usb device tree
		if (m_usb_config_desc != NULL)
		{
			m_bNumInterfaces = m_usb_config_desc->bNumInterfaces;
			libusb_interface usb_interface;
			libusb_interface_descriptor usb_interface_desc;
			libusb_endpoint_descriptor usb_endpoint_desc;
			uint8_t m_bNumEndpoints;
			uint8_t l_endpoint_addr = 0;
			//iterating over the interfaces in config index 0
			for (int i = 0; i < (int)m_bNumInterfaces; i++)
			{
				usb_interface = m_usb_config_desc->interface[i];
				int num_of_alt_settings = usb_interface.num_altsetting;
				// iterating over the
				for (int j = 0; j < num_of_alt_settings; j++)
				{
					usb_interface_desc = usb_interface.altsetting[j];
					m_interface_nubmer = usb_interface_desc.bInterfaceNumber;
					m_bNumEndpoints = usb_interface_desc.bNumEndpoints;

					for (int k = 0; k < (int)m_bNumEndpoints; k++)
					{
						usb_endpoint_desc = usb_interface_desc.endpoint[k];
						l_endpoint_addr = usb_endpoint_desc.bEndpointAddress;
						if (l_endpoint_addr & 0x80)
						{
							//bit 7 is set -> IN endpoint
							m_usb_in_endpoint_addr = l_endpoint_addr;
							m_usb_max_in_packet_size = usb_endpoint_desc.wMaxPacketSize;
						}
						else
						{
							m_usb_out_endpoint_addr = l_endpoint_addr;
							m_usb_max_out_packet_size = usb_endpoint_desc.wMaxPacketSize;
						}
					}
				}
			}
		}
		libusb_free_config_descriptor(m_usb_config_desc);

		return STATUS_OK;
	}
	return ERROR_FAIL;
}

IntecDeviceOperationMode ClibIntecUsbDevice::GetDeviceMode()
{
	return m_DeviceOpMode;
}

int32_t ClibIntecUsbDevice::SetDeviceMode(IntecDeviceOperationMode DeviceMode)
{
	m_DeviceOpMode = DeviceMode;
	return STATUS_OK;
}

int ClibIntecUsbDevice::GetConfiguration()
{
	int config;
	if (libusb_get_configuration(m_usb_device_handle, &config) == 0)
		return config;
	else
		return ERROR_FAIL;
}

int32_t ClibIntecUsbDevice::SetConfiguration(int config)
{
	if (libusb_set_configuration(m_usb_device_handle, config) == 0)
		return STATUS_OK;
	else
		return ERROR_FAIL;
}

void ClibIntecUsbDevice::SetDeviceReference(libusb_device * usb_device)
{
	m_usb_device = usb_device;
}

int32_t ClibIntecUsbDevice::GetPortNumber()
{
	if (m_usb_device != NULL)
		return (int32_t)libusb_get_port_number(m_usb_device);
	else
	{
		return ERROR_FAIL;
	}
}

int ClibIntecUsbDevice::GetDeviceVersion(char *buffer)
{
	if (m_DeviceType == IntecH)
	{
		UN_FW_VERSION intec_ver;
		unsigned int readSize_ = sizeof(UN_FW_VERSION);
		if (Read(INTEC_BASE_ADDR|OFFSET_UNIT_GENERAL|OFFSET_FW_VERSION, (unsigned char*)&intec_ver.value, &readSize_) != STATUS_OK)
		{
			SetIntecLastError("CIntecUSBDeviceH::GetDeviceVersion:Failed to Read IntecCard version ");
			return ERROR_FAIL;
		}
		std::cout << "intec FW version " << intec_ver.value << std::endl;
		memcpy(buffer,(char *)&intec_ver.value, readSize_);
		return STATUS_OK;
	}

	return ERROR_FAIL;
}

void ClibIntecUsbDevice::SetUsbDeviceType(IntecUsbDeviceType type)
{
	m_DeviceType = type;
}

int ClibIntecUsbDevice::ClearReadBuffers()
{
	if (m_device_connect_flag)
	{
		unsigned char buffer[8];
		unsigned int size = sizeof(buffer);
		if (Read(1, buffer, &size) != STATUS_OK)
		{
			return ERROR_FAIL;
		}
		return STATUS_OK;
	}

}
