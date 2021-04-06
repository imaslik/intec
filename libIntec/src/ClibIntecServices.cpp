/*
 * libIntecServices.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#include "ClibIntecServices.h"
#include "ClibIntecException.h"
#include "libIntec.h"
#include <libusb-1.0/libusb.h>

ClibIntecServices* InstantiateIntecServices(IntecUsbDeviceType dev)
{
	return new ClibIntecServices(dev);
}

ClibIntecServices* InstantiateIntecServicesOverEthernet(IntecUsbDeviceType dev,uint32_t numOfDevices, char **devicesAddress)
{
	return new ClibIntecServices(dev, numOfDevices, devicesAddress);
}

void DeleteIntecServices(ClibIntecServices* services)
{
	delete services;
}

ClibIntecServices::ClibIntecServices(IntecUsbDeviceType DevType)
{
	m_DevCount = 0;
	for (int i=0; i < MAX_USB_DEVICES; i++)
	{
		m_Devices[i] = NULL;
	}
}

ClibIntecServices::~ClibIntecServices()
{
	libusb_free_device_list(m_libusb_devv, 1);
	libusb_exit(m_libusb_ctx);
}

const int32_t ClibIntecServices::Initialize(void)
{
	try
	{
		InitializeLibusb();
		InitializeUsbDevices();
		return STATUS_OK;
	}
	catch (...)
	{
		return ERROR_LIBUSB_FAIL;
	}
}

const int32_t ClibIntecServices::InitializeLibusb(void)
{
	//initializing libusb
	if(libusb_init(&m_libusb_ctx) !=0)
		throw ClibIntecException("libusb initialization failed");

	try
	{
		m_libusb_devc = libusb_get_device_list(m_libusb_ctx, &m_libusb_devv);
		if (m_libusb_devc < 0)
			throw ClibIntecException("no USB devices were detected by libusb");
	}
	catch (...)
	{
		libusb_exit(m_libusb_ctx);
		return ERROR_LIBUSB_FAIL;
	}
	return STATUS_OK;
}

const int32_t ClibIntecServices::ExitLibusb(void)
{
	libusb_free_device_list(m_libusb_devv, 1);
	libusb_exit(m_libusb_ctx);
	return STATUS_OK;
}

ClibIntecUsbDevice *ClibIntecServices::operator[](uint32_t i)
{
	if (i<m_DevCount)
		return m_Devices[i];
	else
		throw ClibIntecException("Index out of USB devices range");
}

const int32_t ClibIntecServices::InitializeUsbDevices(IntecUsbDeviceType DevType)
{
	try
	{
		uint16_t VID, PID;
		switch(DevType)
		{
		case IntecH:
			PID=0x3c;
			VID=0x4d8;
			break;
		case IntecD:
			PID=0x3c;
			VID=0x4d8;
			break;
		case TAU:
			PID=0x3c;
			VID=0x4d8;
			break;
		default:
			PID=0x3c;
			VID=0x4d8;
		}

		for (int i=0; i < m_libusb_devc; i++)
		{
			libusb_device *device = m_libusb_devv[i];
			libusb_device_descriptor desc;
			if (libusb_get_device_descriptor(device, &desc) != 0)
				throw ClibIntecException("libusb_get_device_descriptor failed");

			if (desc.idProduct == PID && desc.idVendor == VUD)
				std::cout << "found Device " << std::hex << PID << " : " << std::hex << VID << std::endl;
		}
	}
	catch (...)
	{
		return ERROR_FAIL;
	}
}
