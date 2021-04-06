#ifndef INC_LIBINTEC_H_
#define INC_LIBINTEC_H_

#include <stdint.h>

#define LIBINTEC_VERSION "beta 0.1"
#define MAX_TEST_MSG_SIZE 512
#define MSG_BUF_SIZE 512

//Error codes
#define STATUS_OK               0
#define ERROR_FAIL              1
#define ERROR_NOT_IMPLEMETED    2
#define ERROR_LIBUSB_FAIL       3

static const char *IntecH_VIDPID="vid_04d8&pid_0053";
static const char *IntecD_VIDPID="vid_04d8&pid_0054";
static const char *TAU_VIDPID="vid_04d8&pid_fce7";
static const char *TAU_INENDPOINT="\\MCHP_EP1";
static const char *TAU_OUTENDPOINT="\\MCHP_EP1";

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
int libtIntec_GetNumberOfDevices(unsigned int * NumOfUsbDevices);

#endif //INC_LIBINTEC_H_
