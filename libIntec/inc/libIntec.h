#ifndef INC_LIBINTEC_H_
#define INC_LIBINTEC_H_

#include <stdint.h>

#define LIBINTEC_VERSION "beta 0.1"
#define MAX_TEST_MSG_SIZE 512
#define MSG_BUF_SIZE 512

//Error codes
#define STATUS_OK 0
#define ERROR_FAIL 1
#define ERROR_NOT_IMPLEMETED 2
#define ERROR_LIBUSB_FAIL 3
#define ERROR_NO_DEVICE 4
#define ERROR_USB_OPEN_FAIL 5

enum IntecUsbDeviceType
{
	IntecH,
	IntecD,
	TAU
};

enum IntecDeviceOperationMode
{
	UndefinedOpMode,
	NormalOpMode,
	BootLoaderOpMode
};

enum IntecDeviceType
{
	Usb
};

enum IntecDeviceDriverType
{
	GenericWinUsb,
	GenericMPUsb,
	bootLoaderHID,
	Ethernet,
	libusb
};

int libIntec_Initialize(IntecUsbDeviceType dev);
int libIntec_Exit(void);
int libIntec_InitializeOverNetwork(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName);
int libtIntec_GetNumOfUsbDevices(int&);
int libIntec_GetDeviceMode(int index, IntecDeviceOperationMode &mode);
int libIntec_SetDeviceMode(int index, IntecDeviceOperationMode mode);
int libIntec_GetDeviceName(int index, char* Buffer);


#endif //INC_LIBINTEC_H_
