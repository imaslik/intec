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

ClibIntecOperations* InstantiateIntecOperations(unsigned int index)
{
	return new ClibIntecOperations(index);
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
		m_Operations[i] = NULL;
	}
}

ClibIntecServices::ClibIntecServices(IntecUsbDeviceType DevType_arg, uint32_t numOfDevices, char **HostName)
{
	m_DevCount = 0;
	m_DevType = DevType_arg;
	for (int i=0; i < MAX_USB_DEVICES; i++)
	{
		m_Devices[i] = NULL;
		//m_Operations[i] = NULL;
	}
}

ClibIntecServices::~ClibIntecServices()
{
	for (int i=(int)m_DevCount; i > 0 ; i--)
	{
		delete m_Devices[i];
		delete m_Operations[i];
	}
	libusb_exit(m_libusb_ctx);
}

void ClibIntecServices::Initialize()
{
	InitializeLibusb();
	InitializeUsbDevices();
}

int32_t ClibIntecServices::Exit(void)
{
	for (int i=0; i < (int)m_DevCount;i++)
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

const int32_t ClibIntecServices::InitializeLibusb()
{
	if(libusb_init(&m_libusb_ctx) != 0)
	{
		throw ClibIntecException("libusb returned error: initialization failed");
	}
	return STATUS_OK;
}

void ClibIntecServices::GetVidPidBytype(IntecUsbDeviceType dev, uint16_t &VID, uint16_t &PID)
{
	switch (m_DevType)
	{
		case IntecH:
			VID = 0x4d8;
			PID = 0x53;
			break;
		case IntecD:
			VID = 0x4d8;
			PID = 0x54;
			break;
		case TAU:
			VID = 0x4d8;
			PID = 0xfce7;
			break;
		default:
			VID = 0x4d8;
			PID = 0x53;
			break;
	}
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
	m_libusb_devc = libusb_get_device_list(m_libusb_ctx, &m_libusb_devv);
	if (m_libusb_devc < 0)
	{
		throw ClibIntecException("libusb returned error at libusb_get_device_list");
	}

	//TODO implement a method that searches for devices in "bootLoader mode PID=0x3c VID=0x4d8

	uint16_t VID, PID;
	GetVidPidBytype(m_DevType, VID, PID);

	// iterating over all usb devices on the machine
	for (int index = 0; index < m_libusb_devc; index++)
	{
		libusb_device *device = m_libusb_devv[index];
		libusb_device_descriptor desc;
		if (libusb_get_device_descriptor(device, &desc) != 0)
			throw ClibIntecException("libusb_get_device_descriptor failed");

		if (desc.idProduct == PID && desc.idVendor == VID)
		{
			if (m_DevCount <= MAX_USB_DEVICES)
			{
				int current_index;
				current_index = m_DevCount;
				m_Devices[current_index] = InstantiateIntecDevice(Usb);
				m_DevCount++;
				if (m_Devices[current_index] == NULL)
					throw ClibIntecException("Failed to allocate USB device ");
				m_Operations[current_index] = InstantiateIntecOperations(current_index);
				if (m_Operations[current_index] == NULL)
					throw ClibIntecException("Failed to allocate Operations object");

				m_Devices[current_index]->SetDeviceReference(device);
				m_Devices[current_index]->InitializeDevice(current_index);
				m_Devices[current_index]->SetUsbDeviceType(m_DevType);

				if (m_Devices[current_index]->Open() != STATUS_OK)
					throw ClibIntecException("Failed to open usb devcie");

				if (m_Devices[current_index]->Connect() != STATUS_OK)
					throw ClibIntecException("Failed to connect to usb device");

				m_Devices[current_index]->ClearReadBuffers();
			}
		}
	}
	libusb_free_device_list(m_libusb_devv, 1);
	return STATUS_OK;
}
