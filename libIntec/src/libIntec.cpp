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

void SetIntecLastError(const char * err)
{
	libIntecServices->SetLastError(err);
}

int libIntec_Initialize(IntecUsbDeviceType dev)
{
	try
	{
		IntecMutex.lock();
		libIntecServices = InstantiateIntecServices(dev);
		libIntecServices->Initialize();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
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
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_Exit(void)
{
	IntecMutex.lock();
	libIntecServices->Exit();
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
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_ReadDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int *cbRead)
{
	int res;
	try
	{
		IntecMutex.lock();
		res = libIntecServices->m_Devices[index]->Read(addr, szBuffer, cbRead);
		IntecMutex.unlock();
		if (res != STATUS_OK)
			return (int)res;
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntec_WriteDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int cbRead)
{
	int res;
	try
	{
		IntecMutex.lock();
		res = libIntecServices->m_Devices[index]->Write(addr, szBuffer, cbRead);
		IntecMutex.unlock();
		if (res != STATUS_OK)
			return (int)res;
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
	try
	{
		IntecMutex.lock();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntec_InitializeCard(unsigned int index)
{
	try
	{
		IntecMutex.lock();
		libIntecServices->m_Operations[index]->Initialize(1);
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_InitializeCardNoReset(unsigned int index)
{
	try
	{
		IntecMutex.lock();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_GetTemperature(unsigned int index)
{
	try
	{
		IntecMutex.lock();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntec_SetTemperature(unsigned int index, int cardId, float Temp)
{
	try
	{
		IntecMutex.lock();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntex_SetFeedBackControlParameter(unsigned int index, int cardId, IntecTemperatureCalcType calcMode, IntecTemperatureSourceType srcType, int mask)
{
	try
	{
		IntecMutex.lock();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (...)
	{
		IntecMutex.unlock();
		return ERROR_FAIL;
	}
}

int libIntec_SetCaseInput(unsigned int index, int cardId, bool enable, int mask)
{
	try
	{
		IntecMutex.lock();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
}

int libintec_GetLastError(char *buff, unsigned int bufsize)
{
	try
	{
		IntecMutex.lock();
		libIntecServices->GetLastError(buff, bufsize);
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_GetTemperatureSource(unsigned int index, IntecTemperatureSourceType, int *source_size, short* sources, unsigned int *timestamp, int* valid_mask)
{
	try
	{
		IntecMutex.lock();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_GetActualFeedbackType(unsigned int index, int cardId, IntecTemperatureSourceType* actualSrcType)
{
	try
	{
		IntecMutex.lock();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		libIntecServices->SetLastError(e.what());
		return ERROR_FAIL;
	}
}
