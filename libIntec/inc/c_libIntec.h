/*
 * c_libIntec.h
 *
 *  Created on: Apr 12, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#ifndef INC_C_LIBINTEC_H_
#define INC_C_LIBINTEC_H_
#include "libIntec.h"

#define EXTER_C
#ifdef EXTER_C

extern "C"
{
int __libIntec_Initialize(int dev);
int __libIntec_GetlibVersion(unsigned int &major, unsigned int &minor);
int __libIntec_GetDeviceVersion(unsigned int index, char * Buffer);
int __libIntec_GetDeviceSerialNumber(unsigned int index, IntecCardType type, int cardId, char *serial);
int __libIntec_Exit(void);
int __libIntec_InitializeOverNetwork(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName);
int __libtIntec_GetNumOfUsbDevices(int& number_devices_found);
int __libIntec_InitializeCard(unsigned int index);
int __libIntec_InitializeCardNoReset(unsigned int index);
int __libIntec_GetTemperature(unsigned int index, int cardId,float *temprature, unsigned int * timestamp);
int __libIntec_SetTemperature(unsigned int index, int cardId, float Temp);
int __libIntec_GetLastError(char *buffer, unsigned int buffersize);
//	int __libIntex_SetFeedBackControlParameter(unsigned int index, int cardId, IntecTemperatureCalcType calcMode, IntecTemperatureSourceType srcType, int mask);
//	int __libIntec_SetCaseInput(unsigned int index, int cardId, bool enable, int mask);

//	int __libIntec_GetTemperatureSource(unsigned int index, IntecTemperatureSourceType, int *source_size, short* sources, unsigned int *timestamp, int* valid_mask);
//	int __libIntec_GetActualFeedbackType(unsigned int index, int cardId, IntecTemperatureSourceType* actualSrcType);
//	int __libIntec_GetDeviceMode(int index, IntecDeviceOperationMode &mode);
//	int __libIntec_SetDeviceMode(int index, IntecDeviceOperationMode mode);
//	int __libIntec_GetDeviceName(int index, char* Buffer);
}

int __libIntec_Initialize(int dev)
{
	IntecUsbDeviceType deviceType;
	if (dev == 0)
		deviceType = IntecH;
	else if (dev == 1)
		deviceType = IntecD;
	else if (dev == 2)
		deviceType = TAU;

	return libIntec_Initialize(deviceType);
}

int __libIntec_GetlibVersion(unsigned int &major, unsigned int &minor)
{
	return libIntec_GetlibVersion(major, minor);
}

int __libIntec_GetDeviceVersion(unsigned int index, char * Buffer)
{
	return libIntec_GetDeviceVersion(index, Buffer);
}

int __libIntec_GetDeviceSerialNumber(unsigned int index, IntecCardType type, int cardId, char *serial)
{
	return libIntec_GetDeviceSerialNumber(index, type, cardId, serial);
}

int __libIntec_Exit(void)
{
	return libIntec_Exit();
}

int __libIntec_InitializeOverNetwork(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName)
{
	return libIntec_InitializeOverNetwork(dev, numOfDevices, HostName);
}

int __libtIntec_GetNumOfUsbDevices(int& number_devices_found)
{
	return libtIntec_GetNumOfUsbDevices(number_devices_found);
}

int __libIntec_InitializeCard(unsigned int index)
{
	return libIntec_InitializeCard(index);
}

int __libIntec_InitializeCardNoReset(unsigned int index)
{
	return libIntec_InitializeCard(index);
}

int __libIntec_GetTemperature(unsigned int index, int cardId,float *temprature, unsigned int * timestamp)
{
	return libIntec_GetTemperature(index, cardId, temprature, timestamp);
}

int __libIntec_SetTemperature(unsigned int index, int cardId, float Temp)
{
	return libIntec_SetTemperature(index, cardId, Temp);
}

int __libIntec_GetLastError(char *buffer, unsigned int buffersize)
{
	return libintec_GetLastError(buffer, buffersize);
}

//	int __libIntec_GetDeviceMode(int index, IntecDeviceOperationMode &mode);
//	int __libIntec_SetDeviceMode(int index, IntecDeviceOperationMode mode);
//	int __libIntec_GetDeviceName(int index, char* Buffer);
//	int __libIntex_SetFeedBackControlParameter(unsigned int index, int cardId, IntecTemperatureCalcType calcMode, IntecTemperatureSourceType srcType, int mask);
//	int __libIntec_SetCaseInput(unsigned int index, int cardId, bool enable, int mask);

//	int __libIntec_GetTemperatureSource(unsigned int index, IntecTemperatureSourceType, int *source_size, short* sources, unsigned int *timestamp, int* valid_mask);
//	int __libIntec_GetActualFeedbackType(unsigned int index, int cardId, IntecTemperatureSourceType* actualSrcType);

#endif
#endif /* INC_C_LIBINTEC_H_ */
