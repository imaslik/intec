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

int libtIntec_GetNumOfUsbDevices(int& number_devices_found)
{
	try
	{
		IntecMutex.lock();
		number_devices_found = (int)libIntecServices->GetUsbDevicesCount();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntec_GetDeviceMode(int index, IntecDeviceOperationMode &mode)
{
	try
	{
		IntecMutex.lock();
		mode = libIntecServices->m_Devices[index]->GetDeviceMode();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntec_SetDeviceMode(int index, IntecDeviceOperationMode mode)
{
	try
	{
		IntecMutex.lock();
		libIntecServices->m_Devices[index]->SetDeviceMode(mode);
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntec_GetDeviceName(int index, char* Buffer)
{
	return STATUS_OK;
}

int libIntec_InitializeCard(unsigned int index)
{
	return STATUS_OK;
}

int libIntec_InitializeCardNoReset(unsigned int index)
{
	return STATUS_OK;
}

int libIntec_GetTemperature(unsigned int index)
{
	return STATUS_OK;
}

int libIntec_SetTemperature(unsigned int index, int cardId, float Temp)
{
	return STATUS_OK;
}

int libIntex_SetFeedBackControlParameter(unsigned int index, int cardId, IntecTemperatureCalcType calcMode, IntecTemperatureSourceType srcType, int mask)
{
	return STATUS_OK;
}

int libIntec_SetCaseInput(unsigned int index, int cardId, bool enable, int mask)
{
	return STATUS_OK;
}

int libintec_GetIntecLastError()
{
	return STATUS_OK;
}

