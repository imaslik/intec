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


ClibIntecDevice* InstantiateIntecDevice(IntecDeviceType DeviceType)
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

	std::cout << "count before calling delete ------------- " << services->m_DevCount << std::endl;
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
	for (int i=(int)m_DevCount; i > 0 ; i--)
	{
		std::cout << "calling devcie distrucor" << std::endl;
		delete m_Devices[i];
	}
	libusb_free_device_list(m_libusb_devv, 1);
	libusb_exit(m_libusb_ctx);
}

void ClibIntecServices::Initialize()
{
	InitializeLibusb();
	InitializeUsbDevices();
}
int32_t ClibIntecServices::Exit(void)
{
	for (int i=0; i< (int)m_DevCount;i++)
	{
		m_Devices[i]->Diconnect();
		m_Devices[i]->Close();
	}

	return STATUS_OK;
}

uint32_t ClibIntecServices::GetUsbDevicesCount()
{
	return m_DevCount;
}

void ClibIntecServices::SetLastError(const char* err)
{
	if(!m_LastErrorMsg.empty())
	{
		m_LastErrorMsg.insert(0,"->");
	}
	m_LastErrorMsg.insert(0,err);
}

void ClibIntecServices::GetLastError(char* buffer, unsigned int buffersize)
{
	std::memset(buffer,0,buffersize);
	// check boundries & copy
	if(m_LastErrorMsg.size() < buffersize)
		std::memcpy(buffer,m_LastErrorMsg.c_str(),m_LastErrorMsg.size());
	else
		std::memcpy(buffer,m_LastErrorMsg.c_str(),buffersize-1);
	m_LastErrorMsg.clear();
}

const int32_t ClibIntecServices::InitializeLibusb()
{
	//initializing libusb
	if(libusb_init(&m_libusb_ctx) != 0)
	{
		throw ClibIntecException("libusb returned error: initialization failed");
	}
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
	//get usb devices list
	m_libusb_devc = libusb_get_device_list(m_libusb_ctx, &m_libusb_devv);
	if (m_libusb_devc < 0)
	{
		throw ClibIntecException("libusb returned error at libusb_get_device_list");
	}

	//TODO implement a method that searches for devices in "bootLoader mode PID=0x3c VID=0x4d8

	//looking for regular usb devices
	std::pair<uint16_t, uint16_t> VidPid = m_DevTypeToVidPid[m_DevType];
	uint16_t VID = VidPid.first;
	uint16_t PID = VidPid.second;

	for (int i=0; i < m_libusb_devc; i++)
	{
		libusb_device *device = m_libusb_devv[i];
		libusb_device_descriptor desc;
		if (libusb_get_device_descriptor(device, &desc) != 0)
			throw ClibIntecException("libusb_get_device_descriptor failed");
		if (desc.idProduct == PID && desc.idVendor == VID)
		{
			if (m_DevCount <= MAX_USB_DEVICES)
			{
				m_Devices[m_DevCount] = InstantiateIntecDevice(Usb);
				if (m_Devices[m_DevCount] == NULL)
					throw ClibIntecException("failed to allocate USB device ");
				m_Devices[m_DevCount++]->SetVidPid(desc.idVendor, desc.idProduct);
				m_Devices[m_DevCount-1]->SetDeviceReference(device);
				m_Devices[m_DevCount-1]->InitializeDevice(m_DevCount-1);

				if (!m_Devices[m_DevCount-1]->Open())
					throw ClibIntecException("failed to open usb devcie");

				std::cout << "Debug print: Device was opened " << std::endl;

//				if (!m_Devices[m_DevCount]->Connect())
//					throw ClibIntecException("failed to connect to usb device");
			}
		}
	}
	return STATUS_OK;
}
