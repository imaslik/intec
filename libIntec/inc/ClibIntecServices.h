/*
 * ClibIntecServices.h
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */
#ifndef INC_CLIBINTECSERVICES_H_
#define INC_CLIBINTECSERVICES_H_

#include <stdint.h>
#include "libIntec.h"
#include "ClibIntecUsbDevice.h"
#include <libusb-1.0/libusb.h>

#define MAX_USB_DEVICES 8

class ClibIntecServices
{

public:
	ClibIntecServices(IntecUsbDeviceType dev);
	ClibIntecServices(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName);
	const int32_t Initialize(void);
	virtual ~ClibIntecServices() {}
	virtual uint32_t GetUSBDevicesCount(){return m_Devc;}

private:
	//libusb data members
	libusb_device **m_libusb_devv = NULL;
	libusb_context *m_libusb_ctx = NULL;
	ssize_t m_libusb_devc=0;

protected:
	uint32_t m_DevCount;
	ClibIntecUsbDevice *m_Devices[MAX_USB_DEVICES];
	char m_MsgBuffer[512];

protected:
	const int32_t InitializeUsbDevices(IntecUsbDeviceType DevType);
	const int32_t SearchUsbDevices(IntecUsbDeviceType DevType);
	const int32_t SearchEthernetDevices(IntecUsbDeviceType DevType,uint32_t numOfDevices, char **devicesAddress);
	ClibIntecUsbDevice *operator[](uint32_t i);

private:
	const int32_t InitializeLibusb();
	const int32_t ExitLibusb(void);
};

ClibIntecServices* InstantiateIntecServices(IntecUsbDeviceType dev);
void DeleteIntecServices(ClibIntecServices* services);
//ClibIntecServices* InstantiateIntecServicesOverEthernet(IntecUsbDeviceType dev,uint32_t numOfDevices, char **devicesAddress);

#endif /* INC_CLIBINTECSERVICES_H_ */
