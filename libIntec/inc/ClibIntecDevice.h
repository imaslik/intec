/*
 * ClibIntecDevice.h
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#ifndef SRC_CLIBINTECDEVICE_H_
#define SRC_CLIBINTECDEVICE_H_
#include <stdint.h>


class ClibIntecDevice {
public:
	ClibIntecDevice();
	virtual ~ClibIntecDevice()=0;
	virtual int32_t Open()=0;
	virtual int32_t Close()=0;
	virtual int32_t Connect()=0;
	virtual int32_t Diconnect()=0;
	virtual int32_t Write(unsigned char *szBuffer, uint32_t cbSize)=0;
	virtual int32_t Read(unsigned char *szBuffer, uint32_t *cbRead)=0;
	virtual int32_t Write(uint32_t addr, unsigned char *szBuffer, uint32_t cbSize)=0;
	virtual int32_t Read(uint32_t addr, unsigned char *szBuffer, uint32_t *cbSize)=0;

};

#endif /* SRC_CLIBINTECDEVICE_H_ */
