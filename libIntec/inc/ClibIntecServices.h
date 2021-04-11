/*
 * ClibIntecServices.h
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */
#ifndef INC_CLIBINTECSERVICES_H_
#define INC_CLIBINTECSERVICES_H_

#include "libIntec.h"
#include "ClibIntecDevice.h"
#include "ClibIntecOperations.h"


#include <stdint.h>
#include <utility>
#include <libusb-1.0/libusb.h>
#include <map>
#include <cstdint>
#include <cstring>
#include <string>


#define MAX_USB_DEVICES 8

class ClibIntecServices
{
public:
	ClibIntecServices(IntecUsbDeviceType dev=IntecH);
	ClibIntecServices(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName);
	virtual ~ClibIntecServices();
	virtual void Initialize(void);
	virtual int32_t Exit(void);
	virtual uint32_t GetUsbDevicesCount();
public:

	uint32_t m_DevCount;
	ClibIntecDevice *m_Devices[MAX_USB_DEVICES];
	ClibIntecOperations *m_Operations[MAX_USB_DEVICES];
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
	virtual void GetVidPidBytype(IntecUsbDeviceType dev, uint16_t &VID, uint16_t &PID);

private:
	const int32_t InitializeLibusb();
	const int32_t ExitLibusb(void);
};

ClibIntecServices* InstantiateIntecServices(IntecUsbDeviceType dev);
ClibIntecOperations* InstantiateIntecOperations(unsigned int index);
void DeleteIntecServices(ClibIntecServices* services);
//TODO implement
//ClibIntecServices* InstantiateIntecServicesOverEthernet(IntecUsbDeviceType dev,uint32_t numOfDevices, char **devicesAddress);
ClibIntecDevice* InstantiateIntecDevice(IntecDeviceType DeviceType);

#endif /* INC_CLIBINTECSERVICES_H_ */
