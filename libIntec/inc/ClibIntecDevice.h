/*
 * ClibIntecDevice.h
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#ifndef INC_CLIBINTECDEVICE_H_
#define INC_CLIBINTECDEVICE_H_
#include <stdint.h>
#include <iostream>
#include "libIntec.h"
#include <libusb-1.0/libusb.h>
class ClibIntecDevice {
public:
	ClibIntecDevice(){}
	virtual ~ClibIntecDevice(){}
	virtual int32_t Open()=0;
	virtual int32_t Close()=0;
	virtual int32_t Connect()=0;
	virtual int32_t Diconnect()=0;
	virtual int32_t Write(unsigned char *szBuffer, uint32_t cbSize)=0;
	virtual int32_t Read(unsigned char *szBuffer, uint32_t *cbRead)=0;
	virtual int32_t Write(uint32_t addr, unsigned char *szBuffer, uint32_t cbSize)=0;
	virtual int32_t Read(uint32_t addr, unsigned char *szBuffer, uint32_t *cbSize)=0;
	virtual IntecDeviceOperationMode GetDeviceMode()=0;
	virtual int32_t SetDeviceMode(IntecDeviceOperationMode)=0;
	virtual int GetConfiguration(){return ERROR_NOT_IMPLEMETED;}
	virtual int32_t SetConfiguration(int config){return ERROR_NOT_IMPLEMETED;}
	virtual int32_t SetVidPid(uint16_t vid, uint16_t pid){return ERROR_NOT_IMPLEMETED;}
	virtual int32_t SetDeviceReference(libusb_device*){return ERROR_NOT_IMPLEMETED;}
	virtual int32_t GetPortNumber(){return ERROR_NOT_IMPLEMETED;}

};

#endif /* SRC_CLIBINTECDEVICE_H_ */
