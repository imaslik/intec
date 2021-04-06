/*
 * ClibIntecUsbDevice.h
 *
 *  Created on: Apr 6, 2021
 *      Author: svshared
 */

#ifndef SRC_CLIBINTECUSBDEVICE_H_
#define SRC_CLIBINTECUSBDEVICE_H_

#include <stdint.h>
#include "libIntec.h"
#include <libusb-1.0/libusb.h>


#define USB_READ_WRITE_TIMEOUT_MS 10000

typedef struct _USB_TRANS {
	unsigned short transCmd;
	unsigned long Addr;
	unsigned short DataCount;  // the  actual Data size
	unsigned char Data[256];
} USB_TRANS, *PUSB_TRANS;

struct PIPE_ID
{
	unsigned char PipeInId;
	unsigned short PipeInMaxPacketSize;
	unsigned char PipeOutId;
	unsigned short PipeOutMaxPacketSize;
};

class ClibIntecUsbDevice {
public:
	ClibIntecUsbDevice(IntecUsbDeviceType devType, unsigned long devIndex, IntecDeviceOperationMode mode, IntecDeviceDriverType driverType);
	virtual ~ClibIntecUsbDevice();

	virtual int32_t Open();
	virtual int32_t Connect();
	virtual int32_t Write(unsigned char *szBuffer, uint32_t cbSize);
	virtual int32_t Read(uint32_t addr, unsigned char *szBuffer, uint32_t *cbSize);
	virtual int32_t Write(uint32_t addr, unsigned char *szBuffer, uint32_t cbSize);
	virtual int32_t Read(unsigned char *szBuffer, uint32_t *cbRead);
	virtual int32_t Diconnect();
	virtual int32_t Close();
	virtual IntecDeviceOperationMode GetDeviceOperationMode();

protected:
	bool GetUsbDeviceSpeed(unsigned char * pDevcieSpeed);
	bool GetDeviceHnadleByIndex(IntecUsbDeviceType type, unsigned long RequestedIndex, int hDeviceHandle);
	bool QueryDeviceEndpoints(PIPE_ID pipeid, unsigned long TimeOutMSec);

private:

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
