#ifndef _libIntecDefs_H_
#define _libIntecDefs_H_

#include"IntecHWDefs.h"

#define stringify( name ) # name

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
	Ethernet
};


// Operation defs
#define INTEC_BASE_ADDR 0x10000
#define PECI_DEVICE_BASE_ADDR 0x20000
#define INTECD0_DEVICE_BASE_ADDR 0x40000
#define INTECD1_DEVICE_BASE_ADDR 0x80000
#define INTECD2_DEVICE_BASE_ADDR 0x100000
#define INTECD3_DEVICE_BASE_ADDR 0x200000
#define TIC_DEVICE_BASE_ADDR 0x400000
#define WATER_DEVICE_BASE_ADDR 0x800000

enum IntecCardType
{
	IntecCard, 
	IntecDCard,
	PeciCard,
	TicCard,
	WaterModule
};

enum IntecIpMode
{
	StaticIPMode,
	DHCPMode
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

static const char* IntecTemperatureSourceTypeNames[] = 
{
	stringify( DefaultSrc ),
	stringify( Tc ),
	stringify( Tj ),
	stringify( Tp ),
	stringify( PowerFollowing ),
	stringify( CaseWithOffsetSrc ),
	stringify( Prochot )
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

typedef IntecTemperatureSourceType IntecVoltageSourceType;

enum IntecTestabiliyMode
{
	BenchSelfTest=0,
	StandaloneSelfTest,
	BasicFunctionalitySelfTest,
	WaterModuleBenchTest
};

enum IntecTDAUStatus
{
	TDAUReady=0,
	TDAUBusy,
	TDAUSystemErr,
	TDAUNotConnected
};



static const char* IntecTDAUStatusNames[] = 
{
	stringify( TDAUReady ),
	stringify( TDAUBusy ),
	stringify( TDAUSystemErr ),
	stringify( TDAUNotConnected )
};

#define TDAU_MAX_DATASIZE 52

#define TESTABILITY_STATUS_PASSED 0
#define TESTABILITY_STATUS_RUNNING 1
#define  TESTABILITY_STATUS_FAILED 2


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
	UINT value;
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

#endif
