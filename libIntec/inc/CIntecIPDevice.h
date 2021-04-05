#ifndef _CIntec_IPDevice_H_
#define _CIntec_IPDevice_H_

#include "IIntecServices.h"
#include "IIntecUSBDevice.h"
#pragma warning ( disable : 4290 4995 4996)
#define WIN32_LEAN_AND_MEAN

#include <string>  
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#define __stringize(n) #n
#define __eval(line) __stringize(line)
#define todo(task) message(__FILE__ "(" __eval(__LINE__) ") : TODO: " task)
#define info(task) message(__FILE__ "(" __eval(__LINE__) ") : INFO: " task)


//#pragma pack(push, 1)                       // force byte alignment
//
//
//typedef struct _USB_TRANS {
//	WORD transCmd;
//	DWORD Addr;
//	WORD DataCount;  // the  actual Data size
//	BYTE Data[256];
//} USB_TRANS, *PUSB_TRANS;
//
//#pragma pack(pop)                          // restore previous alignment
//
//
//struct PIPE_ID
//{
//	UCHAR  PipeInId;
//	USHORT PipeInMaxPacketSize;
//	UCHAR  PipeOutId;
//	USHORT PipeOutMaxPacketSize;
//
//};

class CIntecIPDevice: public IIntecUSBDevice
{

public : 

	// ctor
	 CIntecIPDevice(IntecUsbDeviceType devType, DWORD devIndex,IntecDeviceOperationMode mode,IntecDeviceDriverType driverType);
	// dtor
	virtual ~CIntecIPDevice();


	// Find # of USB device of Type are connected
	virtual const int Open();
	virtual const int Connect();
	virtual const int Write(UCHAR *szBuffer,UINT cbSize);
	virtual const int Read(UINT addr,UCHAR *szBuffer,UINT *cbSize);
	virtual const int Write(UINT addr, UCHAR *szBuffer,UINT cbSize);
	virtual const int Read(UCHAR *szBuffer,UINT *cbRead);
	virtual const int Disconnect();
	virtual const int Close();

	virtual IntecDeviceOperationMode GetDeviceMode();
	virtual const int SetDeviceAddress(char *addr);
protected:
	//BOOL GetUSBDeviceSpeed( UCHAR* pDeviceSpeed);
	//BOOL GetDeviceHandleByIndex (IntecUsbDeviceType type,DWORD requestedIndex, PHANDLE hDeviceHandle);
	//BOOL QueryDeviceEndpoints (PIPE_ID* pipeid);
	//BOOL SetInOutPipeTimeout (PIPE_ID pipeid, ULONG timeOutMsec);
	virtual const int WriteAndRead(UCHAR * writeBuffer,UINT writeSize, UCHAR * readBuffer, UINT *readSize);
	const int Reconnect();
	IntecUsbDeviceType devType_;
	DWORD devIndex_;
	IntecDeviceOperationMode mode_;
	IntecDeviceDriverType driverType_;
	std::string IntecUsbDeviceTypeNames[3] ;
	std::string ipAddress_;
private:
	
	SOCKET connectSocket_ ;
	struct addrinfo hints_;
	struct addrinfo *pServerAddr_;
	bool socketCreated_;
	bool connected_;

	static const UCHAR USB_WRITE_WORD_COMMAND = 0x02;
	static const UCHAR USB_READ_WORD_COMMAND = 0x01;
	static const int DEFAULT_TX_TIMEOUT_MS = 2000;
	static const int DEFAULT_RX_TIMEOUT_MS = 2000;
	static const int MAX_WRITE_PKT_SIZE = 63;
	static const int  MAX_READ_PKT_SIZE = 256;
	static const short PKT_HEADER_LENGTH = 6;
	static const short REG_WIDTH = 4;
};

#endif //_CIntec_USBDevice_H_
