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
	if (libusb_open(m_usb_device, &m_usb_device_handle) == 0)
	{
		return STATUS_OK;
	}
	else
	{
		return ERROR_USB_OPEN_FAIL;
	}
}

int32_t ClibIntecUsbDevice::Close()
{
	libusb_close(m_usb_device_handle);
	return STATUS_OK;
}

int32_t ClibIntecUsbDevice::Connect()
{
	if (libusb_claim_interface(m_usb_device_handle, m_interface_nubmer) == 0)
		return STATUS_OK;
	else
		return ERROR_FAIL;
}

int32_t ClibIntecUsbDevice::Diconnect()
{
	if (libusb_release_interface(m_usb_device_handle, m_interface_nubmer) == 0)
		return STATUS_OK;
	else
		return ERROR_FAIL;
}

int32_t ClibIntecUsbDevice::Write(unsigned char *szBuffer, uint32_t cbSize)
{
	if (m_usb_device_handle == NULL)
	{
		return ERROR_FAIL;
	}
	unsigned char m_write_end_point = 0x82;
	int actual_transffer=0;
	int status = libusb_bulk_transfer(m_usb_device_handle, m_write_end_point, szBuffer, (int)cbSize, &actual_transffer, m_usb_transffer_timeout);

	if (status !=0)
	{
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

ClibIntecUsbDevice::~ClibIntecUsbDevice()
{
	;
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

int32_t ClibIntecUsbDevice::SetDeviceReference(libusb_device * usb_device)
{
	m_usb_device = usb_device;

	return STATUS_OK;
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
