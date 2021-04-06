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

ClibIntecUsbDevice::~ClibIntecUsbDevice()
{
	;
}

