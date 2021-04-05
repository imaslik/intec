// IntecDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "windows.h"
#include "CIntecException.h"
#include "CIntecServices.h"
#include "IIntecUSBDevice.h"
#include "IntecDLL.h"

#define INTEC_MUTEX_NAME "Global\\IntecMutex"
void* pIntecMutex = NULL;
int mutexTimeOut=2000;
bool  ignoreMutex=false;
_ULonglong process_id = 0;
bool locked=0;

IIntecServices *p=NULL;
DWORD devs;

DWORD devs_;
IntecDeviceOperationMode operationMode_;

// Semaphore Functions
HRESULT CreateIntecMutex()
{
	if(!ignoreMutex)
	{

		process_id = _ULonglong(GetCurrentProcessId());
		pIntecMutex = CreateMutex(NULL,FALSE,INTEC_MUTEX_NAME);
		if(pIntecMutex == NULL)
		{
			std::string errorStr("PID: ");
			errorStr+=std::to_string(process_id);
			errorStr+=" Failed creating Mutex object";
			SetIntecLastError( errorStr.c_str());
			return E_FAIL;
		}
	}
	return S_OK;
}


HRESULT DeleteIntecMutex()
{
	if(!ignoreMutex)
	{
		if(locked)
		{
		   HRESULT hr=UnlockMutex();
		   if(hr!=S_OK)
			return hr;
		}
		if(!CloseHandle(pIntecMutex))
		{
			char err[512];																			
			char errMsg[256];																			
			::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,												
				0,																			
				::GetLastError(),															
				0,																			
				errMsg,																		
				255,																		
				0);																			
			sprintf(err," %s %s"," Last Error = ",errMsg);								
			SetIntecLastError(err);	
			return E_FAIL;
		}
	}
	return S_OK;
}

HRESULT LockMutex()
{

	if(!ignoreMutex && !locked)
	{
		DWORD winAPIres = 0;

		winAPIres = WaitForSingleObject(pIntecMutex,mutexTimeOut);
		if(winAPIres == WAIT_TIMEOUT || winAPIres == WAIT_FAILED)
		{
			std::string errorStr("PID: ");
			errorStr+=std::to_string(process_id);
			errorStr+=" Could not acquire mutex lock, timeout";
			SetIntecLastError( errorStr.c_str());
			return E_FAIL;
		}
		locked=true;
	}
	return S_OK;
}

HRESULT UnlockMutex()
{
	if(!ignoreMutex && locked)
	{

		if(!ReleaseMutex(pIntecMutex))
		{
			char err[512];																			
				char errMsg[256];																			
				::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,												
				0,																			
				::GetLastError(),															
				0,																			
				errMsg,																		
				255,																		
				0);																			
				sprintf(err," %s %s"," Last Error = ",errMsg);								
				SetIntecLastError(err);	
				return E_FAIL;
		}
		locked=false;
	}
	return S_OK;
}
HRESULT Initialize(IntecUsbDeviceType dev)
{
	HRESULT hr=CreateIntecMutex();
	if(hr!=S_OK)
		return hr;

	// check if it is IntecH or IntecD using WinUSB driver
	try
	{
		p=InstantiateIntecServices(dev);
	}
	catch (std::exception& e)
	{
		DeleteIntecMutex();
		SetIntecLastError(e.what());
		return E_FAIL;
	}
	
	if(!p)
	{
		DeleteIntecMutex();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT InitializeOverEthernet(IntecUsbDeviceType dev,UINT numOfDevices, char * devicesAddress[])
{
	HRESULT hr=CreateIntecMutex();
	if(hr!=S_OK)
		return hr;

	// check if it is IntecH or IntecD using WinUSB driver
	try
	{
		p=InstantiateIntecServicesOverEthernet(dev, numOfDevices,  devicesAddress);
	}
	catch (std::exception& e)
	{
		DeleteIntecMutex();
		SetIntecLastError(e.what());
		return E_FAIL;
	}

	if(!p)
	{
		DeleteIntecMutex();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT  GetNumOfUSBDevices(UINT *numDevices)
{
	*numDevices=0;
	if(p)
	{
	if(LockMutex()!=S_OK)
		return E_FAIL;
	*numDevices=p->GetUSBDevices();
	if(UnlockMutex()!=S_OK)
		return E_FAIL;
	return S_OK;
	}
	return E_POINTER;
}

HRESULT GetDeviceMode(UINT index, IntecDeviceOperationMode *mode)
{
	*mode=UndefinedOpMode;
	if(p)
	{
		try
		{
		if(LockMutex()!=S_OK)
			return E_FAIL;
	    *mode=(*p)[index]->GetDeviceMode();
		if(UnlockMutex()!=S_OK)
			return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return S_OK;
	}
	return E_POINTER;

}

HRESULT SetDeviceMode(UINT index, IntecDeviceOperationMode mode)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			 res= (*p)[index]->SetDeviceMode(mode);
			 if(UnlockMutex()!=S_OK)
				 return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;

}


// return the Device Name by Index
HRESULT GetDeviceName(UINT index,UCHAR *szBuffer)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res=(*p)[index]->GetDeviceName(szBuffer);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;

}

// return the Device Version by Index
HRESULT GetDeviceVersion(UINT index,UCHAR *szBuffer)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (*p)[index]->GetDeviceVersion(szBuffer);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;
}
// return a mask of all the sub devices that are connected to by Index
// bit 0 is always ON - it represent the device itself

HRESULT GetNumOfSubDevices(UINT index,UINT *subDevicesMask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res=(*p)[index]->GetNumOfSubDevices(subDevicesMask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;
}

// Get a subDevice Mode
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
HRESULT GetSubDeviceMode(UINT index, UINT subDeviceIndex, IntecDeviceOperationMode *mode)
{
	*mode=UndefinedOpMode;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			*mode=(*p)[index]->GetSubDeviceMode(subDeviceIndex);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return S_OK;
	}
	return E_POINTER;

}

// Get a subDevice name
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
HRESULT GetSubDeviceName(UINT deviceIndex, UINT subDeviceIndex, UCHAR *szBuffer)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (*p)[deviceIndex]->GetSubDeviceName(subDeviceIndex,szBuffer);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;
}

// Get a subDevice version
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
HRESULT GetSubDeviceVersion(UINT deviceIndex, UINT subDeviceIndex, UCHAR *szBuffer)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (*p)[deviceIndex]->GetSubDeviceVersion(subDeviceIndex,szBuffer);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;
}


// Start a subDevice Boot Mode
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
// The function writes to the master register in inform it to enter subdevice into boot loader
// it has 2 effects: - the subdevice is enter to bootloader mode (jump into the boot code)
//					 - the master application enter to special bypass mode that transfer reads & writes to the sub device
// you must use StopSubDeviceBootMode to return the master to normal mode after you finished the programming of the sub device or you needs to abort this mode
HRESULT StartSubDeviceBootMode(UINT deviceIndex, UINT subDeviceIndex)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (*p)[deviceIndex]->StartSubDeviceBootMode(subDeviceIndex);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;
}

// Stop a subDevice Boot Mode
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
// The function writes to the master register in inform it to abort  to special bypass mode that used to transfer reads & writes to the sub device for programming
// this function is closed after  you finished the programming of the sub device or you needs to abort this mode

HRESULT StopSubDeviceBootMode(UINT deviceIndex, UINT subDeviceIndex)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (*p)[deviceIndex]->StopSubDeviceBootMode(subDeviceIndex);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;
}

// Get the Device Site # by Index
// when multiple Intec devices are connected to the same host it can be identified by the Site #,
// the user can change the Site # of intec by calling the SetDeviceSiteNumber(UINT index,UINT siteNum)
HRESULT GetDeviceSiteNumber(UINT index, UINT  *siteNum)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (*p)[index]->GetDeviceSiteNumber(*siteNum);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;
}

// Set the Device Site # by Index
// when multiple Intec devices are connected to the same host it can be identified by the Site #,
// the user can change the Site # of intec by calling the SetDeviceSiteNumber(UINT index,UINT siteNum)
HRESULT SetDeviceSiteNumber(UINT index, UINT  siteNum)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (*p)[index]->SetDeviceSiteNumber(siteNum);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		return res;

	}
	return E_POINTER;
}

HRESULT Terminate()
{
	delete p;
	p=NULL;
	return DeleteIntecMutex();
}


HRESULT WriteDevice(UINT index ,UCHAR *szBuffer,UINT cbSize)
{
	int res;
	if(p)
	{
		try
		{
		if(LockMutex()!=S_OK)
			return E_FAIL;
		res=(*p)[index]->Write(szBuffer,cbSize);
		if(UnlockMutex()!=S_OK)
			return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if (res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;

}

HRESULT WriteDeviceByAddr(UINT index ,UINT addr ,UCHAR *szBuffer,UINT cbSize)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res=(*p)[index]->Write(addr,szBuffer,cbSize);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if (res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;

}

HRESULT ReadDevice(UINT index,UCHAR *szBuffer,UINT *cbRead)
{
	int res;
	if(p)
	{
		try
		{
		if(LockMutex()!=S_OK)
			return E_FAIL;
		res= (*p)[index]->Read(szBuffer,cbRead);
		if(UnlockMutex()!=S_OK)
			return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT ReadDeviceByAddr(UINT index,UINT addr,UCHAR *szBuffer,UINT *cbRead)
{
	int res;
//	UCHAR internalReadBuff[64];

	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (*p)[index]->Read(addr,szBuffer,cbRead);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

//--------------------------
// Intec operation functions
//--------------------------

HRESULT InitializeCard(UINT index)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->Initialize(1);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


HRESULT InitializeCardNoReset(UINT index)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->Initialize(0);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecConfigurePeciPackage(unsigned int index, int package, int bus, int address)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecConfigurePeciPackage(package,bus,address);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecGetPeciPackageConfiguration(unsigned int index, int package,int *bus, int *address)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetPeciPackageConfiguration( package,bus, address);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecSetPeciInputs(UINT index,bool enable, UINT mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetPeciInputs(enable,mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}



// Get Peci inputs (channels) that are currently active  
HRESULT IntecGetPeciInputs(UINT index,UINT *mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetPeciInputs(mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Configure a Peci input (channel ) that the Intec device will read the temperatures ()
HRESULT IntecConfigurePeciInput(UINT index,int channel,int package, int sensor_num, char * sensor_name,bool enMaxTemp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecConfigurePeciInput( channel,package,  sensor_num,  sensor_name, enMaxTemp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get a Peci input (channel ) configured parameters
HRESULT IntecGetPeciInputConfiguration(UINT index,int channel,int *bus, int *address, int * sensor_num, char * sensor_name, BOOL *enMaxTemp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetPeciInputConfiguration( channel,bus, address, sensor_num, sensor_name, (bool *)enMaxTemp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}



//load and configure XML file that map between the source logical name (e.g core0) it’s PECI address (e.g addres 31) and the physical channel in Intec card.
HRESULT IntecLoadandConfigurePeciMapping(UINT index,char * peciConfFileName)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecLoadandConfigurePeciMapping( peciConfFileName);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

//Retrieve the  Address ,PeciVersion,ActualTjMax ,VttOk  ,Bus ,MuxCtrlOnPolarity from the peciClient (0..3)
// if the client is NOT connected an error is returned
HRESULT  IntecGetPeciClientParams(UINT index,UINT peciClient, UINT	*Address ,char *PeciVersion, UINT *ActualTjMax ,UINT *VttOk  ,UINT *Bus ,UINT *MuxCtrlOnPolarity )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetPeciClientParams(peciClient, *Address ,PeciVersion, *ActualTjMax ,*VttOk  ,*Bus ,*MuxCtrlOnPolarity );
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


HRESULT IntecConfigurePeciGenParams(UINT index,UINT EnMasterMode,UINT EnOnBoardVtt,UINT EnAutoTjMax,UINT frequencyIndex,UINT CmdsDelayUs,UINT LoopsDelayMs,UINT ManualTjMax)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecConfigurePeciGenParams( EnMasterMode, EnOnBoardVtt, EnAutoTjMax,frequencyIndex, CmdsDelayUs, LoopsDelayMs, ManualTjMax);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecGetPeciGenParams(UINT index,UINT *EnMasterMode,UINT *EnOnBoardVtt,UINT *EnAutoTjMax,UINT *frequencyIndex,UINT *CmdsDelayUs,UINT *LoopsDelayMs,UINT *ManualTjMax)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetPeciGenParams( *EnMasterMode, *EnOnBoardVtt, *EnAutoTjMax, *frequencyIndex, *CmdsDelayUs, *LoopsDelayMs, *ManualTjMax);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecExecutePassThroughPeciCommand(UINT index,UINT8 peciAddress, UINT8 peciBusNumber, UINT totalWriteLength, UINT totalReadLength, UCHAR * dataBufferToSend, UCHAR *dataBufferToReceive, bool  * FCSHeaderErr, bool * FCSMessageErr, UCHAR *CalcFCSHeader, UCHAR *CalFCSMessage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecExecutePassThroughPeciCommand(peciAddress, peciBusNumber, totalWriteLength, totalReadLength,  dataBufferToSend, dataBufferToReceive, *FCSHeaderErr, *FCSMessageErr, *CalcFCSHeader, *CalFCSMessage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
//this API will load an XML file into the TDAU device. 
HRESULT IntecLoadandConfigureTDAUConfiguration(UINT index,char * TdauConFileName)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecLoadandConfigureTDAUConfiguration( TdauConFileName);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecLoadandConfigureTDAUConfigurationNew(UINT index, char * TdauConFileName, char * TdauChnlMapFileName, bool loadHot)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecLoadandConfigureTDAUConfiguration( TdauConFileName, TdauChnlMapFileName, loadHot);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

//this API will load an XML file into the FastCal device. 
HRESULT IntecFastCalConfigurationRTD(UINT index,float slope0, float intercept0,float slope1, float intercept1,float slope2, float intercept2)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecFastCalConfigurationRTD(  slope0, intercept0, slope1,  intercept1,slope2,  intercept2);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

//Load the Tcase xml file that contains the  Tcase  configuration for each channels on Intecd cards
// actually it holds the manual calibration offset in InTEC Temp format
HRESULT IntecLoadandConfigureCaseConfiguration(UINT index,char * caseFileName)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecLoadandConfigureCaseConfiguration( caseFileName);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

//Calibrate the FASTcalRTD - this API calibrate the FAST cal on specific Temperature
HRESULT IntecFastCalCalibrationRTD(UINT index)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecFastCalCalibrationRTD( );
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


HRESULT IntecGetFastCalDiode(UINT index,int diode,float *slope, float *intercept)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetFastCalDiode(diode, slope, intercept);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecGetFastCalRTDStatus(UINT index,bool *RTDstatus )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetFastCalRTDStatus(RTDstatus );
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Enable/Disable the Diode inputs (channels ) that the Intec device will read the temperatures ()
HRESULT IntecSetDiodeInputs(UINT index,bool enable, UINT mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetDiodeInputs( enable,  mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get the Diodes inputs (channels) that are active status. 
HRESULT IntecGetDiodeInputs(UINT index,UINT *mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetDiodeInputs(mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Enable/Disable the Case inputs (channels ) that the Intec device will read the temperatures ()
HRESULT IntecSetCaseInputs(UINT index,int cardId,bool enable, UINT mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetCaseInputs( cardId, enable,  mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get the Case inputs (channels) that the Intec device will read the temperatures 
HRESULT IntecGetCaseInputs(UINT index,int cardId,UINT* mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetCaseInputs( cardId, mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Set the parameters for temperature calculation for specific Intecd ,the mode of calculation can bb avg/min/max, sources can be  DTS/
HRESULT IntecSetFeedBackControlParameters(UINT index,int cardId,IntecTemperatureCalcType calcMode,IntecTemperatureSourceType srcType,int sourceMask) 
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetFeedBackControlParameters( cardId, calcMode, srcType, sourceMask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecGetActualFeedBackType(UINT index,int cardId,IntecTemperatureSourceType *actualSrcType)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetActualFeedBackType(cardId,*actualSrcType);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Reset the FeedBack Min and Max Temperature values
HRESULT IntecResetMinMaxFeedBackTemperature(UINT index,int cardId)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecResetMinMaxFeedBackTemperature(cardId);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get the FeedBack Min and Max Temperature values
HRESULT IntecGetMinMaxFeedBackTemperature(UINT index,int cardId,float *minTemp, float *maxTemp,float *avgTemp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetMinMaxFeedBackTemperature(cardId,*minTemp, *maxTemp, *avgTemp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get the PCB Temperature values
HRESULT IntecGetPCBTemperature(UINT index,int cardId,float *DcDcModuleTemp, float *HBridgeModuleTemp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetPCBTemperature(cardId,*DcDcModuleTemp, *HBridgeModuleTemp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecSetMultiDiodePeciAllocation(UINT index, int diode_map_size,unsigned short diode_map[],int peci_map_size,unsigned short peci_map[])
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetMultiDiodePeciAllocation( diode_map_size, diode_map,peci_map_size,peci_map);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecGetActualFeedBackTemperatureSources(UINT index,int cardId,UINT *actualFeedBackTempSources)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetActualFeedBackTemperatureSources(cardId,*actualFeedBackTempSources);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecConfigureFallBack(UINT index, int cardId,IntecTemperatureCalcType  equation,IntecTemperatureSourceType source_type,unsigned short selected_Sources ,unsigned short caseWithOffsetTimeout, bool manualOffsetEnable, float manualOffset )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecConfigureFallBack(cardId,  equation, source_type, selected_Sources , caseWithOffsetTimeout,  manualOffsetEnable, manualOffset);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecGetFallBackConfiguration(UINT index, int cardId,IntecTemperatureCalcType  *equation,IntecTemperatureSourceType *source_type,unsigned short *selected_Sources ,unsigned short *caseWithOffsetTimeout, bool *manualOffsetEnable, float *manualOffset )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetFallBackConfiguration(cardId,  *equation, *source_type, *selected_Sources , *caseWithOffsetTimeout,  *manualOffsetEnable, *manualOffset);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get the parameters for temperature calculation for specific Intecd ,the mode of calculation can bb avg/min/max, sources can be  DTS
HRESULT IntecGetFeedBackControlParameters(UINT index,int cardId,IntecTemperatureCalcType *calcMode,IntecTemperatureSourceType *srcType,int *sourceMask) 
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetFeedBackControlParameters( cardId, *calcMode,*srcType,*sourceMask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Configure the temperature that we want to reach the temperature is IN IntecFormat 
HRESULT IntecSetTemperatureIF(UINT index,int cardId,unsigned short temprature)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetTemperature( cardId,temprature);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Configure the temperature that we want to reach  
HRESULT IntecSetTemperature(UINT index,int cardId,float temprature)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetTemperature( cardId,temprature);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get  the temperature that calculated for specific card  
HRESULT IntecGetTemperature(UINT index,int cardId,float *temprature, unsigned int * timestamp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetTemperature( cardId,temprature,  timestamp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get  the temperature that calculated for specific card in INtec format 
HRESULT IntecGetTemperatureIF(UINT index,int cardId,unsigned short *temprature, unsigned int * timestamp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetTemperature( cardId,temprature,  timestamp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get  the temperature that was reuested from specific intecd card  
HRESULT IntecGetRequestedTemperature(UINT index,int cardId,float *temprature, unsigned int * timestamp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetRequestedTemperature( cardId,temprature,  timestamp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// get the feedback temperature  feedback in all InTEC-D.
HRESULT IntecGetAllFeedBackTemperaturesIF( UINT index, int * sources_size, short  sources[], unsigned int *timestamp ,int * valid_mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetAllFeedBackTemperatures(  *sources_size, (unsigned short *)sources,  *timestamp , *valid_mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// get the feedback temperature  feedback in all InTEC-D.
HRESULT IntecGetAllFeedBackTemperatures(UINT index, int * sources_size,float  sources[], unsigned int *timestamp ,int * valid_mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetAllFeedBackTemperatures(  *sources_size, sources,  *timestamp , *valid_mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// get the temperature  from the  source that the user request (this enable the user to get the temperature  from various sources) in Intec Format
HRESULT IntecGetTemperatureSourcesIF(UINT index,IntecTemperatureSourceType src , int *sources_size, short  sources[], unsigned int *timestamp ,int * valid_mask) 
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetTemperatureSources( src ,  *sources_size,  (unsigned short *)sources, *timestamp ,*valid_mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// get the temperature  from the  source that the user request (this enable the user to get the temperature  from various sources).
HRESULT IntecGetTemperatureSources(UINT index,IntecTemperatureSourceType src , int *sources_size,float  sources[], unsigned int *timestamp ,int * valid_mask) 
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetTemperatureSources( src ,  *sources_size,  sources, *timestamp ,*valid_mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecEnableDisableVariableSetPointTemperature(UINT index,int cardId,bool enable)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecEnableDisableVariableSetPointTemperature(cardId, enable);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecSetVariableSetPointTemperature(UINT index,int cardId,float temperature )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetVariableSetPointTemperature(cardId,temperature );
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecGetVariableSetPointTemperature(UINT index,int cardId,bool  *enable, float *temperature )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetVariableSetPointTemperature(cardId,enable, temperature );
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// get the voltage  from the  sources that the user request (this enable the user to get the temperature  from various sources).
HRESULT IntecGetVoltageSources(UINT index,IntecVoltageSourceType src , int *sources_size,short sources[], unsigned int *timestamp ,int *valid_mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetVoltageSources( src , *sources_size, (unsigned short *)sources, * timestamp ,*valid_mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Enable/Disable the ProcHot inputs (channels ) that the Intec device will sense
HRESULT IntecSetProcHotInputs(UINT index,bool enable, UINT mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetProcHotInputs( enable,  mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get the ProcHot input mask that the Intec device will sense
HRESULT IntecGetProcHotInputs(UINT index,UINT *mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetProcHotInputs(mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Enable/Disable the PowerFollowing inputs (channels ) that the Intec device will sense
HRESULT IntecSetPFInputs(UINT index,bool enable, UINT mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetPFInputs(enable,  mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get the PowerFollowing input mask that the Intec device will sense
HRESULT IntecGetPFInputs(UINT index,UINT *mask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetPFInputs(mask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Configure the PowerFollowing parameters of pf_channel (channels ) that the Intec device will sense 
HRESULT IntecConfPFInputsParams(UINT index,int pf_channel, float slope, float intercept)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecConfPFInputsParams( pf_channel,  slope, intercept);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get the PowerFollowing parameters of pf_channel (channels ) that the Intec device sense 
HRESULT IntecGetPFInputsParams(UINT index,int pf_channel, float *slope, float *intercept)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetPFInputsParams( pf_channel,  *slope, *intercept);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get the counter of prochot events that occured on specific input channel
HRESULT IntecGetProcHotEventsCounter(UINT index,int input_num,int *Num_of_events)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetProcHotEventsCounter(input_num, Num_of_events);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Clear  the ProcHot inputs (channels ) that the Intec device will sense
HRESULT IntecClearProcHotEventsCounter(UINT index,int input_num) 		
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecClearProcHotEventsCounter( input_num);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


HRESULT IntecGetProcHotActualStatus(UINT index,int input_num,bool *procHot_detect_status)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetProcHotActualStatus(input_num,procHot_detect_status);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Configure and Run Auto Tcase SetPoint Below Prochot
// To check if the configuration is finished call IntecGetTcaseBelowProchotStatus
// params:
//		input_num = 0-3 of prochot channels
//		offset - the offset below Prochot temp to set 
HRESULT IntecSetTcaseBelowProchot(UINT index,int input_num,float offset)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetTcaseBelowProchot(input_num,offset);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}



// Get  Auto Tcase SetPoint Below Prochot configuration status
// enable the SetPoint in the HW according to the configuration in IntecConfigureTcaseBelowProchot()
// params:
//		input_num = 0-3 of prochot channels
//		inProcessStatus  = 1- the configuration is still in process, 0 - configuration terminated
//		prochotTemp - the Prochot temperature that was found 
HRESULT IntecGetTcaseBelowProchotStatus(UINT index,int input_num,bool * TcaseBelowProchotInProcess,float *prochotTemp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetTcaseBelowProchotStatus(input_num,TcaseBelowProchotInProcess,prochotTemp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Enable/Disable the TEC head
HRESULT IntecTECEnableDisable(UINT index,int cardId,bool enable)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECEnableDisable(cardId,enable);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Set Proportional gain,Integral,Derivative parameters
HRESULT IntecTECSetControlParams(UINT index,int cardId,UINT proportional, UINT integral, UINT derivative)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECSetControlParams(cardId,proportional, integral,derivative);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Set Proportional gain,Integral,Derivative parameters
HRESULT IntecTECGetControlParams(UINT index,int cardId,UINT *proportional, UINT *integral, UINT *derivative)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECGetControlParams(cardId,proportional, integral,derivative);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get the  CurrentSense ,VoltageSense , PowerOutCalc and PowerSupplySense  Fields in D_POWER_OUT_SENSE 
HRESULT IntecTECGetParams(UINT index,int cardId,float *currentSense, float *voltageSense, float *powerOutCalc, float *powerSupplySense, UINT *PWMCalc)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECGetParams(cardId,currentSense,voltageSense, powerOutCalc, powerSupplySense, PWMCalc);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get the TEC head status enable/disable, cooling/heating
HRESULT IntecTECStatus(UINT index,int cardId,int *enable, int *heat_status, int *cool_status)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECStatus(cardId,enable, heat_status, cool_status);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Set PRBS Low and High voltages
HRESULT IntecTECSetPRBSVoltage(UINT index,int cardId,float lowVoltage, float highVoltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECSetPRBSVoltage(cardId,lowVoltage,highVoltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}



// Get PRBS Low and High voltages
HRESULT IntecTECGetPRBSVoltage(UINT index,int cardId,float *lowVoltage, float *highVoltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECGetPRBSVoltage(cardId,*lowVoltage,*highVoltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// Set OpenLoop  voltage
HRESULT  IntecTECSetOpenLoopVoltage(UINT index,int cardId,float Voltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECSetOpenLoopVoltage(cardId,Voltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get Open Loop voltage
HRESULT IntecTECGetOpenLoopVoltage(UINT index,int cardId,float *Voltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECGetOpenLoopVoltage(cardId,*Voltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// Set Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
HRESULT IntecTECSetVmax(UINT index,int cardId,float Voltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECSetVmax(cardId,Voltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
HRESULT  IntecTECGetVmax(UINT index,int cardId,float *Voltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECGetVmax(cardId,*Voltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Set Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
HRESULT IntecTECSetVmaxHeatTec(UINT index,int cardId,float Voltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECSetVmaxHeatTec(cardId,Voltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
HRESULT  IntecTECGetVmaxHeatTec(UINT index,int cardId,float *Voltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECGetVmaxHeatTec(cardId,*Voltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Set PRBS Control Mode
HRESULT  IntecTECSetControlMode(UINT index,int cardId,IntecTecMode mode)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECSetControlMode(cardId, mode);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get PRBS Control Mode
HRESULT IntecTECGetControlMode(UINT index,int cardId,IntecTecMode *mode)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTECGetControlMode(cardId, *mode);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Read TDAU register
HRESULT IntecReadTDAURegister(UINT index,unsigned short regAddr, unsigned char regSize,unsigned char *actualReadSize,unsigned char *readData)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecReadTDAURegister(regAddr, regSize,actualReadSize,readData);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

//Thermal Head APIs
HRESULT IntecGetThermalHeadParam(UINT index,int cardId,IntecThermalHeadRegId paramType, unsigned int maxdataLen, char * data, unsigned int *actualDataLen )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetThermalHeadParam(cardId,paramType, maxdataLen, data,*actualDataLen);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


HRESULT IntecConfigureRampRateControlParam(UINT index,int cardId,bool  EnableRampRateControl,bool EnableFullRampRateControl, unsigned short   DesRampRate, unsigned short RampRateSPMargin)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecConfigureRampRateControlParam(cardId, EnableRampRateControl, EnableFullRampRateControl,    DesRampRate,  RampRateSPMargin );
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecGetRampRateControlParam(UINT index,int cardId,bool * EnableRampRateControl,bool *EnableFullRampRateControl, unsigned short  * DesRampRate, unsigned short * RampRateSPMargin,unsigned short * MesRampRate )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetRampRateControlParam(cardId, EnableRampRateControl, EnableFullRampRateControl,    DesRampRate,  RampRateSPMargin,MesRampRate );
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// WRITE to BLT TH EEPROM
HRESULT IntecWriteBLTEEprom(UINT index,int card_id, UINT offset, unsigned char * buffer, unsigned int size)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecWriteBLTEEprom(card_id, offset, buffer,size);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// Read to BLT TH EEPROM
HRESULT IntecReadBLTEEprom(UINT index,int card_id, UINT offset, unsigned char * buffer, unsigned int size)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecReadBLTEEprom(card_id, offset, buffer,size);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// Write TDAU register
HRESULT IntecWriteTDAURegister(unsigned int index,unsigned short regAddr, unsigned char regSize, char *writeData)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecWriteTDAURegister(regAddr, regSize,(unsigned char *)writeData);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Read TDAU register
HRESULT IntecReadTDAURegisterInt(unsigned int index,unsigned short regAddr, unsigned char regSize,unsigned char *actualReadSize,unsigned int *readData)
{
	HRESULT res;
	unsigned char regBuffer[6];
	if(regSize>4)
	{
		SetIntecLastError("IntecReadTDAURegisterInt:: Invalid Size to read");
		return E_INVALIDARG;
	}
	res=IntecReadTDAURegister(index, regAddr, regSize,actualReadSize,regBuffer);
	if(res==S_OK)
		memcpy(readData,regBuffer,min(regSize,*actualReadSize));
	return res;
	
}

// Write TDAU register
HRESULT IntecWriteTDAURegisterInt(unsigned int index,unsigned short regAddr, unsigned char regSize, unsigned  int writeData)
{
	char regBuffer[6];
	if(regSize>4)
	{
		SetIntecLastError("IntecWriteTDAURegisterInt:: Invalid Size to read");
		return E_INVALIDARG;
	}
	memcpy(regBuffer,&writeData,regSize);
	return IntecWriteTDAURegister(index,regAddr, regSize,regBuffer);
}

// Get TDAU status 
HRESULT IntecGetTDAUStatus(unsigned int index,IntecTDAUStatus *status)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetTDAUStatus(*status);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get TDAU status 
HRESULT IntecGetTDAUVersion(unsigned int index,unsigned short *version)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetTDAUVersion(*version);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Calibrate the TDAU
HRESULT IntecTDAUCalibrate(unsigned int index)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTDAUCalibrate();
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}



//load and configure Events XML file.
HRESULT IntecLoadandConfigureEvents(UINT index,int cardId,char * eventsFileName)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecLoadandConfigureEvents(cardId,eventsFileName);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT  IntecLoadEvents(UINT index,int cardId,char * eventsFileName)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecLoadandConfigureEvents(cardId,eventsFileName,false);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get a Event configuration
HRESULT IntecGetEventParam(UINT index,int cardId,EventType evType,int eventId,  char *paramName,UINT *paramValue)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			EventConfigurationParam eventParam;
			memset(&eventParam,0,sizeof(EventConfigurationParam));
			memcpy(eventParam.Name,paramName,min(strlen(paramName),64));
			res= (p->GetOperations(index))->IntecGetEventParam(cardId,evType,eventId, &eventParam);
			*paramValue=eventParam.value;
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Set a Event configuration
HRESULT IntecSetEventParam(UINT index,int cardId,EventType evType,int eventId,  char *paramName,UINT paramValue)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			EventConfigurationParam eventParam;
			memset(&eventParam,0,sizeof(EventConfigurationParam));
			memcpy(eventParam.Name,paramName,min(strlen(paramName),64));
			eventParam.value=paramValue;
			res= (p->GetOperations(index))->IntecSetEventParam(cardId,evType,eventId, eventParam);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get a Event disable
HRESULT IntecGetEventDisableStatus(UINT index,int cardId,EventType evType,int eventId, bool * isDisable, bool *disableStatus)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetEventDisableStatus(cardId,evType,eventId, isDisable,disableStatus);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get a Event StopTesting status
HRESULT  IntecGetEventStopTestingStatus(UINT index,int cardId,EventType evType,int eventId, bool * stopTesting)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetEventStopTestingStatus(cardId,evType,eventId,stopTesting);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Set a Event disable or enable
HRESULT IntecSetEventDisableEnable(UINT index,int cardId,EventType evType,int eventId, bool disable_enable)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetEventDisableEnable(cardId,evType,eventId, disable_enable);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get Events status
HRESULT IntecGetEventsStatus(UINT index,int cardId,EventType evType,UINT32 * eventsStatus)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetEventsStatus( cardId, evType, eventsStatus);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get Event Name
HRESULT IntecGetEventName(UINT index,int cardId,EventType evType,int eventId,int maxMsgLen, char * msg)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetEventName(cardId, evType, eventId, maxMsgLen,  msg);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get Events Description
HRESULT IntecGetEventDescription(UINT index,int cardId,EventType evType,int eventId,int maxMsgLen, char * msg)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetEventDescription(cardId, evType, eventId, maxMsgLen,  msg);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// Get Events Action
HRESULT IntecGetEventAction(UINT index,int cardId,EventType evType,int eventId,int maxMsgLen, char * msg)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetEventAction(cardId, evType, eventId, maxMsgLen,  msg);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get Event ParamsSize
HRESULT IntecGetEventParamsSize(UINT index,int cardId,EventType evType,int eventId,unsigned int * paramsSize)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetEventParamsSize(cardId, evType, eventId, paramsSize);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get Events Params[paramIdx] name
HRESULT IntecGetEventParamName(UINT index,int cardId,EventType evType,int eventId,unsigned int paramId,int maxMsgLen, char * msg)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetEventParamName(cardId, evType, eventId, paramId,maxMsgLen,  msg);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Disarm Intec  and enable the operator to fix issues
HRESULT IntecDisarm(UINT index,int cardId, UINT TimeOutMiliSec)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecDisarm(cardId,TimeOutMiliSec);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// Arm Intec  after the operator to fix issues
HRESULT IntecRearm(UINT index,int cardId, UINT TimeOutMiliSec)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecRearm(cardId,TimeOutMiliSec);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// Get Disarm Intec status and enable the operator to fix issues
HRESULT IntecGetDisarmStatus(UINT index,int cardId,  bool * isDisarmed)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetDisarmStatus(cardId, isDisarmed);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Fast Disarm Intec  and enable the operator to fix issues
HRESULT IntecFastDisarm(UINT index,int cardId)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecFastDisarm(cardId);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Fast Arm Intec  after the operator to fix issues
HRESULT IntecFastRearm(UINT index,int cardId)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecFastRearm(cardId);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// choose RTD Sensor Type
HRESULT IntecSetRTDSensor(UINT index,int cardId,IntecRTDSensorType sensor_type)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetRTDSensor(cardId,sensor_type);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get RTD Sensor Type
HRESULT IntecGetRTDSensor(UINT index,int cardId,IntecRTDSensorType *sensor_type)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetRTDSensor(cardId,*sensor_type);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Set The Gang Auto Cfg mode : 1- enable, 0-disable
HRESULT  IntecGetGangAutoCfg(UINT index,int cardId,bool * gangAutoCfgMode)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetGangAutoCfg(cardId, gangAutoCfgMode);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get The Gang Auto Cfg mode : 1- enabled, 0-disabled
HRESULT   IntecSetGangAutoCfg(UINT index,int cardId,bool gangAutoCfgMode)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetGangAutoCfg(cardId, gangAutoCfgMode);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT IntecGetTCaseType(UINT index,int cardId,IntecTCASEType *tcase_type)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetTCaseType(cardId,*tcase_type);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecTestabilityStart(unsigned int index,IntecTestabiliyMode test,IntecCardType card_type,int card_id)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTestabilityStart( test, card_type,card_id);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecTestabilityAbort(UINT index,IntecTestabiliyMode test,IntecCardType card_type,int card_id)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTestabilityAbort( test, card_type,card_id);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecTestabilityGetResults(UINT index,IntecTestabiliyMode test,IntecCardType card_type,int card_id ,UINT * testStatus,UINT64 *testErrorMask)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTestabilityGetResults(test, card_type, card_id , testStatus,testErrorMask);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecTestabilityGetErrorMessage(UINT index,IntecTestabiliyMode test,IntecCardType card_type,UINT errorId,char *errorMsg,UINT errorMsgSize)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecTestabilityGetErrorMessage(test, card_type,errorId,errorMsg , errorMsgSize);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// return the number of cards (intecD ) that installed on the system
HRESULT IntecGetNumberIntecDCards(UINT index,int * cards)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetNumberIntecDCards( *cards);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Check if the PECI Module card is connected 
HRESULT IntecCheckPECIModuleConnected(UINT index,int * connected)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecCheckPECIModuleConnected(*connected);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// return the Intec Firmware version 
HRESULT IntecGetFirmWareVersion(UINT index,IntecCardType card_type,int card_id, int *ver)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetFirmWareVersion(card_type,card_id, ver);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

//return the Intec FW bundle version
HRESULT IntecGetFirmWareBundleVersion(UINT index,int *intecBundleVer)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetFirmWareBundleVersion(intecBundleVer);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// return the Intec Device Serial
HRESULT IntecGetDeviceSerialNumber(UINT index, IntecCardType card_type,int card_id, char *serial)

{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetDeviceSerialNumber(card_type,card_id, serial);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// return the Intec Driver software version 
HRESULT IntecGetSoftwareVersion(UINT index,char *ver, int bufferSize)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetSoftwareVersion(ver,bufferSize);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT  IntecGetIPAddress(UINT index,char *ip_addr,int bufferSize)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetIPAddress(ip_addr,bufferSize);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Set the Intec IP address according to  dot notation ip_addr
HRESULT IntecSetIPAddress(UINT index, const char *ip_addr)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetIPAddress(ip_addr);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// Set IP Mode Static or DHCP
HRESULT IntecSetIPMode(UINT index, IntecIpMode mode)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSetIPMode(mode);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Get IP mode DHAC or Static
HRESULT  IntecGetIPMode(UINT index, IntecIpMode * mode)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetIPMode(mode);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT  IntecApplyIPChanges(UINT index)
{
	int res;
	char addr[20];

	if(p)
	{

		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetIPAddress(addr,20);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecApplyIPChanges();
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		Sleep(2000);
		res= (*p)[index]->Disconnect();
		if(!res)
			return E_FAIL;
		res= (*p)[index]->Close();
		if(!res)
			return E_FAIL;

		res= (*p)[index]->SetDeviceAddress(addr);
		if(!res)
			return E_FAIL;

		res= (*p)[index]->Open();
		if(!res)
			return E_FAIL;
		res= (*p)[index]->Connect();
		if(!res)
			return E_FAIL;
		return S_OK;
	}

	return E_POINTER;

}
HRESULT IntecGetDeviceTimeStamp(UINT index,IntecCardType card_type,int card_id, unsigned int *hours, unsigned int *minutes, unsigned int *seconds)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetDeviceTimeStamp(card_type,card_id, *hours, *minutes,*seconds);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Get EEPROM Status and Type
HRESULT IntecGetThermalHeadEEpromStatus(UINT index,int card_id,bool *ThEEpormNotDetected,bool *THEEpromType )
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetThermalHeadEEpromStatus(card_id,*ThEEpormNotDetected,*THEEpromType);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// clear EEPROM configuration to defaule and restart software.
HRESULT IntecClearConfigurationFromEEPROM(UINT index)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecClearConfigurationFromEEPROM();
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
// Store configuration to EEPROM .
HRESULT IntecStoreConfigurationToEEPROM(UINT index)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecStoreConfigurationToEEPROM();
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

// Reset Microchip Software
// after this call user need to call Terminate() and  Initialize() functions
HRESULT IntecSoftwareReset(UINT index)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecSoftwareReset();
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
//General functions

// Reset Intec HW
// resetType:  0 – reset device
// 			 1  - reset to EEPROM default params
HRESULT IntecReset(UINT index,int resetType)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecReset(resetType);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


//configuration by file
HRESULT IntecConfigureByFile(UINT index,char * configFileName)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecConfigureByFile(configFileName);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;	
}

// Disable/Enable the Intec buzzer
HRESULT  IntecBuzzerDisableEnable(UINT index,bool disable)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecBuzzerDisableEnable(disable);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


// diagnostics

HRESULT  IntecDiagnosticConfigure(UINT index,char *configureDiagnosticFileName)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecDiagnosticConfigure(configureDiagnosticFileName);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT  IntecDiagnosticStart(UINT index)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecDiagnosticStart();
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT  IntecDiagnosticAbort(UINT index) 
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecDiagnosticAbort();
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT  IntecDiagnosticGetResult(UINT index,bool * running,bool *passed, int * num_of_errors ,char* error_msgs[], int max_messages)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecDiagnosticGetResult(*running,*passed, *num_of_errors ,error_msgs,max_messages);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}


HRESULT IntecDiagnosticGetXMLFileName(UINT index, char *configureDiagnosticFileName, unsigned int bufferSize)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecDiagnosticGetXMLFileName(configureDiagnosticFileName, bufferSize);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;		
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecGetDiagnosticTestStatus(UINT index, unsigned int testID, bool * enabled)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetDiagnosticTestStatus(testID, *enabled);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;		
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}
HRESULT IntecGetDiagnosticParamVal(UINT index, const char * paramName,const char * paramType, float * calcVal)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetDiagnosticParamVal( std::string (paramName),std::string (paramType), * calcVal);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;		
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT  IntecGetImpedance(UINT index,int cardId,bool * valid,float *impedance)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))->IntecGetImpedance( cardId,*valid,*impedance);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;	
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT  IntecEnvGetCondensationVoltage(UINT index, int cardId, float *voltage)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))-> IntecEnvGetCondensationVoltage(cardId, *voltage);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;	
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT  IntecGetWaterModuleStatus(UINT index,int cardId,bool *connected)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))-> IntecGetWaterModuleStatus(cardId, *connected);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;		
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT  IntecGetWaterModuleParams(UINT index,int cardId,bool *moduleConnected,bool *WaterModuleMeasEnabled,bool *ChillerMeasEnabled,bool *FloorMeasEnabled, float *WaterModuleImp ,float *ChillerImp , float *FloorImp)
{
	int res;
	if(p)
	{
		try
		{
			if(LockMutex()!=S_OK)
				return E_FAIL;
			res= (p->GetOperations(index))-> IntecGetWaterModuleParams(cardId, *moduleConnected,*WaterModuleMeasEnabled, *ChillerMeasEnabled, *FloorMeasEnabled, *WaterModuleImp , *ChillerImp , *FloorImp);
			if(UnlockMutex()!=S_OK)
				return E_FAIL;
		}
		catch (std::exception& e)
		{
			UnlockMutex();
			SetIntecLastError(e.what());
			return E_FAIL;
		}
		if(res)
			return S_OK;
		else
			return E_FAIL;
	}
	return E_POINTER;
}

HRESULT  IntecGetCoolentFlowsense(UINT index,int cardId,float *flowsense)
{
	HRESULT res;
	UINT paramValue;
	res=IntecGetEventParam(index,cardId,(EventType)0 ,0,  "FlowSense",&paramValue);
	if(res==S_OK)
	{
		*flowsense=(float)paramValue/100;
	}
	return res;
}

//-------------------------
// Error handling functions
//-------------------------
std::string IntecLastError;
void SetIntecLastError(const char * err)
{
	if(!IntecLastError.empty())
	{
		IntecLastError.insert(0,"->");
	}
	IntecLastError.insert(0,err);




}

void GetIntecLastError(char *buff, UINT bufsize)
{
	// clear the buffer
	memset(buff,0,bufsize);
	// check boundries & copy
	if(IntecLastError.size() <bufsize)
		memcpy(buff,IntecLastError.c_str(),IntecLastError.size());
	else
		memcpy(buff,IntecLastError.c_str(),bufsize-1);
	IntecLastError.clear();
}



