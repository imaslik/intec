#ifndef INTEC_DWDEFS_H
#define INTEC_DWDEFS_H

#pragma pack(push, 1)                       // force byte alignment
// -------------------------------------------------------------------------
// Register and Field Definitions
// -------------------------------------------------------------------------
#define	UNIT_GENERAL             	0
#define	UNIT_BOOTLOADING         	1
#define	UNIT_JUNCTION            	2
#define	UNIT_CASE                	3
#define	UNIT_CONTROL             	4
#define	UNIT_TESTABILITY         	5
#define	UNIT_TESTER              	6
#define	UNIT_HIF                 	7
#define	UNIT_FRU                 	8

// Unit Offsets Definitions
#define	OFFSET_UNIT_GENERAL                    	0x00
#define	OFFSET_UNIT_BOOTLOADING                	0x100
#define	OFFSET_UNIT_JUNCTION                   	0x200
#define	OFFSET_UNIT_CASE                       	0x300
#define	OFFSET_UNIT_CONTROL                    	0x400
#define	OFFSET_UNIT_TESTABILITY                	0x500
#define	OFFSET_UNIT_TESTER                     	0x600
#define	OFFSET_UNIT_HIF                        	0x700
#define	OFFSET_UNIT_FRU                        	0xF00

//	UNIT GENERAL registers
#define	OFFSET_FW_VERSION          	0x00
#define	OFFSET_GET_ALL_FW_VERSIONS 	0x01
#define	OFFSET_DEVICE_TYPE         	0x02
#define	OFFSET_RESET_TIMESTAMP     	0x04
#define	OFFSET_INTEC_HW_CFG        	0x05
#define	OFFSET_INTEC_TIMESTAMP     	0x03
#define	OFFSET_INTEC_SERIAL        	0x06
#define	OFFSET_INTEC_SERIAL_DUMMY  	0x07
#define	OFFSET_INTEC_SERIAL_DUMMY_1	0x08
#define	OFFSET_INTEC_SERIAL_DUMMY_2	0x09
#define	OFFSET_INTEC_SYS_ERR_STATUS	0x0A
#define	OFFSET_CONNECTED_DEVICES   	0x0B
#define	OFFSET_DEVICE_NAME         	0x0C
#define	OFFSET_DEVICE_NAME_DUMMY   	0x0D
#define	OFFSET_DEVICE_NAME_DUMMY_1 	0x0E
#define	OFFSET_DEVICE_NAME_DUMMY_2 	0x0F
#define	OFFSET_SW_RESET            	0x10
#define	OFFSET_GEN_FLAGS           	0x11
#define	OFFSET_WORK_MODE           	0x12
#define	OFFSET_EEPROM_DELETE       	0x13
#define	OFFSET_PRODUCT_NAME        	0x14
#define	OFFSET_PRODUCT_NAME_DUMMY  	0x15
#define	OFFSET_PRODUCT_NAME_DUMMY_1	0x16
#define	OFFSET_PRODUCT_NAME_DUMMY_2	0x17
#define	OFFSET_EEPROM_STORE        	0x20
#define	OFFSET_UI_STATUS           	0x21
#define	OFFSET_GENERAL_STATUS      	0x22
#define	OFFSET_DEVICE_TYPE_LEGACY  	0xEE
#define	OFFSET_EMULATION           	0x23
#define	OFFSET_UI_CONTROL          	0x24
#define	OFFSET_SITE_NUM            	0x25
#define	OFFSET_GET_ADDITIONAL_SUBDEV_FW_VERSIONS	0x26
#define	OFFSET_MULTI_INTEC_X1      	0x27

//	UNIT BOOTLOADING registers
#define	OFFSET_BOOTLOADING_STATUS  	0x000
#define	OFFSET_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE	0x001
#define	OFFSET_BOOTLOADING_ENTER   	0x002
#define	OFFSET_BOOTLOADING_ABORT   	0x003
#define	OFFSET_BOOTLOADING_GET_DATA_FROM_DEV	0x004
#define	OFFSET_BOOTLOADING_SEND_DATA_TO_DEV	0x005
#define	OFFSET_BOOTLOADING_BUFF    	0x006

//	UNIT JUNCTION registers
#define	OFFSET_DIODE_CFG           	0x000
#define	OFFSET_DIODE_STATUS        	0x001
#define	OFFSET_TDAU_PT_WR          	0x002
#define	OFFSET_TDAU_PT_RD          	0x003
#define	OFFSET_FASTCAL_GO          	0x004
#define	OFFSET_FASTCAL_COEF_DIODE0 	0x005
#define	OFFSET_FASTCAL_COEF_DIODE1 	0x006
#define	OFFSET_FASTCAL_COEF_DIODE2 	0x007
#define	OFFSET_FASTCAL_COEF_DIODE3 	0x008
#define	OFFSET_TDIODE0             	0x009
#define	OFFSET_TDIODE1             	0x00A
#define	OFFSET_TDIODE2             	0x00B
#define	OFFSET_TDIODE3             	0x00C
#define	OFFSET_GET_ALL_TDIODES     	0x00D
#define	OFFSET_PF_CFG              	0x00E
#define	OFFSET_PF_STATUS           	0x00F
#define	OFFSET_PF0_COEF            	0x010
#define	OFFSET_PF1_COEF            	0x011
#define	OFFSET_PF2_COEF            	0x012
#define	OFFSET_PF3_COEF            	0x013
#define	OFFSET_VPF0                	0x014
#define	OFFSET_VPF1                	0x015
#define	OFFSET_VPF2                	0x016
#define	OFFSET_VPF3                	0x017
#define	OFFSET_TPF0                	0x018
#define	OFFSET_TPF1                	0x019
#define	OFFSET_TPF2                	0x01A
#define	OFFSET_TPF3                	0x01B
#define	OFFSET_GET_ALL_TPF_VPF     	0x01C
#define	OFFSET_PROCHOT_CFG         	0x01D
#define	OFFSET_PROCHOT_STATUS      	0x01E
#define	OFFSET_TDAU_CFG            	0x01F
#define	OFFSET_TDAU_STATUS         	0x020
#define	OFFSET_TDAU_DO_SCOCAL      	0x021
#define	OFFSET_JUNCTION_GEN_CFG_STATUS	0x022
#define	OFFSET_TDAU_OPEN_I2C_WR    	0x036
#define	OFFSET_TDAU_OPEN_I2C_RD    	0x037
#define	OFFSET_TDAU_CONTROL        	0x038
#define	OFFSET_FASTCAL_STATUS      	0x039
#define	OFFSET_SET_TCASE_UNDER_PROCHOT_CFG	0x02D

//	UNIT CASE registers
#define	OFFSET_GET_ALL_TCASES      	0x000

//	UNIT CONTROL registers
#define	OFFSET_GET_ALL_FEEDBACK_TEMPS	0x000
#define	OFFSET_DIODE_N_DTS_OUTPUT_ALLOC	0x001

//	UNIT TESTABILITY registers
#define	OFFSET_TESTABILITY_START   	0x000
#define	OFFSET_TESTABILITY_ABORT   	0x001
#define	OFFSET_BENCH_TEST_STATUS   	0x002
#define	OFFSET_BENCH_TEST_STATUS_DUMMY	0x003
#define	OFFSET_STANDALONE_TEST_STATUS	0x004
#define	OFFSET_BASIC_FUNC_TEST_STATUS	0x005
#define	OFFSET_TESTABILITY_MASKS   	0x006
#define	OFFSET_STANDALONE_TEST_DIS 	0x007
#define	OFFSET_STANDALONE_TEST_CFG 	0x008
#define	OFFSET_STANDALONE_TEST_CFG_DUMMY1	0x009
#define	OFFSET_STANDALONE_TEST_CFG_DUMMY2	0x00A
#define	OFFSET_STANDALONE_TEST_CFG_DUMMY3	0x00B
#define	OFFSET_STANDALONE_TEST_CFG_DUMMY4	0x00C
#define	OFFSET_STANDALONE_TEST_CFG_DUMMY5	0x00D
#define	OFFSET_STANDALONE_TEST_CFG_DUMMY6	0x00E
#define	OFFSET_STANDALONE_TEST_TDAU_MODULE_ERR_DETAILS	0x020
#define	OFFSET_STANDALONE_TEST_PECI_MODULE_ERR_DETAILS	0x021
#define	OFFSET_STANDALONE_TEST_TH_MODULE_ERR_DETAILS	0x022
#define	OFFSET_STANDALONE_TEST_TH_MODULE_ERR_DETAILS_1	0x023
#define	OFFSET_STANDALONE_TEST_COMM_AND_IC_MODULE_ERR_DETAILS	0x024
#define	OFFSET_STANDALONE_TEST_UI_MODULE_ERR_DETAILS	0x025
#define	OFFSET_STANDALONE_TEST_STAGE_STARTED	0x026
#define	OFFSET_STANDALONE_TEST_STAGE_ENDED	0x027

//	UNIT TESTER registers
#define	OFFSET_TE_GEN_FLAGS        	0x000
#define	OFFSET_TE_WORK_MODE        	0x001
#define	OFFSET_TE_DATA_TO_TESTER   	0x002
#define	OFFSET_TE_INTEC_STATUS     	0x003
#define	OFFSET_TE_DATA_FROM_TESTER 	0x004
#define	OFFSET_TE_LAST_TIC_RX_TIME 	0x022
#define	OFFSET_TE_BOOTLOADING_STATUS	0x014
#define	OFFSET_TE_BOOTLOADING_ENTER	0x010
#define	OFFSET_TE_BOOTLOADING_ABORT	0x011
#define	OFFSET_TE_BOOTLOADING_GET_DATA_FROM_DEV	0x012
#define	OFFSET_TE_BOOTLOADING_SEND_DATA_TO_DEV	0x013
#define	OFFSET_TE_FW_VERSION       	0x005

//	UNIT HIF registers
#define	OFFSET_IP_MODE             	0x000
#define	OFFSET_IP_ADDRESS          	0x001
#define	OFFSET_IP_NETBIOS          	0x002
#define	OFFSET_IP_NETBIOS_DUMMY    	0x003
#define	OFFSET_IP_NETBIOS_DUMMY_1  	0x004
#define	OFFSET_IP_NETBIOS_DUMMY_2  	0x005
#define	OFFSET_IP_UPDATE_CFG       	0x006

//	UNIT FRU registers
#define	OFFSET_FRU                 	0x000

//****************************************************************************
//* GENERAL Unit Registers Description
//****************************************************************************

// Enumeration for field FWVERSION10T of register: FW_VERSION
#define INTEC_FW_VERSION    	0x00000050

// Register: FW_VERSION		Offset: OFFSET_FW_VERSION
// Description: 	Firmware version 10T format
typedef union {
	LONG32 value;
		struct {
			ULONG32	FwVersion10T        	:16; 	//Firmware version 10T format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_FW_VERSION;

// Enumeration for field BUNDLE of register: GET_ALL_FW_VERSIONS
#define FW_BUNDLE_VERSION   	0x0000001c

// Register: GET_ALL_FW_VERSIONS		Offset: OFFSET_GET_ALL_FW_VERSIONS
// Description: 	Holds all uC's FW verisons
typedef union {
	UCHAR value[16];
		struct {
			ULONG32	Main                	:16; 	//Main uC FW version
			ULONG32	PeciModule          	:16; 	//PECI Module uC FW version
			ULONG32	D0                  	:16; 	//InTEC-D#0 uC FW version
			ULONG32	D1                  	:16; 	//InTEC-D#1 uC FW version
			ULONG32	D2                  	:16; 	//InTEC-D#2 uC FW version
			ULONG32	D3                  	:16; 	//InTEC-D#3 uC FW version
			ULONG32	Bundle              	:16; 	//FW Version Bundle version
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_GET_ALL_FW_VERSIONS;

// Enumeration for field DEVTYPE of register: DEVICE_TYPE
#define DEVICE_TYPE_INTEC   	0x000000d2
#define DEVICE_TYPE_INTECD  	0x000000d3

// Register: DEVICE_TYPE		Offset: OFFSET_DEVICE_TYPE
// Description: 	Device type (InTEC/InTEC-D/Other...)
typedef union {
	LONG32 value;
		struct {
			ULONG32	DevType             	:8; 	//Device type 
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_DEVICE_TYPE;

// Register: RESET_TIMESTAMP		Offset: OFFSET_RESET_TIMESTAMP
// Description: 	write 0x01 to this register to reset the Timestamp
typedef union {
	LONG32 value;
		struct {
			ULONG32	Reset               	:1; 	//set this bit to reset the timestamp
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_RESET_TIMESTAMP;

// Enumeration for field MEDUSAMODE of register: INTEC_HW_CFG
#define INTEC_HW_CFG_STANDALONE_MODE	0x00000000
#define INTEC_HW_CFG_MEDUSA_MODE	0x00000001

// Enumeration for field SYNCMASTER of register: INTEC_HW_CFG
#define INTEC_HW_CFG_SYNC_SLAVE	0x00000000
#define INTEC_HW_CFG_SYNC_MASTER	0x00000001

// Enumeration for field SEVENSEGORIENTATION of register: INTEC_HW_CFG
#define INTEC_HW_CFG_RS422_EN	0x00000000
#define INTEC_HW_CFG_RS422_DIS	0x00000001

// Enumeration for field LEGACYOROTHERASSEMBLYTYPE of register: INTEC_HW_CFG
#define INTEC_HW_CFG_LEGACY_ASSEMBLY_CA	0x00000000
#define INTEC_HW_CFG_CTC_OR_FASE_ASSEMBLY	0x00000001

// Enumeration for field FASEORCTCASSEMBLYTYPE of register: INTEC_HW_CFG
#define INTEC_HW_CFG_FASE_ASSEMBLY	0x00000000
#define INTEC_HW_CFG_CTC_ASSEMBLY	0x00000001

// Register: INTEC_HW_CFG		Offset: OFFSET_INTEC_HW_CFG
// Description: 	InTEC I/O Expansion status as read at board startup
typedef union {
	LONG32 value;
		struct {
			ULONG32	MedusaMode          	:1; 	//0 - InTEC in Standalone Mode, 
						                            //1 - InTEC in Medusa Mode
			ULONG32	SyncMaster          	:1; 	//0 - InTEC is Slave on sync bus, 
						                            //1 - InTEC is Master on sync bus
			ULONG32	EnRS422             	:1; 	//0 - RS422 Enabled, 
						                            //1 - RS422 Disabled (pins used as GPIO)
			ULONG32	FastcalForRtdEn     	:1; 	//use RTD meas & algo for Fastcal if bit is set
			ULONG32	SevenSegOrientation 	:1; 	//0 - 7seg top towards the TC connector, 
						                            //1 - 7seg bottom towards the TC connector
			ULONG32	LegacyOrOtherAssemblyType	:1; 	//0 - Legacy InTEC RevCA assembly
						                            //1 - SCS (FASE) or CTC PCB
			ULONG32	FaseOrCtcAssemblyType	:1; 	//0  - SCS (FASE) assembly
						                            //1 -  CTC assembly
			ULONG32	RESERVED0           	:25; 	//reserved
		} fields;
} UN_INTEC_HW_CFG;

// Register: INTEC_TIMESTAMP		Offset: OFFSET_INTEC_TIMESTAMP
// Description: 	holds the InTEC timestamp in 1ms counts
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Timestamp           	:32;
		} fields;
} UN_INTEC_TIMESTAMP;

// Enumeration for field INTECSERIALNUMBER of register: INTEC_SERIAL
#define SERIAL_NUMBER_MAX_LEN	0x00000010

// Register: INTEC_SERIAL		Offset: OFFSET_INTEC_SERIAL
// Description: 	unique 5-character serial number that is stored in its nonvolatile memory 
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	IntecSerialNumber   [16]; 	//InTEC serial number
		} fields;
} UN_INTEC_SERIAL;

// Register: INTEC_SERIAL_DUMMY		Offset: OFFSET_INTEC_SERIAL_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_INTEC_SERIAL_DUMMY;

// Register: INTEC_SERIAL_DUMMY_1		Offset: OFFSET_INTEC_SERIAL_DUMMY_1
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_INTEC_SERIAL_DUMMY_1;

// Register: INTEC_SERIAL_DUMMY_2		Offset: OFFSET_INTEC_SERIAL_DUMMY_2
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_INTEC_SERIAL_DUMMY_2;

// Register: INTEC_SYS_ERR_STATUS		Offset: OFFSET_INTEC_SYS_ERR_STATUS
// Description: 	InTEC System Error Status, holds the HW modules error indications
typedef union {
	ULONG32 value;
		struct {
			ULONG32	InTECD0Err          	:1; 	//InTECD0 Error if bit is set
			ULONG32	InTECD1Err          	:1; 	//InTECD1 Error if bit is set
			ULONG32	InTECD2Err          	:1; 	//InTECD2 Error if bit is set
			ULONG32	InTECD3Err          	:1; 	//InTECD3 Error if bit is set
			ULONG32	PECIModuleErr       	:1; 	//PECI Module Error if bit is set
			ULONG32	IOExpErr            	:1; 	//I/O Expansion Error if bit is set
			ULONG32	ADCErr              	:1; 	//ADC Error if bit is set
			ULONG32	EEPROMErr           	:1; 	//EEPROM Error if bit is set
			ULONG32	FLASHErr            	:1; 	//FLASH Error if bit is set
			ULONG32	I2CMasterErr        	:1; 	//I2C Master Module (I2C1) Error if bit is set
			ULONG32	SPIMasterErr        	:1; 	//SPI Master Module (SPI1) Error if bit is set
			ULONG32	CurrSrcErr          	:1; 	//Current Source Error if bit is set
			ULONG32	FastcalErr          	:1; 	//FastCal Error if bit is set
			ULONG32	LCDErr              	:1; 	//LCD Error if bit is set
			ULONG32	TDAUErr             	:1; 	//TDAU Error if bit is set
			ULONG32	EthernetPhyErr      	:1; 	//Ethernet PHY Error if bit is set
			ULONG32	I2CSlaveErr         	:1; 	//I2C Slave Module (I2C2) Error if bit is set
			ULONG32	USBErr              	:1; 	//USB Module Error if bit is set
			ULONG32	EthernetErr         	:1; 	//Ethernet Module Error if bit is set
			ULONG32	SPISlaveErr         	:1; 	//SPI Slave Module (SPI4) Error if bit is set
			ULONG32	UARTErr             	:1; 	//UART Module (UART1) Error if bit is set
			ULONG32	WaterModuleErr      	:1; 	//WaterModule Error if bit is set, (WaterModule in Bootloading mode)
			ULONG32	RESERVED0           	:2; 	//reserved for more HW Errors 
			ULONG32	FeedbackWarn        	:1; 	//Feedback warning if bit is set. (ex: not using the requested feedback type due to no input or safety)
			ULONG32	FeedbackFailure     	:1; 	//Feedback faliure if bit is set. (according to event module)
			ULONG32	RESERVED1           	:6;
		} fields;
} UN_INTEC_SYS_ERR_STATUS;


#define PECI_MODULE_INDEX 1
#define INTECD_CARD_0_INDEX 2
#define INTECD_CARD_1_INDEX 3
#define INTECD_CARD_2_INDEX 4
#define INTECD_CARD_3_INDEX 5
#define TIC_CARD_INDEX 6
#define WATER_CARD_INDEX 7

// Register: CONNECTED_DEVICES		Offset: OFFSET_CONNECTED_DEVICES
// Description: 	Contains which devices (uC/cards) connected
typedef union {
	LONG32 value;
		struct {
			ULONG32	Main                	:1; 	//Main uC connected if set (will be set if this register can be read by communication) 
			ULONG32	PECIModule          	:1; 	//PECI Module uC connected if set
			ULONG32	InTECD0             	:1; 	//InTECD0 connected if set
			ULONG32	InTECD1             	:1; 	//InTECD1 connected if set
			ULONG32	InTECD2             	:1; 	//InTECD2 connected if set
			ULONG32	InTECD3             	:1; 	//InTECD3 connected if set
			ULONG32	TIC                 	:1; 	//InTEC TIC connected if set
			ULONG32	WaterModule         	:1; 	//CTC Water Module connected if set
			ULONG32	RESERVED0           	:24; 	//RESERVED
		} fields;
} UN_CONNECTED_DEVICES;

// Enumeration for field DEVICENAME of register: DEVICE_NAME
#define INTEC_DEV_NAME_LEN  	0x00000010

// Register: DEVICE_NAME		Offset: OFFSET_DEVICE_NAME
// Description: 	contains theDevice name (16 characters, no '/0') of a connected device.
// 	write request for this read must contain the requested device ID in its data field.
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	DeviceName          [16]; 	//Device name (16 characters, no '/0')
		} fields;
} UN_DEVICE_NAME;

// Register: DEVICE_NAME_DUMMY		Offset: OFFSET_DEVICE_NAME_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_DEVICE_NAME_DUMMY;

// Register: DEVICE_NAME_DUMMY_1		Offset: OFFSET_DEVICE_NAME_DUMMY_1
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_DEVICE_NAME_DUMMY_1;

// Register: DEVICE_NAME_DUMMY_2		Offset: OFFSET_DEVICE_NAME_DUMMY_2
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_DEVICE_NAME_DUMMY_2;

// Register: SW_RESET		Offset: OFFSET_SW_RESET
// Description: 	Write any data to reset the device (soft reset of Main MCU)
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_SW_RESET;

// Enumeration for field GENDEFINITIONS of register: GEN_FLAGS
#define CONNECTED_DEV_INTEC_MAIN	0x00000001
#define CONNECTED_DEV_PECI_MODULE	0x00000002
#define CONNECTED_DEV_INTEC_D0	0x00000004
#define CONNECTED_DEV_INTEC_D1	0x00000008
#define CONNECTED_DEV_INTEC_D2	0x00000010
#define CONNECTED_DEV_INTEC_D3	0x00000020
#define CONNECTED_DEV_INTEC_E	0x00000100
#define CONNECTED_DEV_INTEC_TIC	0x00000040
#define CONNECTED_DEV_WATER_MODULE	0x00000080

// Enumeration for field ERRMASKS of register: GEN_FLAGS
#define SYS_ERR_LED_HW_MASK 	0x00ffffff
#define SYS_ERR_LED_SW_MASK 	0x001f0000
#define SYS_ERR_LED_TO_CHECK_MASK	0x01ffdfff
#define SYS_ERR_LED_WARNING_MASK	0x01000000

// Register: GEN_FLAGS		Offset: OFFSET_GEN_FLAGS
// Description: 	contain general flags
typedef union {
	LONG64 value;
		struct {
			ULONG32	UsbDataRx           	:1; 	//signals that a USB transaction received (and we can toggle the USB led
			ULONG32	LcdFlag             	:1; 	//flag updated in Timer2 ISR, set every 20mS. cleared after LCD interface was called.
			ULONG32	MainLoopMsCount     	:4; 	//holds counts (starting from 0) for main routine.
			ULONG32	RESERVED0           	:10;
			ULONG32	GenDefinitions      	:16; 	//for General Enum
			ULONG32	ErrMasks            	:32; 	//masks fo for determine which HW/SW error to use for Erro LED indication
		} fields;
} UN_GEN_FLAGS;

// Register: WORK_MODE		Offset: OFFSET_WORK_MODE
// Description: 	Holds current work mode (Run/testability/...)
// 	use I2D_RUN_DESCRIPTOR.TransactionType ENUM. 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Mode                	:4; 	//use I2D_RUN_DESCRIPTOR.TransactionType ENUM.
			ULONG32	RESERVED0           	:28;
		} fields;
} UN_WORK_MODE;

// Register: EEPROM_DELETE		Offset: OFFSET_EEPROM_DELETE
// Description: 	Clean most of EEPROM flags, FRU & TESTABILITY flags undeleted 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Delete              	:1; 	//Delete EEPROM is set, during read operation if set bad EEPROM
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_EEPROM_DELETE;

// Register: PRODUCT_NAME		Offset: OFFSET_PRODUCT_NAME
// Description: 	Product name that had been stored in FRU
// 	          
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	ProductName         [16]; 	//Product name that had been stored in FRU
		} fields;
} UN_PRODUCT_NAME;

// Register: PRODUCT_NAME_DUMMY		Offset: OFFSET_PRODUCT_NAME_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_PRODUCT_NAME_DUMMY;

// Register: PRODUCT_NAME_DUMMY_1		Offset: OFFSET_PRODUCT_NAME_DUMMY_1
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_PRODUCT_NAME_DUMMY_1;

// Register: PRODUCT_NAME_DUMMY_2		Offset: OFFSET_PRODUCT_NAME_DUMMY_2
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_PRODUCT_NAME_DUMMY_2;

// Register: EEPROM_STORE		Offset: OFFSET_EEPROM_STORE
// Description: 	store InTEC cfg from RAM in ROM
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Store               	:1; 	//set this bit to store cfg in ROM (wait about 2 sec after using this function before any other write to InTEC).
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_EEPROM_STORE;

// Register: UI_STATUS		Offset: OFFSET_UI_STATUS
// Description: 	Holds the UI status (ACK btn, buzzer)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	AckBtnOn            	:1; 	//ACK btn is pressed if this bit is set
			ULONG32	BuzzerOn            	:1; 	//Buzzer is on if this bit is set
			ULONG32	BuzzerDisabled      	:1; 	//Buzzer is disabled (by user command) if bit is set
			ULONG32	RESERVED0           	:29;
		} fields;
} UN_UI_STATUS;

// Register: GENERAL_STATUS		Offset: OFFSET_GENERAL_STATUS
// Description: 	Diagnostics Status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	FailureOn           	:1; 	//there is a Failure in one of connected intec-ds
			ULONG32	WarningOn           	:1; 	//there is a Warning in one of connected intec-ds
			ULONG32	NotificationOn      	:1; 	//there is a Notification in one of connected intec-ds
			ULONG32	Disarmed            	:1; 	//one of intec-ds is disarmed if this bit is set
			ULONG32	ArmBtnWasPressed    	:1; 	//Arm button was pressed since last Arming if this bit is set. so stop buzzer/remove LCB msg
			ULONG32	DisarmMenu          	:1; 	//Flag use for Disarm Menu entrance
			ULONG32	OutOffBtnWasPressed 	:1; 	//Out Off button was pressed 
			ULONG32	EnableGangedOutputs 	:1; 	//this bit is set if there are no issues for all ganged InTEC-Ds and we can enable thier output.
						                            //if there is a failure or output button pressed for any of them, this bit will be cleared and the output of the Ganged InTEC-Ds will be turned off
			ULONG32	GangedPwrSaveMode   	:1; 	//this bit is set if any of the ganged InTEC-Ds has a TH leak and we need to signal all ganged to stop their output and close TH valve.
						                            //
			ULONG32	RESERVED0           	:23;
		} fields;
} UN_GENERAL_STATUS;

// Enumeration for field DEVTYPE of register: DEVICE_TYPE_LEGACY
#define DEVICE_TYPE_INTEC_1 	0x000000d2
#define DEVICE_TYPE_INTECD_1	0x000000d3

// Register: DEVICE_TYPE_LEGACY		Offset: OFFSET_DEVICE_TYPE_LEGACY
// Description: 	Device type (InTEC/InTEC-D/Other...)
// 	according Bootloader legacy mapping
typedef union {
	LONG32 value;
		struct {
			ULONG32	DevType             	:8; 	//Device type 
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_DEVICE_TYPE_LEGACY;

// Register: EMULATION		Offset: OFFSET_EMULATION
// Description: 	holds bits for Emulation of states for Debug and Dev
typedef union {
	ULONG32 value;
		struct {
			ULONG32	EventsEmulation     	:1; 	//when bit is set: take EVENTS bits from Regfile instead from InTEC-D or other monitoring
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_EMULATION;

// Register: UI_CONTROL		Offset: OFFSET_UI_CONTROL
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DisableBuzzer       	:1; 	//buzzer will be always turned off if bit is set
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_UI_CONTROL;

// Register: SITE_NUM		Offset: OFFSET_SITE_NUM
// Description: 	hold the Site Number field (for multi-site ATE, for ease of identification when host is connected to more than 1 intec)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Site                	:8; 	//data range [0-255]
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_SITE_NUM;

// Register: GET_ADDITIONAL_SUBDEV_FW_VERSIONS		Offset: OFFSET_GET_ADDITIONAL_SUBDEV_FW_VERSIONS
// Description: 	Holds additional subdevices uC's FW verisons (Water Module, InTEC TIC...)
typedef union {
	UCHAR value[16];
		struct {
			ULONG32	TIC                 	:16; 	//InTEC TIC uC FW version
			ULONG32	WaterModule         	:16; 	//CTC Water Module uC FW version
			UCHAR	RESERVED0           [12];
		} fields;
} UN_GET_ADDITIONAL_SUBDEV_FW_VERSIONS;

// Register: MULTI_INTEC_X1		Offset: OFFSET_MULTI_INTEC_X1
// Description: 	Multi InTECx1 flags
typedef union {
	ULONG32 value;
		struct {
			ULONG32	MultiIntecOn        	:1; 	//if set Multi InTEC mode is on
			ULONG32	MultiIntecRole      	:2; 	//holds the number of intec-D to implement in Multi InTEC mode :
						                            //0 - InTEC-D0
						                            //1 - InTEC-D1
						                            //2 - InTEC-D2
						                            //3 - InTEC-D3
			ULONG32	RESERVED0           	:5;
			ULONG32	MultiIntecWaitingForSOF	:1; 	//if set Multi InTEC mode waiting for SOF to be RX
			ULONG32	MultiIntecGettingMsg	:1; 	//if set Multi InTEC mode is getting msg (after SOF wazs RXed)
			ULONG32	MultiIntecDataFullyRx	:1; 	//relevant for Slave Role (when UART Rx on interrupt)
						                            //bit is set when data was fully recieved (we got start and end of frame)
			ULONG32	RESERVED1           	:21;
		} fields;
} UN_MULTI_INTEC_X1;

//****************************************************************************
//* BOOTLOADING Unit Registers Description
//****************************************************************************

// Register: BOOTLOADING_STATUS		Offset: OFFSET_BOOTLOADING_STATUS
// Description: 	External device bootloading status 
typedef union {
	LONG32 value;
		struct {
			ULONG32	EnterBootloadingMode	:1; 	//set when request to enter bootloader mode received from host
			ULONG32	RESERVED0           	:1;
			ULONG32	DeviceComInBootMode 	:1; 	//set when communication reply received that external device is in bootloading mode
			ULONG32	DeviceComInAppMode  	:1; 	//set when communication reply received that external device is in application mode
			ULONG32	HaveDataToSendToDev 	:1; 	//set when we got data from host to send to the device
			ULONG32	HaveDataToSendToHost	:1; 	//set when we got data from device to send to the host
			ULONG32	RESERVED1           	:2;
			ULONG32	DevPointer          	:8; 	//device index that bootloader actions are performed on
			ULONG32	RESERVED2           	:16;
		} fields;
} UN_BOOTLOADING_STATUS;

// Enumeration for field INBOOTMODEMAIN of register: BOOTLOADING_GET_DEVICES_IN_BOOT_MODE
#define MAIN_IN_BOOT_MODE   	0x00000001
#define PECI_MODULE_IN_BOOT_MODE	0x00000002
#define INTEC_D0_IN_BOOT_MODE	0x00000004
#define INTEC_D1_IN_BOOT_MODE	0x00000008
#define INTEC_D2_IN_BOOT_MODE	0x00000010
#define INTEC_D3_IN_BOOT_MODE	0x00000020

// Register: BOOTLOADING_GET_DEVICES_IN_BOOT_MODE		Offset: OFFSET_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE
// Description: 	which device is in Bootloading mode (first ext device on bit#1, local device on bit#0)
typedef union {
	LONG32 value;
		struct {
			ULONG32	InBootModeMain      	:1; 	//Device in Bootloader mode is set
			ULONG32	InBootModePeciModule	:1; 	//Device in Bootloader mode is set
			ULONG32	InBootModeIntecD0   	:1; 	//Device in Bootloader mode is set
			ULONG32	InBootModeIntecD1   	:1; 	//Device in Bootloader mode is set
			ULONG32	InBootModeIntecD2   	:1; 	//Device in Bootloader mode is set
			ULONG32	InBootModeIntecD3   	:1; 	//Device in Bootloader mode is set
			ULONG32	InBootModeTic       	:1; 	//Device in Bootloader mode is set
			ULONG32	InBootModeWaterModule	:1; 	//Device in Bootloader mode is set
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE;

// Register: BOOTLOADING_ENTER		Offset: OFFSET_BOOTLOADING_ENTER
// Description: 	write the device id in data field for setting it in Bootloading mode (first ext device on bit#1, local device on bit#0).
// 	from this point any data sent from bootloading interface will be sent to this selected device
typedef union {
	LONG32 value;
		struct {
			ULONG32	EnterBootloadingMain	:1; 	//enter Main MCU to bootloading mode
			ULONG32	EnterBootloadingPeciModule	:1; 	//enter Peci Module MCU to bootloading mode
			ULONG32	EnterBootloadingIntecD0	:1; 	//enter InTEC D0 MCU to bootloading mode
			ULONG32	EnterBootloadingIntecD1	:1; 	//enter InTEC D1 MCU to bootloading mode
			ULONG32	EnterBootloadingIntecD2	:1; 	//enter InTEC D2 MCU to bootloading mode
			ULONG32	EnterBootloadingIntecD3	:1; 	//enter InTEC D3 MCU to bootloading mode
			ULONG32	EnterBootloadingTic 	:1; 	//enter TICMCU to bootloading mode
			ULONG32	EnterBootloadingWaterModule	:1; 	//enter Water Module MCU to bootloading mode
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_BOOTLOADING_ENTER;

// Register: BOOTLOADING_ABORT		Offset: OFFSET_BOOTLOADING_ABORT
// Description: 	write to this register will abort bootloading operation, and reset the bootloading status
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_BOOTLOADING_ABORT;

// Register: BOOTLOADING_GET_DATA_FROM_DEV		Offset: OFFSET_BOOTLOADING_GET_DATA_FROM_DEV
// Description: 	get string from the device in bootloader mode (InTEC Header [6 B] + DATA [54 B] = 60 B)
typedef union {
	UCHAR value[54];
		struct {
			UCHAR	DataFromDev         [54];
		} fields;
} UN_BOOTLOADING_GET_DATA_FROM_DEV;

// Register: BOOTLOADING_SEND_DATA_TO_DEV		Offset: OFFSET_BOOTLOADING_SEND_DATA_TO_DEV
// Description: 	send string to the device in bootloader mode (
// 	send: LEN [1B], DATA [LEN B])
typedef union {
	UCHAR value[51];
		struct {
			ULONG32	SendDataLen         	:8; 	//Length of data to send to ext device
			UCHAR	DataToSend          [50]; 	//Data to send to ext device
		} fields;
} UN_BOOTLOADING_SEND_DATA_TO_DEV;

// Enumeration for field HOSTTODEVBUFF of register: BOOTLOADING_BUFF
#define BOOTLOADING_HOST_TO_DEV_BUFFER_LEN	0x00000040

// Register: BOOTLOADING_BUFF		Offset: OFFSET_BOOTLOADING_BUFF
// Description: 	holds the bootloading buffers (internal use)
typedef union {
	LONG32 value;
		struct {
			ULONG32	HostToDevBuff       	:8; 	//stores the host data to send to the ext device
			ULONG32	DevToHostBuff       	:8; 	//stores the ext device data to send to the host
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_BOOTLOADING_BUFF;

//****************************************************************************
//* JUNCTION Unit Registers Description
//****************************************************************************

// Enumeration for field POLLDIODES of register: DIODE_CFG
#define EN_DIODE0           	0x00000001
#define EN_DIODE1           	0x00000002
#define EN_DIODE2           	0x00000004
#define EN_DIODE3           	0x00000008

// Register: DIODE_CFG		Offset: OFFSET_DIODE_CFG
// Description: 	contains the Thermal Diode configuration.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	PollDiodes          	:4; 	//bitwise for selecting which diode to read (set bit to enable read)
			ULONG32	RESERVED0           	:28;
		} fields;
} UN_DIODE_CFG;

// Enumeration for field DETECTEDDIODES of register: DIODE_STATUS
#define DIODE0_DETECTED     	0x00000001
#define DIODE1_DETECTED     	0x00000002
#define DIODE2_DETECTED     	0x00000004
#define DIODE3_DETECTED     	0x00000008

// Enumeration for field TDAUDETECTED of register: DIODE_STATUS
#define TDAU_DETECTED       	0x00000010

// Register: DIODE_STATUS		Offset: OFFSET_DIODE_STATUS
// Description: 	holds diodes status info (including TDAU)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DetectedDiodes      	:4; 	//bitwise for indication of which thermal diode detected (set if ok)
			ULONG32	TDAUDetected        	:1; 	//set if TDAU detected,else implies working in FastCal mode
			ULONG32	RESERVED0           	:2;
			ULONG32	ModuleOk            	:1; 	//set if Tjunction module is ok, if cleared there is an error in one of the Tjunction modules
			ULONG32	FastCalFinished     	:4; 	//Bitwise, FastCal calibration finished successfully. 
						                            //The appropriate bit is cleared when FastCalGo command received, set after successful calibration and cleared after reading this register
			ULONG32	RESERVED1           	:20;
		} fields;
} UN_DIODE_STATUS;

// Register: TDAU_PT_WR		Offset: OFFSET_TDAU_PT_WR
// Description: 	use this register for writing to the TDAU Memory directly (for TDAU configuration using WriteMem)
typedef union {
	UCHAR value[55];
		struct {
			ULONG32	RegAdd              	:16; 	//number of bytes expected to read from TDAU (<=55)
			ULONG32	DataLength          	:7; 	//WrLen bytes to write to TDAU
			ULONG32	CmdType             	:1; 	//clear this bit to perform a write command to the TDAU. set this bit for read
			ULONG32	RESERVED0           	:8; 	//WrLen bytes to write to TDAU
			UCHAR	Data                [51]; 	//WrLen bytes to write to TDAU
		} fields;
} UN_TDAU_PT_WR;

// Register: TDAU_PT_RD		Offset: OFFSET_TDAU_PT_RD
// Description: 	use this register for reading the TDAU Memory directly (for TDAU configuration using ReadMem)
typedef union {
	UCHAR value[55];
		struct {
			ULONG32	RegAdd              	:16; 	//bytes read from TDAU
			ULONG32	CmdTypeAndDataLength	:8; 	//bytes read from TDAU
			ULONG32	RESERVED0           	:8; 	//bytes read from TDAU
			UCHAR	Data                [51]; 	//bytes read from TDAU
		} fields;
} UN_TDAU_PT_RD;

// Enumeration for field FASTCALFORRTD of register: FASTCAL_GO
#define FASTCAL_RTD_MODE_ON 	0x00000001
#define FASTCAL_DIODE_MODE_ON	0x00000000

// Register: FASTCAL_GO		Offset: OFFSET_FASTCAL_GO
// Description: 	set the appropriate bit to initiate a FastCal calibration process
// 	(resets the FastCalFinished Field in DIODE_STATUS register)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DiodeInput          	:4; 	//bitwise, set appropriate bit to start fastcal for this Thermal Diode input
			ULONG32	FastCalForRTD       	:1; 	//set this bit in order to use fascal for RTD.
						                            //clear this bit for using fascal diode
			ULONG32	RESERVED0           	:3;
			ULONG32	Diode0Ref           	:2; 	//Set the number of the thermal head to use for this Thermal Diode input calibration
			ULONG32	Diode1Ref           	:2; 	//Set the number of the thermal head to use for this Thermal Diode input calibration
			ULONG32	Diode2Ref           	:2; 	//Set the number of the thermal head to use for this Thermal Diode input calibration
			ULONG32	Diode3Ref           	:2; 	//Set the number of the thermal head to use for this Thermal Diode input calibration
			ULONG32	RESERVED1           	:16;
		} fields;
} UN_FASTCAL_GO;

// Register: FASTCAL_COEF_DIODE0		Offset: OFFSET_FASTCAL_COEF_DIODE0
// Description: 	contain the FastCal calibration coefficients
// 	   fields 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Slope10T            	:16; 	//slope multiplied by10
			ULONG32	Intercept10T        	:16; 	//Intercept multiplied by10
		} fields;
} UN_FASTCAL_COEF_DIODE0;

// Register: FASTCAL_COEF_DIODE1		Offset: OFFSET_FASTCAL_COEF_DIODE1
// Description: 	contain the FastCal calibration coefficients
// 	    fields
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Slope10T            	:16; 	//Slope multiplied by10
			ULONG32	Intercept10T        	:16; 	//Intercept multiplied by10
		} fields;
} UN_FASTCAL_COEF_DIODE1;

// Register: FASTCAL_COEF_DIODE2		Offset: OFFSET_FASTCAL_COEF_DIODE2
// Description: 	contain the FastCal calibration coefficients
// 	   fields 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Slope10T            	:16; 	//Slope multiplied by10
			ULONG32	Intercept10T        	:16; 	//Intercept multiplied by10
		} fields;
} UN_FASTCAL_COEF_DIODE2;

// Register: FASTCAL_COEF_DIODE3		Offset: OFFSET_FASTCAL_COEF_DIODE3
// Description: 	contain the FastCal calibration coefficients
// 	   fields 
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Slope10T            	:16; 	//Slope multiplied by 10
			ULONG32	Intercept10T        	:16; 	//Intercept multiplied by 10
		} fields;
} UN_FASTCAL_COEF_DIODE3;

// Register: TDIODE0		Offset: OFFSET_TDIODE0
// Description: 	Holds the Thermal Diode temperature in InTEC temp format
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//Holds the Thermal Diode temperature in InTEC temp format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TDIODE0;

// Register: TDIODE1		Offset: OFFSET_TDIODE1
// Description: 	Holds the Thermal Diode temperature in InTEC temp format
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//Holds the Thermal Diode temperature in InTEC temp format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TDIODE1;

// Register: TDIODE2		Offset: OFFSET_TDIODE2
// Description: 	Holds the Thermal Diode temperature in InTEC temp format
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//Holds the Thermal Diode temperature in InTEC temp format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TDIODE2;

// Register: TDIODE3		Offset: OFFSET_TDIODE3
// Description: 	Holds the Thermal Diode temperature in InTEC temp format
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//Holds the Thermal Diode temperature in InTEC temp format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TDIODE3;

// Register: GET_ALL_TDIODES		Offset: OFFSET_GET_ALL_TDIODES
// Description: 	get all TDiode temperatures:
// 	TimeStamp,Valid,Temp0,Temp1...
typedef union {
	UCHAR value[16];
		struct {
			ULONG32	Timestamp           	:32; 	//holds the InTEC-D timestamp
			ULONG32	Valid               	:4; 	//holds which of the TCase temperature is valid
			ULONG32	RESERVED0           	:12;
			ULONG32	Temp0               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp1               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp2               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp3               	:16; 	//Temperatures in InTEC format
			ULONG32	RESERVED1           	:16;
		} fields;
} UN_GET_ALL_TDIODES;

// Enumeration for field POLLPF of register: PF_CFG
#define PF0_POLL            	0x00000001
#define PF1_POLL            	0x00000002
#define PF2_POLL            	0x00000004
#define PF3_POLL            	0x00000008

// Register: PF_CFG		Offset: OFFSET_PF_CFG
// Description: 	hold the power following configuration
typedef union {
	ULONG32 value;
		struct {
			ULONG32	PollPF              	:4; 	//bitwise, set appropriate bit to enable which Power Following input to read
			ULONG32	RESERVED0           	:28; 	//bitwise, set appropriate bit to enable which Power Following input to read
		} fields;
} UN_PF_CFG;

// Enumeration for field DETECTEDPF of register: PF_STATUS
#define PF0_DETECTED        	0x00000001
#define PF1_DETECTED        	0x00000002
#define PF2_DETECTED        	0x00000004
#define PF3_DETECTED        	0x00000008

// Register: PF_STATUS		Offset: OFFSET_PF_STATUS
// Description: 	holds the Power Following module status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DetectedPF          	:4; 	//bitewise, bit is set if input enabled and result is within range
			ULONG32	RESERVED0           	:28; 	//bitewise, bit is set if input enabled and result is within range
		} fields;
} UN_PF_STATUS;

// Register: PF0_COEF		Offset: OFFSET_PF0_COEF
// Description: 	linear equation coefficients for the PF voltage input conversion to temperature.
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Slope               	:16; 	//Slope coefficient, 100T format
			ULONG32	Intercept           	:16; 	//Intercept coefficient, 100T format
		} fields;
} UN_PF0_COEF;

// Register: PF1_COEF		Offset: OFFSET_PF1_COEF
// Description: 	linear equation coefficients for the PF voltage input conversion to temperature.
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Slope               	:16; 	//Slope coefficient, 100T format
			ULONG32	Intercept           	:16; 	//Intercept coefficient, 100T format
		} fields;
} UN_PF1_COEF;

// Register: PF2_COEF		Offset: OFFSET_PF2_COEF
// Description: 	linear equation coefficients for the PF voltage input conversion to temperature.
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Slope               	:16; 	//Slope coefficient, 100T format
			ULONG32	Intercept           	:16; 	//Intercept coefficient, 100T format
		} fields;
} UN_PF2_COEF;

// Register: PF3_COEF		Offset: OFFSET_PF3_COEF
// Description: 	linear equation coefficients for the PF voltage input conversion to temperature.
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Slope               	:16; 	//Slope coefficient, 100T format
			ULONG32	Intercept           	:16; 	//Intercept coefficient, 100T format
		} fields;
} UN_PF3_COEF;

// Register: VPF0		Offset: OFFSET_VPF0
// Description: 	Power Following input voltage measurement.
// 	Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
typedef union {
	LONG32 value;
		struct {
			ULONG32	Voltage             	:16; 	//Power Following input voltage measurement.
						                            //Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_VPF0;

// Register: VPF1		Offset: OFFSET_VPF1
// Description: 	Power Following input voltage measurement.
// 	Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
typedef union {
	LONG32 value;
		struct {
			ULONG32	Voltage             	:16; 	//Power Following input voltage measurement.
						                            //Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_VPF1;

// Register: VPF2		Offset: OFFSET_VPF2
// Description: 	Power Following input voltage measurement.
// 	Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
typedef union {
	LONG32 value;
		struct {
			ULONG32	Voltage             	:16; 	//Power Following input voltage measurement.
						                            //Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_VPF2;

// Register: VPF3		Offset: OFFSET_VPF3
// Description: 	Power Following input voltage measurement.
// 	Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
typedef union {
	LONG32 value;
		struct {
			ULONG32	Voltage             	:16; 	//Power Following input voltage measurement.
						                            //Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_VPF3;

// Register: TPF0		Offset: OFFSET_TPF0
// Description: 	Power Following temperature result.
// 	Format: InTEC temperature format
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//Power Following temperature result.
						                            //Format: InTEC temperature format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TPF0;

// Register: TPF1		Offset: OFFSET_TPF1
// Description: 	Power Following temperature result.
// 	Format: InTEC temperature format
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//Power Following temperature result.
						                            //Format: InTEC temperature format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TPF1;

// Register: TPF2		Offset: OFFSET_TPF2
// Description: 	Power Following temperature result.
// 	Format: InTEC temperature format
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//Power Following temperature result.
						                            //Format: InTEC temperature format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TPF2;

// Register: TPF3		Offset: OFFSET_TPF3
// Description: 	Power Following temperature result.
// 	Format: InTEC temperature format
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//Power Following temperature result.
						                            //Format: InTEC temperature format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TPF3;

// Register: GET_ALL_TPF_VPF		Offset: OFFSET_GET_ALL_TPF_VPF
// Description: 	get all PF  temperatures and voltages:
// 	TimeStamp,Valid,Temp0,Temp1..., Voltage1,Voltage2...
typedef union {
	UCHAR value[24];
		struct {
			ULONG32	Timestamp           	:32; 	//holds the InTEC-D timestamp
			ULONG32	Valid               	:4; 	//holds which of the PF temperature (and voltage) is valid
			ULONG32	RESERVED0           	:12;
			ULONG32	Temp0               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp1               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp2               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp3               	:16; 	//Temperatures in InTEC format
			ULONG32	Voltage0            	:16; 	//Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
			ULONG32	Voltage1            	:16; 	//Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
			ULONG32	Voltage2            	:16; 	//Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
			ULONG32	Voltage3            	:16; 	//Format: 3.3v, 16bit ==> Result[V] = 3.3*(read_data)/(2^16)
			ULONG32	RESERVED1           	:16;
		} fields;
} UN_GET_ALL_TPF_VPF;

// Enumeration for field POLLPROCHOT of register: PROCHOT_CFG
#define EN_PROCHOT0         	0x00000001
#define EN_PROCHOT1         	0x00000002
#define EN_PROCHOT2         	0x00000004
#define EN_PROCHOT3         	0x00000008

// Enumeration for field ENSENDINGNOTIFICATIONTOHOST of register: PROCHOT_CFG
#define PROCHOT_EN_SENDING_NOTIFICATION_TO_HOST0	0x00000010
#define PROCHOT_EN_SENDING_NOTIFICATION_TO_HOST1	0x00000020
#define PROCHOT_EN_SENDING_NOTIFICATION_TO_HOST2	0x00000040
#define PROCHOT_EN_SENDING_NOTIFICATION_TO_HOST3	0x00000080

// Register: PROCHOT_CFG		Offset: OFFSET_PROCHOT_CFG
// Description: 	contains the Prochot configuration.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	PollProchot         	:4; 	//bitwise, for selecting which Prochot to monitor (set bit to enable read)
			ULONG32	EnSendingNotificationToHost	:4; 	//bitwise for selecting which Host to send notification to when Prochot detected (set bit to enable notification)
			ULONG32	ChResetCounter      	:4; 	//bitwise, set the appropriate bit for clearing the counter and flag of the Prochot Status register
			ULONG32	RESERVED0           	:20;
		} fields;
} UN_PROCHOT_CFG;

// Enumeration for field DETECTEDPROCHOT of register: PROCHOT_STATUS
#define PROCHOT0_DETECTED   	0x00000001
#define PROCHOT1_DETECTED   	0x00000002
#define PROCHOT2_DETECTED   	0x00000004
#define PROCHOT3_DETECTED   	0x00000008

// Register: PROCHOT_STATUS		Offset: OFFSET_PROCHOT_STATUS
// Description: 	holds the Prochot module status
typedef union {
	ULONG64 value;
		struct {
			ULONG32	DetectedProchot     	:4; 	//bitewise, bit is set if input enabled and detected
			ULONG32	SetTcaseBelowProchotInProcess	:1; 	//bit is set if Set Tcase Below Prochot is in Process
			ULONG32	RESERVED0           	:3;
			ULONG32	Ch0Count            	:8; 	//Contains the channe's number of detected Prochot signals since last reset.
			ULONG32	Ch1Count            	:8; 	//Contains the channe's number of detected Prochot signals since last reset.
			ULONG32	Ch2Count            	:8; 	//Contains the channe's number of detected Prochot signals since last reset.
			ULONG32	Ch3Count            	:8; 	//Contains the channe's number of detected Prochot signals since last reset.
			ULONG32	ProchotTemp         	:16; 	//Contains the temp that caused prochot in the last Auto Tcase Below Prochot search, if wasn't found will contain 0xFFFF
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_PROCHOT_STATUS;

// Enumeration for field CONTROLWORD1 of register: TDAU_CFG
#define TDAU_CFG_MAIN_EQU_SINGLE_CURRENT	0x0000000e
#define TDAU_CFG_MAIN_EQU_2_CURRENT_IDEALITY	0x00000002
#define TDAU_CFG_MAIN_EQU_CH_DISABLED	0x0000000f
#define TDAU_CFG_MAIN_EQU_CH1_3_4_DIS_CH2_SINGLE_CURRENT	0x0000ffef

// Enumeration for field CONTROLWORD2 of register: TDAU_CFG
#define TDAU_CFG_CTRL_WORD2 	0x00001001
#define TDAU_CFG_CTRL_WORD2_STANDALONE_TEST_CFG	0x000000f0

// Enumeration for field CONTROLWORD3 of register: TDAU_CFG
#define TDAU_CFG_CTRL_WORD3 	0x00000000

// Enumeration for field CONTROLWORD4 of register: TDAU_CFG
#define TDAU_CFG_SCOCAL_EQU_2_CUR_IFACT	0x00000002
#define TDAU_CFG_SCOCAL_EQU_CHANNEL_DISABLED	0x0000000f
#define TDAU_CFG_SCOCAL_EQU_CH1_3_4_DIS_CH2_2_CUR_IDEALITY	0x0000ff2f
#define TDAU_CFG_SCOCAL_EQU_2_CUR_IDEALITY_LEAK	0x0000000a

// Enumeration for field SCOCALSAMPIEINTERVAL of register: TDAU_CFG
#define TDAU_CFG_SCOCAL_SAMPLE_INTERVAL_MS	0x0000001e

// Enumeration for field SCOCALNUMOFSAMPLES of register: TDAU_CFG
#define TDAU_CFG_SCOCAL_NUM_OF_SAMPLES	0x00000001

// Enumeration for field IDEALITY of register: TDAU_CFG
#define TDAU_CFG_IDEALITY   	0x3f839581

// Enumeration for field EARLYVOLTAGE of register: TDAU_CFG
#define TDAU_CFG_EARLY_VOLTAGE	0x3f266666

// Enumeration for field SLOPE of register: TDAU_CFG
#define TDAU_CFG_SLOPE      	0x0000e9ee

// Enumeration for field FORCECURRENT1 of register: TDAU_CFG
#define TDAU_CFG_FORCE_CURRENT1	0x3727c5ac

// Enumeration for field FORCECURRENT2 of register: TDAU_CFG
#define TDAU_CFG_FORCE_CURRENT2	0x37a7c5ac

// Enumeration for field FORCECURRENT3 of register: TDAU_CFG
#define TDAU_CFG_FORCE_CURRENT3	0x3827c5ac

// Register: TDAU_CFG		Offset: OFFSET_TDAU_CFG
// Description: 	Hold TDAU configuration.
// 	1. used for testing with on-board BJT readout.
// 	2. used to store TDAU cfg in RUN mode (only sume of the fields are update)
// 	3. used to store InTEC calc results related to TDAU 
typedef union {
	UCHAR value[38];
		struct {
			ULONG32	ControlWord1        	:16; 	//channels 1-4 Main Equation coding (According to user's manual Table 6-1)
						                            //
						                            //write this to control word1 (location 00 00), bits 4-7 allocated for ch2
			ULONG32	ControlWord2        	:16; 	//write this to control word2(location 00 02), 
						                            //set common cathode bit0 
						                            //
			ULONG32	ControlWord3        	:16; 	//write this to control word3(location 00 04), 
						                            // 
						                            //
			ULONG32	ControlWord4        	:16; 	//channels 1-4 SCOCAL Equation coding (According to user's manual Table 6-4)
						                            //
						                            //write this to control word4 (location 00 06), bits 4-7 allocated for ch2
			ULONG32	ScocalSampIeInterval	:16; 	//Scocal SampIing Interval (ms counts) (location 00 14), 
						                            // 
						                            //
			ULONG32	ScocalNumOfSamples  	:16; 	//Scocal Number of samples(location 00 16), 
						                            // 
						                            //
			ULONG32	ScocalDelayCalcRes  	:16; 	//TDAU SCOCAL delay (in 6ms counts) calculation result (done by InTEC)
			ULONG32	MainEquDelayCalcRes 	:16; 	//TDAU Main Equation delay (in 6ms counts) calculation result (done by InTEC)
			ULONG32	Ideality            	:32; 	//Ideality factor (channel2  location 00 20), 
						                            //The default setting is 1.0042, which translates to the following four bytes: 0xA0, 0x89,
						                            //0x80, 0x3F.
						                            //Enum is configured to 1.028
						                            //
			ULONG32	EarlyVoltage        	:32; 	//Early Voltage (channel2  location 00 30), 
						                            //The default setting is 3.165v, which translates to the following four bytes: 0x40, 0x4A, 0x8F, 0x5C.
						                            //Enum is configured to 0.65mV 
						                            //
						                            //
			ULONG32	Slope               	:16; 	//10T.
						                            //-565.0 => -5650 => 0xEE 0xE9 (LSB first)
						                            //(location for ch2 00 3E)
			ULONG32	ForceCurrent1       	:32; 	//10uA.
						                            //10uA => 0x37, 0x27, 0xC5, 0xAC
						                            //(location for ch2 00 60)
			ULONG32	ForceCurrent2       	:32; 	//10uA.
						                            //20uA => 0x37, 0xA7, 0xC5, 0xAC
						                            //(location for ch2 00 64)
			ULONG32	ForceCurrent3       	:32; 	//10uA.
						                            //40uA => 0x38, 0x27, 0xC5, 0xAC
						                            //(location for ch2 00 68)
		} fields;
} UN_TDAU_CFG;

// Register: TDAU_STATUS		Offset: OFFSET_TDAU_STATUS
// Description: 	Holds basic TDAU data and status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Detected            	:1; 	//TDAU detected if set
			ULONG32	SysErr              	:1; 	//TDAU system error detected if set
			ULONG32	ScocalIntervalTooShort	:1; 	//TDAU SCOCAL interval configurartion is too short according to InTEC calc (check the value in TDAU cfg, InTEC calc value can be found in TDAU_CFG)
			ULONG32	HasBootloader       	:1; 	//TDAU has Bootloader if bit is set
			ULONG32	RESERVED0           	:3;
			ULONG32	Busy                	:1; 	//bit set if TDAU communication is busy (do not initiate TDAU_PT command if busy
			ULONG32	FwVersion           	:16; 	//contains the major & minor version number, Data of 0x010A would indicate a version of 01.10.
			ULONG32	DiodeReadErrChannel1	:1; 	//Diode read error received from TDAU if this bit is set
			ULONG32	DiodeReadErrChannel2	:1; 	//Diode read error received from TDAU if this bit is set
			ULONG32	DiodeReadErrChannel3	:1; 	//Diode read error received from TDAU if this bit is set
			ULONG32	DiodeReadErrChannel4	:1; 	//Diode read error received from TDAU if this bit is set
			ULONG32	LastAckStatus       	:1; 	//bit set if ACK recived on last TDAU communication
			ULONG32	RESERVED1           	:3;
		} fields;
} UN_TDAU_STATUS;

// Register: TDAU_DO_SCOCAL		Offset: OFFSET_TDAU_DO_SCOCAL
// Description: 	write to this register to start TDAU SCOCAL (if something changed in diode hw configuration)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	ScocalGo            	:1; 	//set this bit to start TDAU SCOCAL
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_TDAU_DO_SCOCAL;

// Register: JUNCTION_GEN_CFG_STATUS		Offset: OFFSET_JUNCTION_GEN_CFG_STATUS
// Description: 	general Tjunction cfg & status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	JunctionDataFromTIC 	:1; 	//T-Junction (Diode/PF) is updated in TesterInterface module from TIC if bit is set.
						                            //disable Diode & PF reading from TDAU and analog FP.
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_JUNCTION_GEN_CFG_STATUS;

// Register: TDAU_OPEN_I2C_WR		Offset: OFFSET_TDAU_OPEN_I2C_WR
// Description: 	use this register for writing any I2C command to the TDAU directly (for TDAU FW update for example) 
// 	          
typedef union {
	UCHAR value[55];
		struct {
			ULONG32	RegAdd              	:16; 	//number of bytes expected to read from TDAU (<=55)
			ULONG32	DataLength          	:7; 	//WrLen bytes to write to TDAU
			ULONG32	CmdType             	:1; 	//clear this bit to perform a write command to the TDAU. set this bit for read
			ULONG32	RESERVED0           	:8; 	//WrLen bytes to write to TDAU
			UCHAR	Data                [51]; 	//WrLen bytes to write to TDAU
		} fields;
} UN_TDAU_OPEN_I2C_WR;

// Register: TDAU_OPEN_I2C_RD		Offset: OFFSET_TDAU_OPEN_I2C_RD
// Description: 	use this register for reading any I2C command to the TDAU directly (for TDAU FW update for example) 
// 	          
typedef union {
	UCHAR value[55];
		struct {
			ULONG32	RegAdd              	:16; 	//bytes read from TDAU
			ULONG32	CmdTypeAndDataLength	:8; 	//bytes read from TDAU
			ULONG32	RESERVED0           	:8; 	//bytes read from TDAU
			UCHAR	Data                [51]; 	//bytes read from TDAU
		} fields;
} UN_TDAU_OPEN_I2C_RD;

// Register: TDAU_CONTROL		Offset: OFFSET_TDAU_CONTROL
typedef union {
	ULONG32 value;
		struct {
			ULONG32	StopAddTdau         	:1; 	//intec stops addressing TDAU if this bit is set.
						                            //to be used when before starting TDAU programming (with TdauOpenI2C interface)
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_TDAU_CONTROL;

// Register: FASTCAL_STATUS		Offset: OFFSET_FASTCAL_STATUS
// Description: 	holds Fastcal status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	CalibrationOffset1000R	:16; 	//calibration offset on the 1000k resistor
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_FASTCAL_STATUS;

// Register: SET_TCASE_UNDER_PROCHOT_CFG		Offset: OFFSET_SET_TCASE_UNDER_PROCHOT_CFG
// Description: 	contains the Set Tcase Under Prochot configuration.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	SetTcaseUnderProchotCh	:2; 	//select which Prochot (0/1/2/3) to use for bringing the Tcase under Prochot active temp (Prochot# and intec-D# are tied together)
			ULONG32	SetTcaseUnderProchotGo	:1; 	//set bit to start searching prochot temp, see PROCHOT_STATUS for result
			ULONG32	RESERVED0           	:5;
			ULONG32	SetTcaseUnderProchotOffset10T	:6; 	//write the temp offset from prochot temp to set the setpoint to.
						                            //Format:10T, range 0-64 (0C-6.4C)
						                            //for 0.5C enter 5.
			ULONG32	RESERVED1           	:18;
		} fields;
} UN_SET_TCASE_UNDER_PROCHOT_CFG;

//****************************************************************************
//* CASE Unit Registers Description
//****************************************************************************
#define TCASE0_D0_TEMP0       	0x00000001
#define TCASE0_D0_TEMP1        	0x00000002
#define TCASE0_D0_TEMP2        	0x00000004
#define TCASE0_D0_TEMP3        	0x00000008
#define TCASE0_D1_TEMP0        	0x00000010
#define TCASE0_D1_TEMP1        	0x00000020
#define TCASE0_D1_TEMP2        	0x00000040
#define TCASE0_D1_TEMP3        	0x00000080
#define TCASE0_D2_TEMP0        	0x00000100
#define TCASE0_D2_TEMP1        	0x00000200
#define TCASE0_D2_TEMP2       	0x00000400
#define TCASE0_D2_TEMP3       	0x00000800
#define TCASE0_D3_TEMP0       	0x00001000
#define TCASE0_D3_TEMP1       	0x00002000
#define TCASE0_D3_TEMP2       	0x00004000
#define TCASE0_D3_TEMP3      	0x00008000
// Register: GET_ALL_TCASES		Offset: OFFSET_GET_ALL_TCASES
// Description: 	get all temperatures from all InTEC-Ds:
// 	TimeStamp,Valid,D0Temp0,D0Temp1,...,D3Temp3
typedef union {
	UCHAR value[40];
		struct {
			ULONG32	Timestamp           	:32; 	//holds the InTEC Main timestamp
			ULONG32	Valid               	:16; 	//holds which of the TCase temperature is valid
			ULONG32	D0Temp0             	:16; 	//Temperatures in InTEC format
			ULONG32	D0Temp1             	:16; 	//Temperatures in InTEC format
			ULONG32	D0Temp2             	:16; 	//Temperatures in InTEC format
			ULONG32	D0Temp3             	:16; 	//Temperatures in InTEC format
			ULONG32	D1Temp0             	:16; 	//Temperatures in InTEC format
			ULONG32	D1Temp1             	:16; 	//Temperatures in InTEC format
			ULONG32	D1Temp2             	:16; 	//Temperatures in InTEC format
			ULONG32	D1Temp3             	:16; 	//Temperatures in InTEC format
			ULONG32	D2Temp0             	:16; 	//Temperatures in InTEC format
			ULONG32	D2Temp1             	:16; 	//Temperatures in InTEC format
			ULONG32	D2Temp2             	:16; 	//Temperatures in InTEC format
			ULONG32	D2Temp3             	:16; 	//Temperatures in InTEC format
			ULONG32	D3Temp0             	:16; 	//Temperatures in InTEC format
			ULONG32	D3Temp1             	:16; 	//Temperatures in InTEC format
			ULONG32	D3Temp2             	:16; 	//Temperatures in InTEC format
			ULONG32	D3Temp3             	:16; 	//Temperatures in InTEC format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_GET_ALL_TCASES;

//****************************************************************************
//* CONTROL Unit Registers Description
//****************************************************************************

// Register: GET_ALL_FEEDBACK_TEMPS		Offset: OFFSET_GET_ALL_FEEDBACK_TEMPS
// Description: 	holds the temperature that if used feedback in all InTEC-D,
// 	TimeStamp,Valid,D0Temp,D0Temp,...,D3Temp
typedef union {
	UCHAR value[16];
		struct {
			ULONG32	Timestamp           	:32; 	//temperature timestamp
			ULONG32	Valid               	:4; 	//temperature is valid if set
			ULONG32	RESERVED0           	:12;
			ULONG32	D0Temp              	:16; 	//InTEC Temp format
			ULONG32	D1Temp              	:16; 	//InTEC Temp format
			ULONG32	D2Temp              	:16; 	//InTEC Temp format
			ULONG32	D3Temp              	:16; 	//InTEC Temp format
			ULONG32	RESERVED1           	:16;
		} fields;
} UN_GET_ALL_FEEDBACK_TEMPS;

// Register: DIODE_N_DTS_OUTPUT_ALLOC		Offset: OFFSET_DIODE_N_DTS_OUTPUT_ALLOC
// Description: 	Diode and DTS allocation per InTEC-D
// 	          
// 	          
typedef union {
	LONG64 value;
		struct {
			ULONG32	IntecdAllocationDiode0	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDiode1	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDiode2	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDiode3	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS0	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS1	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS2	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS3	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS4	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS5	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS6	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS7	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS8	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS9	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS10	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS11	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS12	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS13	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS14	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	IntecdAllocationDTS15	:2; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
			ULONG32	RESERVED0           	:24; 	//Allocation to InTEC-D:
						                            //00 - InTEC-D0
						                            //01 - InTEC-D1
						                            //02 - InTEC-D2
						                            //03 - InTEC-D3
						                            //
		} fields;
} UN_DIODE_N_DTS_OUTPUT_ALLOC;

//****************************************************************************
//* TESTABILITY Unit Registers Description
//****************************************************************************

// Register: TESTABILITY_START		Offset: OFFSET_TESTABILITY_START
// Description: 	write to this register to start InTEC selftest, set the appropriate bit for the required test.
// 	Note: use the required HW & cables for each test. 
// 	InTEC-D#0 must be up and running.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	BenchStart          	:1; 	//start bench selftest, selftest HW/cables are required. bit is cleared at the end of the test.
			ULONG32	StandaloneStart     	:1; 	//start Standalone selftest, no special HW/cable required. bit is cleared at the end of the test.
			ULONG32	BasicFuncStart      	:1; 	//start Basic Functionality test, InTEC requires TH & platform connectivity. bit is cleared at the end of the test.
			ULONG32	RESERVED0           	:29;
		} fields;
} UN_TESTABILITY_START;

// Register: TESTABILITY_ABORT		Offset: OFFSET_TESTABILITY_ABORT
// Description: 	set the appropriate bit to abort the test.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	BenchAbort          	:1; 	//set to abort the bench selftest. bit is cleared at the start of new test.
			ULONG32	StandaloneAbort     	:1; 	//set to abort the standalone selftest. bit is cleared at the start of new test.
			ULONG32	BasicFuncAbort      	:1; 	//set to abort the basic functionality test. bit is cleared at the start of new test.
			ULONG32	RESERVED0           	:29;
		} fields;
} UN_TESTABILITY_ABORT;

// Register: BENCH_TEST_STATUS		Offset: OFFSET_BENCH_TEST_STATUS
// Description: 	Contains the Bench selftest status and result. Reading this register will give the last selftest results (stored in ROM).
typedef union {
	ULONG64 value;
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
						                            //
						                            //no communication with PECI Module if bit is set.
						                            //
						                            //check if U28 (PECI MCU) running (LEDs, Vdd = 3.3v, Avdd = 3.3v, Vcap = 1.8v??, MCLR = 3.3v)
						                            //
						                            //check relevant components:  R429, R165, R171-R173, R85, U11, R26, R46
						                            //
			ULONG32	PeciMonitorErr      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //test flow: cfg U32 (Mux8:1) to connect PECI Monitor input to MCU PECI Rx (3.3v level).
						                            //Set and clear MCU PECIMuxCtrl and check MCU PECI Rx.
						                            //Relevant components:
						                            //U32, R266, R488, R174.
						                            //R176.
						                            //R175, C43 - no stuff
						                            //
			ULONG32	PeciCtrlErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //Not used, will always show 0
						                            //
			ULONG32	PeciCircuitErr      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(Internal Vtt, PECI Rx/Tx, Level Shift & Switch)
						                            //
						                            //checked only if Vtt is ok, otherwise ignore this bit.
						                            //
						                            //test flow: cfg U32 (Mux8:1) to connect PECI0 input to MCU PECI Rx (1.2v level).
						                            //toggle the MCU PECI TX output and check if it sensed in the MCU PECI Rx (1.2v level).
						                            //Relevant components:
						                            //U32, U36, R510, R73, R491, R479, R488, R174.
						                            //U54, U37, U35 (Low), R490, R489, R487, R495,  R526, R194, C170.
						                            //
			ULONG32	PeciIntVttErr       	:1; 	//dev Internal Vtt failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //test flow: enable U12 (internal Vtt Reg) measure MCU VTT Sense pin (for 1.05v level).
						                            //
						                            //in case of error in internal Vtt PeciHwErr bit is also set
						                            //
						                            //Relevant components:
						                            //U12, R499, R188, C63, C64.
						                            //
			ULONG32	PeciMuxVttListenerErr	:1; 	//dev Vtt/Listener Mux failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //checked only if Vtt is ok, otherwise ignore this bit.
						                            //
						                            //test flow: cfg U32 (Mux8:1) to connect PECI Monitor input to MCU PECI Rx (3.3v level).
						                            //Set and clear MCU PECIMuxCtrl and check MCU PECI Rx.
						                            //
						                            //Relevant components:
						                            //U32, R266, R488, R174.
						                            //R176.
						                            //R175, C43 - no stuff
						                            //
			ULONG32	PeciMuxCtrlErr      	:1; 	//PECI Mux Ctrl failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //test flow: cfg U32 (Mux8:1) to connect PECI Monitor input to MCU PECI Rx (3.3v level).
						                            //Set and clear MCU PECIMuxCtrl and check MCU PECI Rx.
						                            //Relevant components:
						                            //U32, R266, R488, R174.
						                            //R176.
						                            //R175, C43 - no stuff
						                            //
			ULONG32	PeciSpiErr          	:1; 	//bad communication if bit is set.
			ULONG32	IntecDMcuErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
			ULONG32	TdauErr             	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	PeciLedsErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //checked manually by the user.
			ULONG32	MainLedsErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //checked manually by the user.
			ULONG32	BuzzerErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //checked manually by the user.
			ULONG32	Timeout             	:1; 	//Timout occurred if set (user didn't finish manual test on time).
			ULONG32	RESERVED0           	:25;
		} fields;
} UN_BENCH_TEST_STATUS;

// Register: BENCH_TEST_STATUS_DUMMY		Offset: OFFSET_BENCH_TEST_STATUS_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_BENCH_TEST_STATUS_DUMMY;

// Register: STANDALONE_TEST_STATUS		Offset: OFFSET_STANDALONE_TEST_STATUS
// Description: 	Contains the Standalone selftest status and result. Reading this register will give the last selftest results (note - not stored in ROM)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TestRun             	:1; 	//Test running if set. bit is cleared when test ended.
			ULONG32	TestEnded           	:1; 	//Test Ended if set. bit is cleared at the start of new test.
			ULONG32	TestPass            	:1; 	//Test finished successfuly (no errors) if set. bit is cleared if one of the modules has error. bit is cleared at the start of new test.
			ULONG32	TdauModuleErr       	:1; 	//xxxModule failed test if bit set.
						                            //check details in STANDALONE_TEST_xxx_MODULE_ERR_DETAILS 
						                            // bit is cleared at the start of new test.
			ULONG32	PeciModuleErr       	:1; 	//xxxModule failed test if bit set.
						                            //check details in STANDALONE_TEST_xxx_MODULE_ERR_DETAILS 
						                            // bit is cleared at the start of new test.
			ULONG32	ThModuleErr         	:1; 	//xxxModule failed test if bit set.
						                            //check details in STANDALONE_TEST_xxx_MODULE_ERR_DETAILS 
						                            // bit is cleared at the start of new test.
			ULONG32	CommAndIcModuleErr  	:1; 	//xxxModule failed test if bit set.
						                            //check details in STANDALONE_TEST_xxx_MODULE_ERR_DETAILS 
						                            // bit is cleared at the start of new test
			ULONG32	UiModuleErr         	:1; 	//xxxModule failed test if bit set.
						                            //check details in STANDALONE_TEST_xxx_MODULE_ERR_DETAILS 
						                            // bit is cleared at the start of new test
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_STANDALONE_TEST_STATUS;

// Register: BASIC_FUNC_TEST_STATUS		Offset: OFFSET_BASIC_FUNC_TEST_STATUS
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
} UN_BASIC_FUNC_TEST_STATUS;

// Enumeration for field PASSORFAIL of register: TESTABILITY_MASKS
#define TESTABILITY_ERROR_CHECK_MASK	0x7ffffffff8

// Enumeration for field TESTLIMITS of register: TESTABILITY_MASKS
#define TESTABILITY_PF_TOLERANCE_VAL_FOR_0_75V	0x000007d0
#define TESTABILITY_PF_EXPECTED_VAL_FOR_2_8V	0x00001d2a

// Register: TESTABILITY_MASKS		Offset: OFFSET_TESTABILITY_MASKS
// Description: 	hold masks for checking pass/fail results for FW
typedef union {
	UCHAR value[12];
		struct {
			ULONG64	PassOrFail          	:64;
			ULONG32	TestLimits          	:32; 	//Holds limit values for tests.
						                            //note that PF values naming is refered to voltages on the inpuit connector (before voltage divider), but the values are suitable for the ticks that the ADC will show after the voltage divider and conversion. 
		} fields;
} UN_TESTABILITY_MASKS;

// Register: STANDALONE_TEST_DIS		Offset: OFFSET_STANDALONE_TEST_DIS
// Description: 	select which tests to disable.
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TdauModuleTestDis   	:1; 	//set bit to disable this test
			ULONG32	ThermalDiodeExtUserCfgTestDis	:1; 	//set bit to disable this test
			ULONG32	PeciModuleTestDis   	:1; 	//set bit to disable this test
			ULONG32	PeciExtUserCfgTestDis	:1; 	//set bit to disable this test
			ULONG32	UiLcdTestDis        	:1; 	//set bit to disable this test
			ULONG32	UiOutOffButAndDisarrmTestDis	:1; 	//set bit to disable this test
			ULONG32	ThTecTestDis        	:1; 	//set bit to disable this test
			ULONG32	ThAssemblyTestDis   	:1; 	//set bit to disable this test
			ULONG32	ThCfgTestDis        	:1; 	//set bit to disable this test
			ULONG32	FastcalModuleTestDis	:1; 	//set bit to disable this test
			ULONG32	RESERVED0           	:22;
		} fields;
} UN_STANDALONE_TEST_DIS;

// Enumeration for field MAXALLOWEDTJAROUNDTC of register: STANDALONE_TEST_CFG
#define STANDALONE_TEST_CFG_MAX_TJ_FROM_TC	0x0000000e

// Enumeration for field ONBOARDDIODETEMPGBAROUNDROOMTEMP of register: STANDALONE_TEST_CFG
#define STANDALONE_TEST_CFG_ONBOARD_DIODE_GB_FROM_ROOM	0x0000000f

// Enumeration for field ONBOARDDIODEVOLTAGEGBAROUND550MV1000T of register: STANDALONE_TEST_CFG
#define STANDALONE_TEST_CFG_DIODE_V_GB_FROM_550MV	0x00000030

// Enumeration for field REMOTEDIODEVOLTAGEGBAROUND600MV1000T of register: STANDALONE_TEST_CFG
#define STANDALONE_TEST_CFG_REMOTE_DIODE_V_GB_FROM_600MV	0x000000c8

// Enumeration for field RESERVED of register: STANDALONE_TEST_CFG
#define STANDALONE_TEST_CFG_TDAU_SLOPE	0x0000eae8

// Enumeration for field RESERVED of register: STANDALONE_TEST_CFG
#define STANDALONE_TEST_CFG_TDAU_IF	0x3f8089a0
#define STANDALONE_TEST_CFG_TDAU_FORCE_CUR_100U	0x38d1b717
#define STANDALONE_TEST_CFG_TDAU_FORCE_CUR_120U	0x38fba882
#define STANDALONE_TEST_CFG_TDAU_FORCE_CUR_170U	0x39324207

// Register: STANDALONE_TEST_CFG		Offset: OFFSET_STANDALONE_TEST_CFG
// Description: 	hold the standalone test cfg values
typedef union {
	UCHAR value[20];
		struct {
			ULONG32	PeciPackagesToTest  	:4; 	//which packages to test uses according PECI cfg (preloaded by user in Run mode), 
						                            //
						                            //Format bitwise, 4bit, Example:
						                            //0x05==> test packages 0 & 2.
						                            //
						                            //
						                            //
			ULONG32	TakeCfgFromThEepromIfConn	:1; 	//Take test cfg from Thermal Head EEPROM (if connected),
						                            //if set, following will be taken from TH EEPROM:
						                            //ExpTecImp
			ULONG32	RESERVED0           	:3;
			ULONG32	MaxAllowedTjAroundTc	:8; 	//Max allowed Guardband of Tjunction around Tcase in which the Tjunction considered as ok. 
						                            //
						                            //Format: 1T, 8bit unsigned
						                            //Example: 
						                            //8C --> 0x08
						                            //
			ULONG32	OnboardDiodeTempGbAroundRoomTemp	:8; 	//Max allowed Guardband of Onboard Diode Temp around room temp (above or below), in which the Onboard diode considered as ok.
						                            //
						                            //Format: 1T, 8bit unsigned
						                            //Example: 
						                            //15C --> 15 (=0x0F)
						                            //
			ULONG32	IntecDToTest        	:4; 	//which InTEC-D to test, uses Tj to InTEC-D cfg/allocation (preloaded by user in Run mode), 
						                            //
						                            //Format bitwise, 4bit, Example:
						                            //0x05==> test InTEC-D 0 & 2.
						                            //
						                            //
						                            //
			ULONG32	RESERVED1           	:4;
			ULONG32	OnboardDiodeVoltageGbAround550mv1000T	:16; 	//Max allowed Guardband of Onboard Diode Voltage around 550mV (above or below), in which the Onboard diode considered as ok.
						                            //
						                            //Format: 1000T, 16bit unsigned
						                            //Example: 
						                            //0.05v (25C) --> 50 (=0x30)
						                            //
			ULONG32	RemoteDiodeVoltageGbAround600mv1000T	:16; 	//Max allowed Guardband of Remote Diode Voltage around 600mV (above or below), in which the Remote diode considered as found.
						                            //
						                            //Format: 1000T, 16bit unsigned
						                            //Example: 
						                            //0.2v --> 200 (=0xC8)
						                            //
			ULONG32	ExpTecImp           	:16; 	//Expected TEC impedance (Max allowed valut), if TakeCfgFromThEepromIfConn=1 intec uses the value stored in the thermal head eeprom.
						                            //
						                            //Format 1000T, Example:
						                            //1.000ohm ==> 1000 (0x3e8)
						                            //
						                            //Range 16bit:
						                            //[0,65535]
						                            //
			ULONG32	SetpointOffset      	:16; 	//offset from 20C to reach in TEC test for heating and cooling check
						                            //
						                            //Format 1T, Example:
						                            //10C ==> 10 (0x0A)
						                            //
						                            //Range 7bit:
						                            //[0,127]
						                            //
			ULONG32	TimeToSetpointLimit 	:16; 	//Time to reach new test setpoint (20C + SetpointOffset) and back
						                            //
						                            //Format 1T, Example:
						                            //10Sec ==> 10 (0x0A)
						                            //
						                            //Range 8bit:
						                            //[0,255]
						                            //
			ULONG32	TjToTcAllowedChangeInHotSetpoint	:8; 	//Max allowed change in Tjunction to Tcase delta after reaching test setpoint+offset in which the Tjunction considered as ok. 
						                            //
						                            //Format: 1T, 8bit unsigned
						                            //Example: 
						                            //4C --> 0x04
						                            //
			ULONG32	RESERVED2           	:8;
			ULONG32	RESERVED3           	:16; 	//TDAU Slope  (for remote diode)
						                            //
						                            //Format 10T, signed, 16bit, Example:
						                            //-565.0 => -5650 => 0xE9EE
						                            //-540.0 => -5400 => 0xEAE8
						                            //
						                            //TdauTestSlope
			ULONG32	RESERVED4           	:16; 	//TDAU Ideality Factor (for remote diode)
						                            //
						                            //Format FLOAT, Example:
						                            //1.028 ==> 0x3F8089A0
						                            //
						                            //TdauTestIf
						                            //
		} fields;
} UN_STANDALONE_TEST_CFG;

// Register: STANDALONE_TEST_CFG_DUMMY1		Offset: OFFSET_STANDALONE_TEST_CFG_DUMMY1
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_STANDALONE_TEST_CFG_DUMMY1;

// Register: STANDALONE_TEST_CFG_DUMMY2		Offset: OFFSET_STANDALONE_TEST_CFG_DUMMY2
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_STANDALONE_TEST_CFG_DUMMY2;

// Register: STANDALONE_TEST_CFG_DUMMY3		Offset: OFFSET_STANDALONE_TEST_CFG_DUMMY3
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_STANDALONE_TEST_CFG_DUMMY3;

// Register: STANDALONE_TEST_CFG_DUMMY4		Offset: OFFSET_STANDALONE_TEST_CFG_DUMMY4
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_STANDALONE_TEST_CFG_DUMMY4;

// Register: STANDALONE_TEST_CFG_DUMMY5		Offset: OFFSET_STANDALONE_TEST_CFG_DUMMY5
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_STANDALONE_TEST_CFG_DUMMY5;

// Register: STANDALONE_TEST_CFG_DUMMY6		Offset: OFFSET_STANDALONE_TEST_CFG_DUMMY6
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_STANDALONE_TEST_CFG_DUMMY6;

// Register: STANDALONE_TEST_TDAU_MODULE_ERR_DETAILS		Offset: OFFSET_STANDALONE_TEST_TDAU_MODULE_ERR_DETAILS
// Description: 	Contains the TDAU Module error details. Reading this register will give the last selftest results (note - not stored in ROM)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TdauCardErr         	:1; 	//Bad TDAU card.
						                            //wasn't able to read on board diode with TDAU (but able to read with fastcal)
			ULONG32	OnBoardDiodeCircuitryErr	:1; 	//Bad on board diode circuitry (Q19/U49 and related) 
						                            //contact intec support
			ULONG32	IntecDiodeCircuitryErr	:1; 	//Bad PCB diode path (no external or on board diode readout) 
						                            //contact intec support
			ULONG32	DutNotFound         	:1; 	//no DUT found.
						                            //(have Vtt, internal read ok, but no remote diode read.
			ULONG32	PlatformCableNotConnectedOrDutNotFound	:1; 	//Platfom cable not connected or DUT not found.
						                            //(didn't find ext Vtt, or ext diode read) 
			ULONG32	BadDiodeRouting     	:1; 	//Bad Diode Routing due to bad platform wiring/jumpering or bad diode wiring in Platfom cable 
						                            //(found ext Vtt & PECI but no ext diode read) 
			ULONG32	BadDiodeTestCfg     	:1; 	//bad diode test cfg (TdauTestIf Or TdauTestBeta).
						                            //(have remote diode readout with user's cfg but not with test cfg)
			ULONG32	UserCfgNoChEnabled  	:1; 	//User cfg warning  - no diode ch is selected to read although diodes were found.
			ULONG32	ExtUserCfgEnableCh3_0	:4; 	//User cfg warning  - ChX channel disabled. (Ext cfg test was  enabled) - chX not selected to read remote diode although diode is connected to ch (diode found using Test cfg).
						                            //recommendation to user - enable ChX (verify TDAU ch if cfg for it)
						                            //
						                            //bitwise - ch0 on LSb
			ULONG32	TdauBadCfgForCh3_0  	:4; 	//Diode found on ChX with test cfg but not found with user's cfg. (and Ch selected to read by user)
						                            //
						                            //bitwise - ch0 on LSb
			ULONG32	NoDiodeFoundOnCh3_0 	:4; 	//no diode found on chX although user requested to read it
						                            // (other diode found, so cable & DUT are connected, but cant read this ch diode with user's/test cfg.
						                            //
						                            //bitwise - ch0 on LSb
			ULONG32	TdauBadCfgTjLoThanTcForCh3_0	:4; 	//the Diode temp that was found on ChX with use cfg is lower than Tcase - consider changing this TDAU channel cfg 
						                            //
						                            //bitwise - ch0 on LSb
			ULONG32	TdauNotConnected    	:1; 	//TDAU wasn't found on I2C
			ULONG32	TdauBadOnBoardDiodeReadErr	:1; 	//Bad TDAU On-Board Diode measurement (might be issue with TDAU 2nd channel)
			ULONG32	RESERVED0           	:6;
		} fields;
} UN_STANDALONE_TEST_TDAU_MODULE_ERR_DETAILS;

// Register: STANDALONE_TEST_PECI_MODULE_ERR_DETAILS		Offset: OFFSET_STANDALONE_TEST_PECI_MODULE_ERR_DETAILS
// Description: 	Contains the PECI Module error details. Reading this register will give the last selftest results (note - not stored in ROM)
typedef union {
	LONG64 value;
		struct {
			ULONG32	PeciMcuErr          	:1; 	//PECI MCU Not Detected -  wasn't able to communication with MCU (not running/bad communication).
						                            //See suggested Resolution
						                            //of PECIModuleErr in “InTEC
						                            // Error and Events Handling” doc
			ULONG32	BadVttCircuitry     	:1; 	//Bad Vtt Circuitry (check U12, R499, R188, C63, C64)
			ULONG32	BadPeciCircuitry    	:1; 	//Bad PECI Circuitry (check U32, U36, R510, R73, R491, R479, R488, R174.
						                            //U54, U37, U35, R490, R489, R487, R495,  R526, R194, C170)
			ULONG32	TestCfgErrNoPackageSelected	:1; 	//Test Cfg Err - No Package selected for test
			ULONG32	BadUserCfgNotCfgForPackage3_0	:4; 	//PackageX selected for test but wasn’t cfg
						                            //bitwise field package0 on bit 0
			ULONG32	BadUserCfgNoMaxTempForPackage3_0	:4; 	//No MaxTemp selected to read for PackageX ->  need to update Package PECI cfg 
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	NoExtVttFoundForPackage3_0	:4; 	//no Ext Vtt found for PackageX
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	BadUserCfgPeciFreqTooHiForPackage3_0	:16; 	//PECI frequency too high for packageX.
						                            //
						                            //4 bits describe how much required to reduce PECI Frequency.
						                            //0x00 - represents that the current value is ok.
						                            //0x08 - represents that no suitable value found in 3 trials (each using half the previous freq)
						                            //
						                            //4 first bits desctibe package0... 
						                            //
						                            //Ex: bits=4 ==> use freq/(2^4)=freq/8
			ULONG32	DutFuseErrTjMaxIs0ForPackage3_0	:4; 	//TjMax read from DUT is 0 for PackageX.
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	DutFuseErrBadMaxTempForPackage3_0	:4; 	//Max Temp read from DUT is out of +/-MaxAllowedTjAroundTc for PackageX 
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	ExtCfgErrNoDtsFoundExcMaxTempForPackage3_0	:4; 	//ExtCfgErr - No DTS found except for MaxTemp for packageX although cfg ->  unlock DUT or Fuse DUT DTS params
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	NoPeciFoundForPackage3_0	:4; 	//No Client found (or Ext Vtt) for PackageX ->  check if cable connected/platform powered on/Unit passed boot
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	ExtCfgErrNoDtsCfgOtherThenMaxTempForPackage3_0	:4; 	//ExtCfgErr - packageZ don't have any DTS cfg other than MaxTemp - load PECI XML to intec
						                            //
			ULONG32	ExtCfgErrClientConnectedButNotSelectedToTest	:1; 	//ExtCfgErr - have client connected that wasn’t selected/cfg to test (didn't detect any client that was selected to test)
						                            //
			ULONG32	DutNotFoundOrCableNotConnected	:1; 	//DUT not found or platform cable not connected.
						                            //(no diode and no Vtt found)
						                            //
			ULONG32	PlatformNotPowerOrRoutingIssue	:1; 	//DUT not powered or have routing issue with PECI wires in platform cable.
						                            //(found diode but no Vtt found)
						                            //
			ULONG32	BadUserCfgMaxTempNotSelectedToPollForPackage3_0	:4; 	//MaxTemp sensor is not selected to poll for PackageX ->  need to update Package PECI cfg 
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	RESERVED0           	:1; 	//BadPeciMuxCtrlOrPeciMonitorCircuitr
						                            //
						                            //Bad Peci Mux Ctrl Circuitry 
						                            //Or 
						                            //Bad Peci Monitor Circuitry  
						                            //
						                            //(check U32, R266, R488, R174.
						                            //R176.
						                            //R175, C43 - no stuff)
			ULONG32	RESERVED1           	:4;
		} fields;
} UN_STANDALONE_TEST_PECI_MODULE_ERR_DETAILS;

// Register: STANDALONE_TEST_TH_MODULE_ERR_DETAILS		Offset: OFFSET_STANDALONE_TEST_TH_MODULE_ERR_DETAILS
// Description: 	Contains the Thermal Head Module error details. Reading this register will give the last selftest results (note - not stored in ROM)
typedef union {
	LONG64 value;
		struct {
			ULONG32	TestCfgErrNoIntecDSelected	:1; 	//Test Cfg Err - No InTEC-D selected for test
						                            //
						                            //Update IntecDToTest in test Cfg
			ULONG32	RESERVED0           	:3;
			ULONG32	McuErrIntecD3_0     	:4; 	//InTEC-Dx MCU Not Detected -  wasn't able to communication with MCU (not running/bad communication).
						                            //See suggested Resolution
						                            //of InTECD0Err in “InTEC
						                            // Error and Events Handling” doc
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	DcdcOverheatIntecD3_0	:4; 	//InTEC-Dx DC/DC Overheat
						                            //Check enclosure-fan connected and operating. If ok, Check if TH spec suitable for InTEC.
						                            //if spec ok, replace U16 (ADT7461)
						                            //Contact support
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	HbridgeOverheatIntecD3_0	:4; 	//InTEC-Dx H-Bridge Overheat
						                            //Check enclosure-fan connected and operating. If ok, Check TH spec suitable for InTEC.
						                            //if spec ok, replace Q3 (MMBT3904LT1G).
						                            //Contact support
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	OutOffButtonIntecD3_0	:4; 	//Can’t complete InTEC-Dx TEC testing since OUT OFF button is pressed
						                            //
						                            //Toggle OUT OFF button and retry
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	RESERVED1           	:4; 	//Can’t complete InTEC-Dx TEC testing since OUT OFF button is pressed
						                            //
						                            //Toggle OUT OFF button and retry
						                            //
						                            //bitwise field package0 on bit 0
						                            //
						                            //OutOffIntecD3_0
			ULONG32	OutOffFromHostIntecD3_0	:4; 	//Can’t complete InTEC-Dx TEC testing since OUT OFF From host communication command sent
						                            //
						                            //Enable output from Host and retry
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	FailureEventOntIntecD3_0	:4; 	//Can’t complete InTEC-Dx TEC testing since have an Event Failure
						                            //
						                            //Solve Event and retry
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	ThNotConnectedIntecD3_0	:4; 	//InTEC-Dx Thermal Head Not Connected 
						                            //
						                            //Connected TH and retry
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	BadTc0IntecD3_0     	:4; 	//InTEC-Dx Bad Tc#0 
						                            //
						                            //Connected/Replace Tcase#0 sensor and retry
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	TcaseTooHiForImpTestIntecD3_0	:4; 	//InTEC-Dx Tcase Too high for imp measurement
						                            //
						                            //Put TH in socket or wait for it
						                            // to cool to water temp
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	CantReachImpTestSpIntecD3_0	:4; 	//InTEC-Dx Can’t reach Imp test setpoint
						                            //
						                            //Check TEC connectivity
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	VoltageTooHiForImpTestIntecD3_0	:4; 	//InTEC-Dx TEC Voltage Too high for imp measurement
						                            //
						                            //Put TH in socket (DFF head??)
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	BadTecIntecD3_0     	:4; 	//InTEC-Dx Bad TEC (Imp Too Hi)
						                            //see TEC imp measurement result of appropriate intec-D
						                            //
						                            //Replace TEC
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	HeadNotInSocketIntecD3_0	:4; 	//InTEC-Dx Head not in socket
						                            //
						                            //Put head in socket or disable TTP in Events module
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	PsVoltTooLowIntecD3_0	:4; 	//Can’t complete InTEC-Dx TEC testing since  PS Voltage Too low
						                            //
						                            //Verify TEC PS connected and outputs desired value
						                            //
						                            //bitwise field package0 on bit 0
		} fields;
} UN_STANDALONE_TEST_TH_MODULE_ERR_DETAILS;

// Register: STANDALONE_TEST_TH_MODULE_ERR_DETAILS_1		Offset: OFFSET_STANDALONE_TEST_TH_MODULE_ERR_DETAILS_1
// Description: 	Contains the Thermal Head Module error details. Reading this register will give the last selftest results (note - not stored in ROM)
typedef union {
	LONG64 value;
		struct {
			ULONG32	CantReachHiSpIntecD3_0	:4; 	//Can’t reach TEC test high setpoint, 
						                            //
						                            //Bad Heating Circuitry (H-Bridge Q8,Q7,Q22,Q23
						                            //Control: D13,U27,U47,U18 and their circuitry)
						                            //
						                            //Contact Support
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	CantReachLoSpIntecD3_0	:4; 	//Can’t reach TEC test low  setpoint, 
						                            //
						                            //Bad Cooling Circuitry (H-Bridge Q24,Q25,Q5,Q4
						                            //Control : D8,U27,U47,U46
						                            // and their circuitry)
						                            //
						                            //Contact Support
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	BadCurrentSensorIntecD3_0	:4; 	//Bad Current sensor ACS713 (U24)
						                            //
						                            //contact support
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	NoTjForThisIntecD3_0	:4; 	//Can’t complete InTEC-Dx TH Assembly testing since don’t have Tj for this InTEC-D
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	DisarmedIntecD3_0   	:4; 	//Can’t complete InTEC-Dx TEC testing since InTEC-D is Disarmed
						                            //
						                            //ReArm intec and retry
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	BadTecPolarityIntecD3_0	:4; 	//InTEC-Dx Bad TEC polarity
						                            //
						                            //change TEC wire connection or flip TEC assembly.
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	BadThAssemblyIntecD3_0	:4; 	//InTEC-Dx Bad TH assembly - Tj temp   too far from Tcase when changing setpoint (currently using Diode or DTS ch0, till channel allocation to multiple InTEC-Ds be implemented)
						                            //
						                            //Verify minimum power to DUT,Check thermal contact of thermal head to DUT or thermal head assembly. if both ok, verify Tj allocation to fits this InTEC-D.
						                            //
						                            //bitwise field package0 on bit 0
			ULONG32	RESERVED0           	:4;
			ULONG32	RESERVED1           	:8; 	//Holds InTEC-D0 impedance test result. 
						                            //
						                            //Format: 1000T, 16bit unsigned.
						                            //Ex: 1000 (0x3E8) ==> 1.000 (1ohm)
						                            //
						                            //ImpResInTECD0
						                            //
			ULONG32	RESERVED2           	:8; 	//Holds InTEC-D1 impedance test result. 
						                            //
						                            //Format: 1000T, 16bit unsigned.
						                            //Ex: 1000 (0x3E8) ==> 1.000 (1ohm)
						                            //
						                            //ImpResInTECD1
			ULONG32	RESERVED3           	:8; 	//Holds InTEC-D2 impedance test result. 
						                            //
						                            //Format: 1000T, 16bit unsigned.
						                            //Ex: 1000 (0x3E8) ==> 1.000 (1ohm)
						                            //
						                            //ImpResInTECD2
			ULONG32	RESERVED4           	:8; 	//Holds InTEC-D3 impedance test result. 
						                            //
						                            //Format: 1000T, 16bit unsigned.
						                            //Ex: 1000 (0x3E8) ==> 1.000 (1ohm)
						                            //
						                            //ImpResInTECD3
		} fields;
} UN_STANDALONE_TEST_TH_MODULE_ERR_DETAILS_1;

// Register: STANDALONE_TEST_COMM_AND_IC_MODULE_ERR_DETAILS		Offset: OFFSET_STANDALONE_TEST_COMM_AND_IC_MODULE_ERR_DETAILS
// Description: 	Contains the PCB Communication & IC Module error details. Reading this register will give the last selftest results (note - not stored in ROM)
// 	          
typedef union {
	LONG32 value;
		struct {
			ULONG32	SpiMasterErr        	:1; 	//No SPI slave devce detected-  
						                            //
						                            //Check if R26 and R46 assembled, if assembled   replace U11.
			ULONG32	I2cMasterErr        	:1; 	//No I2C slave devce detected-  
						                            //
						                            //Check if R134 and R135 are assembled, if assembled   probably one of the I2C slave components are stuck (IOExp, LCD in VFT UI).
						                            //power cycle intec when VFT UI is not connected, if problem not solved replace U48 (IO Exp)
			ULONG32	EepromErr           	:1; 	//EEPROM IC not responsive 
						                            //verify all EEPROM circuitry components are assembled, if all assembled - U15 should be replaced
			ULONG32	FlashErr            	:1; 	//Flash IC not responsive 
						                            //verify all Flash circuitry components are assembled, if all assembled - U14 should be replaced
			ULONG32	IoExpErr            	:1; 	//IO Expension IC not responsive 
						                            //verify all IO Expension circuitry components are assembled, if all assembled - U48 should be replaced
			ULONG32	RESERVED0           	:27;
		} fields;
} UN_STANDALONE_TEST_COMM_AND_IC_MODULE_ERR_DETAILS;

// Register: STANDALONE_TEST_UI_MODULE_ERR_DETAILS		Offset: OFFSET_STANDALONE_TEST_UI_MODULE_ERR_DETAILS
// Description: 	Contains the User Interface Module error details. Reading this register will give the last selftest results (note - not stored in ROM)
// 	          
typedef union {
	LONG32 value;
		struct {
			ULONG32	LcdErr              	:1; 	//LCD not responsive.
						                            //check if VFT UI connected (and select button is in the right possition).
						                            //if seems connected - try to replace the cable
						                            //
			ULONG32	Disarmed            	:1; 	//InTEC is disarmed, rearm intec to return to normal mode (and enable output to TEC).
						                            //toggle Arm and Disram modes by 4 sec press on ACK button or using the Arm/Rearm button in GUI.
			ULONG32	OutputOffButtonPressed	:1; 	//Output Off button is pressed, toggle the button to enable intec out to TEC.
						                            //
			ULONG32	RESERVED0           	:29;
		} fields;
} UN_STANDALONE_TEST_UI_MODULE_ERR_DETAILS;

// Register: STANDALONE_TEST_STAGE_STARTED		Offset: OFFSET_STANDALONE_TEST_STAGE_STARTED
// Description: 	check standalone internal tests stage
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TdauModuleTestStarted	:1; 	//if set this test Started
			ULONG32	ThermalDiodeExtUserCfgTestStarted	:1; 	//if set this test Started
			ULONG32	PeciModuleTestStarted	:1; 	//if set this test Started
			ULONG32	PeciExtUserCfgTestStarted	:1; 	//if set this test Started
			ULONG32	UiLcdTestStarted    	:1; 	//if set this test Started
			ULONG32	UiOutOffButAndDisarrmTestStarted	:1; 	//if set this test Started
			ULONG32	ThTecTestStarted    	:1; 	//if set this test Started
			ULONG32	ThAssemblyTestStarted	:1; 	//if set this test Started
			ULONG32	ThCfgTestStarted    	:1; 	//if set this test Started
			ULONG32	FastcalModuleTestStarted	:1; 	//if set this test Started
			ULONG32	RESERVED0           	:22;
		} fields;
} UN_STANDALONE_TEST_STAGE_STARTED;

// Register: STANDALONE_TEST_STAGE_ENDED		Offset: OFFSET_STANDALONE_TEST_STAGE_ENDED
// Description: 	check standalone internal tests stage
// 	          
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TdauModuleTestEnded 	:1; 	//if set this test ended
			ULONG32	ThermalDiodeExtUserCfgTestEnded	:1; 	//if set this test ended
			ULONG32	PeciModuleTestEnded 	:1; 	//if set this test ended
			ULONG32	PeciExtUserCfgTestEnded	:1; 	//if set this test ended
			ULONG32	UiLcdTestEnded      	:1; 	//if set this test ended
			ULONG32	UiOutOffButAndDisarrmTestEnded	:1; 	//if set this test ended
			ULONG32	ThTecTestEnded      	:1; 	//if set this test ended
			ULONG32	ThAssemblyTestEnded 	:1; 	//if set this test ended
			ULONG32	ThCfgTestEnded      	:1; 	//if set this test ended
			ULONG32	FastcalModuleTestEnded	:1; 	//if set this test ended
			ULONG32	RESERVED0           	:22;
		} fields;
} UN_STANDALONE_TEST_STAGE_ENDED;

//****************************************************************************
//* TESTER Unit Registers Description
//****************************************************************************

// Register: TE_GEN_FLAGS		Offset: OFFSET_TE_GEN_FLAGS
// Description: 	TIC General flags
typedef union {
	ULONG32 value;
		struct {
			ULONG32	NewStreamData       	:1; 	//new data from stream bus arrived if bit is set
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_TE_GEN_FLAGS;

// Register: TE_WORK_MODE		Offset: OFFSET_TE_WORK_MODE
// Description: 	Mode of work
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Mode                	:4; 	//use         T2I_RUN_DESCRIPTOR.TransactionType ENUM.
			ULONG32	RunModeChanged      	:1;
			ULONG32	RESERVED0           	:27;
		} fields;
} UN_TE_WORK_MODE;

// Register: TE_DATA_TO_TESTER		Offset: OFFSET_TE_DATA_TO_TESTER
// Description: 	Hold the data to tx to tester
typedef union {
	UCHAR value[28];
		struct {
			ULONG32	Status              	:32; 	//bitwise TBD
			ULONG32	TFeedback           	:32;
			ULONG32	Tc0                 	:32;
			ULONG32	Tpf                 	:32; 	//PF temp in InTEC Temp format
			ULONG32	Timestamp           	:32; 	//1ms count
			ULONG64	RESERVED0           	:64;
		} fields;
} UN_TE_DATA_TO_TESTER;

// Register: TE_INTEC_STATUS		Offset: OFFSET_TE_INTEC_STATUS
// Description: 	Holds InTEC basic status (bundle version / errors)
typedef union {
	UCHAR value[6];
		struct {
			ULONG32	Bundle              	:8;
			ULONG32	BootloadingState    	:8;
			ULONG32	SysErr              	:32;
		} fields;
} UN_TE_INTEC_STATUS;

// Register: TE_DATA_FROM_TESTER		Offset: OFFSET_TE_DATA_FROM_TESTER
// Description: 	Data rx from tester
typedef union {
	UCHAR value[28];
		struct {
			ULONG32	Diode0              	:32;
			ULONG32	Diode1              	:32;
			ULONG32	Diode2              	:32;
			ULONG32	Diode3              	:32;
			ULONG32	ControlSet          	:32;
			ULONG32	PF0                 	:32;
			ULONG32	DeltaTemp           	:32;
		} fields;
} UN_TE_DATA_FROM_TESTER;

// Register: TE_LAST_TIC_RX_TIME		Offset: OFFSET_TE_LAST_TIC_RX_TIME
// Description: 	holds the last tx time rx from TIC (Tester)
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Time                	:32;
		} fields;
} UN_TE_LAST_TIC_RX_TIME;

// Register: TE_BOOTLOADING_STATUS		Offset: OFFSET_TE_BOOTLOADING_STATUS
// Description: 	External device bootloading status 
typedef union {
	LONG32 value;
		struct {
			ULONG32	EnterBootloadingMode	:1; 	//set when request to enter bootloader mode received from host
			ULONG32	RESERVED0           	:1;
			ULONG32	DeviceComInBootMode 	:1; 	//set when communication reply received that external device is in bootloading mode
			ULONG32	DeviceComInAppMode  	:1; 	//set when communication reply received that external device is in application mode
			ULONG32	HaveDataToSendToDev 	:1; 	//set when we got data from host to send to the device
			ULONG32	HaveDataToSendToHost	:1; 	//set when we got data from device to send to the host
			ULONG32	RESERVED1           	:26;
		} fields;
} UN_TE_BOOTLOADING_STATUS;

// Register: TE_BOOTLOADING_ENTER		Offset: OFFSET_TE_BOOTLOADING_ENTER
// Description: 	write the device id in data field for setting it in Bootloading mode (first ext device on bit#1, local device on bit#0).
// 	from this point any data sent from bootloading interface will be sent to this selected device
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_TE_BOOTLOADING_ENTER;

// Register: TE_BOOTLOADING_ABORT		Offset: OFFSET_TE_BOOTLOADING_ABORT
// Description: 	write to this register will abort bootloading operation, and reset the bootloading status
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_TE_BOOTLOADING_ABORT;

// Register: TE_BOOTLOADING_GET_DATA_FROM_DEV		Offset: OFFSET_TE_BOOTLOADING_GET_DATA_FROM_DEV
// Description: 	get string from the device in bootloader mode (InTEC Header [6 B] + DATA [54 B] = 60 B)
typedef union {
	UCHAR value[54];
		struct {
			UCHAR	DataFromDev         [54];
		} fields;
} UN_TE_BOOTLOADING_GET_DATA_FROM_DEV;

// Register: TE_BOOTLOADING_SEND_DATA_TO_DEV		Offset: OFFSET_TE_BOOTLOADING_SEND_DATA_TO_DEV
// Description: 	send string to the device in bootloader mode (
// 	send: LEN [1B], DATA [LEN B])
typedef union {
	UCHAR value[51];
		struct {
			ULONG32	SendDataLen         	:8; 	//Length of data to send to ext device
			UCHAR	DataToSend          [50]; 	//Data to send to ext device
		} fields;
} UN_TE_BOOTLOADING_SEND_DATA_TO_DEV;

// Register: TE_FW_VERSION		Offset: OFFSET_TE_FW_VERSION
// Description: 	Firmware version 10T format
typedef union {
	LONG32 value;
		struct {
			ULONG32	FwVersion10T        	:16; 	//Firmware version 10T format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_TE_FW_VERSION;

//****************************************************************************
//* HIF Unit Registers Description
//****************************************************************************

// Register: IP_MODE		Offset: OFFSET_IP_MODE
// Description: 	select between Static IP and DHCP
typedef union {
	ULONG32 value;
		struct {
			ULONG32	EnableDHCP          	:1; 	//set this bit to enable DHCP mode, if clear intec will use static IP
			ULONG32	RESERVED0           	:31; 	//
						                            //
		} fields;
} UN_IP_MODE;

// Register: IP_ADDRESS		Offset: OFFSET_IP_ADDRESS
// Description: 	change the static IP address
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Byte0               	:8; 	//least significant number
			ULONG32	Byte1               	:8;
			ULONG32	Byte2               	:8;
			ULONG32	Byte3               	:8; 	//Most significant number
		} fields;
} UN_IP_ADDRESS;

// Register: IP_NETBIOS		Offset: OFFSET_IP_NETBIOS
// Description: 	hold the NetBIOS name
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	RESERVED0           [16];
		} fields;
} UN_IP_NETBIOS;

// Register: IP_NETBIOS_DUMMY		Offset: OFFSET_IP_NETBIOS_DUMMY
// Description: 	hold the NetBIOS name
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	RESERVED0           [16];
		} fields;
} UN_IP_NETBIOS_DUMMY;

// Register: IP_NETBIOS_DUMMY_1		Offset: OFFSET_IP_NETBIOS_DUMMY_1
// Description: 	hold the NetBIOS name
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	RESERVED0           [16];
		} fields;
} UN_IP_NETBIOS_DUMMY_1;

// Register: IP_NETBIOS_DUMMY_2		Offset: OFFSET_IP_NETBIOS_DUMMY_2
// Description: 	hold the NetBIOS name
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	RESERVED0           [16];
		} fields;
} UN_IP_NETBIOS_DUMMY_2;

// Register: IP_UPDATE_CFG		Offset: OFFSET_IP_UPDATE_CFG
// Description: 	only after writing to this register the cfg will be changed
typedef union {
	LONG32 value;
		struct {
			ULONG32	update              	:1; 	//set this bit to change the configuration
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_IP_UPDATE_CFG;

//****************************************************************************
//* FRU Unit Registers Description
//****************************************************************************

// Register: FRU		Offset: OFFSET_FRU
typedef union {
	UCHAR value[44];
		struct {
			ULONG32	DeviceID            	:8;
			ULONG32	Add                 	:16;
			ULONG32	TypeDataLen         	:8;
			UCHAR	RESERVED0           [40];
		} fields;
} UN_FRU;

//****************************************************************************
//* Units Description
//****************************************************************************

// Unit: GENERAL		Offset: OFFSET_UNIT_GENERAL
typedef struct ST_GENERAL{
	UN_FW_VERSION FW_VERSION;
	UN_GET_ALL_FW_VERSIONS GET_ALL_FW_VERSIONS;
	UN_DEVICE_TYPE DEVICE_TYPE;
	UN_RESET_TIMESTAMP RESET_TIMESTAMP;
	UN_INTEC_HW_CFG INTEC_HW_CFG;
	UN_INTEC_TIMESTAMP INTEC_TIMESTAMP;
	UN_INTEC_SERIAL INTEC_SERIAL;
	UN_INTEC_SERIAL_DUMMY INTEC_SERIAL_DUMMY;
	UN_INTEC_SERIAL_DUMMY_1 INTEC_SERIAL_DUMMY_1;
	UN_INTEC_SERIAL_DUMMY_2 INTEC_SERIAL_DUMMY_2;
	UN_INTEC_SYS_ERR_STATUS INTEC_SYS_ERR_STATUS;
	UN_CONNECTED_DEVICES CONNECTED_DEVICES;
	UN_DEVICE_NAME DEVICE_NAME;
	UN_DEVICE_NAME_DUMMY DEVICE_NAME_DUMMY;
	UN_DEVICE_NAME_DUMMY_1 DEVICE_NAME_DUMMY_1;
	UN_DEVICE_NAME_DUMMY_2 DEVICE_NAME_DUMMY_2;
	UN_SW_RESET SW_RESET;
	UN_GEN_FLAGS GEN_FLAGS;
	UN_WORK_MODE WORK_MODE;
	UN_EEPROM_DELETE EEPROM_DELETE;
	UN_PRODUCT_NAME PRODUCT_NAME;
	UN_PRODUCT_NAME_DUMMY PRODUCT_NAME_DUMMY;
	UN_PRODUCT_NAME_DUMMY_1 PRODUCT_NAME_DUMMY_1;
	UN_PRODUCT_NAME_DUMMY_2 PRODUCT_NAME_DUMMY_2;
	UN_EEPROM_STORE EEPROM_STORE;
	UN_UI_STATUS UI_STATUS;
	UN_GENERAL_STATUS GENERAL_STATUS;
	UN_DEVICE_TYPE_LEGACY DEVICE_TYPE_LEGACY;
	UN_EMULATION EMULATION;
	UN_UI_CONTROL UI_CONTROL;
	UN_SITE_NUM SITE_NUM;
	UN_GET_ADDITIONAL_SUBDEV_FW_VERSIONS GET_ADDITIONAL_SUBDEV_FW_VERSIONS;
	UN_MULTI_INTEC_X1 MULTI_INTEC_X1;
} ST_GENERAL_T;

// Unit: BOOTLOADING		Offset: OFFSET_UNIT_BOOTLOADING
typedef struct ST_BOOTLOADING{
	UN_BOOTLOADING_STATUS BOOTLOADING_STATUS;
	UN_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE BOOTLOADING_GET_DEVICES_IN_BOOT_MODE;
	UN_BOOTLOADING_ENTER BOOTLOADING_ENTER;
	UN_BOOTLOADING_ABORT BOOTLOADING_ABORT;
	UN_BOOTLOADING_GET_DATA_FROM_DEV BOOTLOADING_GET_DATA_FROM_DEV;
	UN_BOOTLOADING_SEND_DATA_TO_DEV BOOTLOADING_SEND_DATA_TO_DEV;
	UN_BOOTLOADING_BUFF BOOTLOADING_BUFF;
} ST_BOOTLOADING_T;

// Unit: JUNCTION		Offset: OFFSET_UNIT_JUNCTION
typedef struct ST_JUNCTION{
	UN_DIODE_CFG DIODE_CFG;
	UN_DIODE_STATUS DIODE_STATUS;
	UN_TDAU_PT_WR TDAU_PT_WR;
	UN_TDAU_PT_RD TDAU_PT_RD;
	UN_FASTCAL_GO FASTCAL_GO;
	UN_FASTCAL_COEF_DIODE0 FASTCAL_COEF_DIODE0;
	UN_FASTCAL_COEF_DIODE1 FASTCAL_COEF_DIODE1;
	UN_FASTCAL_COEF_DIODE2 FASTCAL_COEF_DIODE2;
	UN_FASTCAL_COEF_DIODE3 FASTCAL_COEF_DIODE3;
	UN_TDIODE0 TDIODE0;
	UN_TDIODE1 TDIODE1;
	UN_TDIODE2 TDIODE2;
	UN_TDIODE3 TDIODE3;
	UN_GET_ALL_TDIODES GET_ALL_TDIODES;
	UN_PF_CFG PF_CFG;
	UN_PF_STATUS PF_STATUS;
	UN_PF0_COEF PF0_COEF;
	UN_PF1_COEF PF1_COEF;
	UN_PF2_COEF PF2_COEF;
	UN_PF3_COEF PF3_COEF;
	UN_VPF0 VPF0;
	UN_VPF1 VPF1;
	UN_VPF2 VPF2;
	UN_VPF3 VPF3;
	UN_TPF0 TPF0;
	UN_TPF1 TPF1;
	UN_TPF2 TPF2;
	UN_TPF3 TPF3;
	UN_GET_ALL_TPF_VPF GET_ALL_TPF_VPF;
	UN_PROCHOT_CFG PROCHOT_CFG;
	UN_PROCHOT_STATUS PROCHOT_STATUS;
	UN_TDAU_CFG TDAU_CFG;
	UN_TDAU_STATUS TDAU_STATUS;
	UN_TDAU_DO_SCOCAL TDAU_DO_SCOCAL;
	UN_JUNCTION_GEN_CFG_STATUS JUNCTION_GEN_CFG_STATUS;
	UN_TDAU_OPEN_I2C_WR TDAU_OPEN_I2C_WR;
	UN_TDAU_OPEN_I2C_RD TDAU_OPEN_I2C_RD;
	UN_TDAU_CONTROL TDAU_CONTROL;
	UN_FASTCAL_STATUS FASTCAL_STATUS;
	UN_SET_TCASE_UNDER_PROCHOT_CFG SET_TCASE_UNDER_PROCHOT_CFG;
} ST_JUNCTION_T;

// Unit: CASE		Offset: OFFSET_UNIT_CASE
typedef struct ST_CASE{
	UN_GET_ALL_TCASES GET_ALL_TCASES;
} ST_CASE_T;

// Unit: CONTROL		Offset: OFFSET_UNIT_CONTROL
typedef struct ST_CONTROL{
	UN_GET_ALL_FEEDBACK_TEMPS GET_ALL_FEEDBACK_TEMPS;
	UN_DIODE_N_DTS_OUTPUT_ALLOC DIODE_N_DTS_OUTPUT_ALLOC;
} ST_CONTROL_T;

// Unit: TESTABILITY		Offset: OFFSET_UNIT_TESTABILITY
typedef struct ST_TESTABILITY{
	UN_TESTABILITY_START TESTABILITY_START;
	UN_TESTABILITY_ABORT TESTABILITY_ABORT;
	UN_BENCH_TEST_STATUS BENCH_TEST_STATUS;
	UN_BENCH_TEST_STATUS_DUMMY BENCH_TEST_STATUS_DUMMY;
	UN_STANDALONE_TEST_STATUS STANDALONE_TEST_STATUS;
	UN_BASIC_FUNC_TEST_STATUS BASIC_FUNC_TEST_STATUS;
	UN_TESTABILITY_MASKS TESTABILITY_MASKS;
	UN_STANDALONE_TEST_DIS STANDALONE_TEST_DIS;
	UN_STANDALONE_TEST_CFG STANDALONE_TEST_CFG;
	UN_STANDALONE_TEST_CFG_DUMMY1 STANDALONE_TEST_CFG_DUMMY1;
	UN_STANDALONE_TEST_CFG_DUMMY2 STANDALONE_TEST_CFG_DUMMY2;
	UN_STANDALONE_TEST_CFG_DUMMY3 STANDALONE_TEST_CFG_DUMMY3;
	UN_STANDALONE_TEST_CFG_DUMMY4 STANDALONE_TEST_CFG_DUMMY4;
	UN_STANDALONE_TEST_CFG_DUMMY5 STANDALONE_TEST_CFG_DUMMY5;
	UN_STANDALONE_TEST_CFG_DUMMY6 STANDALONE_TEST_CFG_DUMMY6;
	UN_STANDALONE_TEST_TDAU_MODULE_ERR_DETAILS STANDALONE_TEST_TDAU_MODULE_ERR_DETAILS;
	UN_STANDALONE_TEST_PECI_MODULE_ERR_DETAILS STANDALONE_TEST_PECI_MODULE_ERR_DETAILS;
	UN_STANDALONE_TEST_TH_MODULE_ERR_DETAILS STANDALONE_TEST_TH_MODULE_ERR_DETAILS;
	UN_STANDALONE_TEST_TH_MODULE_ERR_DETAILS_1 STANDALONE_TEST_TH_MODULE_ERR_DETAILS_1;
	UN_STANDALONE_TEST_COMM_AND_IC_MODULE_ERR_DETAILS STANDALONE_TEST_COMM_AND_IC_MODULE_ERR_DETAILS;
	UN_STANDALONE_TEST_UI_MODULE_ERR_DETAILS STANDALONE_TEST_UI_MODULE_ERR_DETAILS;
	UN_STANDALONE_TEST_STAGE_STARTED STANDALONE_TEST_STAGE_STARTED;
	UN_STANDALONE_TEST_STAGE_ENDED STANDALONE_TEST_STAGE_ENDED;
} ST_TESTABILITY_T;

// Unit: TESTER		Offset: OFFSET_UNIT_TESTER
typedef struct ST_TESTER{
	UN_TE_GEN_FLAGS TE_GEN_FLAGS;
	UN_TE_WORK_MODE TE_WORK_MODE;
	UN_TE_DATA_TO_TESTER TE_DATA_TO_TESTER;
	UN_TE_INTEC_STATUS TE_INTEC_STATUS;
	UN_TE_DATA_FROM_TESTER TE_DATA_FROM_TESTER;
	UN_TE_LAST_TIC_RX_TIME TE_LAST_TIC_RX_TIME;
	UN_TE_BOOTLOADING_STATUS TE_BOOTLOADING_STATUS;
	UN_TE_BOOTLOADING_ENTER TE_BOOTLOADING_ENTER;
	UN_TE_BOOTLOADING_ABORT TE_BOOTLOADING_ABORT;
	UN_TE_BOOTLOADING_GET_DATA_FROM_DEV TE_BOOTLOADING_GET_DATA_FROM_DEV;
	UN_TE_BOOTLOADING_SEND_DATA_TO_DEV TE_BOOTLOADING_SEND_DATA_TO_DEV;
	UN_TE_FW_VERSION TE_FW_VERSION;
} ST_TESTER_T;

// Unit: HIF		Offset: OFFSET_UNIT_HIF
typedef struct ST_HIF{
	UN_IP_MODE IP_MODE;
	UN_IP_ADDRESS IP_ADDRESS;
	UN_IP_NETBIOS IP_NETBIOS;
	UN_IP_NETBIOS_DUMMY IP_NETBIOS_DUMMY;
	UN_IP_NETBIOS_DUMMY_1 IP_NETBIOS_DUMMY_1;
	UN_IP_NETBIOS_DUMMY_2 IP_NETBIOS_DUMMY_2;
	UN_IP_UPDATE_CFG IP_UPDATE_CFG;
} ST_HIF_T;

// Unit: FRU		Offset: OFFSET_UNIT_FRU
typedef struct ST_FRU{
	UN_FRU FRU;
} ST_FRU_T;

#pragma pack(pop)                          // restore previous alignment
#endif //INTEC_DWDEFS_H

