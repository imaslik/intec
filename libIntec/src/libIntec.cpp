/*
 * libIntec.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#include <mutex>
#include "ClibIntecException.h"
#include "ClibIntecServices.h"
#include "libIntec.h"
#include "c_libIntec.h"

std::mutex IntecMutex;
ClibIntecServices *libIntecServices = NULL;
std::string libIntecLastErrorMsg;

void SetIntecLastError(const char * err)
{
	if(!libIntecLastErrorMsg.empty())
	{
		libIntecLastErrorMsg.insert(0,"->");
	}
	libIntecLastErrorMsg.insert(0,err);
}

int libIntec_Initialize(IntecUsbDeviceType dev)
{
	try
	{
		IntecMutex.lock();
		libIntecServices = InstantiateIntecServices(dev);
		if (libIntecServices != NULL)
			libIntecServices->Initialize();
		else
			throw ClibIntecException("could not initializde ClibIntecServices");
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_GetlibVersion(unsigned int &major, unsigned int &minor)
{
	major = LIBINTEC_VERSION_MAJOR;
	minor = LIBINTEC_VERSION_MINOR;
	return STATUS_OK;
}

int libIntec_GetDeviceVersion(unsigned int index, char *buffer)
{
	try
	{
		IntecMutex.lock();
		if (libIntecServices->m_Devices[index]->GetDeviceVersion(buffer) != STATUS_OK)
			throw ClibIntecException("Get device version failed");
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
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
		SetIntecLastError(e.what());
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
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_ReadDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int *cbRead)
{
	int res;
	res = libIntecServices->m_Devices[index]->Read(addr, szBuffer, cbRead);
	if (res != STATUS_OK)
		return (int)res;
	return STATUS_OK;
}

int libIntec_WriteDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int cbRead)
{
	int res;
	res = libIntecServices->m_Devices[index]->Write(addr, szBuffer, cbRead);
	if (res != STATUS_OK)
		return (int)res;
	return STATUS_OK;
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
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
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
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
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
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_InitializeCard(unsigned int index)
{
	try
	{
		IntecMutex.lock();
		if (libIntecServices->m_Operations[index]->Initialize(1) != STATUS_OK)
			throw ClibIntecException("Initialize card failed");
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_InitializeCardNoReset(unsigned int index)
{
	try
	{
		IntecMutex.lock();
		if (libIntecServices->m_Operations[index]->Initialize(0) != STATUS_OK)
			throw ClibIntecException("Initialize card failed");
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_GetTemperature(unsigned int index, int cardId,float *temprature, unsigned int * timestamp)
{
	try
	{
		IntecMutex.lock();
		int status = libIntecServices->m_Operations[index]->IntecGetTemperature(cardId, temprature, timestamp);
		IntecMutex.unlock();
		if (status != STATUS_OK)
			return ERROR_FAIL;
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_SetTemperature(unsigned int index, int cardId, float Temp)
{
	try
	{
		IntecMutex.lock();
		if (libIntecServices->m_Operations[index]->IntecSetTemperature(cardId, Temp) != STATUS_OK)
			throw ClibIntecException("Set Temperature returned has failed");
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
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
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
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
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}

int libintec_GetLastError(char *buffer, unsigned int buffersize)
{
	try
	{
		IntecMutex.lock();
		std::memset(buffer, 0, buffersize);
		// check boundries & copy
		if(libIntecLastErrorMsg.size() < buffersize)
			std::memcpy(buffer,libIntecLastErrorMsg.c_str(),libIntecLastErrorMsg.size());
		else
			std::memcpy(buffer,libIntecLastErrorMsg.c_str(),buffersize-1);
		libIntecLastErrorMsg.clear();
		IntecMutex.unlock();
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
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
		SetIntecLastError(e.what());
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
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}

int libIntec_GetDeviceSerialNumber(unsigned int index, IntecCardType type, int cardId, char *serial)
{
	try
	{
		IntecMutex.lock();
		int ret = libIntecServices->m_Operations[index]->IntecGetDeviceSerialNumber(type, cardId, serial);
		IntecMutex.unlock();
		if (ret != STATUS_OK)
			throw ClibIntecException("ERROR at GetDeviceNumber has failed");
		return STATUS_OK;
	}
	catch (std::exception& e)
	{
		IntecMutex.unlock();
		SetIntecLastError(e.what());
		return ERROR_FAIL;
	}
}
