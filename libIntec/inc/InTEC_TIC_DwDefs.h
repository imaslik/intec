#ifndef INTEC_TIC_DWDEFS_H
#define INTEC_TIC_DWDEFS_H

// -------------------------------------------------------------------------
// Register and Field Definitions
// -------------------------------------------------------------------------
#define	UNIT_T_GENERAL           	0
#define	UNIT_T_BOOTLOADING       	1
#define	UNIT_T_TESTABILITY       	2
#define	UNIT_T_FRU               	3

// Unit Offsets Definitions
#define	OFFSET_UNIT_T_GENERAL                  	0x00
#define	OFFSET_UNIT_T_BOOTLOADING              	0x100
#define	OFFSET_UNIT_T_TESTABILITY              	0x500
#define	OFFSET_UNIT_T_FRU                      	0xF00

//	UNIT T_GENERAL registers
#define	OFFSET_T_FW_VERSION        	0x00
#define	OFFSET_T_DEVICE_TYPE       	0x02
#define	OFFSET_T_SERIAL            	0x06
#define	OFFSET_T_SERIAL_DUMMY      	0x07
#define	OFFSET_T_SERIAL_DUMMY_1    	0x08
#define	OFFSET_T_SERIAL_DUMMY_2    	0x09
#define	OFFSET_T_SYS_ERR_STATUS    	0x0A
#define	OFFSET_T_CONNECTED_DEVICES 	0x0B
#define	OFFSET_T_DEVICE_NAME       	0x0C
#define	OFFSET_T_DEVICE_NAME_DUMMY 	0x0D
#define	OFFSET_T_DEVICE_NAME_DUMMY_1	0x0E
#define	OFFSET_T_DEVICE_NAME_DUMMY_2	0x0F
#define	OFFSET_T_SW_RESET          	0x10
#define	OFFSET_T_PRODUCT_NAME      	0x14
#define	OFFSET_T_PRODUCT_NAME_DUMMY	0x15
#define	OFFSET_T_PRODUCT_NAME_DUMMY_1	0x16
#define	OFFSET_T_PRODUCT_NAME_DUMMY_2	0x17
#define	OFFSET_T_DEVICE_TYPE_LEGACY	0xEE
#define	OFFSET_T_TIC_HW_CFG        	0x18

//	UNIT T_BOOTLOADING registers
#define	OFFSET_T_BOOTLOADING_STATUS	0x000
#define	OFFSET_T_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE	0x001
#define	OFFSET_T_BOOTLOADING_ENTER 	0x002
#define	OFFSET_T_BOOTLOADING_ABORT 	0x003
#define	OFFSET_T_BOOTLOADING_GET_DATA_FROM_DEV	0x004
#define	OFFSET_T_BOOTLOADING_SEND_DATA_TO_DEV	0x005
#define	OFFSET_T_BOOTLOADING_BUFF  	0x006

//	UNIT T_TESTABILITY registers
#define	OFFSET_T_TESTABILITY_START 	0x000
#define	OFFSET_T_TESTABILITY_ABORT 	0x001
#define	OFFSET_T_BENCH_TEST_STATUS 	0x002
#define	OFFSET_T_BENCH_TEST_STATUS_DUMMY	0x003
#define	OFFSET_T_STANDALONE_TEST_STATUS	0x004
#define	OFFSET_T_BASIC_FUNC_TEST_STATUS	0x005
#define	OFFSET_T_TESTABILITY_MASKS 	0x006

//	UNIT T_FRU registers
#define	OFFSET_T_FRU               	0x000

//****************************************************************************
//* T_GENERAL Unit Registers Description
//****************************************************************************

// Enumeration for field FWVERSION10T of register: T_FW_VERSION
#define TIC_FW_VERSION      	0x00000004

// Register: T_FW_VERSION		Offset: OFFSET_T_FW_VERSION
// Description: 	Firmware version 10T format
typedef union {
	LONG32 value;
		struct {
			ULONG32	FwVersion10T        	:16; 	//Firmware version 10T format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_T_FW_VERSION;

// Enumeration for field DEVTYPE of register: T_DEVICE_TYPE
#define DEVICE_TYPE_INTEC   	0x000000d2
#define DEVICE_TYPE_INTECD  	0x000000d3
#define DEVICE_TYPE_TIC     	0x000000fd

// Register: T_DEVICE_TYPE		Offset: OFFSET_T_DEVICE_TYPE
// Description: 	Device type (InTEC/InTEC-D/TIC/Other...)
typedef union {
	LONG32 value;
		struct {
			ULONG32	DevType             	:8; 	//Device type 
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_T_DEVICE_TYPE;

// Enumeration for field TICSERIALNUMBER of register: T_SERIAL
#define SERIAL_NUMBER_MAX_LEN	0x00000010

// Register: T_SERIAL		Offset: OFFSET_T_SERIAL
// Description: 	unique 5-character serial number that is stored in its nonvolatile memory 
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	TicSerialNumber     [16]; 	//TIC serial number
		} fields;
} UN_T_SERIAL;

// Register: T_SERIAL_DUMMY		Offset: OFFSET_T_SERIAL_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_SERIAL_DUMMY;

// Register: T_SERIAL_DUMMY_1		Offset: OFFSET_T_SERIAL_DUMMY_1
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_SERIAL_DUMMY_1;

// Register: T_SERIAL_DUMMY_2		Offset: OFFSET_T_SERIAL_DUMMY_2
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_SERIAL_DUMMY_2;

// Register: T_SYS_ERR_STATUS		Offset: OFFSET_T_SYS_ERR_STATUS
// Description: 	TIC System Error Status, holds the HW modules error indications
typedef union {
	ULONG32 value;
		struct {
			ULONG32	EEPROMErr           	:1; 	//EEPROM Error if bit is set
			ULONG32	RS422CmdBusErr      	:1; 	//RS422 Command Bus (UART1) Error if bit is set
			ULONG32	RS422StreamBusErr   	:1; 	//RS422 Stream Bus (UART4) Error if bit is set
			ULONG32	CanBusErr           	:1; 	//CANBUS Error if bit is set
			ULONG32	I2CMasterErr        	:1; 	//I2C Master Module (I2C1) Error if bit is set
			ULONG32	SPIMasterErr        	:1; 	//SPI Master Module (SPI1) Error if bit is set
			ULONG32	I2CSlaveErr         	:1; 	//I2C Slave Module (I2C2) Error if bit is set
			ULONG32	SPISlaveErr         	:1; 	//SPI Slave Module (SPI4) Error if bit is set
			ULONG32	InTECErr            	:1; 	//InTEC has Error or not connected if bit is set
			ULONG32	RESERVED0           	:23;
		} fields;
} UN_T_SYS_ERR_STATUS;

// Register: T_CONNECTED_DEVICES		Offset: OFFSET_T_CONNECTED_DEVICES
// Description: 	Contains which devices (uC/cards) connected
typedef union {
	LONG32 value;
		struct {
			ULONG32	TIC                 	:1; 	//Main uC connected if set (will be set if this register can be read by communication) 
			ULONG32	InTEC               	:1; 	//InTEC uC connected if set
			ULONG32	HDMT                	:1; 	//HDMT connected if set
			ULONG32	CMT                 	:1; 	//CMT connected if set
			ULONG32	RESERVED0           	:28; 	//RESERVED
		} fields;
} UN_T_CONNECTED_DEVICES;

// Enumeration for field DEVICENAME of register: T_DEVICE_NAME
#define INTEC_DEV_NAME_LEN  	0x00000010

// Register: T_DEVICE_NAME		Offset: OFFSET_T_DEVICE_NAME
// Description: 	contains theDevice name (16 characters, no '/0') of a connected device.
// 	write request for this read must contain the requested device ID in its data field.
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	DeviceName          [16]; 	//Device name (16 characters, no '/0')
		} fields;
} UN_T_DEVICE_NAME;

// Register: T_DEVICE_NAME_DUMMY		Offset: OFFSET_T_DEVICE_NAME_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_DEVICE_NAME_DUMMY;

// Register: T_DEVICE_NAME_DUMMY_1		Offset: OFFSET_T_DEVICE_NAME_DUMMY_1
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_DEVICE_NAME_DUMMY_1;

// Register: T_DEVICE_NAME_DUMMY_2		Offset: OFFSET_T_DEVICE_NAME_DUMMY_2
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_DEVICE_NAME_DUMMY_2;

// Register: T_SW_RESET		Offset: OFFSET_T_SW_RESET
// Description: 	Write any data to reset the device (soft reset of Main MCU)
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_SW_RESET;

// Register: T_PRODUCT_NAME		Offset: OFFSET_T_PRODUCT_NAME
// Description: 	Product name that had been stored in FRU
// 	          
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	ProductName         [16]; 	//Product name that had been stored in FRU
		} fields;
} UN_T_PRODUCT_NAME;

// Register: T_PRODUCT_NAME_DUMMY		Offset: OFFSET_T_PRODUCT_NAME_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_PRODUCT_NAME_DUMMY;

// Register: T_PRODUCT_NAME_DUMMY_1		Offset: OFFSET_T_PRODUCT_NAME_DUMMY_1
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_PRODUCT_NAME_DUMMY_1;

// Register: T_PRODUCT_NAME_DUMMY_2		Offset: OFFSET_T_PRODUCT_NAME_DUMMY_2
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_PRODUCT_NAME_DUMMY_2;

// Register: T_DEVICE_TYPE_LEGACY		Offset: OFFSET_T_DEVICE_TYPE_LEGACY
// Description: 	Device type (InTEC/InTEC-D/TIC/Other...)
// 	according Bootloader legacy mapping
typedef union {
	LONG32 value;
		struct {
			ULONG32	DevType             	:8; 	//Device type 
			ULONG32	RESERVED0           	:24;
		} fields;
} UN_T_DEVICE_TYPE_LEGACY;

// Register: T_TIC_HW_CFG		Offset: OFFSET_T_TIC_HW_CFG
// Description: 	holds the HW cfg bits
typedef union {
	ULONG32 value;
		struct {
			ULONG32	AddressBit0         	:1;
			ULONG32	AddressBit1         	:1;
			ULONG32	AddressBit2         	:1;
			ULONG32	AddressBit3         	:1;
			ULONG32	RESERVED0           	:3;
			ULONG32	Cmt1orHDMT0         	:1; 	//CMT cfg is on if bit is set, HDMT cfg if clear
			ULONG32	HwCfgBit0           	:1;
			ULONG32	HwCfgBit1           	:1;
			ULONG32	HwCfgBit2           	:1;
			ULONG32	HwCfgBit3           	:1;
			ULONG32	HwCfgBit4           	:1;
			ULONG32	RESERVED1           	:19;
		} fields;
} UN_T_TIC_HW_CFG;

//****************************************************************************
//* T_BOOTLOADING Unit Registers Description
//****************************************************************************

// Register: T_BOOTLOADING_STATUS		Offset: OFFSET_T_BOOTLOADING_STATUS
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
} UN_T_BOOTLOADING_STATUS;

// Enumeration for field INBOOTMODEMAIN of register: T_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE
#define MAIN_IN_BOOT_MODE   	0x00000001
#define PECI_MODULE_IN_BOOT_MODE	0x00000002
#define INTEC_D0_IN_BOOT_MODE	0x00000004
#define INTEC_D1_IN_BOOT_MODE	0x00000008
#define INTEC_D2_IN_BOOT_MODE	0x00000010
#define INTEC_D3_IN_BOOT_MODE	0x00000020

// Register: T_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE		Offset: OFFSET_T_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE
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
			ULONG32	RESERVED0           	:26;
		} fields;
} UN_T_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE;

// Register: T_BOOTLOADING_ENTER		Offset: OFFSET_T_BOOTLOADING_ENTER
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
			ULONG32	RESERVED0           	:26;
		} fields;
} UN_T_BOOTLOADING_ENTER;

// Register: T_BOOTLOADING_ABORT		Offset: OFFSET_T_BOOTLOADING_ABORT
// Description: 	write to this register will abort bootloading operation, and reset the bootloading status
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_BOOTLOADING_ABORT;

// Register: T_BOOTLOADING_GET_DATA_FROM_DEV		Offset: OFFSET_T_BOOTLOADING_GET_DATA_FROM_DEV
// Description: 	get string from the device in bootloader mode (InTEC Header [6 B] + DATA [54 B] = 60 B)
typedef union {
	UCHAR value[54];
		struct {
			UCHAR	DataFromDev         [54];
		} fields;
} UN_T_BOOTLOADING_GET_DATA_FROM_DEV;

// Register: T_BOOTLOADING_SEND_DATA_TO_DEV		Offset: OFFSET_T_BOOTLOADING_SEND_DATA_TO_DEV
// Description: 	send string to the device in bootloader mode (
// 	send: LEN [1B], DATA [LEN B])
typedef union {
	UCHAR value[51];
		struct {
			ULONG32	SendDataLen         	:8; 	//Length of data to send to ext device
			UCHAR	DataToSend          [50]; 	//Data to send to ext device
		} fields;
} UN_T_BOOTLOADING_SEND_DATA_TO_DEV;

// Enumeration for field HOSTTODEVBUFF of register: T_BOOTLOADING_BUFF
#define BOOTLOADING_HOST_TO_DEV_BUFFER_LEN	0x00000040

// Register: T_BOOTLOADING_BUFF		Offset: OFFSET_T_BOOTLOADING_BUFF
// Description: 	holds the bootloading buffers (internal use)
typedef union {
	LONG32 value;
		struct {
			ULONG32	HostToDevBuff       	:8; 	//stores the host data to send to the ext device
			ULONG32	DevToHostBuff       	:8; 	//stores the ext device data to send to the host
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_T_BOOTLOADING_BUFF;

//****************************************************************************
//* T_TESTABILITY Unit Registers Description
//****************************************************************************

// Register: T_TESTABILITY_START		Offset: OFFSET_T_TESTABILITY_START
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
} UN_T_TESTABILITY_START;

// Register: T_TESTABILITY_ABORT		Offset: OFFSET_T_TESTABILITY_ABORT
// Description: 	set the appropriate bit to abort the test.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	BenchAbort          	:1; 	//set to abort the bench selftest. bit is cleared at the start of new test.
			ULONG32	StandaloneAbort     	:1; 	//set to abort the standalone selftest. bit is cleared at the start of new test.
			ULONG32	BasicFuncAbort      	:1; 	//set to abort the basic functionality test. bit is cleared at the start of new test.
			ULONG32	RESERVED0           	:29;
		} fields;
} UN_T_TESTABILITY_ABORT;

// Register: T_BENCH_TEST_STATUS		Offset: OFFSET_T_BENCH_TEST_STATUS
// Description: 	Contains the Bench selftest status and result. Reading this register will give the last selftest results (stored in ROM).
typedef union {
	ULONG64 value;
		struct {
			ULONG32	TestRun             	:1; 	//Test running if set. bit is cleared when test ended.
			ULONG32	TestEnded           	:1; 	//Test Ended if set. bit is cleared at the start of new test.
			ULONG32	TestPass            	:1; 	//Test finished successfuly (no errors) if set. bit is cleared if one of the modules has error. bit is cleared at the start of new test.
			ULONG32	EepromErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //check U6 and resistors near it (R58,59,62,63,70).
						                            //if have also SPI Master Error check SPI serial resistors (R47,55)
			ULONG32	RS422CmdBusErr      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test
						                            //
						                            //check U2 and resistor near it (R1).
			ULONG32	RS422StreamBusErr   	:1; 	//dev failed test if bit set. bit is cleared at the start of new test
						                            //
						                            //check U4 and resistor near it (R9).
			ULONG32	CanBusErr           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have error with CANBUS tranceiver (U7) probably card won't get out of init, so we won't start testability and this bit won't be on, check if U7 assembled and R72.
						                            //
			ULONG32	I2cMasterErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //If have error, check if pullups are assembled (R52,53)
						                            //
			ULONG32	SpiMasterErr        	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have error, check serial resistors (R47,51,55)
			ULONG32	I2cSlaveErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have error verify slave pullup ressistors are not installed (R32,R98)
			ULONG32	SpiSlaveErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have SPI Slave Error but don't have SPI Master Error, check that SCK1 serial resistor is assembled (R51). this connected to SCK1 signal to the connector (EEPROM is connected dirctly  to the MCU)
			ULONG32	LcdErr              	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //If have this error check 5v and GND connectivity to the tester connector or I2C master interface.
						                            //ofcourse this error won't be displayed on LCD...
			ULONG32	DipSw0Err           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have this error, check the dipswitch (SW1) and pulldown resistor (R113)
			ULONG32	DipSw1Err           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test
						                            //
						                            //if have this error, check the dipswitch (SW1) and pulldown resistor (R114).
			ULONG32	DipSw2Err           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have this error, check the dipswitch (SW1) and pulldown resistor (R115)
			ULONG32	DipSw3Err           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have this error, check the dipswitch (SW1) and pulldown resistor (R116)
			ULONG32	DipSw4Err           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have this error, check the dipswitch (SW1), pulldown resistor (R116) and pullup resistor (R109)
			ULONG32	DipSw5Err           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have this error, check the dipswitch (SW1), pulldown resistor (R117) and pullup resistor (R108)
			ULONG32	DipSw6Err           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have this error, check the dipswitch (SW1), pulldown resistor (R119) and pullup resistor (R104)
			ULONG32	DipSw7Err           	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have this error, check the dipswitch (SW1), pulldown resistor (R120) and pullup resistor (R103)
			ULONG32	MainLedsErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //checked manually by the user.
						                            //
						                            //if have error, check that LEDs are assembled in the right polarity (LD1-LD9) , and that the serial resistor is assembled (R13,19,21,29,32,45,50,68,69,80)
			ULONG32	IO_TesterPresent_MainTrig_Err	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have error, separate between 2 assembly options:
						                            //1) U8 is not assembled:
						                            //check isolation bypass resistor (R28) assembled, check UEI_TESTER_PRESENT pulldown (R86) is assembled 
						                            //
						                            //2) U8 is assembled:
						                            //check isolation bypass resistor (R28) not assembled, check UEI_TESTER_PRESENT pulldown (R86) is assembled 
			ULONG32	IO_IntecConnected_PeciTrig_Err	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have error:
						                            //check mcu/connectors soldering,
			ULONG32	IO_IntecConnectedPullup_Err	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //if have error:
						                            //check INTEC_CONNECTED_N pullup resistor (R99) assembled,
			ULONG32	IO_ThermalOk_Fault_Err	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //checked manually by the user.
						                            //
						                            //
						                            //if have error, separate between 2 assembly options:
						                            //1) U8 is not assembled:
						                            //check isolation bypass resistor (R20) assembled, 
						                            //check Relay circuiry (R54,Q7,R107,D3,R49) assembled.
						                            //check FAULT_N pullip (R64) assembled and THERMAL_OK_FROM_INTEC pulldown (R60) is assembled 
						                            //
						                            //2) U8 is assembled:
						                            //check isolation bypass resistor (R20) not assembled, 
						                            //check Relay circuiry (R54,Q7,R107,D3,R49) assembled.
						                            //check FAULT_N pullip (R64) assembled and THERMAL_OK_FROM_INTEC pulldown (R60) is assembled 
						                            //
			ULONG32	RESERVED0           	:6;
			ULONG32	Timeout             	:1; 	//Timeout occurred if set (user didn't finish one of UI manual tests on time or DipSw is faulty).
			ULONG32	RESERVED1           	:32;
		} fields;
} UN_T_BENCH_TEST_STATUS;

// Register: T_BENCH_TEST_STATUS_DUMMY		Offset: OFFSET_T_BENCH_TEST_STATUS_DUMMY
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_T_BENCH_TEST_STATUS_DUMMY;

// Register: T_STANDALONE_TEST_STATUS		Offset: OFFSET_T_STANDALONE_TEST_STATUS
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
} UN_T_STANDALONE_TEST_STATUS;

// Register: T_BASIC_FUNC_TEST_STATUS		Offset: OFFSET_T_BASIC_FUNC_TEST_STATUS
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
} UN_T_BASIC_FUNC_TEST_STATUS;

// Enumeration for field PASSORFAIL of register: T_TESTABILITY_MASKS
#define TIC_TESTABILITY_ERROR_CHECK_MASK	0x01fffff8

// Register: T_TESTABILITY_MASKS		Offset: OFFSET_T_TESTABILITY_MASKS
// Description: 	hold masks for checking pass/fail results for FW
typedef union {
	UCHAR value[12];
		struct {
			ULONG64	PassOrFail          	:64;
			ULONG32	TestLimits          	:32; 	//Holds limit values for tests.
						                            //note that PF values naming is refered to voltages on the inpuit connector (before voltage divider), but the values are suitable for the ticks that the ADC will show after the voltage divider and conversion. 
		} fields;
} UN_T_TESTABILITY_MASKS;

//****************************************************************************
//* T_FRU Unit Registers Description
//****************************************************************************

// Register: T_FRU		Offset: OFFSET_T_FRU
typedef union {
	UCHAR value[44];
		struct {
			ULONG32	DeviceID            	:8;
			ULONG32	Add                 	:16;
			ULONG32	TypeDataLen         	:8;
			UCHAR	RESERVED0           [40];
		} fields;
} UN_T_FRU;

//****************************************************************************
//* Units Description
//****************************************************************************

// Unit: T_GENERAL		Offset: OFFSET_UNIT_T_GENERAL
typedef struct ST_T_GENERAL{
	UN_T_FW_VERSION T_FW_VERSION;
	UN_T_DEVICE_TYPE T_DEVICE_TYPE;
	UN_T_SERIAL T_SERIAL;
	UN_T_SERIAL_DUMMY T_SERIAL_DUMMY;
	UN_T_SERIAL_DUMMY_1 T_SERIAL_DUMMY_1;
	UN_T_SERIAL_DUMMY_2 T_SERIAL_DUMMY_2;
	UN_T_SYS_ERR_STATUS T_SYS_ERR_STATUS;
	UN_T_CONNECTED_DEVICES T_CONNECTED_DEVICES;
	UN_T_DEVICE_NAME T_DEVICE_NAME;
	UN_T_DEVICE_NAME_DUMMY T_DEVICE_NAME_DUMMY;
	UN_T_DEVICE_NAME_DUMMY_1 T_DEVICE_NAME_DUMMY_1;
	UN_T_DEVICE_NAME_DUMMY_2 T_DEVICE_NAME_DUMMY_2;
	UN_T_SW_RESET T_SW_RESET;
	UN_T_PRODUCT_NAME T_PRODUCT_NAME;
	UN_T_PRODUCT_NAME_DUMMY T_PRODUCT_NAME_DUMMY;
	UN_T_PRODUCT_NAME_DUMMY_1 T_PRODUCT_NAME_DUMMY_1;
	UN_T_PRODUCT_NAME_DUMMY_2 T_PRODUCT_NAME_DUMMY_2;
	UN_T_DEVICE_TYPE_LEGACY T_DEVICE_TYPE_LEGACY;
	UN_T_TIC_HW_CFG T_TIC_HW_CFG;
} ST_T_GENERAL_T;

// Unit: T_BOOTLOADING		Offset: OFFSET_UNIT_T_BOOTLOADING
typedef struct ST_T_BOOTLOADING{
	UN_T_BOOTLOADING_STATUS T_BOOTLOADING_STATUS;
	UN_T_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE T_BOOTLOADING_GET_DEVICES_IN_BOOT_MODE;
	UN_T_BOOTLOADING_ENTER T_BOOTLOADING_ENTER;
	UN_T_BOOTLOADING_ABORT T_BOOTLOADING_ABORT;
	UN_T_BOOTLOADING_GET_DATA_FROM_DEV T_BOOTLOADING_GET_DATA_FROM_DEV;
	UN_T_BOOTLOADING_SEND_DATA_TO_DEV T_BOOTLOADING_SEND_DATA_TO_DEV;
	UN_T_BOOTLOADING_BUFF T_BOOTLOADING_BUFF;
} ST_T_BOOTLOADING_T;

// Unit: T_TESTABILITY		Offset: OFFSET_UNIT_T_TESTABILITY
typedef struct ST_T_TESTABILITY{
	UN_T_TESTABILITY_START T_TESTABILITY_START;
	UN_T_TESTABILITY_ABORT T_TESTABILITY_ABORT;
	UN_T_BENCH_TEST_STATUS T_BENCH_TEST_STATUS;
	UN_T_BENCH_TEST_STATUS_DUMMY T_BENCH_TEST_STATUS_DUMMY;
	UN_T_STANDALONE_TEST_STATUS T_STANDALONE_TEST_STATUS;
	UN_T_BASIC_FUNC_TEST_STATUS T_BASIC_FUNC_TEST_STATUS;
	UN_T_TESTABILITY_MASKS T_TESTABILITY_MASKS;
} ST_T_TESTABILITY_T;

// Unit: T_FRU		Offset: OFFSET_UNIT_T_FRU
typedef struct ST_T_FRU{
	UN_T_FRU T_FRU;
} ST_T_FRU_T;

#endif //INTEC_TIC_DWDEFS_H

