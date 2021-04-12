
# @author Shady, Ganem <shady.ganem@intel.com>

from ctypes import *
import os
import platform 

if platform.system() == "Linux":
    pass
__libIntec = cdll.LoadLibrary("libIntec.so")


#elif platform.system() == "Windows":
#    libIntec = ctypes.

print(dir(__libIntec))

def GetlibVersion():
    __major = c_uint()
    __minor = c_uint()
    __ret = c_int()
    #__libIntec.libIntec_GetlibVersion.argtypes = (
    __ret = __libIntec.libIntec_GetlibVersion(byref(__major), byref(__minor))
    if __ret is not 0:
        return 1
    return (__major, __minor) 

def libIntec_Intialize(Device):
    __libIntec.libIntec_Intialize.argtypes

def libIntec_InitializeCard(inde):
    pass



#int libIntec_Initialize(IntecUsbDeviceType dev);
#int libIntec_GetlibVersion(unsigned int &major, unsigned int &minor);
#int libIntec_GetDeviceVersion(unsigned int index, char * Buffer);
#int libIntec_GetDeviceSerialNumber(unsigned int index, IntecCardType type, int cardId, char *serial);
#void SetIntecLastError(const char * err);
#int libIntec_Exit(void);
#int libIntec_InitializeOverNetwork(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName);
#int libtIntec_GetNumOfUsbDevices(int&);
#int libIntec_ReadDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int *cbRead);
#int libIntec_WriteDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int cbRead);
#int libIntec_GetDeviceMode(int index, IntecDeviceOperationMode &mode);
#int libIntec_SetDeviceMode(int index, IntecDeviceOperationMode mode);
#int libIntec_GetDeviceName(int index, char* Buffer);
#int libIntec_InitializeCard(unsigned int index);
#int libIntec_InitializeCardNoReset(unsigned int index);
#int libIntec_GetTemperature(unsigned int index, int cardId,float *temprature, unsigned int * timestamp);
#int libIntec_SetTemperature(unsigned int index, int cardId, float Temp);
#int libIntex_SetFeedBackControlParameter(unsigned int index, int cardId, IntecTemperatureCalcType calcMode, IntecTemperatureSourceType srcType, int mask);
#int libIntec_SetCaseInput(unsigned int index, int cardId, bool enable, int mask);
#int libintec_GetLastError(char *buffer, unsigned int buffersize);
#int libIntec_GetTemperatureSource(unsigned int index, IntecTemperatureSourceType, int *source_size, short* sources, unsigned int *timestamp, int* valid_mask);
#int libIntec_GetActualFeedbackType(unsigned int index, int cardId, IntecTemperatureSourceType* actualSrcType);

