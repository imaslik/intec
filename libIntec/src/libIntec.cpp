/*
 * libIntec.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */


#include "libIntec.h"
#include <mutex>
#include "ClibIntecException.h"
#include "ClibIntecServices.h"

std::mutex IntecMutex;
ClibIntecServices *libIntecServices = NULL;

int libIntec_Initialize(IntecUsbDeviceType dev)
{
	IntecMutex.lock();
	int status;
	try
	{
		libIntecServices = InstantiateIntecServices(dev);
		libIntecServices->Initialize();
	}
	catch (...)
	{
		status = ERROR_FAIL;
	}
	status = STATUS_OK;
	IntecMutex.unlock();
	return status;
}

int libIntec_InitializeOverNetwork(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName)
{
	try
	{
		IntecMutex.lock();
		libIntecServices = InstantiateIntecServices(dev);
		if (!libIntecServices)
			throw ClibIntecException("Could not allocate ClibIntecServices");
		libIntecServices->Initialize();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntec_Exit(void)
{
	IntecMutex.lock();
	DeleteIntecServices(libIntecServices);
	IntecMutex.unlock();
	return STATUS_OK;
}

int libtIntec_GetNumberOfDevices(unsigned int * NumOfUsbDevices)
{
	IntecMutex.lock();
	int status;
	try
	{

	}
	catch (...)
	{
		status = ERROR_FAIL;
	}
	status = STATUS_OK;
	IntecMutex.unlock();
	return status;
}
