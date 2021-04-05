#ifndef _CIntec_USBDevice_H_
#define _CIntec_USBDevice_H_

#include "IIntecServices.h"
#include "IIntecUSBDevice.h"
#pragma warning ( disable : 4290 4995 4996)
#include <string>  

#define USB_READ_WRITE_TIMEOUT_MS 10000

#define __stringize(n) #n
#define __eval(line) __stringize(line)
#define todo(task) message(__FILE__ "(" __eval(__LINE__) ") : TODO: " task)
#define info(task) message(__FILE__ "(" __eval(__LINE__) ") : INFO: " task)

typedef enum {
	// supported transaction types
	USB_TRANS_NOADR,          // read or write with no address cycle
	USB_TRANS_8ADR,           // read or write by 8 bit address cycle - the data contains: 8 bit reg address and rest is the data to write
	USB_TRANS_16ADR,          // read or write  by 16 bit address cycle -the data contains: 16 bit reg address and rest is the data to write
	USB_TRANS_32ADR          // read or write with 32 bit address cycle
	
} USB_TRANS_CMD;

#pragma pack(push, 1)                       // force byte alignment


typedef struct _USB_TRANS {
	WORD transCmd;
	DWORD Addr;
	WORD DataCount;  // the  actual Data size
	BYTE Data[256];
} USB_TRANS, *PUSB_TRANS;

#pragma pack(pop)                          // restore previous alignment


struct PIPE_ID
{
	UCHAR  PipeInId;
	USHORT PipeInMaxPacketSize;
	UCHAR  PipeOutId;
	USHORT PipeOutMaxPacketSize;

};

class CIntecUSBDevice: public IIntecUSBDevice
{

public : 

	// ctor
	 CIntecUSBDevice(IntecUsbDeviceType devType, DWORD devIndex,IntecDeviceOperationMode mode,IntecDeviceDriverType driverType);
	// dtor
	virtual ~CIntecUSBDevice();


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
	virtual const int SetDeviceAddress(char *addr) {return true;};
protected:
	BOOL GetUSBDeviceSpeed( UCHAR* pDeviceSpeed);
	BOOL GetDeviceHandleByIndex (IntecUsbDeviceType type,DWORD requestedIndex, PHANDLE hDeviceHandle);
	BOOL QueryDeviceEndpoints (PIPE_ID* pipeid);
	BOOL SetInOutPipeTimeout (PIPE_ID pipeid, ULONG timeOutMsec);
	virtual const int WriteAndRead(UCHAR * writeBuffer,UINT writeSize, UCHAR * readBuffer, UINT *readSize);
	const int Reconnect();
	IntecUsbDeviceType devType_;
	DWORD devIndex_;
	IntecDeviceOperationMode mode_;
	IntecDeviceDriverType driverType_;
	std::string IntecUsbDeviceTypeNames[3] ;
private:
	
	HANDLE hDeviceHandle_;
	WINUSB_INTERFACE_HANDLE hWinUSBHandle_;
	PIPE_ID pipeID_;


	static const UCHAR USB_WRITE_WORD_COMMAND = 0x02;
	static const UCHAR USB_READ_WORD_COMMAND = 0x01;
	static const int DEFAULT_TX_TIMEOUT_MS = 2000;
	static const int DEFAULT_RX_TIMEOUT_MS = 2000;
	static const int MAX_WRITE_PKT_SIZE = 63;
	static const int  MAX_READ_PKT_SIZE = 64;
	static const short PKT_HEADER_LENGTH = 6;
	static const short REG_WIDTH = 4;
};

#endif //_CIntec_USBDevice_H_
