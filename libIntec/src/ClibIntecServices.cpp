/*
 * libIntecServices.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#include "ClibIntecServices.h"
#include "ClibIntecUsbDevice.h"
#include "ClibIntecException.h"
#include "libIntec.h"
#include <libusb-1.0/libusb.h>


ClibIntecDevice* InstantiateIntecDevice(IntecDeiceType DeviceType)
{
	switch (DeviceType)
	{
	case Usb:
		return new ClibIntecUsbDevice();
	default:
		return NULL;
	}
}
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

ClibIntecServices::ClibIntecServices(IntecUsbDeviceType DevType_arg)
{
	m_DevCount = 0;
	m_DevType = DevType_arg;
	for (int i=0; i < MAX_USB_DEVICES; i++)
	{
		m_Devices[i] = NULL;
	}
}

ClibIntecServices::ClibIntecServices(IntecUsbDeviceType DevType_arg, uint32_t numOfDevices, char **HostName)
{
	m_DevCount = 0;
	m_DevType = DevType_arg;
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

uint32_t ClibIntecServices::GetUsbDevicesCount()
{
	return m_DevCount;
}


const int32_t ClibIntecServices::InitializeLibusb(void)
{
	//initializing libusb
	if(libusb_init(&m_libusb_ctx) !=0)
		throw ClibIntecException("libusb initialization failed");
	return STATUS_OK;
}

const int32_t ClibIntecServices::ExitLibusb(void)
{
	libusb_free_device_list(m_libusb_devv, 1);
	libusb_exit(m_libusb_ctx);
	return STATUS_OK;
}

ClibIntecDevice *ClibIntecServices::operator[](uint32_t i)
{
	if (i<m_DevCount)
		return m_Devices[i];
	else
		throw ClibIntecException("Index out of USB devices range");
}

const int32_t ClibIntecServices::InitializeUsbDevices()
{
	try
	{
		std::cout << "debug print: ClibIntecServices::InitializeUsbDevices" << std::endl;
		m_libusb_devc = libusb_get_device_list(m_libusb_ctx, &m_libusb_devv);
		if (m_libusb_devc < 0)
			throw ClibIntecException("no USB devices were detected by libusb");

		std::pair<uint16_t, uint16_t> VidPid = m_DevTypeToVidPid[m_DevType];
		uint16_t VID = VidPid.first;
		uint16_t PID = VidPid.second;

		for (int i=0; i < m_libusb_devc; i++)
		{
			libusb_device *device = m_libusb_devv[i];
			libusb_device_descriptor desc;
			if (libusb_get_device_descriptor(device, &desc) != 0)
				throw ClibIntecException("libusb_get_device_descriptor failed");
			std::cout << "debug print: VID = " << std::hex << desc.idVendor << " PID = " << std::hex << desc.idProduct << std::endl;
			if (desc.idProduct == PID && desc.idVendor == VID)
			{
				std::cout << "found Device " << std::hex << PID << " : " << std::hex << VID << std::endl;
				m_Devices[m_DevCount++];
			}
		}
		return STATUS_OK;
	}
	catch (...)
	{
		return ERROR_FAIL;
	}
}
