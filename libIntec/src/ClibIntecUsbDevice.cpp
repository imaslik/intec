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
		std::cout << "device is closed" << std::endl;
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
		return STATUS_OK;
	}
	else
		return ERROR_FAIL;
}

int32_t ClibIntecUsbDevice::Diconnect()
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
	libusb_free_config_descriptor(m_usb_config_descs);
}

int32_t ClibIntecUsbDevice::InitializeDevice(unsigned int devIndex)
{
	m_DeviceIndex = devIndex;
	if (m_usb_device != NULL)
	{
		m_usb_bus_number = libusb_get_bus_number(m_usb_device);
		std::cout << "device bus number " << (int)m_usb_bus_number << std::endl;
		m_usb_port_number = libusb_get_port_number(m_usb_device);
		std::cout << "device port number " << (int)m_usb_port_number << std::endl;
		m_usb_port_nubers_len = libusb_get_port_numbers(m_usb_device, m_usb_port_numbers, MAX_PORT_DEPTH);
		std::cout << "device port number len " << m_usb_port_nubers_len << std::endl;
		m_usb_device_address = libusb_get_device_address(m_usb_device);
		std::cout << "device address  " << (int)m_usb_device_address << std::endl;
		m_usb_device_speed = libusb_get_device_speed(m_usb_device);


		if (libusb_get_device_descriptor(m_usb_device, &m_usb_devcie_desc) != 0)
			return ERROR_FAIL;

		if (libusb_get_active_config_descriptor(m_usb_device, &m_usb_config_descs) != 0)
			return ERROR_FAIL;


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

int32_t ClibIntecUsbDevice::SetVidPid(uint16_t vid, uint16_t pid)
{
	m_vid = vid;
	m_pid = pid;
	return STATUS_OK;
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
