

#ifndef _CIntec_Services_H_
#define _CIntec_Services_H_

#include "IntecDLL.h"
#include "IIntecServices.h"
#include "CIntecException.h"

#define MAX_USB_DEVICES 8

class CIntecServices : public IIntecServices
{

public : 

	// 
	

	// Find # of USB device of Type are connected
	inline virtual const int GetUSBDevices()
	{
			return m_numDevs;
	}
	//inline virtual IntecDeviceOperationMode GetDeviceMode()
	//{
	//	  return mode_;
	//}
	/*static IIntecServices* instance(bool log=false) {
		if ( ! s_instance )
			s_instance = new CIntecServices();
		return s_instance;
	}
	*/
	void GetLastErrorMsg(LPTSTR lpszFunction, DWORD err) ;

	//ctor is protected for singleton
	CIntecServices(IntecUsbDeviceType type);
	CIntecServices(IntecUsbDeviceType dev,UINT numOfDevices, char * devicesAddress[]);
	IIntecUSBDevice *operator[](UINT i);
	inline IIntecOperations *GetOperations(UINT i)
	{
			if (i<m_numDevs)
				return m_IntecOperations[i]; 
			else
				throw CIntecException("Index Out of USB Devices range");
	};

	//dtor
	~CIntecServices();
protected:
	IIntecUSBDevice *AllocatedUSBInterface( DWORD requestedIndex,IntecUsbDeviceType type,IntecDeviceOperationMode mode,IntecDeviceDriverType driverType);
	IIntecOperations *AllocatedIntecOperations( DWORD requestedIndex,IntecUsbDeviceType type,IntecDeviceOperationMode mode);
	
	const int SearchUSBDevices(IntecUsbDeviceType dev);
	const int SearchWinUSBDevices(IntecUsbDeviceType type);
	const int SearchMPUSBDevices(IntecUsbDeviceType type);
	const int SearchBootLoader(IntecUsbDeviceType type);
	const int SearchEthernetDevices(IntecUsbDeviceType dev,UINT numOfDevices, char * devicesAddress[]);


	CIntecServices();
private:
	//static IIntecServices* s_instance;
	DWORD m_numDevs;

	IIntecUSBDevice * m_Interfaces[MAX_USB_DEVICES];
	IIntecOperations * m_IntecOperations[MAX_USB_DEVICES];
	char m_msgBuff[512];

};

#endif //_CIntec_Services_H_
