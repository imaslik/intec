/*
 * ClibIntecUsbDevice.h
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#ifndef SRC_CLIBINTECUSBDEVICE_H_
#define SRC_CLIBINTECUSBDEVICE_H_

#include <stdint.h>
#include "libIntec.h"
#include <libusb-1.0/libusb.h>
#include "ClibIntecDevice.h"

#define USB_READ_WRITE_TIMEOUT_MS 10000

typedef struct _USB_TRANS {
	unsigned short transCmd;
	unsigned long Addr;
	unsigned short DataCount;  // the  actual Data size
	unsigned char Data[256];
} USB_TRANS, *PUSB_TRANS;

class ClibIntecUsbDevice : public  ClibIntecDevice
{
public:
	ClibIntecUsbDevice();
	ClibIntecUsbDevice(IntecUsbDeviceType devType, uint32_t devIndex, IntecDeviceOperationMode mode, IntecDeviceDriverType driverType);
	virtual ~ClibIntecUsbDevice();

	virtual int32_t Open(){return STATUS_OK;}
	virtual int32_t Close(){return STATUS_OK;}
	virtual int32_t Connect(){return STATUS_OK;}
	virtual int32_t Diconnect(){return STATUS_OK;}
	virtual int32_t Write(unsigned char *szBuffer, uint32_t cbSize){return STATUS_OK;}
	virtual int32_t Read(unsigned char *szBuffer, uint32_t *cbRead){return STATUS_OK;}
	virtual int32_t Write(uint32_t addr, unsigned char *szBuffer, uint32_t cbSize){return STATUS_OK;}
	virtual int32_t Read(uint32_t addr, unsigned char *szBuffer, uint32_t *cbSize){return STATUS_OK;}
	virtual IntecDeviceOperationMode GetDeviceOperationMode(){return UndefinedOpMode;}

protected:
	bool GetUsbDeviceSpeed(unsigned char * pDevcieSpeed){return true;}
	bool GetDeviceHnadleByIndex(IntecUsbDeviceType type, unsigned long RequestedIndex, int hDeviceHandle){return true;}
	bool QueryDeviceEndpoints(unsigned long TimeOutMSec){return true;}

	IntecUsbDeviceType m_DeviceType;
	unsigned long m_DeviceIndex;
	IntecDeviceDriverType m_DriverType;

	static const unsigned char USB_WRITE_WORD_COMMAND = 0x02;
	static const unsigned char USB_READ_WORD_COMMAND = 0x01;
	static const int DEFAULT_TX_TIMEOUT_MS = 2000;
	static const int DEFAULT_RX_TIMEOUT_MS = 2000;
	static const int MAX_WRITE_PKT_SIZE = 63;
	static const int  MAX_READ_PKT_SIZE = 64;
	static const short PKT_HEADER_LENGTH = 6;
	static const short REG_WIDTH = 4;
};

#endif /* SRC_CLIBINTECUSBDEVICE_H_ */
