#ifndef _IIntec_Common_H_
#define _IIntec_Common_H_
#include "atlbase.h"


// Include Windows headers
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <strsafe.h>

// Include WinUSB headers
#include <winusb.h>
#include <Usb100.h>
#include <Setupapi.h>


static const GUID IntecClassGuid = {0x58D07210, 0x27C1, 0x11DD, 0xBD, 0x0B, 0x08, 0x00, 0x20, 0x0C, 0x9A, 0x66}; 
static const char *IntecH_VIDPID="vid_04d8&pid_0053";
static const char *IntecD_VIDPID="vid_04d8&pid_0054";
static const char *TAU_VIDPID="vid_04d8&pid_fce7";
static const char *TAU_INENDPOINT="\\MCHP_EP1";
static const char *TAU_OUTENDPOINT="\\MCHP_EP1";
#endif //_IIntec_Common_H_

