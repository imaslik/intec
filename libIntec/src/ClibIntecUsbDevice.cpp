/*
 * ClibIntecUsbDevice.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: svshared
 */

#include "ClibIntecUsbDevice.h"

ClibIntecUsbDevice::ClibIntecUsbDevice(IntecUsbDeviceType devType, unsigned long devIndex,IntecDeviceOperationMode mode,IntecDeviceDriverType driverType)
{
	m_DeviceType = devType;
	m_DeviceIndex = devIndex;
	m_DriverType = driverType;

}

ClibIntecUsbDevice::~ClibIntecUsbDevice()
{
	;
}

