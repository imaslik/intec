/*
 * ClibIntecUsbDevice.h
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#ifndef SRC_CLIBINTECUSBDEVICE_H_
#define SRC_CLIBINTECUSBDEVICE_H_

#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "libIntec.h"
#include <libusb-1.0/libusb.h>
#include "ClibIntecDevice.h"
#include "ClibIntecException.h"
#include "libIntec_InTEC_DwDefs.h"
#include "libIntec_PECIModule_DwDefs.h"

#define min(a,b) (((a) < (b)) ? (a) : (b))

#define USB_READ_WRITE_TIMEOUT_MS 10000
#define MAX_PORT_DEPTH 7

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
	virtual void SetUsbDeviceType(IntecUsbDeviceType type);
	virtual int32_t InitializeDevice(unsigned int);
	virtual int32_t Open();
	virtual int32_t Close();
	virtual int32_t Connect();
	virtual int32_t Diconnect();
	virtual int32_t Write(unsigned char *szBuffer, unsigned int cbSize);
	virtual int32_t Read(unsigned char *szBuffer, unsigned int *cbRead);

	virtual int32_t Write(unsigned int addr, unsigned char *szBuffer, unsigned int cbSize);
	virtual int32_t Read(unsigned int addr, unsigned char *szBuffer, unsigned int *cbSize);
	virtual int32_t WriteAndRead(unsigned char * writeBuffer,unsigned int writeSize, unsigned char * readBuffer, unsigned int * readSize);
	virtual IntecDeviceOperationMode GetDeviceOperationMode(){return UndefinedOpMode;}
	virtual int GetConfiguration();
	virtual int32_t SetConfiguration(int config);
	virtual void SetDeviceReference(libusb_device* usb_dev);
	virtual int32_t GetPortNumber();
	virtual int GetDeviceVersion(char *buffer);
	virtual int ClearReadBuffers();

public:

	//usb device data members
	libusb_context* m_usb_ctx = NULL;
	libusb_device* m_usb_device = NULL;
	libusb_device_handle* m_usb_device_handle = NULL;
	uint16_t m_vid;
	uint16_t m_pid;
	int m_interface_nubmer;
	libusb_speed m_usb_speed;
	uint8_t m_usb_bus_number;
	uint8_t m_usb_port_number;
	uint8_t m_usb_port_numbers[MAX_PORT_DEPTH];
	int m_usb_port_numbers_len = 0;
	uint8_t m_usb_device_address;
	int m_usb_device_speed;
	int m_usb_max_packet_size;
	int m_usb_max_iso_packet_size;
	unsigned int m_usb_transffer_timeout = 10000;
	libusb_class_code m_usb_class_code;
	libusb_descriptor_type m_usb_desc_type;

	//USB descriptors
	libusb_device_descriptor m_usb_device_desc;
	libusb_endpoint_descriptor m_usb_endpoint_desc;
	libusb_interface_descriptor m_usb_interface_desc;
	libusb_interface m_usb_interface;
	libusb_config_descriptor *m_usb_config_desc;
	libusb_ss_endpoint_companion_descriptor m_usb_companion_desc;
	libusb_bos_dev_capability_descriptor m_usb_bos_dev_desc;
	libusb_bos_descriptor m_usb_bos_desc;
	libusb_usb_2_0_extension_descriptor m_usb_2_0_ext_desc;
	libusb_ss_usb_device_capability_descriptor m_usb_dev_cap_desc;
	libusb_container_id_descriptor m_usb_container_id_desc;


protected:
	IntecDeviceOperationMode GetDeviceMode();
	virtual int32_t SetDeviceMode(IntecDeviceOperationMode);
	bool GetUsbDeviceSpeed(unsigned char * pDevcieSpeed){return true;}
	bool GetDeviceHnadleByIndex(IntecUsbDeviceType type, unsigned long RequestedIndex, int hDeviceHandle){return true;}
	bool QueryDeviceEndpoints(unsigned long TimeOutMSec){return true;}

protected:
	uint8_t m_usb_out_endpoint_addr;
	uint8_t m_usb_in_endpoint_addr;
	uint16_t m_usb_max_in_packet_size;
	uint16_t m_usb_max_out_packet_size;

	bool m_device_open_flag = false;
	bool m_device_connect_flag = false;
	IntecDeviceOperationMode m_DeviceOpMode;
	IntecUsbDeviceType m_DeviceType;
	unsigned long m_DeviceIndex;
	IntecDeviceDriverType m_DriverType;
	const unsigned char USB_WRITE_WORD_COMMAND = 0x02;
	const unsigned char USB_READ_WORD_COMMAND = 0x01;
	const int DEFAULT_TX_TIMEOUT_MS = 2000;
	const int DEFAULT_RX_TIMEOUT_MS = 2000;
	const int MAX_WRITE_PKT_SIZE = 63;
	const int  MAX_READ_PKT_SIZE = 64;
	const short PKT_HEADER_LENGTH = 6;
	const short REG_WIDTH = 4;
};

#endif /* SRC_CLIBINTECUSBDEVICE_H_ */
