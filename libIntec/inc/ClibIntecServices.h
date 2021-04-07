/*
 * ClibIntecServices.h
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */
#ifndef INC_CLIBINTECSERVICES_H_
#define INC_CLIBINTECSERVICES_H_

#include <stdint.h>
#include <utility>
#include <stdint.h>
#include "libIntec.h"
#include "ClibIntecDevice.h"
#include <libusb-1.0/libusb.h>
#include <map>

#define MAX_USB_DEVICES 8

class ClibIntecServices
{

public:
	ClibIntecServices(IntecUsbDeviceType dev);
	ClibIntecServices(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName);

	virtual ~ClibIntecServices();

	const int32_t Initialize(void);
	virtual uint32_t GetUsbDevicesCount();
	std::map<IntecUsbDeviceType, std::pair<uint16_t, uint16_t>> m_DevTypeToVidPid =
	{
			{IntecH, {0x4d8, 0x53}},
			{IntecD, {0x4d8, 0x3c}},
			{TAU, {0x4d8, 0x3c}}
	};

public:
	uint32_t m_DevCount;
	ClibIntecDevice *m_Devices[MAX_USB_DEVICES];
	char m_MsgBuffer[512];
	IntecUsbDeviceType m_DevType;

private:
	//libusb data members
	libusb_device **m_libusb_devv = NULL;
	libusb_context *m_libusb_ctx = NULL;
	ssize_t m_libusb_devc=0;



protected:
	const int32_t InitializeUsbDevices();
	const int32_t SearchUsbDevices();
	const int32_t SearchEthernetDevices(uint32_t numOfDevices, char **devicesAddress);
	ClibIntecDevice *operator[](uint32_t i);

private:
	const int32_t InitializeLibusb();
	const int32_t ExitLibusb(void);
};

ClibIntecServices* InstantiateIntecServices(IntecUsbDeviceType dev);
void DeleteIntecServices(ClibIntecServices* services);
//ClibIntecServices* InstantiateIntecServicesOverEthernet(IntecUsbDeviceType dev,uint32_t numOfDevices, char **devicesAddress);
ClibIntecDevice* InstantiateIntecDevice(IntecDeviceType DeviceType);

#endif /* INC_CLIBINTECSERVICES_H_ */
