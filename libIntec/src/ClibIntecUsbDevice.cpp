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
{

	std::cout << "trying to open usb device" << std::endl;
	if (m_usb_device == NULL)
		throw ClibIntecException("error at USB device open. libusb device not present");

	if (libusb_open(m_usb_device, &m_usb_device_handle) == 0)
	{
		std::cout << "device open is successfull" << std::endl;
		m_device_open_flag = true;
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
			return STATUS_OK;
		}
	}
	return ERROR_FAIL;
}

int32_t ClibIntecUsbDevice::Connect()
{
	if (m_usb_device_handle == NULL)
		throw ClibIntecException("could not connect usb handle not preset");

	if (libusb_claim_interface(m_usb_device_handle, m_interface_nubmer) == 0)
	{
		std::cout << "connection succss" << std::endl;
		m_device_connect_flag = true;
		return STATUS_OK;
	}
	else
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
				std::cout << "disconnection succss" << std::endl;
				return STATUS_OK;
			}
			else
				return ERROR_FAIL;
		}
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

int32_t ClibIntecUsbDevice::Write(unsigned char *szBuffer, uint32_t cbWrite)
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

int32_t ClibIntecUsbDevice::Read(unsigned char *szBuffer, uint32_t cbRead)
{
	if (m_usb_device_handle == NULL)
	{
		return ERROR_FAIL;
	}
	int actual_transffer=0;
	int status = libusb_bulk_transfer(m_usb_device_handle, m_usb_in_endpoint_addr, szBuffer, (int)cbRead, &actual_transffer, DEFAULT_RX_TIMEOUT_MS);

	if (status !=0)
	{
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

ClibIntecUsbDevice::~ClibIntecUsbDevice()
{
	libusb_free_config_descriptor(m_usb_config_desc);
}

int32_t ClibIntecUsbDevice::InitializeDevice(unsigned int devIndex)
{
	std::cout << " ClibIntecUsbDevice::InitializeDevice is called " << std::endl;
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

		//iterating over the usb device tree
		if (libusb_get_config_descriptor(m_usb_device, 0, &m_usb_config_desc) != 0)
		{
			return ERROR_FAIL;
		}

		std::cout << "m_usb_config_desc is set " << std::endl;
		uint8_t m_bNumInterfaces = 0;
		//iterating over the usb device tree
		if (m_usb_config_desc != NULL)
		{
			m_bNumInterfaces = m_usb_config_desc->bNumInterfaces;
			std::cout << "num of interfaces found ---- " << (int)m_bNumInterfaces << std::endl;
			libusb_interface usb_interface;
			libusb_interface_descriptor usb_interface_desc;
			libusb_endpoint_descriptor usb_endpoint_desc;
			//iterating over the interfaces in config index 0
			for (int i = 0; i < (int)m_bNumInterfaces; i++)
			{
				usb_interface = m_usb_config_desc->interface[i];
				int num_of_alt_settings = usb_interface.num_altsetting;
				std::cout << "num of alternative settings for currnet interface ---- " << num_of_alt_settings << std::endl;
				// iterating over the
				for (int j = 0; j < num_of_alt_settings; j++)
				{
					usb_interface_desc = usb_interface.altsetting[j];
					uint8_t m_bNumEndpoints = usb_interface_desc.bNumEndpoints;
					for (int k = 0; k < (int)m_bNumEndpoints; k++)
					{
						usb_endpoint_desc = usb_interface_desc.endpoint[k];
						std::cout << "endpint address " << (int)usb_endpoint_desc.bEndpointAddress << std::endl;
						std::cout << "endpint maxPacketsize" << (int)usb_endpoint_desc.wMaxPacketSize << std::endl;
					}

				}
			}
		}
		libusb_free_config_descriptor(m_usb_config_desc);




//		if (libusb_get_active_config_descriptor(m_usb_device, &m_usb_config_descs) != 0)
//			return ERROR_FAIL;


		//TODO the values of the endpiont addresses must be dynammically determened during device enumeration
		// to verfiy that the values are ok compare to output of - sudo lsusb -v -d 04d8:0053
		m_usb_out_endpoint_addr = 0x01;
		m_usb_in_endpoint_addr = 0x81;

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
