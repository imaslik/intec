#ifndef INC_LIBINTEC_H_
#define INC_LIBINTEC_H_

#define ENABLE_DBG_PRINT
#ifdef ENABLE_DBG_PRINT
#define DBG(x) std::cout << "DEBUG PRINT: " << x << std::endl;
#else
#define DBG(x)
#endif

//#define ENABLE_TRACE
#ifdef ENABLE_TRACE
#define __TRACE  std::cout << "TRACE PRINT: " <<  __func__ << std::endl;
#else
#define __TRACE
#endif

#include <stdint.h>

//Error codes
#define STATUS_OK            0
#define ERROR_FAIL           1
#define ERROR_NOT_IMPLEMETED 2
#define ERROR_LIBUSB_FAIL    3
#define ERROR_NO_DEVICE      4
#define ERROR_USB_OPEN_FAIL  5
#define ERROR_WRITE_FAIL     6
#define ERRoR_READ_FAIL      7


#define LIBINTEC_VERSION_STR "beta 0.1"
#define LIBINTEC_VERSION_MAJOR 0
#define LIBINTEC_VERSION_MINOR 1

#define MAX_TEST_MSG_SIZE 512
#define MSG_BUF_SIZE 512


#define INTEC_SW_VERSION "REV 1.2.0"
#define READ_BUF_SIZE 512
#define WRITE_BUF_SIZE 512

#define MAX_DTS 16
#define MAX_DIODE 4
#define MAX_TCASE_ON_CARD 4
#define MAX_PACKAGES 4
#define DTS_NAME_LEN 32

#define MAX_DIODE_SOURCES 4
#define MAX_PF_TEMPERATURE_SOURCES 4
#define MAX_SOURCES_SIZE 16
#define MAX_FEEDBACK_TEMPERATURE_SOURCES 4

#define MAX_TEST_MSG_SIZE 512
#define MSG_BUF_SIZE 512

#define INTEC_BASE_ADDR 0x10000
#define PECI_DEVICE_BASE_ADDR 0x20000
#define INTECD0_DEVICE_BASE_ADDR 0x40000
#define INTECD1_DEVICE_BASE_ADDR 0x80000
#define INTECD2_DEVICE_BASE_ADDR 0x100000
#define INTECD3_DEVICE_BASE_ADDR 0x200000
#define TIC_DEVICE_BASE_ADDR 0x400000
#define WATER_DEVICE_BASE_ADDR 0x800000

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

enum IntecTemperatureCalcType
{
	Avg=0,
	Max,
	Min,
	AAMax,
	AAMin,
	CaseWithOffsetType
};

enum IntecTemperatureSourceType
{
	DefaultSrc=0,
	Tc,
	Tj,
	Tp,
	PowerFollowing,
	CaseWithOffsetSrc,
	Gang
};

// events
enum EventType
{
	FailureEvent=0,
	WarningEvent,
	NotificationEvent
};
typedef struct EventConfigurationParam
{
	char Name[64];
	char Type[16];
	char Description[128];
	unsigned int value;
} EventConfigurationParam;

enum IntecThermalHeadRegId
{
	TH_SERIAL=0,
	TH_MFG,
	TH_DATE_TIME,
	TH_PRODUCT_NAME,
	TH_PN,
	TH_FRU_FILE_ID,
	TH_HEATSINK_TYPE,
	TH_PRODUCT_TYPE,
	TH_PLATFORM_TYPE,
	TH_SOCKET_TYPE,
	TH_MOO,
	TH_UP_SENSOR,
	TH_EXPECTED_IMP,
	TH_TCASE_TYPE,
	TH_TCASE_NUM,
	TH_VMAX,
	TH_RAMP_RATE_LIMIT,
	TH_P_FACT,
	TH_I_FACT,
	TH_D_FACT,
	TH_TEC_PN,
	TH_EE_VER,
	TH_HEATEC,
	TH_V_HEATEC_MAX
};

enum IntecTecMode
{
  TEC_PRBS_MODE,
  TEC_OPENLOOP_MODE,
  TEC_NORMAL_MODE,
  TEC_SUSTAIN_MODE
};

enum IntecRTDSensorType
{
	RTD_PT1000_00375_HEL705,
	RTD_PT1000_00385_MINCO
};

enum IntecTCASEType
{
	TCASE_T_TYPE=0,
	TCASE_RTD_TYPE=3
};

int libIntec_Initialize(IntecUsbDeviceType dev);
int libIntec_GetlibVersion(unsigned int &major, unsigned int &minor);
void SetIntecLastError(const char * err);
int libIntec_Exit(void);
int libIntec_InitializeOverNetwork(IntecUsbDeviceType dev, uint32_t numOfDevices, char **HostName);
int libtIntec_GetNumOfUsbDevices(int&);
int libIntec_ReadDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int *cbRead);
int libIntec_ReadDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int cbRead);
int libIntec_WriteDeviceByAddr(unsigned int index, unsigned int addr, unsigned char *szBuffer, unsigned int cbRead);
int libIntec_GetDeviceMode(int index, IntecDeviceOperationMode &mode);
int libIntec_SetDeviceMode(int index, IntecDeviceOperationMode mode);
int libIntec_GetDeviceName(int index, char* Buffer);
int libIntec_InitializeCard(unsigned int index);
int libIntec_InitializeCardNoReset(unsigned int index);
int libIntec_GetTemperature(unsigned int index, int cardId,float *temprature, unsigned int * timestamp);
int libIntec_SetTemperature(unsigned int index, int cardId, float Temp);
int libIntex_SetFeedBackControlParameter(unsigned int index, int cardId, IntecTemperatureCalcType calcMode, IntecTemperatureSourceType srcType, int mask);
int libIntec_SetCaseInput(unsigned int index, int cardId, bool enable, int mask);
int libintec_GetLastError(char *buffer, unsigned int buffersize);
int libIntec_GetTemperatureSource(unsigned int index, IntecTemperatureSourceType, int *source_size, short* sources, unsigned int *timestamp, int* valid_mask);
int libIntec_GetActualFeedbackType(unsigned int index, int cardId, IntecTemperatureSourceType* actualSrcType);


#endif //INC_LIBINTEC_H_
