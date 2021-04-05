#ifndef INTEC_D_DWDEFS_H
#define INTEC_D_DWDEFS_H

// -------------------------------------------------------------------------
// Register and Field Definitions
// -------------------------------------------------------------------------
#define	UNIT_D_GENERAL           	0
#define	UNIT_D_BOOTLOADING       	1
#define	UNIT_D_CASE              	2
#define	UNIT_D_CONTROL           	3
#define	UNIT_D_ENVIRONMENT       	4
#define	UNIT_D_EVENTS            	5
#define	UNIT_D_THERMAL_HEAD      	6
#define	UNIT_D_TESTABILITY       	7
#define	UNIT_D_WATER_MODULE      	8
#define	UNIT_D_PHASE_CHANGE      	9

// Unit Offsets Definitions
#define	OFFSET_UNIT_D_GENERAL                  	0x00000000
#define	OFFSET_UNIT_D_BOOTLOADING              	0x000000100
#define	OFFSET_UNIT_D_CASE                     	0x200
#define	OFFSET_UNIT_D_CONTROL                  	0x300
#define	OFFSET_UNIT_D_ENVIRONMENT              	0x400
#define	OFFSET_UNIT_D_EVENTS                   	0x500
#define	OFFSET_UNIT_D_THERMAL_HEAD             	0x600
#define	OFFSET_UNIT_D_TESTABILITY              	0x700
#define	OFFSET_UNIT_D_WATER_MODULE             	0x800
#define	OFFSET_UNIT_D_PHASE_CHANGE             	0x900

//	UNIT D_GENERAL registers
#define	OFFSET_D_FW_VERSION        	0x00
#define	OFFSET_D_DEVICE_TYPE       	0x01
#define	OFFSET_D_TIMESTAMP         	0x02
#define	OFFSET_D_RESET_TIMESTAMP   	0x03
#define	OFFSET_D_HW_CFG            	0x04
#define	OFFSET_D_SERIAL            	0x05
#define	OFFSET_D_SERIAL_DUMMY      	0x06
#define	OFFSET_D_SYS_ERR_STATUS    	0x07
#define	OFFSET_D_DEVICE_NAME       	0x08
#define	OFFSET_D_DEVICE_NAME_DUMMY 	0x09
#define	OFFSET_D_DEVICE_NAME_DUMMY_0	0x0A
#define	OFFSET_D_DEVICE_NAME_DUMMY_1	0x0B
#define	OFFSET_D_SW_RESET          	0x0C
#define	OFFSET_D_WORK_MODE         	0x0E
#define	OFFSET_D_UPDATE_CFG        	0x0D
#define	OFFSET_D_DEVICE_TYPE_LEGACY	0xEE
#define	OFFSET_D_GENERAL_STATUS    	0x0F
#define	OFFSET_D_GENERAL_UPDATE    	0x10

//	UNIT D_BOOTLOADING registers
#define	OFFSET_D_BOOTLOADING_STATUS	0x000
#define	OFFSET_D_BOOTLOADING_ENTER 	0x001
#define	OFFSET_D_BOOTLOADING_ABORT 	0x002
#define	OFFSET_D_BOOTLOADING_GET_DATA_FROM_DEV	0x003
#define	OFFSET_D_BOOTLOADING_SEND_DATA_TO_DEV	0x004

//	UNIT D_CASE registers
#define	OFFSET_D_CASE_CFG          	0x000
#define	OFFSET_D_CFG_CASE0         	0x001
#define	OFFSET_D_CFG_CASE1         	0x002
#define	OFFSET_D_CFG_CASE2         	0x003
#define	OFFSET_D_CFG_CASE3         	0x004
#define	OFFSET_D_CASE_STATUS       	0x005
#define	OFFSET_D_TCASE0            	0x006
#define	OFFSET_D_TCASE1            	0x007
#define	OFFSET_D_TCASE2            	0x008
#define	OFFSET_D_TCASE3            	0x009
#define	OFFSET_D_GET_ALL_TCASES    	0x00A

//	UNIT D_CONTROL registers
#define	OFFSET_D_PID_LOOP_PWM_CALC 	0x000
#define	OFFSET_D_PID_COEF          	0x001
#define	OFFSET_D_TEC_CONTROL       	0x002
#define	OFFSET_D_TEC_STATUS        	0x003
#define	OFFSET_D_FEEDBACK_CONTROL  	0x004
#define	OFFSET_D_FEEDBACK_CONTROL_DUMMY	0x005
#define	OFFSET_D_FEEDBACK_CONTROL_DUMMY_1	0x006
#define	OFFSET_D_FEEDBACK_CONTROL_DUMMY_2	0x007
#define	OFFSET_D_FEEDBACK_STATUS   	0x008
#define	OFFSET_D_FEEDBACK_TEMP     	0x009
#define	OFFSET_D_FEEDBACK_SETPOINT 	0x00A
#define	OFFSET_D_FEEDBACK_JUNCTION_TEMP	0x00B
#define	OFFSET_D_POWER_OUT_SENSE   	0x00C
#define	OFFSET_D_FEEDBACK_DELTA_CFG	0x013
#define	OFFSET_D_CONTROL_MODULE_TEMP	0x014
#define	OFFSET_D_ANALOG_OUT        	0x015
#define	OFFSET_D_FEEDBACK_LIMITS   	0x016
#define	OFFSET_D_FEEDBACK_LIMITS_DUMMY	0x017
#define	OFFSET_D_FEEDBACK_LIMITS_DUMMY_1	0x018
#define	OFFSET_D_FEEDBACK_LIMITS_DUMMY_2	0x019
#define	OFFSET_D_FEEDBACK_LIMITS_DUMMY_3	0x01A
#define	OFFSET_D_FEEDBACK_LIMITS_DUMMY_4	0x01B
#define	OFFSET_D_FEEDBACK_MAX_MIN_TEMP	0x01C
#define	OFFSET_D_CONTROL_MISC_CFG  	0x01D
#define	OFFSET_D_CONTROL_OPEN_LOOP_CFG	0x01E
#define	OFFSET_D_CONTROL_PRBS_CFG  	0x01F
#define	OFFSET_D_TEC_OUT_VMAX      	0x020
#define	OFFSET_D_FEEDBACK_AVG_STDEV_TEMP	0x021
#define	OFFSET_D_FEEDBACK_TJ_ALLOC 	0x022
#define	OFFSET_D_RAMP_RATE_CONTROL 	0x023
#define	OFFSET_D_VAR_SP            	0x024
#define	OFFSET_D_GANG_CFG          	0x025

//	UNIT D_ENVIRONMENT registers
#define	OFFSET_D_ACTUATION         	0x001
#define	OFFSET_D_LEAKAGE           	0x002
#define	OFFSET_D_COOLANT           	0x003
#define	OFFSET_D_COOLANT_DUMMY     	0x004
#define	OFFSET_D_COOLANT_DUMMY_1   	0x005
#define	OFFSET_D_PURGE             	0x006
#define	OFFSET_D_PURGE_DUMMY       	0x007
#define	OFFSET_D_ENV_STATUS        	0x008
#define	OFFSET_D_LEAK_BOARD        	0x009
#define	OFFSET_D_LEAK_BOARD_LIMITS 	0x00A

//	UNIT D_EVENTS registers
#define	OFFSET_D_FAILURES_STATUS   	0x000
#define	OFFSET_D_WARNINGS_STATUS   	0x001
#define	OFFSET_D_NOTIFICATION_STATUS	0x002
#define	OFFSET_D_FAILURES_DISABLE  	0x003
#define	OFFSET_D_WARNINGS_DISABLE  	0x004
#define	OFFSET_D_NOTIFICATION_DISABLE	0x005
#define	OFFSET_D_EVENTS_DEFAULTS   	0x006
#define	OFFSET_D_EVENTS_RESPOND    	0x007
#define	OFFSET_D_EVENTS_CHECK_RESTART	0x008

//	UNIT D_THERMAL_HEAD registers
#define	OFFSET_D_TH_SERIAL         	0x000
#define	OFFSET_D_TH_MFG            	0x001
#define	OFFSET_D_TH_TYPE           	0x002
#define	OFFSET_D_TH_TEC_EXP_IMP_1000T_DEC	0x003
#define	OFFSET_D_TH_DATE_TIME      	0x004
#define	OFFSET_D_TH_RESET          	0x005
#define	OFFSET_D_TH_GENERAL        	0x006
#define	OFFSET_D_TH_STATUS         	0x008
#define	OFFSET_D_TH_POSITION       	0x009
#define	OFFSET_D_TH_EE_PT_WR       	0x00A
#define	OFFSET_D_TH_EE_PT_RD       	0x00B
#define	OFFSET_D_TH_PRODUCT_NAME   	0x00C
#define	OFFSET_D_TH_PN             	0x00D
#define	OFFSET_D_TH_FRU_FILE_ID    	0x00E
#define	OFFSET_D_TH_HEATSINK_TYPE  	0x00F
#define	OFFSET_D_TH_PRODUCT_TYPE   	0x010
#define	OFFSET_D_TH_PLATFORM_TYPE  	0x011
#define	OFFSET_D_TH_SOCKET_TYPE    	0x012
#define	OFFSET_D_TH_MOO            	0x013
#define	OFFSET_D_TH_EXPECTED_IMP   	0x014
#define	OFFSET_D_TH_TCASE_TYPE     	0x015
#define	OFFSET_D_TH_TCASE_NUM      	0x016
#define	OFFSET_D_TH_VMAX           	0x017
#define	OFFSET_D_TH_RAMP_RATE_LIMIT	0x018
#define	OFFSET_D_TH_P_FACT         	0x019
#define	OFFSET_D_TH_I_FACT         	0x01A
#define	OFFSET_D_TH_D_FACT         	0x01B
#define	OFFSET_D_TH_TEC_PN         	0x01C
#define	OFFSET_D_TH_EE_VER         	0x01D
#define	OFFSET_D_TH_UP_SENSOR      	0x01E
#define	OFFSET_D_TH_TEC_IMPEDANCE  	0x01F
#define	OFFSET_D_TH_HEATEC         	0x020
#define	OFFSET_D_TH_V_HEATEC_MAX   	0x021

//	UNIT D_TESTABILITY registers
#define	OFFSET_D_TESTABILITY_START 	0x000
#define	OFFSET_D_TESTABILITY_ABORT 	0x001
#define	OFFSET_D_BENCH_TEST_STATUS 	0x002
#define	OFFSET_D_STANDALONE_TEST_STATUS	0x003
#define	OFFSET_D_BASIC_FUNC_TEST_STATUS_1	0x004
#define	OFFSET_D_TESTABILITY_MASKS 	0x005
#define	OFFSET_D_TH_BENCH_TEST_STATUS	0x006
#define	OFFSET_D_TESTABILITY_GEN_STAT	0x007
#define	OFFSET_D_IMPEDANCE_MES_RESULT	0x008
#define	OFFSET_D_IMPEDANCE_MES_STATUS	0x009
#define	OFFSET_D_WATER_MODULE_BENCH_TEST_STATUS	0x00A
#define	OFFSET_D_WATER_MODULE_BENCH_TEST_IMP_RESULT 	0x00B

//	UNIT D_WATER_MODULE registers
#define	OFFSET_D_WATER_MODULE_GENERAL	0x000
#define	OFFSET_D_WATER_MODULE_LIMITS 	0x001
#define	OFFSET_D_WATER_MODULE_LIMITS_DUMMY	0x002
#define	OFFSET_D_WATER_MODULE_LIMITS_DUMMY_1	0x003
#define	OFFSET_D_WATER_MODULE_LIMITS_DUMMY_2	0x004
#define	OFFSET_D_WATER_MODULE_IMP_RESULT 	0x005
#define	OFFSET_D_WATER_MODULE_CONTROL 	0x006

//	UNIT D_PHASE_CHANGE registers
#define	OFFSET_D_PHASE_CHANGE_GENERAL	0x000
#define	OFFSET_D_PHASE_CHANGE_STATUS	0x001
#define	OFFSET_D_PHASE_CHANGE_ERROR	0x002

//****************************************************************************
//* D_GENERAL Unit Registers Description
//****************************************************************************

// Register: D_FW_VERSION		Offset: OFFSET_D_FW_VERSION
// Description: 	Firmware version 10T format
typedef union {
	ULONG32 value;
		struct {
			ULONG32	FwVersion10T        	:16; 	//Firmware version 10T format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_FW_VERSION;

// Enumeration for field DEVTYPE of register: D_DEVICE_TYPE
#define D_DEVICE_TYPE_INTEC 	0x000000d2
#define D_DEVICE_TYPE_INTECD	0x000000d3

// Register: D_DEVICE_TYPE		Offset: OFFSET_D_DEVICE_TYPE
// Description: 	Device type (InTEC/InTEC-D/Other...)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DevType             	:8; 	//Device type 
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_D_DEVICE_TYPE;

// Register: D_TIMESTAMP		Offset: OFFSET_D_TIMESTAMP
// Description: 	holds the InTEC-D timestamp in 1ms counts
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Timestamp           	:32;
		} fields;
} UN_D_TIMESTAMP;

// Register: D_RESET_TIMESTAMP		Offset: OFFSET_D_RESET_TIMESTAMP
// Description: 	write 0x01 to this register tol reset the Timestamp
typedef union {
	LONG32 value;
		struct {
			ULONG32	Reset               	:1; 	//set this bit to reset the timestamp
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_D_RESET_TIMESTAMP;

// Enumeration for field HPOUTMODE of register: D_HW_CFG
#define D_HW_CFG_ANALOG     	0x00000000
#define D_HW_CFG_PWM        	0x00000001

// Enumeration for field TCASETYPE of register: D_HW_CFG
#define D_HW_CFG_TC_T       	0x00000000
#define D_HW_CFG_TC_K       	0x00000001
#define D_HW_CFG_RTD        	0x00000003

// Enumeration for field SEVENSEGORIENTATION of register: D_HW_CFG
#define D_HW_CFG_7SEG_NORM  	0x00000000
#define D_HW_CFG_7SEG_INV   	0x00000001

// Register: D_HW_CFG		Offset: OFFSET_D_HW_CFG
// Description: 	InTEC-D I/O Expansion status as read at board startup
typedef union {
	ULONG32 value;
		struct {
			ULONG32	HpOutMode           	:1; 	//0 - InTEC-D in Analog output mode, 
						                            //1 - InTEC-D in PWM mode
			ULONG32	TcaseType           	:2; 	//00 - TC T-Type, 
						                            //01 - TC K-Type, 
						                            //11 - RTD (PT1000)
			ULONG32	RESERVED0           	:1;
			ULONG32	SevenSegOrientation 	:1; 	//0 - 7seg top towards the TC connector, 
						                            //1 - 7seg bottom towards the TC connector
			ULONG32	RESERVED1           	:9; 	//reserved
			ULONG32	IntecDStandAlone    	:1; 	//1 - if bit is set intec D is in stand alone mode
			ULONG32	Ecn24v              	:1; 	//1 - if bit is set InTEC pass ECN #3 - 24v 
			ULONG32	RESERVED2           	:16; 	//reserved
		} fields;
} UN_D_HW_CFG;

// Enumeration for field SERIALNUMBYTE0 of register: D_SERIAL
#define D_SERIAL_NUMBER_MAX_LEN	0x00000005

// Register: D_SERIAL		Offset: OFFSET_D_SERIAL
// Description: 	unique 5-character serial number that is stored in its nonvolatile memory 
typedef union {
	UCHAR value[5];
		struct {
			ULONG32	SerialNumByte0      	:8; 	//Serial number byte0
			ULONG32	SerialNumByte1      	:8; 	//Serial number byte1
			ULONG32	SerialNumByte2      	:8; 	//Serial number byte2
			ULONG32	SerialNumByte3      	:8; 	//Serial number byte3
			ULONG32	SerialNumByte4      	:8; 	//Serial number byte4
		} fields;
} UN_D_SERIAL;

// Register: D_SERIAL_DUMMY		Offset: OFFSET_D_SERIAL_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_SERIAL_DUMMY;

// Register: D_SYS_ERR_STATUS		Offset: OFFSET_D_SYS_ERR_STATUS
// Description: 	InTEC-D System Error Status, holds the HW modules error indications
typedef union {
	ULONG32 value;
		struct {
			ULONG32	McuErr              	:1;
			ULONG32	IOExpError          	:1;
			ULONG32	CurrentSourceError  	:1;
			ULONG32	EEpromError         	:1;
			ULONG32	OnBoardTempSenseError	:1; 	//If bit is set, on board thermal sensor error detected 
			ULONG32	RESERVED0           	:3; 	//reserved for more HW Errors 
			ULONG32	McuInBootMode       	:1;
			ULONG32	McuNotInReqMode     	:1;
			ULONG32	RESERVED1           	:22; 	//reserved for more HW Errors 
		} fields;
} UN_D_SYS_ERR_STATUS;

// Enumeration for field DEVICENAME of register: D_DEVICE_NAME
#define INTEC_D_DEV_NAME_LEN	0x00000010

// Register: D_DEVICE_NAME		Offset: OFFSET_D_DEVICE_NAME
// Description: 	contains theDevice name (16 characters, no '/0') of a connected device.
// 	write request for this read must contain the requested device ID in its data field.
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	DeviceName          [16]; 	//Device name (16 characters, no '/0')
		} fields;
} UN_D_DEVICE_NAME;

// Register: D_DEVICE_NAME_DUMMY		Offset: OFFSET_D_DEVICE_NAME_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_DEVICE_NAME_DUMMY;

// Register: D_DEVICE_NAME_DUMMY_0		Offset: OFFSET_D_DEVICE_NAME_DUMMY_0
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_DEVICE_NAME_DUMMY_0;

// Register: D_DEVICE_NAME_DUMMY_1		Offset: OFFSET_D_DEVICE_NAME_DUMMY_1
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_DEVICE_NAME_DUMMY_1;

// Register: D_SW_RESET		Offset: OFFSET_D_SW_RESET
// Description: 	Write any data to reset the device (soft reset of InTEC-D MCU)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_SW_RESET;

// Register: D_WORK_MODE		Offset: OFFSET_D_WORK_MODE
// Description: 	Holds current work mode (Run/Ping/...)
// 	use I2D_RUN_DESCRIPTOR.TransactionType ENUM. 
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Mode                	:4; 	//use I2D_RUN_DESCRIPTOR.TransactionType ENUM.
			ULONG32	RunModeChanged      	:1; 	//not in Run mode if bit is set, invalidate Run results (and enter safe mode if necessary) after Enum counts.
			ULONG32	RESERVED0           	:11;
			ULONG32	RequestedMode       	:4; 	//holds the mode the Main MCU request from InTEC-D (updated in Main MCU)
			ULONG32	FirstTimeCfgTHData  	:1;
			ULONG32	RESERVED1           	:11;
		} fields;
} UN_D_WORK_MODE;

// Register: D_UPDATE_CFG		Offset: OFFSET_D_UPDATE_CFG
// Description: 	set this bit to signal that InTEC-D needs to be updated (special transaction), clear this bit after cfg updated.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	UpdateIntecD        	:1;
			ULONG32	UpdateGanged        	:1; 	//updated all intec ganged with control params
			ULONG32	UpdateWaterModule   	:1; 	//updated all water module CFG
			ULONG32	RESERVED0           	:29;
		} fields;
} UN_D_UPDATE_CFG;

// Enumeration for field DEVTYPE of register: D_DEVICE_TYPE_LEGACY
#define D_DEVICE_TYPE_INTEC_1	0x000000d2
#define D_DEVICE_TYPE_INTECD_1	0x000000d3

// Register: D_DEVICE_TYPE_LEGACY		Offset: OFFSET_D_DEVICE_TYPE_LEGACY
// Description: 	Device type (InTEC/InTEC-D/Other...)
// 	according Bootloader legacy mapping
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DevType             	:8; 	//Device type 
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_D_DEVICE_TYPE_LEGACY;

// Register: D_GENERAL_STATUS		Offset: OFFSET_D_GENERAL_STATUS
// Description: 	Hold Intec-D general statuses
typedef union {
	ULONG32 value;
		struct {
			ULONG32	GeneralFailureFlag  	:1; 	//The bit is set if any Failure event has descovered, to see the safety description go to D_SAFETY.D_FAILURE
			ULONG32	GeneralWarningFlag  	:1; 	//The bit is set if any warning event has descovered, to see the safety description go to D_SAFETY.D_WARNING
			ULONG32	GeneralNotificationFlag	:1; 	//The bit is set if any notification event has descovered, to see the safety description go to D_SAFETY.D_WARNING
			ULONG32	GeneralSystemErrorFlag	:1; 	//The bit is set if any InTEC_D  HW error  has descovered, to see the description go to D_GENERAL.D_SYSTEM_ERR_STATUS
			ULONG32	GeneralTTDataChanged	:1; 	//The bit is set if Thermal tool was recoonected and EEprom data has been changed
			ULONG32	RearmWip            	:1;
			ULONG32	WaterModuleConnected	:1; 	//The bit is set if Water Module is connected
			ULONG32	WaterModuleInBootMode	:1; 	//If bit is set water module is in boot loading mode
			ULONG32	RESERVED0           	:24; 	//The bit is set if any InTEC_D  HW error  has descovered, to see the description go to D_GENERAL.D_SYSTEM_ERR_STATUS
		} fields;
} UN_D_GENERAL_STATUS;

// Enumeration for field GLOBALUPDATE of register: D_GENERAL_UPDATE
#define D_PID_UPDATE        	0x00000001
#define D_SET_POINT_UPDATE  	0x00000002
#define D_WPS_UPDATE        	0x00000004
#define D_GPM_UPDATE        	0x00000008
#define D_PPT_UPDATE        	0x00000010
#define D_OVER_ERR_MARGIN_UPDATE	0x00000020
#define D_OVER_ERR_SLOPE_UPDATE	0x00000040
#define D_OVER_ERR_TIME_UPDATE	0x00000080
#define D_SP_MARGIN_UPDATE  	0x00000100
#define D_SP_TIME_UPDATE    	0x00000200
#define D_OVER_WARN_MARGIN_UPDATE	0x00000400
#define D_OVER_WARN_SLOPE_UPDATE	0x00000800
#define D_OVER_WARN_TIME_UPDATE	0x00001000

// Register: D_GENERAL_UPDATE		Offset: OFFSET_D_GENERAL_UPDATE
typedef union {
	ULONG32 value;
		struct {
			ULONG32	GlobalUpdate        	:32;
		} fields;
} UN_D_GENERAL_UPDATE;

//****************************************************************************
//* D_BOOTLOADING Unit Registers Description
//****************************************************************************

// Register: D_BOOTLOADING_STATUS		Offset: OFFSET_D_BOOTLOADING_STATUS
// Description: 	External device bootloading status 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	EnterBootloadingMode	:1; 	//set when request to enter bootloader mode received from host
			ULONG32	RESERVED1           	:1;
			ULONG32	DeviceComInBootMode 	:1; 	//set when communication reply received that external device is in bootloading mode
			ULONG32	DeviceComInAppMode  	:1; 	//set when communication reply received that external device is in application mode
			ULONG32	RESERVED0           	:28;
		} fields;
} UN_D_BOOTLOADING_STATUS;

// Register: D_BOOTLOADING_ENTER		Offset: OFFSET_D_BOOTLOADING_ENTER
// Description: 	write this register for setting it in Bootloading mode
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_BOOTLOADING_ENTER;

// Register: D_BOOTLOADING_ABORT		Offset: OFFSET_D_BOOTLOADING_ABORT
// Description: 	write to this register will abort bootloading operation, and reset the bootloading status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_BOOTLOADING_ABORT;

// Register: D_BOOTLOADING_GET_DATA_FROM_DEV		Offset: OFFSET_D_BOOTLOADING_GET_DATA_FROM_DEV
// Description: 	get string from the device in bootloader mode (InTEC Header [6 B] + DATA [54 B] = 60 B)
// 	          
typedef union {
	UCHAR value[54];
		struct {
			UCHAR	DataFromDev         [54];
		} fields;
} UN_D_BOOTLOADING_GET_DATA_FROM_DEV;

// Register: D_BOOTLOADING_SEND_DATA_TO_DEV		Offset: OFFSET_D_BOOTLOADING_SEND_DATA_TO_DEV
// Description: 	send string to the device in bootloader mode (
// 	send: LEN [1B], DATA [LEN B])
// 	          
// 	          
// 	         8
// 	       407
// 	          
// 	          
typedef union {
	UCHAR value[51];
		struct {
			ULONG32	SendDataLen         	:8; 	//Length of data to send to ext device
			UCHAR	DataToSend          [50]; 	//Data to send to ext device
		} fields;
} UN_D_BOOTLOADING_SEND_DATA_TO_DEV;

//****************************************************************************
//* D_CASE Unit Registers Description
//****************************************************************************

// Enumeration for field POLLTCASE of register: D_CASE_CFG
#define D_TCASE_EN_IN0      	0x00000001
#define D_TCASE_EN_IN1      	0x00000002
#define D_TCASE_EN_IN2      	0x00000004
#define D_TCASE_EN_IN3      	0x00000008

// Enumeration for field RTDTYPE of register: D_CASE_CFG
#define RTD_375_TYPE        	0x00000000
#define RTD_385_TYPE        	0x00000001

// Register: D_CASE_CFG		Offset: OFFSET_D_CASE_CFG
// Description: 	Holds the Tcase (TC/RTD) configuration.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	PollTcase           	:4; 	//Bitewise, set the bit to enable the appropriate Tcase input readout. (Tcase0 is enabled by default) 
						                            //if writing 0x00 to PollTcase, the actual updated value will be 0x01. 
			ULONG32	RTDType             	:2; 	//Holds the RTD type 0.00385
						                            //or 0.00375
			ULONG32	RESERVED0           	:26;
		} fields;
} UN_D_CASE_CFG;

// Register: D_CFG_CASE0		Offset: OFFSET_D_CFG_CASE0
// Description: 	Case0 sensor specific configuration 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Offset              	:16; 	//hold the manual calibration offset in InTEC Temp format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_CFG_CASE0;

// Register: D_CFG_CASE1		Offset: OFFSET_D_CFG_CASE1
// Description: 	Case0 sensor specific configuration 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Offset              	:16; 	//hold the manual calibration offset in InTEC Temp format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_CFG_CASE1;

// Register: D_CFG_CASE2		Offset: OFFSET_D_CFG_CASE2
// Description: 	Case0 sensor specific configuration 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Offset              	:16; 	//hold the manual calibration offset in InTEC Temp format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_CFG_CASE2;

// Register: D_CFG_CASE3		Offset: OFFSET_D_CFG_CASE3
// Description: 	Case0 sensor specific configuration 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Offset              	:16; 	//hold the manual calibration offset in InTEC Temp format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_CFG_CASE3;

// Register: D_CASE_STATUS		Offset: OFFSET_D_CASE_STATUS
// Description: 	holds the Tcase status of this InTEC-D
typedef union {
	LONG32 value;
		struct {
			ULONG32	DetectedTcase       	:4; 	//bitwise, bit is set if Tcase input is valid 
			ULONG32	TcaseType           	:2; 	//Hold the actual Tcase Type
						                            //00 - TC T-Type, 
						                            //11 - RTD 
						                            //						                        
			ULONG32	RESERVED0           	:26;
		} fields;
} UN_D_CASE_STATUS;

// Register: D_TCASE0		Offset: OFFSET_D_TCASE0
// Description: 	Holds the Tcase temperature
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//the Tcase temperature (InTEC format)
			ULONG32	RESERVED0           	:16; 	//the Tcase temperature (InTEC format)
		} fields;
} UN_D_TCASE0;

// Register: D_TCASE1		Offset: OFFSET_D_TCASE1
// Description: 	Holds the Tcase temperature
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//the Tcase temperature (InTEC format)
			ULONG32	RESERVED0           	:16; 	//the Tcase temperature (InTEC format)
		} fields;
} UN_D_TCASE1;

// Register: D_TCASE2		Offset: OFFSET_D_TCASE2
// Description: 	Holds the Tcase temperature
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//the Tcase temperature (InTEC format)
			ULONG32	RESERVED0           	:16; 	//the Tcase temperature (InTEC format)
		} fields;
} UN_D_TCASE2;

// Register: D_TCASE3		Offset: OFFSET_D_TCASE3
// Description: 	Holds the Tcase temperature
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//the Tcase temperature (InTEC format)
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_TCASE3;

// Register: D_GET_ALL_TCASES		Offset: OFFSET_D_GET_ALL_TCASES
// Description: 	get all temperatures:
// 	TimeStamp,Valid,Temp0,Temp1...
typedef union {
	UCHAR value[16];
		struct {
			ULONG32	Timestamp           	:32; 	//holds the InTEC Main timestamp
			ULONG32	Valid               	:4; 	//holds which of the TCase temperature is valid
			ULONG32	RESERVED0           	:12;
			ULONG32	Temp0               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp1               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp2               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp3               	:16; 	//Temperatures in InTEC format
			ULONG32	RESERVED1           	:16;
		} fields;
} UN_D_GET_ALL_TCASES;

//****************************************************************************
//* D_CONTROL Unit Registers Description
//****************************************************************************

// Enumeration for field PWMCALC of register: D_PID_LOOP_PWM_CALC
#define ANALOG_OUT_MAX_PWM  	0x0000157c
#define ANALOG_OUT_MIN_PWM  	0x000001f4
#define ANALOG_OUT_PWM_SCALING	0x00000004
#define ANALOG_OUT_MAX_12V  	0x00000af0

// Register: D_PID_LOOP_PWM_CALC		Offset: OFFSET_D_PID_LOOP_PWM_CALC
// Description: 	PID Loop PWM calculation
typedef union {
	ULONG32 value;
		struct {
			ULONG32	PWMCalc             	:32;
		} fields;
} UN_D_PID_LOOP_PWM_CALC;

// Enumeration for field P of register: D_PID_COEF
#define D_CONTROL_P_PRE_BUNDLE0X14	0x00003500
#define D_CONTROL_P_DEFAULT 	0x00003a98

// Enumeration for field I of register: D_PID_COEF
#define D_CONTROL_I_PRE_BUNDLE0X14	0x0000022b
#define D_CONTROL_I_DEFAULT 	0x00001770

// Enumeration for field D of register: D_PID_COEF
#define D_CONTROL_D_DEFAULT 	0x00000000

// Register: D_PID_COEF		Offset: OFFSET_D_PID_COEF
// Description: 	PID Loop Coeficeints 
// 	          
typedef union {
	UCHAR value[12];
		struct {
			ULONG32	P                   	:32; 	//Proportional gain, 
			ULONG32	I                   	:32; 	//Integral
			ULONG32	D                   	:32; 	//Derivative
		} fields;
} UN_D_PID_COEF;

// Register: D_TEC_CONTROL		Offset: OFFSET_D_TEC_CONTROL
// Description: 	Set parameters for TEC Control
typedef union {
	LONG32 value;
		struct {
			ULONG32	EnableOutput        	:1; 	//Set the this bit to enable the output, clear for disable
						                            //
			ULONG32	EnablePowerSavingMode	:1; 	//Set the this bit to enable the Power Savingn which
						                            // Disable output and close coolant valves & deactivate TH fan.
						                            //
			ULONG32	Disarm              	:1; 	//Disarm
			ULONG32	ToggleDisarm        	:1; 	//If bit is set for at least 4 sec change the disarm mode (after bit is clear )
			ULONG32	EnableOpenLoop      	:1; 	//If bit is set open loop control is enabled
						                            //
			ULONG32	EnablePRBS          	:1; 	//If bit is set PRBS is enabled till the bit is clear
			ULONG32	QuickDisarm         	:1; 	//set this bit to disarm intec (no delay), 
			ULONG32	QuickArm            	:1; 	//set this bit to arm intec (no delay), 
			ULONG32	EnableSustainLastVout	:1; 	//If the bit is set InTEC power out and polarity(Hot/cold) will be sustained 
			ULONG32	RESERVED0           	:23;
		} fields;
} UN_D_TEC_CONTROL;

// Enumeration for field TECHEATING of register: D_TEC_STATUS
#define TEC_HEATING         	0x00000001

// Enumeration for field TECCOOLING of register: D_TEC_STATUS
#define TEC_COOLING         	0x00000001

// Register: D_TEC_STATUS		Offset: OFFSET_D_TEC_STATUS
// Description: 	Holds the TEC Status
typedef union {
	LONG32 value;
		struct {
			ULONG32	TECHeating          	:1; 	//output heating if bit is set
			ULONG32	TECCooling          	:1; 	//output cooling if bit is set
			ULONG32	OutputEnabled       	:1; 	//If bit is set  the output enabled, cleared  if disabled
						                            //
						                            //
			ULONG32	TempOverrunErrorDetected	:1;
			ULONG32	DefaultFeedbackSetpointErrorDetected	:1;
			ULONG32	CfgFallbackTempOverrunWarning	:1;
			ULONG32	CfgFallbackSetpointWarning	:1;
			ULONG32	SetPointIsInLimits  	:1; 	//set point is in limits of default Setpoint feedback
			ULONG32	FeedbackSetpointWarningDetected	:1;
			ULONG32	FeedbackOverrunWarningDetected	:1;
			ULONG32	HeaTecDetected      	:1;
			ULONG32	RESERVED0           	:21;
		} fields;
} UN_D_TEC_STATUS;

// Enumeration for field EQUATION of register: D_FEEDBACK_CONTROL
#define D_FEEDBACK_EQU_AVG  	0x00000000
#define D_FEEDBACK_EQU_MAX  	0x00000001
#define D_FEEDBACK_EQU_MIN  	0x00000002
#define D_FEEDBACK_EQU_AAMAX	0x00000003
#define D_FEEDBACK_EQU_AAMIN	0x00000004
#define D_FEEDBACK_EQU_CASE_WITH_OFFSET	0x00000005

// Enumeration for field TYPE of register: D_FEEDBACK_CONTROL
#define D_FEEDBACK_TYPE_DEFAULT	0x00000000
#define D_FEEDBACK_TYPE_CASE	0x00000001
#define D_FEEDBACK_TYPE_DIODE	0x00000002
#define D_FEEDBACK_TYPE_DTS 	0x00000003
#define D_FEEDBACK_TYPE_PF  	0x00000004
#define D_FEEDBACK_TYPE_CASE_WITH_OFFSET	0x00000005
#define D_FEEDBACK_TYPE_GANG	0x00000006

// Enumeration for field SELSOURCES of register: D_FEEDBACK_CONTROL
#define D_FEEDBACK_SOURCE0  	0x00001000
#define D_FEEDBACK_SOURCE1  	0x00002000
#define D_FEEDBACK_SOURCE2  	0x00004000
#define D_FEEDBACK_SOURCE3  	0x00008000
#define D_FEEDBACK_SEL_SRC0 	0x00000001
#define D_FEEDBACK_SEL_SRC1 	0x00000002
#define D_FEEDBACK_SEL_SRC2 	0x00000004
#define D_FEEDBACK_SEL_SRC3 	0x00000008
#define D_FEEDBACK_SEL_SRC4 	0x00000010
#define D_FEEDBACK_SEL_SRC5 	0x00000020
#define D_FEEDBACK_SEL_SRC6 	0x00000040
#define D_FEEDBACK_SEL_SRC7 	0x00000080
#define D_FEEDBACK_SEL_SRC8 	0x00000100
#define D_FEEDBACK_SEL_SRC9 	0x00000200
#define D_FEEDBACK_SEL_SRC10	0x00000400
#define D_FEEDBACK_SEL_SRC11	0x00000800
#define D_FEEDBACK_SEL_SRC12	0x00001000
#define D_FEEDBACK_SEL_SRC13	0x00002000
#define D_FEEDBACK_SEL_SRC14	0x00004000
#define D_FEEDBACK_SEL_SRC15	0x00008000
#define D_FEEDBACK_SEL_SRC_MAX	0x00000010
#define D_FEEDBACK_SEL_DIODE_MAX	0x00000004
#define D_FEEDBACK_SEL_PF_MAX	0x00000004
#define D_FEEDBACK_SEL_CASE_MAX	0x00000003
#define D_FEEDBACK_SEL_DTS_MAX	0x00000010

// Register: D_FEEDBACK_CONTROL		Offset: OFFSET_D_FEEDBACK_CONTROL
// Description: 	Set the temperature source type & equation for  feedback 
typedef union {
	UCHAR value[16];
		struct {
			ULONG32	Equation            	:8; 	//Set the equation to use on sources for feedback according to Enum. 
			ULONG32	Type                	:8; 	//Select the feedback type (which sources to use - Case/Diode/DTS), use the Enum. 
						                            //Default Type is Tcase feedback (writing 0x00 to this field will return 0x01 after read)
			ULONG32	SelSources          	:16; 	//bitwise, set the appropriate bit to use the input temperature source for feedback. this field is a derivative of the Type field.
			ULONG32	CfgFallbackEquation 	:16; 	//Type of equation to use when going to Cfg Fallback mode
			ULONG32	CfgFallbackType     	:16; 	//Type of input to use when going to Cfg Fallback mode
			ULONG32	CfgFallbackSelSources	:16; 	//which sensors to use when going to Cfg Fallback mode
			ULONG32	CaseWithOffsetTimeout	:16; 	//time of using the cfg fallback till going to the default fallback
						                            //Res: 1Sec
						                            //Range [1,180]
						                            //Format: 1T
			ULONG32	CaseWithOffsetManualValue	:16; 	//Manual offset for TcaseWithOffset mode
						                            //Res: 0.1C
						                            //Range [0.1,50]
						                            //Format: InTEC Temp
			ULONG32	CaseWithOffsetUseManualOffset	:16; 	//set this bit for using Manual Offset mode for CaseWithOffset Equation
		} fields;
} UN_D_FEEDBACK_CONTROL;

// Register: D_FEEDBACK_CONTROL_DUMMY		Offset: OFFSET_D_FEEDBACK_CONTROL_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_FEEDBACK_CONTROL_DUMMY;

// Register: D_FEEDBACK_CONTROL_DUMMY_1		Offset: OFFSET_D_FEEDBACK_CONTROL_DUMMY_1
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_FEEDBACK_CONTROL_DUMMY_1;

// Register: D_FEEDBACK_CONTROL_DUMMY_2		Offset: OFFSET_D_FEEDBACK_CONTROL_DUMMY_2
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_FEEDBACK_CONTROL_DUMMY_2;

// Enumeration for field SOURCEVALID of register: D_FEEDBACK_STATUS
#define D_FEEDBACK_VALID_SOURCE0	0x00000001
#define D_FEEDBACK_VALID_SOURCE1	0x00000002
#define D_FEEDBACK_VALID_SOURCE2	0x00000004
#define D_FEEDBACK_VALID_SOURCE3	0x00000008
#define D_FEEDBACK_VALID_SOURCE4	0x00000010
#define D_FEEDBACK_VALID_SOURCE5	0x00000020
#define D_FEEDBACK_VALID_SOURCE6	0x00000040
#define D_FEEDBACK_VALID_SOURCE7	0x00000080
#define D_FEEDBACK_VALID_SOURCE8	0x00000100
#define D_FEEDBACK_VALID_SOURCE9	0x00000200
#define D_FEEDBACK_VALID_SOURCE10	0x00000400
#define D_FEEDBACK_VALID_SOURCE11	0x00000800
#define D_FEEDBACK_VALID_SOURCE12	0x00001000
#define D_FEEDBACK_VALID_SOURCE13	0x00002000
#define D_FEEDBACK_VALID_SOURCE14	0x00004000
#define D_FEEDBACK_VALID_SOURCE15	0x00008000

// Register: D_FEEDBACK_STATUS		Offset: OFFSET_D_FEEDBACK_STATUS
// Description: 	Hold the feedback status (the actual valid inputs that are used for feedback)
typedef union {
	LONG64 value;
		struct {
			ULONG32	SourceValid         	:16; 	//Bitewise, bit is set if the appropriate input is valid (and used for the feedback equation)
			ULONG32	ActualFeedbackType  	:8; 	//indication which feedback type is on. 
						                            //note that even if any feedback Type was configured, other type can be active, for example in a case of no valid input, or safety. 
			ULONG32	TjFeedbackOn        	:1; 	//Tj Feedback is used for InTEC-D if this bit is set, Tcase is used if clear
			ULONG32	CfgFallbackOn       	:1; 	//Cfg Fallback is on if selected feedback is unavailable.
			ULONG32	DefaultFallbackOn   	:1; 	//DefaultFallback is on if selected feedback & cfg fallback are unavailable.
			ULONG32	RESERVED0           	:5;
			ULONG32	CaseWithOffsetAutoValue	:16; 	//Holds the difference between Tfeedback and Tcase (while the feedback is not Tcase) - in InTEC format
						                            //note that this value won't change if when the actual feedback is CaseWithOffset to Case.
			ULONG32	RESERVED1           	:16;
		} fields;
} UN_D_FEEDBACK_STATUS;

// Register: D_FEEDBACK_TEMP		Offset: OFFSET_D_FEEDBACK_TEMP
// Description: 	holds the temperature that if used feedback, this it the temperature calculated be the selected sources with the selected equation.
typedef union {
	LONG64 value;
		struct {
			ULONG32	TimeStamp           	:32; 	//temperature timestamp
			ULONG32	Temp                	:16; 	//InTEC Temp format
			ULONG32	RESERVED0           	:15;
			ULONG32	TempValid           	:1; 	//temperature is valid if set
		} fields;
} UN_D_FEEDBACK_TEMP;

// Enumeration for field SETPOINT of register: D_FEEDBACK_SETPOINT
#define D_CONTROL_FEEDBACK_SETPOINT_MAX	0x0000085c
#define D_CONTROL_FEEDBACK_SETPOINT_MIN	0x0000008c
#define D_CONTROL_FEEDBACK_SETPOINT_DEFAULT	0x0000037a

// Register: D_FEEDBACK_SETPOINT		Offset: OFFSET_D_FEEDBACK_SETPOINT
// Description: 	holds the feedback setpoint temperature
typedef union {
	ULONG32 value;
		struct {
			ULONG32	SetPoint            	:16; 	//feedback setpoint temperature in InTEC temperature format.
						                            //see ENUM for setpoint Min & Max values
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_FEEDBACK_SETPOINT;

// Register: D_FEEDBACK_JUNCTION_TEMP		Offset: OFFSET_D_FEEDBACK_JUNCTION_TEMP
// Description: 	holds the Junction temp
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TjTemp              	:16; 	//feedback setpoint temperature in InTEC temperature format
			ULONG32	TjTempValid         	:1; 	//Tj Temperature valid flag
			ULONG32	RESERVED0           	:15;
		} fields;
} UN_D_FEEDBACK_JUNCTION_TEMP;

// Enumeration for field CURRENTSENSE of register: D_POWER_OUT_SENSE
#define D_POWER_OUT_CURRENT 	0x00000001
#define D_POWER_OUT_VOLTAGE 	0x00000002
#define D_POWER_OUT_POWER   	0x00000004
#define D_POWER_OUT_ZERO_CURRENT	0x00000008
#define D_POWER_OUT_PS      	0x00000010
#define D_CURRENT_LIMIT     	0x00000c06

// Enumeration for field POWEROUTCALC of register: D_POWER_OUT_SENSE
#define D_POWER_LIMIT       	0x0000a02f

// Enumeration for field POWERSUPPLYSENSE of register: D_POWER_OUT_SENSE
#define D_24PS_SENSE_CODE   	0x00000745
#define D_12PS_SENSE_CODE   	0x000003a2
#define D_UNDER_VOLTAGE_PS  	0x00000136

// Register: D_POWER_OUT_SENSE		Offset: OFFSET_D_POWER_OUT_SENSE
// Description: 	Holds the values of voltage,current and power
typedef union {
	UCHAR value[10];
		struct {
			ULONG32	CurrentSense        	:16; 	//ADC code for current
			ULONG32	VoltageSense        	:16; 	//ADC code for voltage
			ULONG32	PowerOutCalc        	:16;
			ULONG32	ZeroCurentOffset    	:16; 	//ADC value of zero current offset
			ULONG32	PowerSupplySense    	:16; 	//ADC value of analog out power supply
		} fields;
} UN_D_POWER_OUT_SENSE;

// Register: D_FEEDBACK_DELTA_CFG		Offset: OFFSET_D_FEEDBACK_DELTA_CFG
// Description: 	Difference between Tcase and Tfeedback is higher than DeltaTemp for DeltaTempTime
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DeltaTemp           	:16; 	//Difference between Tcase and Tfeedback limit
			ULONG32	DeltaTempTime       	:16; 	//Delta time 
		} fields;
} UN_D_FEEDBACK_DELTA_CFG;

// Enumeration for field DCDCFANACT of register: D_CONTROL_MODULE_TEMP
#define ENC_FAN_OFF         	0x00000000
#define ENC_FAN_ON          	0x00000001
#define DC_DC_SOURCE        	0x00000000

// Enumeration for field HBRIDGEFANACT of register: D_CONTROL_MODULE_TEMP
#define H_BRIDGE_SOURCE     	0x00000001

// Enumeration for field DCDCMODULETEMP of register: D_CONTROL_MODULE_TEMP
#define DCDC_TEMP_LIMIT     	0x00000032
#define DCDC_OVER_TEMP_LIMIT	0x00000055
#define DCDC_FAN_HYS        	0x0000000a

// Enumeration for field HBRIDGEMODULETEMP of register: D_CONTROL_MODULE_TEMP
#define H_BRIDGE_TEMP_LIMIT 	0x00000032
#define H_BRIDGE_OVER_TEMP_LIMIT	0x00000055
#define H_BRIDGE_FAN_HYS    	0x0000000a

// Register: D_CONTROL_MODULE_TEMP		Offset: OFFSET_D_CONTROL_MODULE_TEMP
// Description: 	Holds control module temperature
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DcDcFanAct          	:1; 	//If bit is set enclosure fan has been actuated due to DC/DC over limit temperature
			ULONG32	HBridgeFanAct       	:1; 	//If bit is set enclosure fan has been actuated due to H-Bridge over limit temperature
			ULONG32	RESERVED0           	:14; 	//holds the Hbridge module temperature sense 1T
			ULONG32	DcDcModuleTemp      	:8; 	//holds the DC/DC module temperature sense 1T
			ULONG32	HBridgeModuleTemp   	:8; 	//holds the Hbridge module temperature sense 1T
		} fields;
} UN_D_CONTROL_MODULE_TEMP;

// Enumeration for field DCDCLIMIT of register: D_ANALOG_OUT
#define D_ANALOG_OUT_12LIMIT	0x00000001
#define D_ANALOG_FULL_RANGE 	0x00000000
#define D_ANALOG_OUT_REDUCE_LIMIT	0x00000002

// Enumeration for field SOFTSTOPPWMVAL of register: D_ANALOG_OUT
#define SOFT_STOP_REDUCE_VAL	0x000001f4

// Enumeration for field SOFTSTARTPWMVAL of register: D_ANALOG_OUT
#define SOFT_START_INCREASE_VAL	0x000001f4

// Register: D_ANALOG_OUT		Offset: OFFSET_D_ANALOG_OUT
// Description: 	Analog out soft start/stop and limitation  parameters
typedef union {
	UCHAR value[12];
		struct {
			ULONG32	AnalogOutSoftStop   	:1; 	//if set soft Stop is wip
			ULONG32	AnalogOutSoftStart  	:1; 	//if set soft start is wip
			ULONG32	DcDcLimitEn         	:1; 	//if bit is set DC/DC output power is limited
			ULONG32	UnderVoltagePS      	:1; 	//if bit is set power PS is under voltage
			ULONG32	RESERVED0           	:12; 	//if bit is set DC/DC output power is limited
			ULONG32	DcDcLimit           	:16; 	//holds the DC/DC PWM val limit
			ULONG32	SoftStopPWMVal      	:32; 	//Holds the Soft Stop PWM Value
			ULONG32	SoftStartPWMVal     	:32; 	//Holds the Soft Start PWM Value
		} fields;
} UN_D_ANALOG_OUT;

// Enumeration for field OVERRUNERRSLOPE of register: D_FEEDBACK_LIMITS
#define OVERRUN_12SEC_FRAME 	0x00002ee0
#define OVERRUN_1SEC_FRAME  	0x000003e8

// Register: D_FEEDBACK_LIMITS		Offset: OFFSET_D_FEEDBACK_LIMITS
// Description: 	Holds the Max and Min user defined feedback temps
typedef union {
	UCHAR value[24];
		struct {
			ULONG32	OverrunErrMargin    	:16; 	//Difference (±) around setpoint. Default 7C.
			ULONG32	OverrunErrSlope     	:16; 	//Slope {1c/sec}
			ULONG32	OverrunErrTime      	:16; 	//time
			ULONG32	SpMargin            	:16; 	//Feedback <-> set point margin
			ULONG32	SpTime              	:16; 	//Time in [s] to wait befor actuation
			ULONG32	MaxT                	:16; 	//Max temperature
			ULONG32	MaxTime             	:16; 	//Max  time for Max temperature
			ULONG32	MinT                	:16;
			ULONG32	MinTime             	:16;
			ULONG32	OverrunWarnMargin   	:16;
			ULONG32	OverrunWarnSlope    	:16;
			ULONG32	OverrunWarnTime     	:16;
		} fields;
} UN_D_FEEDBACK_LIMITS;

// Register: D_FEEDBACK_LIMITS_DUMMY		Offset: OFFSET_D_FEEDBACK_LIMITS_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_FEEDBACK_LIMITS_DUMMY;

// Register: D_FEEDBACK_LIMITS_DUMMY_1		Offset: OFFSET_D_FEEDBACK_LIMITS_DUMMY_1
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_FEEDBACK_LIMITS_DUMMY_1;

// Register: D_FEEDBACK_LIMITS_DUMMY_2		Offset: OFFSET_D_FEEDBACK_LIMITS_DUMMY_2
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_FEEDBACK_LIMITS_DUMMY_2;

// Register: D_FEEDBACK_LIMITS_DUMMY_3		Offset: OFFSET_D_FEEDBACK_LIMITS_DUMMY_3
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_FEEDBACK_LIMITS_DUMMY_3;

// Register: D_FEEDBACK_LIMITS_DUMMY_4		Offset: OFFSET_D_FEEDBACK_LIMITS_DUMMY_4
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_FEEDBACK_LIMITS_DUMMY_4;

// Register: D_FEEDBACK_MAX_MIN_TEMP		Offset: OFFSET_D_FEEDBACK_MAX_MIN_TEMP
// Description: 	Holds feedback Max and Min temp 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	MaxTemp             	:16; 	//Max feedback temp
			ULONG32	MinTemp             	:16; 	//Min feedback temp
		} fields;
} UN_D_FEEDBACK_MAX_MIN_TEMP;

// Register: D_CONTROL_MISC_CFG		Offset: OFFSET_D_CONTROL_MISC_CFG
typedef union {
	ULONG32 value;
		struct {
			ULONG32	ResetFeedbackHistory	:1; 	//If the bit is set, Reset feedback Max Min temp
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_D_CONTROL_MISC_CFG;

// Enumeration for field OUTPUTDIRECTION of register: D_CONTROL_OPEN_LOOP_CFG
#define OPEN_LOOP_HEATING   	0x00000000
#define OPEN_LOOP_COOLING   	0x00000001

// Register: D_CONTROL_OPEN_LOOP_CFG		Offset: OFFSET_D_CONTROL_OPEN_LOOP_CFG
// Description: 	Holds the open loop control configurations
typedef union {
	ULONG32 value;
		struct {
			ULONG32	OutputDirection     	:1; 	//Set the bit for cooling clear for heating direction
			ULONG32	VoltageOutput       	:15; 	//output voltage in 10T format
			ULONG32	RESERVED0           	:16; 	//output voltage in 10T format
		} fields;
} UN_D_CONTROL_OPEN_LOOP_CFG;

// Enumeration for field LOWVOLTAGEPOLARITY of register: D_CONTROL_PRBS_CFG
#define PRBS_HEAT           	0x00000000
#define PRBS_COOL           	0x00000001
#define PRBS_VOLTAGE_MASK   	0x00007fff
#define PRBS_POLARITY_MASK  	0x00008000
#define PRBS_GENERATION_TIME	0x00000032

// Register: D_CONTROL_PRBS_CFG		Offset: OFFSET_D_CONTROL_PRBS_CFG
// Description: 	Holds the PRBS voltage configuration
typedef union {
	ULONG32 value;
		struct {
			ULONG32	LowVoltagePolarity  	:1; 	//If bit is set the output is on heat
			ULONG32	LowVoltage          	:15;
			ULONG32	HighVoltagePolarity 	:1; 	//If bit is set the output is on heat
			ULONG32	HighVoltage         	:15;
		} fields;
} UN_D_CONTROL_PRBS_CFG;

// Enumeration for field VMAXVAL of register: D_TEC_OUT_VMAX
#define DEFAULT_V_MAX_VAL_PS12	0x00000078
#define DEFAULT_V_MAX_VAL_PS24	0x000000f0

// Register: D_TEC_OUT_VMAX		Offset: OFFSET_D_TEC_OUT_VMAX
// Description: 	Holds the Vmax val
typedef union {
	ULONG32 value;
		struct {
			ULONG32	VmaxVal             	:16; 	//Holds TEC max Vout voltage 
			ULONG32	VmaxValHeaTec       	:16; 	//Holds TEC max Vout cooling voltage 
		} fields;
} UN_D_TEC_OUT_VMAX;

// Register: D_FEEDBACK_AVG_STDEV_TEMP		Offset: OFFSET_D_FEEDBACK_AVG_STDEV_TEMP
// Description: 	holds the feedback average and standard deviation 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Average             	:16; 	//intec temp format
			ULONG32	Stdev               	:16; 	//intec temp format
		} fields;
} UN_D_FEEDBACK_AVG_STDEV_TEMP;

// Register: D_FEEDBACK_TJ_ALLOC		Offset: OFFSET_D_FEEDBACK_TJ_ALLOC
// Description: 	holds the Diode and DTS allocation for intec D
typedef union {
	ULONG32 value;
		struct {
			ULONG32	bwDiodeAllocation   	:4; 	//holds the Diode allocation for intec D (bitwise)
			ULONG32	RESERVED0           	:12;
			ULONG32	bwDtsAllocation     	:16; 	//holds the DTS allocation for intec D (bitwise)
		} fields;
} UN_D_FEEDBACK_TJ_ALLOC;

// Register: D_RAMP_RATE_CONTROL		Offset: OFFSET_D_RAMP_RATE_CONTROL
// Description: 	Hold the ramp rate data
typedef union {
	LONG32 value;
		struct {
			ULONG32	EnableRampRateControl	:1; 	//If bit is set Ramp rate enabled
			ULONG32	EnableFullRampRateControl	:1; 	//If bit is clear,ramp rate control enabled only after SetPoint Change
			ULONG32	RampRateSPMargin    	:6; 	//Use 1T format, Range 1-60[C].
						                            //
			ULONG32	DesRampRate         	:8; 	//Holds the ramp rate control in InTEC temperature control C/Min.
						                            //Use 1T format, Range 5-100[C]/Min
						                            //
			ULONG32	MesRampRate         	:16; 	//Holds the calculated ramp rate  InTEC temperature control C/Min
		} fields;
} UN_D_RAMP_RATE_CONTROL;

// Register: D_VAR_SP		Offset: OFFSET_D_VAR_SP
// Description: 	hold variable setpoint enable/disable and offset value cfg
typedef union {
	ULONG32 value;
		struct {
			ULONG32	SpOffset            	:16; 	//write a value to this field to offset the setpoint (when EnableVarSp = 1). Format: 10T, Range: 0-500 (if 250 was sent, InTEC will offset the setpoint by 25.0) 
			ULONG32	EnableVarSp         	:1; 	//set this bit to enable the Variable Setpoint option
			ULONG32	RESERVED0           	:15;
		} fields;
} UN_D_VAR_SP;

// Register: D_GANG_CFG		Offset: OFFSET_D_GANG_CFG
// Description: 	GANG Mode configuration register
typedef union {
	ULONG32 value;
		struct {
			ULONG32	GangAutoCfg         	:1; 	//If bit set GangAutoCfg enabled
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_D_GANG_CFG;

//****************************************************************************
//* D_ENVIRONMENT Unit Registers Description
//****************************************************************************

// Enumeration for field RESERVED of register: D_ACTUATION
#define CHILLER_OUT_FLAG    	0x00000001
#define REMOTE_PC_POWER_FLAG	0x00000002
#define DUT_POWER_FLAG      	0x00000004
#define LIQUID_VALVE1_FLAG  	0x00000008
#define LIQUID_VALVE2_FLAG  	0x00000010
#define PURGE_FLAG          	0x00000020
#define ACTUATION_1_FLAG    	0x00000040
#define ACTUATION_2_FLAG    	0x00000080
#define ACTUATION_3_FLAG    	0x00000100
#define ACTUATION_4_FLAG    	0x00000200

// Register: D_ACTUATION		Offset: OFFSET_D_ACTUATION
// Description: 	Holds the actuations status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	ChillerOut          	:1; 	//If set the output is actuated
			ULONG32	RemotePCPower       	:1; 	//If set the output is actuated
			ULONG32	DutPower            	:1; 	//If set the output is actuated
			ULONG32	LiquidValve1        	:1; 	//If set the output is actuated
			ULONG32	LiquidValve2        	:1; 	//If set the output is actuated
			ULONG32	PurgeOut            	:1; 	//If set the output is actuated
			ULONG32	Actuation1          	:1; 	//If set the output is actuated
			ULONG32	Actuation2          	:1; 	//If set the output is actuated
			ULONG32	Actuation3          	:1; 	//If set the output is actuated
			ULONG32	Actuation4          	:1; 	//If set the output is actuated
			ULONG32	RESERVED0           	:22; 	//If set the output is actuated
		} fields;
} UN_D_ACTUATION;

// Enumeration for field RESERVED of register: D_LEAKAGE
#define D_LEACK_WATER_MODULE	0x00000001
#define D_LEACK_TH          	0x00000002
#define D_LEACK_WIRE_DETECT_LIMIT	0x00000d48
#define D_LEACK_CHILLER     	0x00000004
#define D_LEACK_FLOOR       	0x00000008
#define D_TH_INTER_COND     	0x00000010
#define D_TH_INTER_LEACK    	0x00000020

// Register: D_LEAKAGE		Offset: OFFSET_D_LEAKAGE
// Description: 	Holds the water leakage detection status in Zone1&2
typedef union {
	ULONG32 value;
		struct {
			ULONG32	LeakWaterModule     	:1; 	//If bit set detected water leak in  Water Module
			ULONG32	LeakTH              	:1; 	//If bit set detected water leak in TH
			ULONG32	LeakChiller         	:1; 	//If bit set detected water leak in Chiller
			ULONG32	LeakFloor           	:1; 	//If bit set detected water leak on floor
			ULONG32	THInterCond         	:1; 	//If bit set detected THInterCond
			ULONG32	THInterLeak         	:1; 	//If bit set detected THInterLeak
			ULONG32	RESERVED0           	:26; 	//If bit set detected water leak in zone 1
		} fields;
} UN_D_LEAKAGE;

// Enumeration for field FLOWSENSE of register: D_COOLANT
#define D_COOLANT_FLOW      	0x00000001

// Enumeration for field PRESSURESENSE of register: D_COOLANT
#define D_COOLANT_PRESSURE  	0x00000002

// Register: D_COOLANT		Offset: OFFSET_D_COOLANT
// Description: 	Holds the water flow status and measurement
// 	          
typedef union {
	UCHAR value[12];
		struct {
			ULONG32	LowFlowDetected     	:1; 	//if bit set water low flow detected
			ULONG32	LowPressureDetected 	:1; 	//if bit set water low pressure detected
						                            //
			ULONG32	RESERVED0           	:14; 	//if bit set water low pressure detected
						                            //
			ULONG32	WpsTreshold         	:16; 	//Coolant pressure threshold.
			ULONG32	GpmTreshold         	:16; 	//coolant flow threshold.
			ULONG32	FlowSense           	:16; 	//Flow measurement
						                            //
			ULONG32	PressureSense       	:16; 	//Pressure  measurement
						                            //
			ULONG32	RESERVED1           	:16; 	//Pressure  measurement
						                            //
		} fields;
} UN_D_COOLANT;

// Register: D_COOLANT_DUMMY		Offset: OFFSET_D_COOLANT_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_COOLANT_DUMMY;

// Register: D_COOLANT_DUMMY_1		Offset: OFFSET_D_COOLANT_DUMMY_1
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_COOLANT_DUMMY_1;

// Enumeration for field PURGEOFFTEMP of register: D_PURGE
#define PURGE_OFF_DELAY     	0x00000bb8

// Register: D_PURGE		Offset: OFFSET_D_PURGE
// Description: 	Purge 
typedef union {
	LONG64 value;
		struct {
			ULONG32	LowPurgePressure    	:1; 	//if bit is set low purge pressure detected
			ULONG32	OverPurgeTcTemp     	:1; 	//if bit is set Tc temperature is above the purge off temp
			ULONG32	RESERVED0           	:6; 	//if bit is set low purge pressure detected
			ULONG32	PurgePressureSense  	:16; 	//PurgePressuremeasurement
			ULONG32	RESERVED1           	:8;
			ULONG32	PptTreshold         	:16; 	//purge pressure threshold
			ULONG32	PurgeOffTemp        	:16; 	//Purge off temp 
		} fields;
} UN_D_PURGE;

// Enumeration for field RESERVED of register: D_PURGE_DUMMY
#define D_ENV_SENSE_WATER_MODULE	0x00000001
#define D_ENV_SENSE_TH      	0x00000002
#define D_ENV_SENSE_COOLANT_FLOW	0x00000003
#define D_ENV_SENSE_COOLANT_PRESSURE	0x00000004
#define D_ENV_SENSE_PURGE_PRESSURE	0x00000005

// Register: D_PURGE_DUMMY		Offset: OFFSET_D_PURGE_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_PURGE_DUMMY;

// Register: D_ENV_STATUS		Offset: OFFSET_D_ENV_STATUS
typedef union {
	ULONG32 value;
		struct {
			ULONG32	NoUnitInSocket      	:1; 	//if the bit is set no unit in socket detected
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_D_ENV_STATUS;

// Register: D_LEAK_BOARD		Offset: OFFSET_D_LEAK_BOARD
// Description: 	Holds the Leak board ADC data
typedef union {
	LONG64 value;
		struct {
			ULONG32	ADCStatus           	:2; 	//Leak board ADC status
			ULONG32	RESERVED0           	:14;
			ULONG32	ADCCfg              	:16; 	//Holds the ADC cfg
			ULONG32	ADCValue            	:16; 	//Holds the ADC voltage value
			ULONG32	RESERVED1           	:16; 	//holds the ADC Voltage result (10T)
		} fields;
} UN_D_LEAK_BOARD;

// Register: D_LEAK_BOARD_LIMITS		Offset: OFFSET_D_LEAK_BOARD_LIMITS
// Description: 	holds the leak board condensation & leak limits for the event cfg
typedef union {
	LONG64 value;
		struct {
			ULONG32	TimeTillEventOn     	:8; 	//Condensation for period more this value will trigger the Failure event. Format: 1T, Range: 0-240
			ULONG32	RESERVED0           	:24;
			ULONG32	CondensationLimit   	:16; 	//Value below this limit considered as condensation. Format: 100T, Range: 1-330
			ULONG32	ThInternalLeakLimit 	:16; 	//Value below this limit considered as Leak in the TH. Format: 100T, Range: 1-330
		} fields;
} UN_D_LEAK_BOARD_LIMITS;

//****************************************************************************
//* D_EVENTS Unit Registers Description
//****************************************************************************

// Register: D_FAILURES_STATUS		Offset: OFFSET_D_FAILURES_STATUS
// Description: 	Holds InTEC_D Failures status, If bit is set failure has been detected
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	ThermalSwitchOn     	:1; 	//Thermal switch had been actuated, and thermal head overheat occurred (no coolant flow for example)
			ULONG32	LeakWaterModule     	:1; 	//A leak was detected in Leak Water Module
			ULONG32	LeakTH              	:1; 	//A leak was detected in Leak TH
			ULONG32	LowCoolantPressure  	:1; 	//The coolant pressure is 20% below WPS
			ULONG32	LowCoolantFlow      	:1; 	//The coolant flowis 20% below GPM
			ULONG32	LowPurgePressure    	:1; 	//The purge pressure is 20% below PPT
			ULONG32	LogicPSFailure      	:1; 	//Logic 12v power supply under-voltage was detected for accumulated 6sec during 1min period.
			ULONG32	DCDCOverheat        	:1; 	//InTEC on-board DCDC temp is above limit.
			ULONG32	HBridgeOverheat     	:1; 	//InTEC on-board H-Bridge temp is above limit
			ULONG32	OutputCurrentOverrun	:1; 	//Output current overrun (probably due to load short circuit)
			ULONG32	OutputPowerOverrun  	:1; 	//Output power overrun
			ULONG32	TempOverrunError    	:1; 	//The default feedback temp is at least OverrunErrMargin away from setpoint and keeps running away for OverrunErrTime in OverrunErrSlope rate For OverrunErrTime: |T(t)-T(t-2)|> OverrunErrSlope |T(t)-SP|> OverrunErrMargin
			ULONG32	DefaultFeedbackSetpointError	:1; 	//The default feedback temp is at least SpMargin away from setpoint for SpTime. For SpTime: |T(t)-SP|>SpMargin
			ULONG32	MaxTemperatureError 	:1; 	//Tfeedback is greater than MaxT for MaxTime For MaxTime: T(t)>MaxT
			ULONG32	MinTemperatureError 	:1; 	//Tfeedback is less than MinT for MinTime. For MinTime: T(t)<MinT
			ULONG32	LeakChiller         	:1; 	//A leak was detected in Chiller
			ULONG32	LeakFloor           	:1; 	//A leak was detected on Floor
			ULONG32	THInterCond         	:1; 	//A high Condensation was detected in TH (TH leak board )
			ULONG32	THInterLeak         	:1; 	//A leak was detected in TH (TH leak board )
			ULONG32	RESERVED0           	:13; 	//A leak was detected in TH (TH leak board )
		} fields;
} UN_D_FAILURES_STATUS;

// Register: D_WARNINGS_STATUS		Offset: OFFSET_D_WARNINGS_STATUS
// Description: 	Holds the InTEC_D warnings status bits, if bit is set warning notification has been detected
typedef union {
	ULONG32 value;
		struct {
			ULONG32	NoTcase             	:1; 	//Tcase#0 is not connected or temp is out of range
			ULONG32	TcaseCfgMismatch    	:1; 	//TH HW cfg bits do not match TH EEPROM cfg
			ULONG32	ThermalHeadNotInSocket	:1; 	//Thermal Tool Position sensor actuated (and no purge on thermal head)
			ULONG32	SelftestCablesConnected	:1; 	//Selftest cables are connected (w/ Resistor instead the TEC)
			ULONG32	RequestedFeedbackNA 	:1; 	//No valid control sensor for the selected feedback type
			ULONG32	DeltaTCTfeedbackHigh	:1; 	//Difference between Tcase and Tfeedback is higher than DeltaTemp for DeltaTempTime
			ULONG32	FeedbackTempOverrunWarning	:1; 	//Feedback temp is at least OverrunWarnMargin away from setpoint and keeps running away for OverrunWarnTime in OverrunWarnSlope rate For OverrunWarnTime: |T(t)-T(t-2)|> OverrunWarnSlope |T(t)-SP|> OverrunWarnMargin
			ULONG32	FeedbackSetpointWarning	:1; 	//Feedback temp (other than the default feedback) is at least SpMargin away from setpoint for SpTime. For SpTime: |T(t)-SP|>SpMargin
			ULONG32	LogicPSUndervoltage 	:1; 	//Logic 12v power supply is under-voltage
			ULONG32	LowTECPSVoltage     	:1; 	//Measured TEC PS voltage level is under the TH EEPROM cfg
			ULONG32	OutputOffButtonAct  	:1; 	//External Output button is pressed
			ULONG32	ThermalHeadNotConnected	:1; 	//Thermal head is not connected (no EEPROM found and no Thermal Switch/bypass)
			ULONG32	ECN24vRequired      	:1; 	//Using 24V power supply with InTEC that didn’t passed 24V ECN (ECN#3)
			ULONG32	CfgFallbackTempOverrunWarning	:1; 	//Cfg Fallback temp is at least OverrunWarnMargin away from setpoint for 12sec and keeps running away for OverrunWarnTime in OverrunWarnSlope rate For OverrunWarnTime: |T(t)-T(t-2)|> OverrunWarnSlope |T(t)-SP|> OverrunWarnMargin
			ULONG32	CfgFallbackSetpointWarning	:1; 	//Cfg Fallback temp is at least SpMargin away from setpoint for SpTime. For SpTime: |T(t)-SP|>SpMargin
			ULONG32	HwError             	:1; 	//InTEC has HW Error, see details in Errors
			ULONG32	PrbsMode            	:1; 	//InTEC is working in PRBS mode, output is toggled between 2 values
			ULONG32	OpenLoopMode        	:1; 	//InTEC is working in Open Loop mode
			ULONG32	MaintainOutputMode  	:1; 	//InTEC maintains last output it had before entering this mode
			ULONG32	LeakBrdNotDetected  	:1;
			ULONG32	RESERVED0           	:12; 	//External Output button is pressed
		} fields;
} UN_D_WARNINGS_STATUS;

// Register: D_NOTIFICATION_STATUS		Offset: OFFSET_D_NOTIFICATION_STATUS
// Description: 	Holds the notefication messages status, is bit is set notification is detected
typedef union {
	ULONG32 value;
		struct {
			ULONG32	CommOutputoff       	:1; 	//Output disabled through communication
			ULONG32	PowerSavingMode     	:1; 	//Power Saving mode enabled through communication
			ULONG32	HighTECPSvoltage    	:1; 	//Measured TEC PS voltage level is over the TH EEPROM cfg
			ULONG32	RESERVED0           	:1;
			ULONG32	NoUnitInSocket      	:1; 	//No unit in socket detected
			ULONG32	THEepromNotDetected 	:1; 	//No communication with TH EEPROM.
			ULONG32	THEepromBlank       	:1; 	//Have communication with TH EEPROM, but it has no data
			ULONG32	OutputOverCurrentRestrained	:1; 	//Output overcurrent detected and restrained
			ULONG32	OutputOverPowerRestrained	:1; 	//Output overpower detected and restrained
			ULONG32	PurgeOff            	:1; 	//Purge is off since Tcase is greater than PurgeOffTemp
			ULONG32	Disarm              	:1; 	//if bit is set the system is disarm
			ULONG32	GangMode            	:1; 	//If bit is set InTEC-D is in gang mode
			ULONG32	THIntHumsense       	:1; 	//TH Internal Humidity detected 
			ULONG32	VarSpEnabled        	:1; 	//Variable SP mode enabled
			ULONG32	RESERVED1           	:18; 	//Output overpower detected and restrained
		} fields;
} UN_D_NOTIFICATION_STATUS;

// Register: D_FAILURES_DISABLE		Offset: OFFSET_D_FAILURES_DISABLE
// Description: 	Hold which failures events are disabled.
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:1;
			ULONG32	DisLeakWaterModule  	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	DisLeakTH           	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	DisLowCoolantPressure	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	DisLowCoolantFlow   	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	DisLowPurgePressure 	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	RESERVED1           	:5;
			ULONG32	DisTempOverrunError 	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	DisDefaultFeedbackSetpointError	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	RESERVED2           	:2;
			ULONG32	DisLeakChiller      	:1; 	//If the bit is set monitoring of the event is disabled.
						                            //
			ULONG32	DisLeakFloor        	:1; 	//If the bit is set monitoring of the event is disabled.
						                            //
			ULONG32	DisTHInterCond      	:1; 	//If the bit is set monitoring of the event is disabled.
						                            //
			ULONG32	DisTHInterLeak      	:1; 	//If the bit is set monitoring of the event is disabled.
						                            //
			ULONG32	RESERVED3           	:13;
		} fields;
} UN_D_FAILURES_DISABLE;

// Register: D_WARNINGS_DISABLE		Offset: OFFSET_D_WARNINGS_DISABLE
// Description: 	Hold which warning events are disabled.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:2;
			ULONG32	DisThermalHeadNotInSocket	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	RESERVED1           	:3;
			ULONG32	DisFeedbackTempOverrunWarning	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	DisFeedbackSetpointWarning	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	RESERVED2           	:1;
			ULONG32	DisLowTECPSVoltage  	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	RESERVED3           	:1;
			ULONG32	DisThermalHeadNotconnected	:1;
			ULONG32	RESERVED4           	:1;
			ULONG32	DisCfgFallbackTempOverrunWarning	:1;
			ULONG32	DisCfgFallbackSetpointWarning	:1;
			ULONG32	RESERVED5           	:17;
		} fields;
} UN_D_WARNINGS_DISABLE;

// Register: D_NOTIFICATION_DISABLE		Offset: OFFSET_D_NOTIFICATION_DISABLE
// Description: 	Hold which notofication events are disabled.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:4;
			ULONG32	DisNoUnitInSocket   	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	DisTHEepromNotDetected	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	DisTHEepromBlank    	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	RESERVED1           	:1;
			ULONG32	DisPurgeOff         	:1; 	//If the bit is set monitoring of the event is disabled.
			ULONG32	RESERVED2           	:23;
		} fields;
} UN_D_NOTIFICATION_DISABLE;

// Enumeration for field RESERVED of register: D_EVENTS_DEFAULTS
#define D_EVENTS_FAILURES_DISABLE_DEAFULT 	0x0007803a
#define D_EVENTS_WARNINGS_DISABLE_DEAFULT	0x00000a04
#define D_EVENTS_NOTIFICATIONS_DISABLE_DEAFULT	0x00000170
#define D_EVENTS_WARNINGS_ENABLE_CHECK	0x00000d0f
#define D_EVENTS_NOTIFICATION_ENABLE_CHECK	0x00000403
#define D_EVENT_DISABLE_OUTPUT	0x00000001
#define D_EVENT_CLOSE_COOLANT_VALVE	0x00000002
#define D_EVENT_OPEN_COOLANT_VALVE	0x00000004
#define D_EVENT_ACTIVATE_TH_FAN	0x00000008
#define D_EVENT_DEACTIVATE_TH_FAN	0x00000010
#define D_EVENT_SHUT_DOWN_SUT	0x00000020
#define D_EVENT_CLOSE_PURGE_VALVE	0x00000040
#define D_EVENT_DISABLE_TEC_ENABLE_BIT	0x00000080
#define D_EVENT_LIMIT_TEC_12V	0x00000100
#define D_EVENT_TJ_TC_FALLBACK_EN	0x00000200
#define D_EVENT_CLEAR       	0x0000ffff
#define D_EVENT_LIMIT_TEC   	0x00000400
#define D_EVENT_DEF_FEEDBACK	0x00000001
#define D_EVENT_FEEDBACK    	0x00000002
#define D_EVENT_CFG_FEEDBACK	0x00000003

// Register: D_EVENTS_DEFAULTS		Offset: OFFSET_D_EVENTS_DEFAULTS
// Description: 	contain default values ENUMs for events disable
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_EVENTS_DEFAULTS;

// Register: D_EVENTS_RESPOND		Offset: OFFSET_D_EVENTS_RESPOND
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DisableOutput       	:1; 	//If bit is set output is disabled
			ULONG32	CloseCoolantValves  	:1; 	//If bit is set Close Coolant Valves
			ULONG32	OpenCoolantValves   	:1; 	//If bit is set Open Coolant Valves
			ULONG32	ActivateThFan       	:1; 	//If bit is set activate TH fan
			ULONG32	DeactivateThFan     	:1; 	//If bit is set Deactivate TH fan
			ULONG32	ShutDownSut         	:1; 	//If bit is set activate Shut Down Sut
			ULONG32	ClosePurgeValves    	:1; 	//If bit is set Close Purge Valves
			ULONG32	DisableTecEnableBit 	:1;
			ULONG32	TecPowerOutLimited12v	:1;
			ULONG32	TjTcFallbackAct     	:1;
			ULONG32	TecPowerOutLimited  	:1;
			ULONG32	OpenMainValve       	:1;
			ULONG32	CloseMainValve      	:1;
			ULONG32	OpenHeadValve       	:1;
			ULONG32	CloseHeadValve      	:1;
			ULONG32	RESERVED0           	:17;
		} fields;
} UN_D_EVENTS_RESPOND;

// Register: D_EVENTS_CHECK_RESTART		Offset: OFFSET_D_EVENTS_CHECK_RESTART
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RestartEvent        	:32;
		} fields;
} UN_D_EVENTS_CHECK_RESTART;

//****************************************************************************
//* D_THERMAL_HEAD Unit Registers Description
//****************************************************************************

// Register: D_TH_SERIAL		Offset: OFFSET_D_TH_SERIAL
// Description: 	holds the Thermal Head serial number, 8 characters
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	SerialNumber        [16];
		} fields;
} UN_D_TH_SERIAL;

// Register: D_TH_MFG		Offset: OFFSET_D_TH_MFG
// Description: 	Thermal head manufacturer 
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	ThMfg               [16];
		} fields;
} UN_D_TH_MFG;

// Enumeration for field TECTYPE of register: D_TH_TYPE
#define TH_TEC_TYPE_12V     	0x00000000
#define TH_TEC_TYPE_24V     	0x00000001

// Register: D_TH_TYPE		Offset: OFFSET_D_TH_TYPE
// Description: 	BW - holds the type and features of the head
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TcaseType           	:2; 	//00 - TC T-Type, 
						                            //01 - TC K-Type, 
						                            //11 - RTD (PT1000)
						                            //
			ULONG32	TecType             	:2; 	//00 - 12v
						                            //01 - 24v
						                            //
						                            //
			ULONG32	RESERVED0           	:28;
		} fields;
} UN_D_TH_TYPE;

// Register: D_TH_TEC_EXP_IMP_1000T_DEC		Offset: OFFSET_D_TH_TEC_EXP_IMP_1000T_DEC
// Description: 	holds the Expected TEC impedance in decimat 1000T (not ascii)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Value               	:16; 	//Expected impedance 1000T decimal
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_TH_TEC_EXP_IMP_1000T_DEC;

// Register: D_TH_DATE_TIME		Offset: OFFSET_D_TH_DATE_TIME
// Description: 	Thermal Head mfg minutes passed from 1/1/96 00:00
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	DateTime            [6];
			UCHAR	RESERVED0           [10]; 	//Count the working hours
		} fields;
} UN_D_TH_DATE_TIME;

// Register: D_TH_RESET		Offset: OFFSET_D_TH_RESET
// Description: 	write to this register to reset the TH history
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_TH_RESET;

// Enumeration for field UPDATETHDATASOURCE of register: D_TH_GENERAL
#define GETSET_TH_SERIAL_NUMBER	0x00000001
#define GETSET_TH_WORK_CNT  	0x00000002
#define GETSET_TH_IMPEDANCE 	0x00000003
#define GETSET_TH_TYPE      	0x00000004
#define GETSET_TH_CONTROL_SET	0x00000005

// Register: D_TH_GENERAL		Offset: OFFSET_D_TH_GENERAL
typedef union {
	ULONG32 value;
		struct {
			ULONG32	UpdateTHDataStatus  	:1; 	//Indicate if Thermal head data should be updated
			ULONG32	UpdateTHDataSource  	:7; 	//Holds the indication of data source will be updated
			ULONG32	RESERVED0           	:24; 	//Holds the indication of data source will be updated
		} fields;
} UN_D_TH_GENERAL;

// Enumeration for field THERMALTOOLPOSITION of register: D_TH_STATUS
#define HEAD_UP             	0x00000001
#define HEAD_DOWN           	0x00000000

// Enumeration for field THEEPROMTYPE of register: D_TH_STATUS
#define TH_PPV_EEPROM       	0x00000001
#define TH_NOT_PPV_EEPROM   	0x00000000

// Register: D_TH_STATUS		Offset: OFFSET_D_TH_STATUS
// Description: 	Hold thermal hed statuses
typedef union {
	ULONG32 value;
		struct {
			ULONG32	ThermalToolPosition 	:1; 	//If the bit is set thermal head is UP
			ULONG32	ThermalSwitch       	:1; 	//If the bit is clear Thermal switch is actuated
			ULONG32	ThermalToolPositionFlowWip	:1; 	//If the bit is set thermal head UP flow is wip
			ULONG32	ThermalToolReconnected	:1; 	//If bits is set Thermal tool has been reconnected sinse the last InTEC power UP, the bit is cleared only after all TH data was found valid
			ULONG32	LowTecPsVoltage     	:1; 	//Mesured TEC PS voltage level under the TH Eprom cfg
			ULONG32	THEepromNotDetected 	:1; 	//bit is set when TH EEPROM is not detected
			ULONG32	ThermalHeadEEpromBusy	:1; 	//bit is set when TH EEPROM Passthrough interface is busy (writing or reading from TH EEPROM).
			ULONG32	ThDataWaitingToBeRead	:1; 	//If the bit is set request for TH eeprom data read was received
			ULONG32	ThDataWaitingToBeWrite	:1; 	//If the bit is set request for TH eeprom data write was received
			ULONG32	SendTHPacket        	:1; 	//If this bit is set InTEC Main sent packet to InTEC D
			ULONG32	CommOk              	:1; 	//The bits is always set
			ULONG32	ThermalHeadNotConnected	:1; 	//If bit is set thermal head not connected
			ULONG32	THEepromType        	:1; 	//If bit is set BLT eeprom was detected
			ULONG32	RESERVED0           	:19; 	//If the bit is set thermal head is UP
		} fields;
} UN_D_TH_STATUS;

// Enumeration for field RESERVED of register: D_TH_POSITION
#define HEAD_UP_DELAY       	0x000007d0

// Register: D_TH_POSITION		Offset: OFFSET_D_TH_POSITION
// Description: 	Holds the SP to wich the head should go and during with periude
typedef union {
	LONG32 value;
		struct {
			ULONG32	TtpSetpoint         	:8; 	//Holds the set point to be reached after the head is up
			ULONG32	TtpTimeout          	:8; 	//Holds the time out to reach the SP  in sec
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_TH_POSITION;

// Enumeration for field CMDTYPE of register: D_TH_EE_PT_WR
#define TH_EE_WRITE         	0x00000000

// Register: D_TH_EE_PT_WR		Offset: OFFSET_D_TH_EE_PT_WR
// Description: 	se this register for writing to the TH EEprom directly 
typedef union {
	UCHAR value[55];
		struct {
			ULONG32	RegAdd              	:16; 	//Register add to start write to
			ULONG32	CmdType             	:8; 	//(1=Rd, 0=Wr)
			ULONG32	DataLength          	:8;
			UCHAR	Data                [51];
		} fields;
} UN_D_TH_EE_PT_WR;

// Enumeration for field CMDTYPE of register: D_TH_EE_PT_RD
#define TH_EE_READ          	0x00000001

// Register: D_TH_EE_PT_RD		Offset: OFFSET_D_TH_EE_PT_RD
// Description: 	Use this register for reading the TH EEprom data 
typedef union {
	UCHAR value[55];
		struct {
			ULONG32	RegAdd              	:16; 	//TH EEprom add to read from
						                            //
			ULONG32	CmdType             	:8; 	//Read bytes to read from TH EEprom
			ULONG32	DataLength          	:8;
			UCHAR	Data                [51]; 	//Readed data
		} fields;
} UN_D_TH_EE_PT_RD;

// Register: D_TH_PRODUCT_NAME		Offset: OFFSET_D_TH_PRODUCT_NAME
// Description: 	Product name
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	ProductName         [16];
		} fields;
} UN_D_TH_PRODUCT_NAME;

// Register: D_TH_PN		Offset: OFFSET_D_TH_PN
// Description: 	Thermal head P/N
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	PartNumber          [16];
		} fields;
} UN_D_TH_PN;

// Register: D_TH_FRU_FILE_ID		Offset: OFFSET_D_TH_FRU_FILE_ID
// Description: 	Fru file ID
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	FruFileID           [16];
		} fields;
} UN_D_TH_FRU_FILE_ID;

// Register: D_TH_HEATSINK_TYPE		Offset: OFFSET_D_TH_HEATSINK_TYPE
// Description: 	 (Ascii) 
typedef union {
	LONG64 value;
		struct {
			ULONG64	RESERVED0           	:64;
		} fields;
} UN_D_TH_HEATSINK_TYPE;

// Register: D_TH_PRODUCT_TYPE		Offset: OFFSET_D_TH_PRODUCT_TYPE
// Description: 	ascii
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	ProductType         [16];
		} fields;
} UN_D_TH_PRODUCT_TYPE;

// Register: D_TH_PLATFORM_TYPE		Offset: OFFSET_D_TH_PLATFORM_TYPE
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	PlatformType        [16];
		} fields;
} UN_D_TH_PLATFORM_TYPE;

// Register: D_TH_SOCKET_TYPE		Offset: OFFSET_D_TH_SOCKET_TYPE
// Description: 	(Ascii) 
typedef union {
	LONG64 value;
		struct {
			ULONG64	RESERVED0           	:64;
		} fields;
} UN_D_TH_SOCKET_TYPE;

// Register: D_TH_MOO		Offset: OFFSET_D_TH_MOO
// Description: 	Mode of operation (Ascii) 
typedef union {
	LONG64 value;
		struct {
			ULONG64	RESERVED0           	:64;
		} fields;
} UN_D_TH_MOO;

// Register: D_TH_EXPECTED_IMP		Offset: OFFSET_D_TH_EXPECTED_IMP
// Description: 	Expected impedance
// 	(Ascii) - 00.489
typedef union {
	UCHAR value[6];
		struct {
			UCHAR	RESERVED0           [6];
		} fields;
} UN_D_TH_EXPECTED_IMP;

// Register: D_TH_TCASE_TYPE		Offset: OFFSET_D_TH_TCASE_TYPE
typedef union {
	LONG64 value;
		struct {
			ULONG64	RESERVED0           	:64;
		} fields;
} UN_D_TH_TCASE_TYPE;

// Register: D_TH_TCASE_NUM		Offset: OFFSET_D_TH_TCASE_NUM
typedef union {
	LONG32 value;
		struct {
			ULONG32	TcaseNumber         	:8;
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_D_TH_TCASE_NUM;

// Register: D_TH_VMAX		Offset: OFFSET_D_TH_VMAX
typedef union {
	UCHAR value[5];
		struct {
			UCHAR	RESERVED0           [5];
		} fields;
} UN_D_TH_VMAX;

// Register: D_TH_RAMP_RATE_LIMIT		Offset: OFFSET_D_TH_RAMP_RATE_LIMIT
// Description: 	heat/cool ramp rate limitation for thermal head 
// 	format (ascii): 100Deg/Min
typedef union {
	UCHAR value[10];
		struct {
			UCHAR	RESERVED0           [10];
		} fields;
} UN_D_TH_RAMP_RATE_LIMIT;

// Register: D_TH_P_FACT		Offset: OFFSET_D_TH_P_FACT
typedef union {
	UCHAR value[6];
		struct {
			UCHAR	RESERVED0           [6];
		} fields;
} UN_D_TH_P_FACT;

// Register: D_TH_I_FACT		Offset: OFFSET_D_TH_I_FACT
typedef union {
	UCHAR value[6];
		struct {
			UCHAR	RESERVED0           [6];
		} fields;
} UN_D_TH_I_FACT;

// Register: D_TH_D_FACT		Offset: OFFSET_D_TH_D_FACT
typedef union {
	UCHAR value[6];
		struct {
			UCHAR	RESERVED0           [6];
		} fields;
} UN_D_TH_D_FACT;

// Register: D_TH_TEC_PN		Offset: OFFSET_D_TH_TEC_PN
// Description: 	TEC Part  Number
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	TecPN               [16];
		} fields;
} UN_D_TH_TEC_PN;

// Register: D_TH_EE_VER		Offset: OFFSET_D_TH_EE_VER
// Description: 	TH EEPROM file version
typedef union {
	ULONG32 value;
		struct {
			ULONG32	THEepromFileVer     	:32;
		} fields;
} UN_D_TH_EE_VER;

// Register: D_TH_UP_SENSOR		Offset: OFFSET_D_TH_UP_SENSOR
// Description: 	Holds if TH UP sensor is connected
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_TH_UP_SENSOR;

// Register: D_TH_TEC_IMPEDANCE		Offset: OFFSET_D_TH_TEC_IMPEDANCE
// Description: 	holds the TEC impedance from the last measurement
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Measurement         	:16; 	//Impedance measuremen
			ULONG32	StartImpMes         	:1; 	//Set the bit for impedance mesurment , the bit will cleared after finish
			ULONG32	RESERVED0           	:15; 	//Set the bit for impedance mesurment , the bit will cleared after finish
		} fields;
} UN_D_TH_TEC_IMPEDANCE;

// Register: D_TH_HEATEC		Offset: OFFSET_D_TH_HEATEC
// Description: 	holds the TEC impedance from the last measurement
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_TH_HEATEC;

// Register: D_TH_V_HEATEC_MAX		Offset: OFFSET_D_TH_V_HEATEC_MAX
typedef union {
	UCHAR value[5];
		struct {
			UCHAR	RESERVED0           [5];
		} fields;
} UN_D_TH_V_HEATEC_MAX;

//****************************************************************************
//* D_TESTABILITY Unit Registers Description
//****************************************************************************

// Register: D_TESTABILITY_START		Offset: OFFSET_D_TESTABILITY_START
// Description: 	write to this register to start InTEC_D selftest, set the appropriate bit for the required test.
// 	Note: use the required HW & cables for each test. 
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	BenchStart          	:1; 	//start bench selftest, selftest HW/cables are required. bit is cleared at the end of the test.
			ULONG32	StandaloneStart     	:1; 	//start Standalone selftest, no special HW/cable required. bit is cleared at the end of the test.
			ULONG32	BasicFuncStart      	:1; 	//start Basic Functionality test, InTEC requires TH & platform connectivity. bit is cleared at the end of the test.
			ULONG32	THBenchStart        	:1; 	//start TH bench selftest, selftest HW/cables are required. bit is cleared at the end of the test.
			ULONG32	TECImpedanceTestStart	:1; 	//  
			ULONG32	WaterModuleBenchStart	:1; 	//start Water Module bench selftest, selftest HW/cables are required. bit is cleared at the end of the test.
			ULONG32	RESERVED0           	:26;
		} fields;
} UN_D_TESTABILITY_START;

// Register: D_TESTABILITY_ABORT		Offset: OFFSET_D_TESTABILITY_ABORT
// Description: 	set the appropriate bit to abort the test.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	BenchAbort          	:1; 	//set to abort the bench selftest. bit is cleared at the start of new test.
			ULONG32	StandaloneAbort     	:1; 	//set to abort the standalone selftest. bit is cleared at the start of new test.
			ULONG32	BasicFuncAbort      	:1; 	//set to abort the basic functionality test. bit is cleared at the start of new test.
			ULONG32	THBenchAbort        	:1; 	//set to abort the bench selftest. bit is cleared at the start of new test.
			ULONG32	WaterModuleBenchAbort	:1; 	//set to abort the bench selftest. bit is cleared at the start of new test.
			ULONG32	RESERVED0           	:27;
		} fields;
} UN_D_TESTABILITY_ABORT;

// Register: D_BENCH_TEST_STATUS		Offset: OFFSET_D_BENCH_TEST_STATUS
// Description: 	Contains the Bench selftest status and result. Reading this register will give the last selftest results (stored in ROM).
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TestRun             	:1; 	//Test running if set. bit is cleared when test ended.
			ULONG32	TestEnded           	:1; 	//Test Ended if set. bit is cleared at the start of new test.
			ULONG32	TestPass            	:1; 	//Test finished successfuly (no errors) if set. bit is cleared if one of the modules has error. bit is cleared at the start of new test.
			ULONG32	AdcTC1TC2Err        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	AdcTC3CPErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	EepromErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	DAC1Err             	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	DAC2Err             	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	IOErr               	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(require Ping from host)
			ULONG32	FANDriverErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	UISenseErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	HISSenseErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	TECSafeErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(requires USB host transaction).
			ULONG32	TECPSRelayErr       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	PWMOutErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	TECOutErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	TECCurrentErr       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	Actuations1Err      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	Actuations2Err      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	Actuations3Err      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	Actuations4Err      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	ValveControl1Err    	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(requires user interaction)
			ULONG32	ValveControl2Err    	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(requires user interaction)
			ULONG32	AnalogOut1Err       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	AnalogOut2Err       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	AnalogOut3Err       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	ChillerRelayErr     	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	DUTPSRelayErr       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(PECI Mux Ctrl, PECI Monitor, Switch & Mux)
			ULONG32	PurgeRelayErr       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(Internal Vtt, PECI Rx/Tx, Level Shift & Switch)
			ULONG32	ImpedanceMesErr     	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	RESERVED0           	:2; 	//dev failed test if bit set. bit is cleared at the start of new test.
		} fields;
} UN_D_BENCH_TEST_STATUS;

// Register: D_STANDALONE_TEST_STATUS		Offset: OFFSET_D_STANDALONE_TEST_STATUS
// Description: 	Contains the Standalone selftest status and result. Reading this register will give the last selftest results (stored in ROM).
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TestRun             	:1; 	//Test running if set. bit is cleared when test ended.
			ULONG32	TestEnded           	:1; 	//Test Ended if set. bit is cleared at the start of new test.
			ULONG32	TestPass            	:1; 	//Test finished successfuly (no errors) if set. bit is cleared if one of the modules has error. bit is cleared at the start of new test.
			ULONG32	AdcErr              	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	EepromErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	FlashErr            	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	LcdErr              	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	IoExpErr            	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	RESERVED0           	:1;
			ULONG32	I2cMasterErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	SpiMasterErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	RESERVED1           	:2;
			ULONG32	CurrentSrcErr       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	FastCalErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	RESERVED2           	:10;
			ULONG32	PeciMcuErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	RESERVED3           	:2;
			ULONG32	PeciCircuitErr      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(Internal Vtt, PECI Rx/Tx, Level Shift & Switch)
			ULONG32	TdauErr             	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	RESERVED4           	:2;
		} fields;
} UN_D_STANDALONE_TEST_STATUS;

// Register: D_BASIC_FUNC_TEST_STATUS_1		Offset: OFFSET_D_BASIC_FUNC_TEST_STATUS_1
// Description: 	Contains the basic functionality test status and result. Reading this register will give the last test results (stored in ROM).
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TestRun             	:1; 	//Test running if set. bit is cleared when test ended.
			ULONG32	TestEnded           	:1; 	//Test Ended if set. bit is cleared at the start of new test.
			ULONG32	TestPass            	:1; 	//Test finished successfuly (no errors) if set. bit is cleared if one of the modules has error. bit is cleared at the start of new test.
			ULONG32	AdcErr              	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	EepromErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	FlashErr            	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	LcdErr              	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	IoExpErr            	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	EternetErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(require Ping from host)
			ULONG32	I2cMasterErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	SpiMasterErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	UartErr             	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	UsbErr              	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(requires USB host transaction).
			ULONG32	CurrentSrcErr       	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	FastCalErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	ArmBtnErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	UpBtnErr            	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	DownBtnErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	SelectBtnErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	RunLedErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	FailLedErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	SevSegErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(requires user interaction)
			ULONG32	DetLedsErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(requires user interaction)
			ULONG32	PfErr               	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	ProchotErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	PeciMcuErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	PeciMonitorErr      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	PeciCtrlErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(PECI Mux Ctrl, PECI Monitor, Switch & Mux)
			ULONG32	PeciCircuitErr      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(Internal Vtt, PECI Rx/Tx, Level Shift & Switch)
			ULONG32	TdauErr             	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	RESERVED0           	:2;
		} fields;
} UN_D_BASIC_FUNC_TEST_STATUS_1;

// Enumeration for field PASSORFAIL of register: D_TESTABILITY_MASKS
#define D_TESTABILITY_ERROR_CHECK_MASK	0xfffffff8

// Register: D_TESTABILITY_MASKS		Offset: OFFSET_D_TESTABILITY_MASKS
// Description: 	hold masks for checking pass/fail results for FW
typedef union {
	LONG64 value;
		struct {
			ULONG32	PassOrFail          	:32;
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_TESTABILITY_MASKS;

// Register: D_TH_BENCH_TEST_STATUS		Offset: OFFSET_D_TH_BENCH_TEST_STATUS
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TestStarted         	:1; 	//set if test had been started
			ULONG32	TestEnded           	:1; 	//set if test ended
			ULONG32	TestPassed          	:1; 	//set if test passed
			ULONG32	TestFailed          	:1; 	//set if test failed
			ULONG32	TermistorErr        	:1; 	//set if test failed
			ULONG32	TCErr               	:1; 	//set if test failed
			ULONG32	TECErr              	:1; 	//set if test failed
			ULONG32	EEPROMErr           	:1; 	//set if test failed
			ULONG32	RTDErr              	:1; 	//set if test failed
			ULONG32	FanErr              	:1; 	//set if test failed
			ULONG32	LeakSensorErr       	:1; 	//set if test failed
			ULONG32	TTpositionErr       	:1; 	//set if test failed
			ULONG32	AirFlowControlErr   	:1; 	//set if test failed
			ULONG32	RESERVED0           	:19; 	//set if test failed
		} fields;
} UN_D_TH_BENCH_TEST_STATUS;

// Register: D_TESTABILITY_GEN_STAT		Offset: OFFSET_D_TESTABILITY_GEN_STAT
// Description: 	General status of selftest
typedef union {
	ULONG32 value;
		struct {
			ULONG32	SelfTestCablesConnected	:1; 	//If bit is set - self test cables connected
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_D_TESTABILITY_GEN_STAT;

// Register: D_IMPEDANCE_MES_RESULT		Offset: OFFSET_D_IMPEDANCE_MES_RESULT
// Description: 	Hold the Impedance mesurment result
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Measurement         	:16;
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_D_IMPEDANCE_MES_RESULT;

// Register: D_IMPEDANCE_MES_STATUS		Offset: OFFSET_D_IMPEDANCE_MES_STATUS
// Description: 	Hold the mesurment status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	ImpedanceMesStatus  	:1; 	//If bit is set - Impedance mesurment has failed due to not reaching to safety voltage levels
			ULONG32	Valid               	:1; 	//If bit is set - Impedance mesurment from last test is valid, 
			ULONG32	RESERVED0           	:30;
		} fields;
} UN_D_IMPEDANCE_MES_STATUS;

// Register: D_WATER_MODULE_BENCH_TEST_STATUS		Offset: OFFSET_D_WATER_MODULE_BENCH_TEST_STATUS
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TestStarted         	:1; 	//set if test had been started
			ULONG32	TestEnded           	:1; 	//set if test ended
			ULONG32	TestPassed          	:1; 	//set if test passed
			ULONG32	ADCErr              	:1; 	//set if test failed
			ULONG32	EEPROMErr           	:1; 	//set if test failed
			ULONG32	ImpCh0Err           	:1; 	//set if test failed
			ULONG32	ImpCh1Err           	:1; 	//set if test failed
			ULONG32	ImpCh2Err           	:1; 	//set if test failed
			ULONG32	ImpCh3Err           	:1; 	//set if test failed
			ULONG32	AlertOutErr         	:1; 	//set if test failed
			ULONG32	Relay3v3Err         	:1; 	//set if test failed
			ULONG32	RelayI2CErr         	:1; 	//set if test failed
			ULONG32	RelayChillerStopErr 	:1; 	//set if test failed
			ULONG32	MainValveErr        	:1; 	//set if test failed
			ULONG32	Relay12vErr         	:1; 	//set if test failed
			ULONG32	Timeout             	:1; 	//set if test failed
			ULONG32	RESERVED0           	:16; 	//set if test failed
		} fields;
} UN_D_WATER_MODULE_BENCH_TEST_STATUS;

// Register: D_WATER_MODULE_BENCH_TEST_IMP_RESULT 		Offset: OFFSET_D_WATER_MODULE_BENCH_TEST_IMP_RESULT 
typedef union {
	LONG64 value;
		struct {
			ULONG32	Ch0                 	:16;
			ULONG32	Ch1                 	:16;
			ULONG32	Ch2                 	:16;
			ULONG32	Ch3                 	:16;
		} fields;
} UN_D_WATER_MODULE_BENCH_TEST_IMP_RESULT ;

//****************************************************************************
//* D_WATER_MODULE Unit Registers Description
//****************************************************************************

// Register: D_WATER_MODULE_GENERAL		Offset: OFFSET_D_WATER_MODULE_GENERAL
// Description: 	Holds general data of the water module
typedef union {
	ULONG32 value;
		struct {
			ULONG32	WaterModuleConnected	:1; 	//If bit is set water module connected
			ULONG32	WaterModuleReadyForMeasure	:1; 	//If bit is set water module connected
						                            //initialized and ready for starting measur
			ULONG32	EnableWaterModule   	:1; 	//If bit is set water module will be enabled by triggering actuation 2 bit
			ULONG32	DataReady           	:1; 	//New Channels data (Enabled/Imp result) is available .
			ULONG32	RESERVED0           	:28;
		} fields;
} UN_D_WATER_MODULE_GENERAL;

// Register: D_WATER_MODULE_LIMITS 		Offset: OFFSET_D_WATER_MODULE_LIMITS 
// Description: 	Holds water module data
typedef union {
	UCHAR value[16];
		struct {
			ULONG32	LeakWmCh0ImpLimit   	:16; 	//Holds impedance mesurment for CH0 (Spare)
			ULONG32	LeakWmCh0TimeTillEventOn	:16; 	//Holds time till event on  for CH0 (Spare)
			ULONG32	LeakWaterModuleImpLimit	:16; 	//Holds impedance mesurment for Water Module internal leak (CH1)
			ULONG32	LeakWaterModuleTimeTillEventOn	:16; 	//Holds time till event on  for Water module internal leak (CH1)
			ULONG32	LeakChillerImpLimit 	:16; 	//Holds impedance mesurment for Chiller leak (CH2)
			ULONG32	LeakChillerTimeTillEventOn	:16; 	//Holds time till event on  for Chiller leak (CH1)
			ULONG32	LeakFloorImpLimit   	:16; 	//Holds impedance mesurment for Floor leak (CH3)
			ULONG32	LeakFloorTimeTillEventOn	:16; 	//Holds time till event on  for Floorleak (CH1)
		} fields;
} UN_D_WATER_MODULE_LIMITS ;

// Register: D_WATER_MODULE_LIMITS_DUMMY		Offset: OFFSET_D_WATER_MODULE_LIMITS_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_WATER_MODULE_LIMITS_DUMMY;

// Register: D_WATER_MODULE_LIMITS_DUMMY_1		Offset: OFFSET_D_WATER_MODULE_LIMITS_DUMMY_1
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_WATER_MODULE_LIMITS_DUMMY_1;

// Register: D_WATER_MODULE_LIMITS_DUMMY_2		Offset: OFFSET_D_WATER_MODULE_LIMITS_DUMMY_2
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_WATER_MODULE_LIMITS_DUMMY_2;

// Register: D_WATER_MODULE_IMP_RESULT 		Offset: OFFSET_D_WATER_MODULE_IMP_RESULT 
// Description: 	Holds the water module channels impedance measure
// 	          
typedef union {
	UCHAR value[10];
		struct {
			ULONG32	CH0ImpMeasEnabled   	:1; 	//If bit is set the channel is enabled
			ULONG32	WaterModuleImpMeasEnabled	:1; 	//If bit is set the channel is enabled
			ULONG32	ChillerImpMeasEnabled	:1; 	//If bit is set the channel is enabled
			ULONG32	FloorImpMeasEnabled 	:1; 	//If bit is set the channel is enabled
			ULONG32	RESERVED0           	:12; 	//If bit is set the channel is enabled
			ULONG32	CH0Imp              	:16; 	//Holds the impedance measurement
			ULONG32	WaterModuleImp      	:16; 	//Holds the impedance measurement
			ULONG32	ChillerImp          	:16; 	//Holds the impedance measurement
			ULONG32	FloorImp            	:16; 	//Holds the impedance measurement
		} fields;
} UN_D_WATER_MODULE_IMP_RESULT ;

// Register: D_WATER_MODULE_CONTROL 		Offset: OFFSET_D_WATER_MODULE_CONTROL 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	ReadRequest         	:1; 	//set this bit to read channels data from the water module (impedance)
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_D_WATER_MODULE_CONTROL ;

//****************************************************************************
//* D_PHASE_CHANGE Unit Registers Description
//****************************************************************************

// Enumeration for field REGISTERS of register: D_PHASE_CHANGE_GENERAL
#define PHASE_CHANGE_GET_VERSION	0x00000000
#define PHASE_CHANGE_GET_STATUS	0x00000001
#define PHASE_CHANGE_SET_POINT	0x00000010
#define PHASE_CHANGE_SET_FB_TEMP	0x00000011
#define PHASE_CHANGE_CFG    	0x00000012
#define PHASE_CHANGE_ADD    	0x0000003e

// Register: D_PHASE_CHANGE_GENERAL		Offset: OFFSET_D_PHASE_CHANGE_GENERAL
// Description: 	Holds the General data about the phase chage
typedef union {
	LONG32 value;
		struct {
			ULONG32	FwVersion10T        	:16;
			ULONG32	Registers           	:16;
		} fields;
} UN_D_PHASE_CHANGE_GENERAL;

// Register: D_PHASE_CHANGE_STATUS		Offset: OFFSET_D_PHASE_CHANGE_STATUS
// Description: 	Holds the statuses if the PhaseChange
typedef union {
	ULONG32 value;
		struct {
			ULONG32	OutputStable        	:1; 	//PhaseChange output is stable if bit it set
			ULONG32	Cooling             	:1; 	//PhaseChange Cooling if bit it set
			ULONG32	Heating             	:1; 	//PhaseChange Heating if bit it set
			ULONG32	PowerUpDown         	:1; 	//PhaseChange Output On but during power-up/down it set
			ULONG32	RESERVED0           	:1; 	//PhaseChange Output On but during power-up/down it set
			ULONG32	ErrorDetected       	:1; 	//PhaseChange Has an Error if bit it set (see Error Code for details)
			ULONG32	OutputOn            	:1; 	//PhaseChange Output is on if bit it set (reply on I2C ready for heat/cool)
			ULONG32	OutputOff           	:1; 	//PhaseChange Output off if bit it set (reply on I2C but not ready for heat/cool)
			ULONG32	Connected           	:1; 	//if bit is set the PahseChage is connected
			ULONG32	RESERVED1           	:23; 	//if bit is set the PahseChage is connected
		} fields;
} UN_D_PHASE_CHANGE_STATUS;

// Register: D_PHASE_CHANGE_ERROR		Offset: OFFSET_D_PHASE_CHANGE_ERROR
// Description: 	Holds the errors from the PhaseChange
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_D_PHASE_CHANGE_ERROR;

//****************************************************************************
//* Units Description
//****************************************************************************

// Unit: D_GENERAL		Offset: OFFSET_UNIT_D_GENERAL
typedef struct ST_D_GENERAL{
	UN_D_FW_VERSION D_FW_VERSION;
	UN_D_DEVICE_TYPE D_DEVICE_TYPE;
	UN_D_TIMESTAMP D_TIMESTAMP;
	UN_D_RESET_TIMESTAMP D_RESET_TIMESTAMP;
	UN_D_HW_CFG D_HW_CFG;
	UN_D_SERIAL D_SERIAL;
	UN_D_SERIAL_DUMMY D_SERIAL_DUMMY;
	UN_D_SYS_ERR_STATUS D_SYS_ERR_STATUS;
	UN_D_DEVICE_NAME D_DEVICE_NAME;
	UN_D_DEVICE_NAME_DUMMY D_DEVICE_NAME_DUMMY;
	UN_D_DEVICE_NAME_DUMMY_0 D_DEVICE_NAME_DUMMY_0;
	UN_D_DEVICE_NAME_DUMMY_1 D_DEVICE_NAME_DUMMY_1;
	UN_D_SW_RESET D_SW_RESET;
	UN_D_WORK_MODE D_WORK_MODE;
	UN_D_UPDATE_CFG D_UPDATE_CFG;
	UN_D_DEVICE_TYPE_LEGACY D_DEVICE_TYPE_LEGACY;
	UN_D_GENERAL_STATUS D_GENERAL_STATUS;
	UN_D_GENERAL_UPDATE D_GENERAL_UPDATE;
} ST_D_GENERAL_T;

// Unit: D_BOOTLOADING		Offset: OFFSET_UNIT_D_BOOTLOADING
typedef struct ST_D_BOOTLOADING{
	UN_D_BOOTLOADING_STATUS D_BOOTLOADING_STATUS;
	UN_D_BOOTLOADING_ENTER D_BOOTLOADING_ENTER;
	UN_D_BOOTLOADING_ABORT D_BOOTLOADING_ABORT;
	UN_D_BOOTLOADING_GET_DATA_FROM_DEV D_BOOTLOADING_GET_DATA_FROM_DEV;
	UN_D_BOOTLOADING_SEND_DATA_TO_DEV D_BOOTLOADING_SEND_DATA_TO_DEV;
} ST_D_BOOTLOADING_T;

// Unit: D_CASE		Offset: OFFSET_UNIT_D_CASE
typedef struct ST_D_CASE{
	UN_D_CASE_CFG D_CASE_CFG;
	UN_D_CFG_CASE0 D_CFG_CASE0;
	UN_D_CFG_CASE1 D_CFG_CASE1;
	UN_D_CFG_CASE2 D_CFG_CASE2;
	UN_D_CFG_CASE3 D_CFG_CASE3;
	UN_D_CASE_STATUS D_CASE_STATUS;
	UN_D_TCASE0 D_TCASE0;
	UN_D_TCASE1 D_TCASE1;
	UN_D_TCASE2 D_TCASE2;
	UN_D_TCASE3 D_TCASE3;
	UN_D_GET_ALL_TCASES D_GET_ALL_TCASES;
} ST_D_CASE_T;

// Unit: D_CONTROL		Offset: OFFSET_UNIT_D_CONTROL
typedef struct ST_D_CONTROL{
	UN_D_PID_LOOP_PWM_CALC D_PID_LOOP_PWM_CALC;
	UN_D_PID_COEF D_PID_COEF;
	UN_D_TEC_CONTROL D_TEC_CONTROL;
	UN_D_TEC_STATUS D_TEC_STATUS;
	UN_D_FEEDBACK_CONTROL D_FEEDBACK_CONTROL;
	UN_D_FEEDBACK_CONTROL_DUMMY D_FEEDBACK_CONTROL_DUMMY;
	UN_D_FEEDBACK_CONTROL_DUMMY_1 D_FEEDBACK_CONTROL_DUMMY_1;
	UN_D_FEEDBACK_CONTROL_DUMMY_2 D_FEEDBACK_CONTROL_DUMMY_2;
	UN_D_FEEDBACK_STATUS D_FEEDBACK_STATUS;
	UN_D_FEEDBACK_TEMP D_FEEDBACK_TEMP;
	UN_D_FEEDBACK_SETPOINT D_FEEDBACK_SETPOINT;
	UN_D_FEEDBACK_JUNCTION_TEMP D_FEEDBACK_JUNCTION_TEMP;
	UN_D_POWER_OUT_SENSE D_POWER_OUT_SENSE;
	UN_D_FEEDBACK_DELTA_CFG D_FEEDBACK_DELTA_CFG;
	UN_D_CONTROL_MODULE_TEMP D_CONTROL_MODULE_TEMP;
	UN_D_ANALOG_OUT D_ANALOG_OUT;
	UN_D_FEEDBACK_LIMITS D_FEEDBACK_LIMITS;
	UN_D_FEEDBACK_LIMITS_DUMMY D_FEEDBACK_LIMITS_DUMMY;
	UN_D_FEEDBACK_LIMITS_DUMMY_1 D_FEEDBACK_LIMITS_DUMMY_1;
	UN_D_FEEDBACK_LIMITS_DUMMY_2 D_FEEDBACK_LIMITS_DUMMY_2;
	UN_D_FEEDBACK_LIMITS_DUMMY_3 D_FEEDBACK_LIMITS_DUMMY_3;
	UN_D_FEEDBACK_LIMITS_DUMMY_4 D_FEEDBACK_LIMITS_DUMMY_4;
	UN_D_FEEDBACK_MAX_MIN_TEMP D_FEEDBACK_MAX_MIN_TEMP;
	UN_D_CONTROL_MISC_CFG D_CONTROL_MISC_CFG;
	UN_D_CONTROL_OPEN_LOOP_CFG D_CONTROL_OPEN_LOOP_CFG;
	UN_D_CONTROL_PRBS_CFG D_CONTROL_PRBS_CFG;
	UN_D_TEC_OUT_VMAX D_TEC_OUT_VMAX;
	UN_D_FEEDBACK_AVG_STDEV_TEMP D_FEEDBACK_AVG_STDEV_TEMP;
	UN_D_FEEDBACK_TJ_ALLOC D_FEEDBACK_TJ_ALLOC;
	UN_D_RAMP_RATE_CONTROL D_RAMP_RATE_CONTROL;
	UN_D_VAR_SP D_VAR_SP;
	UN_D_GANG_CFG D_GANG_CFG;
} ST_D_CONTROL_T;

// Unit: D_ENVIRONMENT		Offset: OFFSET_UNIT_D_ENVIRONMENT
typedef struct ST_D_ENVIRONMENT{
	UN_D_ACTUATION D_ACTUATION;
	UN_D_LEAKAGE D_LEAKAGE;
	UN_D_COOLANT D_COOLANT;
	UN_D_COOLANT_DUMMY D_COOLANT_DUMMY;
	UN_D_COOLANT_DUMMY_1 D_COOLANT_DUMMY_1;
	UN_D_PURGE D_PURGE;
	UN_D_PURGE_DUMMY D_PURGE_DUMMY;
	UN_D_ENV_STATUS D_ENV_STATUS;
	UN_D_LEAK_BOARD D_LEAK_BOARD;
	UN_D_LEAK_BOARD_LIMITS D_LEAK_BOARD_LIMITS;
} ST_D_ENVIRONMENT_T;

// Unit: D_EVENTS		Offset: OFFSET_UNIT_D_EVENTS
typedef struct ST_D_EVENTS{
	UN_D_FAILURES_STATUS D_FAILURES_STATUS;
	UN_D_WARNINGS_STATUS D_WARNINGS_STATUS;
	UN_D_NOTIFICATION_STATUS D_NOTIFICATION_STATUS;
	UN_D_FAILURES_DISABLE D_FAILURES_DISABLE;
	UN_D_WARNINGS_DISABLE D_WARNINGS_DISABLE;
	UN_D_NOTIFICATION_DISABLE D_NOTIFICATION_DISABLE;
	UN_D_EVENTS_DEFAULTS D_EVENTS_DEFAULTS;
	UN_D_EVENTS_RESPOND D_EVENTS_RESPOND;
	UN_D_EVENTS_CHECK_RESTART D_EVENTS_CHECK_RESTART;
} ST_D_EVENTS_T;

// Unit: D_THERMAL_HEAD		Offset: OFFSET_UNIT_D_THERMAL_HEAD
typedef struct ST_D_THERMAL_HEAD{
	UN_D_TH_SERIAL D_TH_SERIAL;
	UN_D_TH_MFG D_TH_MFG;
	UN_D_TH_TYPE D_TH_TYPE;
	UN_D_TH_TEC_EXP_IMP_1000T_DEC D_TH_TEC_EXP_IMP_1000T_DEC;
	UN_D_TH_DATE_TIME D_TH_DATE_TIME;
	UN_D_TH_RESET D_TH_RESET;
	UN_D_TH_GENERAL D_TH_GENERAL;
	UN_D_TH_STATUS D_TH_STATUS;
	UN_D_TH_POSITION D_TH_POSITION;
	UN_D_TH_EE_PT_WR D_TH_EE_PT_WR;
	UN_D_TH_EE_PT_RD D_TH_EE_PT_RD;
	UN_D_TH_PRODUCT_NAME D_TH_PRODUCT_NAME;
	UN_D_TH_PN D_TH_PN;
	UN_D_TH_FRU_FILE_ID D_TH_FRU_FILE_ID;
	UN_D_TH_HEATSINK_TYPE D_TH_HEATSINK_TYPE;
	UN_D_TH_PRODUCT_TYPE D_TH_PRODUCT_TYPE;
	UN_D_TH_PLATFORM_TYPE D_TH_PLATFORM_TYPE;
	UN_D_TH_SOCKET_TYPE D_TH_SOCKET_TYPE;
	UN_D_TH_MOO D_TH_MOO;
	UN_D_TH_EXPECTED_IMP D_TH_EXPECTED_IMP;
	UN_D_TH_TCASE_TYPE D_TH_TCASE_TYPE;
	UN_D_TH_TCASE_NUM D_TH_TCASE_NUM;
	UN_D_TH_VMAX D_TH_VMAX;
	UN_D_TH_RAMP_RATE_LIMIT D_TH_RAMP_RATE_LIMIT;
	UN_D_TH_P_FACT D_TH_P_FACT;
	UN_D_TH_I_FACT D_TH_I_FACT;
	UN_D_TH_D_FACT D_TH_D_FACT;
	UN_D_TH_TEC_PN D_TH_TEC_PN;
	UN_D_TH_EE_VER D_TH_EE_VER;
	UN_D_TH_UP_SENSOR D_TH_UP_SENSOR;
	UN_D_TH_TEC_IMPEDANCE D_TH_TEC_IMPEDANCE;
	UN_D_TH_HEATEC D_TH_HEATEC;
	UN_D_TH_V_HEATEC_MAX D_TH_V_HEATEC_MAX;
} ST_D_THERMAL_HEAD_T;

// Unit: D_TESTABILITY		Offset: OFFSET_UNIT_D_TESTABILITY
typedef struct ST_D_TESTABILITY{
	UN_D_TESTABILITY_START D_TESTABILITY_START;
	UN_D_TESTABILITY_ABORT D_TESTABILITY_ABORT;
	UN_D_BENCH_TEST_STATUS D_BENCH_TEST_STATUS;
	UN_D_STANDALONE_TEST_STATUS D_STANDALONE_TEST_STATUS;
	UN_D_BASIC_FUNC_TEST_STATUS_1 D_BASIC_FUNC_TEST_STATUS_1;
	UN_D_TESTABILITY_MASKS D_TESTABILITY_MASKS;
	UN_D_TH_BENCH_TEST_STATUS D_TH_BENCH_TEST_STATUS;
	UN_D_TESTABILITY_GEN_STAT D_TESTABILITY_GEN_STAT;
	UN_D_IMPEDANCE_MES_RESULT D_IMPEDANCE_MES_RESULT;
	UN_D_IMPEDANCE_MES_STATUS D_IMPEDANCE_MES_STATUS;
	UN_D_WATER_MODULE_BENCH_TEST_STATUS D_WATER_MODULE_BENCH_TEST_STATUS;
	UN_D_WATER_MODULE_BENCH_TEST_IMP_RESULT  D_WATER_MODULE_BENCH_TEST_IMP_RESULT ;
} ST_D_TESTABILITY_T;

// Unit: D_WATER_MODULE		Offset: OFFSET_UNIT_D_WATER_MODULE
typedef struct ST_D_WATER_MODULE{
	UN_D_WATER_MODULE_GENERAL D_WATER_MODULE_GENERAL;
	UN_D_WATER_MODULE_LIMITS  D_WATER_MODULE_LIMITS ;
	UN_D_WATER_MODULE_LIMITS_DUMMY D_WATER_MODULE_LIMITS_DUMMY;
	UN_D_WATER_MODULE_LIMITS_DUMMY_1 D_WATER_MODULE_LIMITS_DUMMY_1;
	UN_D_WATER_MODULE_LIMITS_DUMMY_2 D_WATER_MODULE_LIMITS_DUMMY_2;
	UN_D_WATER_MODULE_IMP_RESULT  D_WATER_MODULE_IMP_RESULT ;
	UN_D_WATER_MODULE_CONTROL  D_WATER_MODULE_CONTROL ;
} ST_D_WATER_MODULE_T;

// Unit: D_PHASE_CHANGE		Offset: OFFSET_UNIT_D_PHASE_CHANGE
typedef struct ST_D_PHASE_CHANGE{
	UN_D_PHASE_CHANGE_GENERAL D_PHASE_CHANGE_GENERAL;
	UN_D_PHASE_CHANGE_STATUS D_PHASE_CHANGE_STATUS;
	UN_D_PHASE_CHANGE_ERROR D_PHASE_CHANGE_ERROR;
} ST_D_PHASE_CHANGE_T;

#endif //INTEC_D_DWDEFS_H

