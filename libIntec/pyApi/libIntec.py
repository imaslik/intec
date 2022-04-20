#!/usr/bin/python3

# @author Shady Ganem <shady.ganem@intel.com>

from __future__ import absolute_import 
from ctypes import *
import os
import platform 
from enum import Enum
import time

if platform.system() == "Linux":
    #os.environ["LD_LIBRARY_PATH"] = f"$LD_LIBRARY_PATH:{os.environ['PWD']}"
    #__libIntec = cdll.LoadLibrary("libIntec.so")
    __libIntec = CDLL("libIntec.so")

IntecUsbDeviceTypeToInt = { "IntecH" : 0,
                            "IntecD" : 1,
                            "TAU"    : 2}

LAST_ERROR_BUFFER_SIZE = 512

__Initialize = __libIntec.__libIntec_Initialize
__Exit = __libIntec.__libIntec_Exit
__InitializeCard = __libIntec.__libIntec_InitializeCard
__GetTemperature = __libIntec.__libIntec_GetTemperature
__SetTemperature = __libIntec.__libIntec_SetTemperature
__GetlibVersion = __libIntec.__libIntec_GetlibVersion
__GetLastError = __libIntec.__libIntec_GetLastError


def Initialize(device="IntecH"):
    __device = c_int(IntecUsbDeviceTypeToInt.get(device, 0))
    __ret = c_int()
    
    try:
        __ret = __Initialize(__device)
    except Exception as e:
        raise Exception("libIntec exception at Initialize")
    if __ret != 0:
        raise Exception("libIntec exception at Initialize")
    return True

def Exit():
    __ret = c_int()
    try:
        __ret = __Exit()
    except Exception as e:
        raise Exception("libIntec exception at Exit")
    if __ret != 0:
        raise Exception("libIntec exception at Exit")
    return True

def InitializeCard(index):
    __index = c_int(index)
    __ret = c_int()
    try:
        __ret = __InitializeCard(__index)
    except Exception as e:
        raise Exception("libIntec exception at InitializeCard")
    if __ret != 0:
        raise Exception("libIntec exception at InitializeCard")
    return True

def GetTemperature(index, cardId):
    __index = c_uint(index)
    __cardId = c_int(cardId)
    __temperature = c_float()
    __timestamp = c_uint()
    try:
        __ret = __GetTemperature(__index, __cardId, pointer(__temperature), pointer(__timestamp))
        if __ret != 0:
            raise Exception("libIntec exception at GetTemperature")
    except Exception as e:
        raise Exception("libIntec exception at GetTemperature")
    return __temperature.value

def GetTemperatureWithTimestamp(index, cardId):
    __index = c_uint(index)
    __cardId = c_int(cardId)
    __temperature = c_float()
    __timestamp = c_uint()
    try:
        __ret = __GetTemperature(__index, __cardId, pointer(__temperature), pointer(__timestamp))
        if __ret != 0:
            raise Exception("libIntec exception at GetTemperature")
    except Exception as e:
        raise Exception("libIntec exception at GetTemperature")
    return {"temperature": __temperature.value, "timestamp": __timestamp.value}

def __WaitForTemperature(index, cardId, temperature, thermal_accuracy, thermal_stabilization_time):
    __time_to_wait = 1
    __waited = 0
    __temp_reached_target = False
    __temp_stable = False
    __state = 0
    
    time.sleep(__time_to_wait)
    print(f"Thermal accuracy: {thermal_accuracy}C")
    print(f"Thermal stabilization time: {thermal_stabilization_time} sec")
    
    while __state < 2:
        if __state == 0:
            print(f"Waiting for temperature to reach target temperature {temperature}")
            __current_temperature = GetTemperature(index,cardId)
            while True:
                time.sleep(__time_to_wait)
                __current_temperature = GetTemperature(index,cardId)
                __temp_reached_target = round(abs(__current_temperature - temperature),1) <= thermal_accuracy
                if __temp_reached_target:
                    break
            __state = 1
        elif __state == 1:
            __waited = 0
            print(f"Waiting for temperature to stabilize")
            while True:
                time.sleep(__time_to_wait)
                __waited += __time_to_wait
                __current_temperature = GetTemperature(index,cardId)
                __temp_stable = round(abs(__current_temperature - temperature),1) <= thermal_accuracy
                
                if not __temp_stable:
                    __state = 0
                    break
                
                if __waited >= thermal_stabilization_time:
                    __state = 2
                    break
    print(f"Reached target temperature {temperature} with accuracy {thermal_accuracy}")
    print(f"Current temperature {GetTemperature(index,cardId)}")

def SetTemperatureAsync(index, cardId, temp):
    __index = c_uint(index)
    __cardId = c_int(cardId)
    __temp = c_float(temp)

    try:
        __ret = __SetTemperature(__index, __cardId, __temp)
        if __ret != 0:
            raise Exception("libIntec exception at SetTemperature")  
    except Exception as e:
        raise e  
    return True

def SetTemperature(index, cardId, temp, thermal_accuracy = 0.5, thermal_stabilization_time = 1):
    __index = c_uint(index)
    __cardId = c_int(cardId)
    __temp = c_float(temp)

    try:
        __ret = __SetTemperature(__index, __cardId, __temp)
        if __ret != 0:
            raise Exception("libIntec exception at SetTemperature") 
        __WaitForTemperature(index,cardId, temp, thermal_accuracy, thermal_stabilization_time)
    except Exception as e:
        raise e  
    return True

def GetlibVersion():
    __major = c_uint()
    __minor = c_uint()
    __ret = c_int()
    __ret = __GetlibVersion(byref(__major), byref(__minor))
    if __ret is not 0:
        raise Exception("libIntec exception at GetlibVersion")
    return {"major":__major.value, "minor":__minor.value}

def GetLastError():
    __buffer = create_string_buffer(LAST_ERROR_BUFFER_SIZE)
    __cptr = c_char_p()
    __cptr.value = addressof(__buffer)
    try:
        ret = __GetLastError(__cptr, LAST_ERROR_BUFFER_SIZE)
        if ret != 0:
            raise Exception("Failed to get last error message")
        return __buffer.value.decode("utf-8") 
    except Exception as e:
        print(str(e))
        raise e

if __name__=="__main__":
    try:
        import time
        ver = GetlibVersion()
        print(f"libIntec Versrion {ver['major']}.{ver['minor']}")
        Initialize()
        InitializeCard(0)
        SetTemperature(0,0,25,0.5,5)
        # print(GetLastError())
        # set_temp = 25 
        # SetTemperature(0, 0, set_temp)
        # temp = GetTemperature(0, 0)
        # print(temp)
        # while temp < set_temp - 0.5 or temp > set_temp + 0.5:
        #     temp = GetTemperature(0, 0)
        #     print(temp)
        #     time.sleep(1)
        Exit()
    except Exception as e:
        Exit()
        raise e


