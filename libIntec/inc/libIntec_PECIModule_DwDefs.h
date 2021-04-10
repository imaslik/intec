/*
 * PECIModule_DwDefs.h
 *
 *  Created on: Apr 8, 2021
 *      Author: svshared
 */

#ifndef INC_LIBINTEC_PECIMODULE_DWDEFS_H_
#define INC_LIBINTEC_PECIMODULE_DWDEFS_H_



#define ULONG32 unsigned int
#define LONG32 int
#define UCHAR unsigned char
#define LONG64 long long
#define ULONG64 unsigned long long

// -------------------------------------------------------------------------
// Register and Field Definitions
// -------------------------------------------------------------------------
#define	UNIT_P_GENERAL           	0
#define	UNIT_P_BOOTLOADING       	1
#define	UNIT_P_DTS_CFG           	2
#define	UNIT_P_DTS_STATUS        	3
#define	UNIT_P_PT                	4
#define	UNIT_P_TESTABILITY       	5

// Unit Offsets Definitions
#define	OFFSET_UNIT_P_GENERAL                  	0x00000000
#define	OFFSET_UNIT_P_BOOTLOADING              	0x100
#define	OFFSET_UNIT_P_DTS_CFG                  	0x200
#define	OFFSET_UNIT_P_DTS_STATUS               	0x300
#define	OFFSET_UNIT_P_PT                       	0x400
#define	OFFSET_UNIT_P_TESTABILITY              	0x00000700

//	UNIT P_GENERAL registers
#define	OFFSET_P_FW_VERSION        	0x0
#define	OFFSET_P_TIMESTAMP         	0x1
#define	OFFSET_P_RESET_TIMESTAMP   	0x2
#define	OFFSET_P_SERIAL            	0x3
#define	OFFSET_P_SERIAL_DUMMY      	0x4
#define	OFFSET_P_SYS_ERR_STATUS    	0x5
#define	OFFSET_P_DEVICE_NAME       	0x6
#define	OFFSET_P_DEVICE_NAME_DUMMY 	0x7
#define	OFFSET_P_DEVICE_NAME_DUMMY_1	0x8
#define	OFFSET_P_DEVICE_NAME_DUMMY_2	0x9
#define	OFFSET_P_SW_RESET          	0xA
#define	OFFSET_P_WORK_MODE         	0xB
#define	OFFSET_P_GEN_FLAGS         	0xC
#define	OFFSET_P_UPDATE_CFG        	0xD

//	UNIT P_BOOTLOADING registers
#define	OFFSET_P_BOOTLOADING_STATUS	0x000
#define	OFFSET_P_BOOTLOADING_ENTER 	0x001
#define	OFFSET_P_BOOTLOADING_ABORT 	0x002
#define	OFFSET_P_BOOTLOADING_GET_DATA_FROM_DEV	0x003
#define	OFFSET_P_BOOTLOADING_SEND_DATA_TO_DEV	0x004

//	UNIT P_DTS_CFG registers
#define	OFFSET_P_PECI_CFG          	0x000
#define	OFFSET_P_PECI_GEN_PARAMS   	0x001
#define	OFFSET_P_PECI_GEN_PARAMS_DUMMY	0x002
#define	OFFSET_P_CFG_DTS0          	0x003
#define	OFFSET_P_CFG_DTS1          	0x004
#define	OFFSET_P_CFG_DTS2          	0x005
#define	OFFSET_P_CFG_DTS3          	0x006
#define	OFFSET_P_CFG_DTS4          	0x007
#define	OFFSET_P_CFG_DTS5          	0x008
#define	OFFSET_P_CFG_DTS6          	0x009
#define	OFFSET_P_CFG_DTS7          	0x00A
#define	OFFSET_P_CFG_DTS8          	0x00B
#define	OFFSET_P_CFG_DTS9          	0x00C
#define	OFFSET_P_CFG_DTS10         	0x00D
#define	OFFSET_P_CFG_DTS11         	0x00E
#define	OFFSET_P_CFG_DTS12         	0x00F
#define	OFFSET_P_CFG_DTS13         	0x010
#define	OFFSET_P_CFG_DTS14         	0x011
#define	OFFSET_P_CFG_DTS15         	0x012
#define	OFFSET_P_CFG_DTS_UPDATE    	0x023
#define	OFFSET_P_PECI_GEN_PARAMS_CONT1	0x024
#define	OFFSET_P_PECI_GEN_PARAMS_CONT2	0x025
#define	OFFSET_P_CFG_NAME_DTS0     	0x026
#define	OFFSET_P_CFG_NAME_DTS0_DUMMY	0x027
#define	OFFSET_P_CFG_NAME_DTS1     	0x028
#define	OFFSET_P_CFG_NAME_DTS1_DUMMY	0x029
#define	OFFSET_P_CFG_NAME_DTS2     	0x02A
#define	OFFSET_P_CFG_NAME_DTS2_DUMMY	0x02B
#define	OFFSET_P_CFG_NAME_DTS3     	0x02C
#define	OFFSET_P_CFG_NAME_DTS3_DUMMY	0x02D
#define	OFFSET_P_CFG_NAME_DTS4     	0x02E
#define	OFFSET_P_CFG_NAME_DTS4_DUMMY	0x02F
#define	OFFSET_P_CFG_NAME_DTS5     	0x030
#define	OFFSET_P_CFG_NAME_DTS5_DUMMY	0x031
#define	OFFSET_P_CFG_NAME_DTS6     	0x032
#define	OFFSET_P_CFG_NAME_DTS6_DUMMY	0x033
#define	OFFSET_P_CFG_NAME_DTS7     	0x034
#define	OFFSET_P_CFG_NAME_DTS7_DUMMY	0x035
#define	OFFSET_P_CFG_NAME_DTS8     	0x036
#define	OFFSET_P_CFG_NAME_DTS8_DUMMY	0x037
#define	OFFSET_P_CFG_NAME_DTS9     	0x038
#define	OFFSET_P_CFG_NAME_DTS9_DUMMY	0x039
#define	OFFSET_P_CFG_NAME_DTS10    	0x03A
#define	OFFSET_P_CFG_NAME_DTS10_DUMMY	0x03B
#define	OFFSET_P_CFG_NAME_DTS11    	0x03C
#define	OFFSET_P_CFG_NAME_DTS11_DUMMY	0x03D
#define	OFFSET_P_CFG_NAME_DTS12    	0x03E
#define	OFFSET_P_CFG_NAME_DTS12_DUMMY	0x03F
#define	OFFSET_P_CFG_NAME_DTS13    	0x040
#define	OFFSET_P_CFG_NAME_DTS13_DUMMY	0x041
#define	OFFSET_P_CFG_NAME_DTS14    	0x042
#define	OFFSET_P_CFG_NAME_DTS14_DUMMY	0x043
#define	OFFSET_P_CFG_NAME_DTS15    	0x044
#define	OFFSET_P_CFG_NAME_DTS15_DUMMY	0x045

//	UNIT P_DTS_STATUS registers
#define	OFFSET_P_PECI_STATUS       	0x000
#define	OFFSET_P_STATUS_CLIENT0    	0x001
#define	OFFSET_P_STATUS_CLIENT1    	0x002
#define	OFFSET_P_STATUS_CLIENT2    	0x003
#define	OFFSET_P_STATUS_CLIENT3    	0x004
#define	OFFSET_P_TDTS0             	0x005
#define	OFFSET_P_TDTS1             	0x006
#define	OFFSET_P_TDTS2             	0x007
#define	OFFSET_P_TDTS3             	0x008
#define	OFFSET_P_TDTS4             	0x009
#define	OFFSET_P_TDTS5             	0x00A
#define	OFFSET_P_TDTS6             	0x00B
#define	OFFSET_P_TDTS7             	0x00C
#define	OFFSET_P_TDTS8             	0x00D
#define	OFFSET_P_TDTS9             	0x00E
#define	OFFSET_P_TDTS10            	0x00F
#define	OFFSET_P_TDTS11            	0x010
#define	OFFSET_P_TDTS12            	0x011
#define	OFFSET_P_TDTS13            	0x012
#define	OFFSET_P_TDTS14            	0x013
#define	OFFSET_P_TDTS15            	0x014
#define	OFFSET_P_GET_ALL_DTS       	0x015

//	UNIT P_PT registers
#define	OFFSET_P_PT_WR             	0x000
#define	OFFSET_P_PT_RD             	0x001
#define	OFFSET_P_PT_STORE          	0x002

//	UNIT P_TESTABILITY registers
#define	OFFSET_P_TESTABILITY_START 	0x000
#define	OFFSET_P_TESTABILITY_ABORT 	0x001
#define	OFFSET_P_BENCH_TEST_STATUS 	0x002
#define	OFFSET_P_STANDALONE_TEST_STATUS	0x003
#define	OFFSET_P_TESTABILITY_MASKS 	0x004

//****************************************************************************
//* P_GENERAL Unit Registers Description
//****************************************************************************

// Register: P_FW_VERSION		Offset: OFFSET_P_FW_VERSION
// Description: 	Firmware version 10T format
typedef union {
	LONG32 value;
		struct {
			ULONG32	FwVersion10T        	:16; 	//Firmware version 10T format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_P_FW_VERSION;

// Register: P_TIMESTAMP		Offset: OFFSET_P_TIMESTAMP
// Description: 	holds the PECI Module timestamp in 1ms counts
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Timestamp           	:32;
		} fields;
} UN_P_TIMESTAMP;

// Register: P_RESET_TIMESTAMP		Offset: OFFSET_P_RESET_TIMESTAMP
// Description: 	write 0x01 to this register to reset the Timestamp
typedef union {
	LONG32 value;
		struct {
			ULONG32	Reset               	:1; 	//set this bit to reset the timestamp
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_P_RESET_TIMESTAMP;

// Enumeration for field SERIALNUMBYTE0 of register: P_SERIAL
#define P_SERIAL_NUMBER_MAX_LEN	0x00000005

// Register: P_SERIAL		Offset: OFFSET_P_SERIAL
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
} UN_P_SERIAL;

// Register: P_SERIAL_DUMMY		Offset: OFFSET_P_SERIAL_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_P_SERIAL_DUMMY;

// Register: P_SYS_ERR_STATUS		Offset: OFFSET_P_SYS_ERR_STATUS
// Description: 	PECI Module System Error Status, holds the HW modules error indications
typedef union {
	ULONG32 value;
		struct {
			ULONG32	PeciMcuErr          	:1; 	//MCU error if bit set.
			ULONG32	PeciMonitorSwErr    	:1; 	//Monitor Sw error if bit set.
			ULONG32	IntVttErr           	:1; 	//Internal Vtt Error if bit set.
			ULONG32	PeciCircuitErr      	:1; 	//PECI circuitry error (internal loop) if bit set.
			ULONG32	RESERVED0           	:4;
			ULONG32	McuInBootMode       	:1; 	//MCU in bootloading mode if this bit is set
			ULONG32	McuNotInReqMode     	:1; 	//MCU not in the requested mode. see P_WORK_MODE for details
			ULONG32	RESERVED1           	:22;
		} fields;
} UN_P_SYS_ERR_STATUS;

// Enumeration for field DEVICENAME of register: P_DEVICE_NAME
#define PECI_MODULE_DEV_NAME_LEN	0x00000010

// Register: P_DEVICE_NAME		Offset: OFFSET_P_DEVICE_NAME
// Description: 	contains theDevice name (16 characters, no '/0') of a connected device.
// 	write request for this read must contain the requested device ID in its data field.
typedef union {
	UCHAR value[16];
		struct {
			UCHAR	DeviceName          [16]; 	//Device name (16 characters, no '/0')
		} fields;
} UN_P_DEVICE_NAME;

// Register: P_DEVICE_NAME_DUMMY		Offset: OFFSET_P_DEVICE_NAME_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_P_DEVICE_NAME_DUMMY;

// Register: P_DEVICE_NAME_DUMMY_1		Offset: OFFSET_P_DEVICE_NAME_DUMMY_1
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_P_DEVICE_NAME_DUMMY_1;

// Register: P_DEVICE_NAME_DUMMY_2		Offset: OFFSET_P_DEVICE_NAME_DUMMY_2
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_P_DEVICE_NAME_DUMMY_2;

// Register: P_SW_RESET		Offset: OFFSET_P_SW_RESET
// Description: 	Write any data to reset the device (soft reset of PECI Module MCU)
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_P_SW_RESET;

// Enumeration for field COUNTER of register: P_WORK_MODE
#define P_WORK_MODE_NOT_IN_RUN_CNT_LIMIT_MS	0x00000030

// Register: P_WORK_MODE		Offset: OFFSET_P_WORK_MODE
// Description: 	Holds current work mode (Run/Ping/...)
// 	use I2P_RUN_DESCRIPTOR.TransactionType ENUM.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Mode                	:4; 	//use I2P_RUN_DESCRIPTOR.TransactionType ENUM.
			ULONG32	RunModeChanged      	:1; 	//not in Run mode if bit is set, invalidate Run results (and enter safe mode if necessary) after Enum counts.
			ULONG32	RESERVED0           	:2;
			ULONG32	Counter             	:9; 	//counts number of mSec since mode is not in Run (for invalidating the results)
			ULONG32	RequestedMode       	:4; 	//holds the mode the Main MCU request from PECI Module (updated in Main MCU)
			ULONG32	RESERVED1           	:12;
		} fields;
} UN_P_WORK_MODE;

// Enumeration for field ENUMS of register: P_GEN_FLAGS
#define PASSTHROUGH_RD_DATA_SIZE	0x00000032
#define PASSTHROUGH_STORE_DATA_SIZE	0x00000129

// Register: P_GEN_FLAGS		Offset: OFFSET_P_GEN_FLAGS
// Description: 	holds general usage flags
typedef union {
	ULONG32 value;
		struct {
			ULONG32	UpdateSpiTxBuffer   	:1; 	//has data to load to SPI Tx buffer if bit is set.
			ULONG32	CompletePT          	:1; 	//Set if PT Tx and Rx(correct Rx) has been conducted and need to return to "RUN" mode
			ULONG32	ReceiveResponse     	:1; 	//when bit is set - host sent LastPacket and Main need to receive response from PECI module
			ULONG32	LoadNextPacket      	:1; 	//if bit is set - load next response packet from P_PT_STORE to P_PT_RD
						                            //no transactions with PECI module
			ULONG32	LastPacketNum       	:3; 	//Last packet number
			ULONG32	SendNewData         	:1; 	//if bit is set - send next Tx with NewData bit set
						                            //else clear NewData
			ULONG32	Enums               	:16; 	//see the enum field
			ULONG32	ResetPT             	:1; 	//reset PECI PassThrough if set
			ULONG32	RESERVED0           	:7;
		} fields;
} UN_P_GEN_FLAGS;

// Register: P_UPDATE_CFG		Offset: OFFSET_P_UPDATE_CFG
// Description: 	contains flags that indicates whats needed to be updated in PECI Module
typedef union {
	ULONG32 value;
		struct {
			ULONG32	DtsExCfg            	:1; 	//set this bit to send DTS extended configuration to PECI Module
			ULONG32	InvalidateDtsData   	:1; 	//set this bit to notify that DTS data needs to be invalidated (new cfg arrived or other)
			ULONG32	RESERVED0           	:30;
		} fields;
} UN_P_UPDATE_CFG;

//****************************************************************************
//* P_BOOTLOADING Unit Registers Description
//****************************************************************************

// Register: P_BOOTLOADING_STATUS		Offset: OFFSET_P_BOOTLOADING_STATUS
// Description: 	External device bootloading status
typedef union {
	LONG32 value;
		struct {
			ULONG32	EnterBootloadingMode	:1; 	//set when request to enter bootloader mode received from host
			ULONG32	RESERVED1           	:1;
			ULONG32	DeviceComInBootMode 	:1; 	//set when communication reply received that external device is in bootloading mode
			ULONG32	DeviceComInAppMode  	:1; 	//set when communication reply received that external device is in application mode
			ULONG32	RESERVED0           	:28;
		} fields;
} UN_P_BOOTLOADING_STATUS;

// Register: P_BOOTLOADING_ENTER		Offset: OFFSET_P_BOOTLOADING_ENTER
// Description: 	write this register for setting it in Bootloading mode
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_P_BOOTLOADING_ENTER;

// Register: P_BOOTLOADING_ABORT		Offset: OFFSET_P_BOOTLOADING_ABORT
// Description: 	write to this register will abort bootloading operation, and reset the bootloading status
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_P_BOOTLOADING_ABORT;

// Register: P_BOOTLOADING_GET_DATA_FROM_DEV		Offset: OFFSET_P_BOOTLOADING_GET_DATA_FROM_DEV
// Description: 	get string from the device in bootloader mode (InTEC Header [6 B] + DATA [54 B] = 60 B)
typedef union {
	UCHAR value[54];
		struct {
			UCHAR	DataFromDev         [54];
		} fields;
} UN_P_BOOTLOADING_GET_DATA_FROM_DEV;

// Register: P_BOOTLOADING_SEND_DATA_TO_DEV		Offset: OFFSET_P_BOOTLOADING_SEND_DATA_TO_DEV
// Description: 	send string to the device in bootloader mode (
// 	send: LEN [1B], DATA [LEN B])
typedef union {
	UCHAR value[51];
		struct {
			ULONG32	SendDataLen         	:8; 	//Length of data to send to ext device
			UCHAR	DataToSend          [50]; 	//Data to send to ext device
		} fields;
} UN_P_BOOTLOADING_SEND_DATA_TO_DEV;

//****************************************************************************
//* P_DTS_CFG Unit Registers Description
//****************************************************************************

// Enumeration for field POLLDTS of register: P_PECI_CFG
#define P_DTS_EN_IN0        	0x00000001
#define P_DTS_EN_IN1        	0x00000002
#define P_DTS_EN_IN2        	0x00000004
#define P_DTS_EN_IN3        	0x00000008
#define P_DTS_EN_IN4        	0x00000010
#define P_DTS_EN_IN5        	0x00000020
#define P_DTS_EN_IN6        	0x00000040
#define P_DTS_EN_IN7        	0x00000080
#define P_DTS_EN_IN8        	0x00000100
#define P_DTS_EN_IN9        	0x00000200
#define P_DTS_EN_IN10       	0x00000400
#define P_DTS_EN_IN11       	0x00000800
#define P_DTS_EN_IN12       	0x00001000
#define P_DTS_EN_IN13       	0x00002000
#define P_DTS_EN_IN14       	0x00004000
#define P_DTS_EN_IN15       	0x00008000

// Register: P_PECI_CFG		Offset: OFFSET_P_PECI_CFG
// Description: 	Holds the PECI configuration.
typedef union {
	int value;
	struct {
		unsigned int PollDts :16; 	//Bitewise, set the bit to enable the appropriate DTS input readout. (Tcase0 is enabled by default)
		unsigned RESERVED0   :16;
	} fields;
} UN_P_PECI_CFG;

// Register: P_PECI_GEN_PARAMS		Offset: OFFSET_P_PECI_GEN_PARAMS
// Description: 	Configure PECI parameters
typedef union {
	LONG64 value;
		struct {
			ULONG32	EnMasterMode        	:1; 	//Set this bit to enable PECI master mode, clear this bit to enable Listener mode
			ULONG32	EnOnBoardVtt        	:1; 	//Set this bit to enable the on board Vtt regulator (and not the external Vtt reference)
			ULONG32	EnAutoTjMax         	:1; 	//Set this bit for getting the TjMax from PECI client, Clear this bit for using a user defined TjMax
			ULONG32	RESERVED0           	:5;
			ULONG32	ManualTjMax         	:8; 	//TjMax reference value for PECI temperature calculation, used only if EnAutoTjMax field is cleared
						                            //InTEC Temp Format.
			ULONG32	Frequency           	:16; 	//Determine the PECI frequecy by writing the period in 100ns ticks.
						                            //Example: for 1.473MHz set this field to 7 (1/[7*100nS]=1.4728MHz ==> value=10/FreqMHz)
			ULONG32	CmdsDelayUs         	:16; 	//write the delay between PECI commands in 0.8uS
			ULONG32	LoopsDelayMs        	:16; 	//write the delay between PECI loops in mS (after all PECI transactions finished and before the new loop of PECI commands starts)
		} fields;
} UN_P_PECI_GEN_PARAMS;

// Register: P_PECI_GEN_PARAMS_DUMMY		Offset: OFFSET_P_PECI_GEN_PARAMS_DUMMY
typedef union {
	LONG32 value;
		struct {
			ULONG32	RESERVED0           	:32;
		} fields;
} UN_P_PECI_GEN_PARAMS_DUMMY;

// Register: P_CFG_DTS0		Offset: OFFSET_P_CFG_DTS0
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS0;

// Register: P_CFG_DTS1		Offset: OFFSET_P_CFG_DTS1
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS1;

// Register: P_CFG_DTS2		Offset: OFFSET_P_CFG_DTS2
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS2;

// Register: P_CFG_DTS3		Offset: OFFSET_P_CFG_DTS3
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS3;

// Register: P_CFG_DTS4		Offset: OFFSET_P_CFG_DTS4
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS4;

// Register: P_CFG_DTS5		Offset: OFFSET_P_CFG_DTS5
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS5;

// Register: P_CFG_DTS6		Offset: OFFSET_P_CFG_DTS6
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS6;

// Register: P_CFG_DTS7		Offset: OFFSET_P_CFG_DTS7
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS7;

// Register: P_CFG_DTS8		Offset: OFFSET_P_CFG_DTS8
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS8;

// Register: P_CFG_DTS9		Offset: OFFSET_P_CFG_DTS9
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS9;

// Register: P_CFG_DTS10		Offset: OFFSET_P_CFG_DTS10
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS10;

// Register: P_CFG_DTS11		Offset: OFFSET_P_CFG_DTS11
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS11;

// Register: P_CFG_DTS12		Offset: OFFSET_P_CFG_DTS12
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS12;

// Register: P_CFG_DTS13		Offset: OFFSET_P_CFG_DTS13
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS13;

// Register: P_CFG_DTS14		Offset: OFFSET_P_CFG_DTS14
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS14;

// Register: P_CFG_DTS15		Offset: OFFSET_P_CFG_DTS15
// Description: 	holds DTS configuration - HW channel allocation, PECI client address & sensor index in RdPkgConfig space.
typedef union {
	LONG32 value;
		struct {
			ULONG32	PeciBus             	:4; 	//which HW channel to use (0x00-0x03, 0x0F to disable this input).
			ULONG32	EnMaxTemp           	:1; 	//set this bit to read the MaxTemp from selected PECI client, if this bit is set, there is no use in IndexDts field.
			ULONG32	RESERVED0           	:3;
			ULONG32	ClientAdd           	:8; 	//which PECI client to address(0x30-0x33).
			ULONG32	Index               	:8; 	//which DTS Index to address in RdPkgConfig space.
			ULONG32	RESERVED1           	:8;
		} fields;
} UN_P_CFG_DTS15;

// Register: P_CFG_DTS_UPDATE		Offset: OFFSET_P_CFG_DTS_UPDATE
// Description: 	Write to this register to update InTEC with data of all P_CFG_DTSX registers.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	UpdateDtsCfg        	:1;
			ULONG32	RESERVED0           	:31;
		} fields;
} UN_P_CFG_DTS_UPDATE;

// Register: P_PECI_GEN_PARAMS_CONT1		Offset: OFFSET_P_PECI_GEN_PARAMS_CONT1
// Description: 	Configure PECI parameters
typedef union {
	LONG32 value;
		struct {
			ULONG32	CmdsDelayUs         	:16; 	//write the delay between PECI commands in 0.8uS
			ULONG32	LoopsDelayMs        	:16; 	//write the delay between PECI loops in mS (after all PECI transactions finished and before the new loop of PECI commands starts)
		} fields;
} UN_P_PECI_GEN_PARAMS_CONT1;

// Register: P_PECI_GEN_PARAMS_CONT2		Offset: OFFSET_P_PECI_GEN_PARAMS_CONT2
// Description: 	Configure PECI parameters
typedef union {
	LONG32 value;
		struct {
			ULONG32	ManualTjMax         	:16; 	//TjMax reference value for PECI temperature calculation, used only if EnAutoTjMax field is cleared
						                            //InTEC Temp Format.
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_P_PECI_GEN_PARAMS_CONT2;

// Register: P_CFG_NAME_DTS0		Offset: OFFSET_P_CFG_NAME_DTS0
// Description: 	Hold DTS name (up to 7 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS0;

// Register: P_CFG_NAME_DTS0_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS0_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS0_DUMMY;

// Register: P_CFG_NAME_DTS1		Offset: OFFSET_P_CFG_NAME_DTS1
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS1;

// Register: P_CFG_NAME_DTS1_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS1_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS1_DUMMY;

// Register: P_CFG_NAME_DTS2		Offset: OFFSET_P_CFG_NAME_DTS2
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS2;

// Register: P_CFG_NAME_DTS2_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS2_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS2_DUMMY;

// Register: P_CFG_NAME_DTS3		Offset: OFFSET_P_CFG_NAME_DTS3
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS3;

// Register: P_CFG_NAME_DTS3_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS3_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS3_DUMMY;

// Register: P_CFG_NAME_DTS4		Offset: OFFSET_P_CFG_NAME_DTS4
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS4;

// Register: P_CFG_NAME_DTS4_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS4_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS4_DUMMY;

// Register: P_CFG_NAME_DTS5		Offset: OFFSET_P_CFG_NAME_DTS5
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS5;

// Register: P_CFG_NAME_DTS5_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS5_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS5_DUMMY;

// Register: P_CFG_NAME_DTS6		Offset: OFFSET_P_CFG_NAME_DTS6
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS6;

// Register: P_CFG_NAME_DTS6_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS6_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS6_DUMMY;

// Register: P_CFG_NAME_DTS7		Offset: OFFSET_P_CFG_NAME_DTS7
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS7;

// Register: P_CFG_NAME_DTS7_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS7_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS7_DUMMY;

// Register: P_CFG_NAME_DTS8		Offset: OFFSET_P_CFG_NAME_DTS8
// Description: 	Hold DTS name (up to 7 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS8;

// Register: P_CFG_NAME_DTS8_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS8_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS8_DUMMY;

// Register: P_CFG_NAME_DTS9		Offset: OFFSET_P_CFG_NAME_DTS9
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS9;

// Register: P_CFG_NAME_DTS9_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS9_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS9_DUMMY;

// Register: P_CFG_NAME_DTS10		Offset: OFFSET_P_CFG_NAME_DTS10
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS10;

// Register: P_CFG_NAME_DTS10_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS10_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS10_DUMMY;

// Register: P_CFG_NAME_DTS11		Offset: OFFSET_P_CFG_NAME_DTS11
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS11;

// Register: P_CFG_NAME_DTS11_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS11_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS11_DUMMY;

// Register: P_CFG_NAME_DTS12		Offset: OFFSET_P_CFG_NAME_DTS12
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS12;

// Register: P_CFG_NAME_DTS12_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS12_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS12_DUMMY;

// Register: P_CFG_NAME_DTS13		Offset: OFFSET_P_CFG_NAME_DTS13
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS13;

// Register: P_CFG_NAME_DTS13_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS13_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS13_DUMMY;

// Register: P_CFG_NAME_DTS14		Offset: OFFSET_P_CFG_NAME_DTS14
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS14;

// Register: P_CFG_NAME_DTS14_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS14_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS14_DUMMY;

// Register: P_CFG_NAME_DTS15		Offset: OFFSET_P_CFG_NAME_DTS15
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	UCHAR value[7];
		struct {
			UCHAR	name                [7]; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS15;

// Register: P_CFG_NAME_DTS15_DUMMY		Offset: OFFSET_P_CFG_NAME_DTS15_DUMMY
// Description: 	Hold DTS name (up to 8 chars)
typedef union {
	LONG64 value;
		struct {
			ULONG64	name                	:64; 	//Hold DTS name (up to 8 chars)
		} fields;
} UN_P_CFG_NAME_DTS15_DUMMY;

//****************************************************************************
//* P_DTS_STATUS Unit Registers Description
//****************************************************************************

// Register: P_PECI_STATUS		Offset: OFFSET_P_PECI_STATUS
// Description: 	Holds the module status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	RESERVED0           	:8;
			ULONG32	DetectedClients     	:4; 	//bitwise, bit is set if client connected. use STATUS_CLIENTX for detailed info
			ULONG32	RESERVED1           	:4;
			ULONG32	DetectedDTS         	:16; 	//bitwise, bit is set if valid DTS detected. see  CFG_DTSX for detailed info
		} fields;
} UN_P_PECI_STATUS;

// Register: P_STATUS_CLIENT0		Offset: OFFSET_P_STATUS_CLIENT0
// Description: 	Hold PECI Client polled data and status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Address             	:8; 	//Hold the PECI client address that this register holds
			ULONG32	PeciVersion10T      	:8; 	//Hold the client PECI version in 10T format
			ULONG32	ActualTjMax         	:8; 	//Hold the TjMax used for PECI temperature calculation. if using AutoTjMax is enabled, this field contain data that was read from the client, but if using Manual TjMax this value is taken from the Manual TjMax field in PECI_CFG register
			ULONG32	VttOk               	:1; 	//this bit is set if Vtt of this channel is ok
			ULONG32	Bus                 	:2; 	//Hold the PECI HW Bus that this register holds (0/1/2/3)
			ULONG32	MuxCtrlOnPolarity   	:1; 	//Hold the detected PECI Mux Control on Polarity :
						                            //0 - '0' for mux enable (default)
						                            //1 - '1' for mux enable
			ULONG32	TjMaxRxOnPECI       	:1; 	//For PECI listener mode, signals that TjMax data rxed on PECI bus and can switch to AutoTjMax from Manual value.
						                            //
						                            //TjMaxRxOnPECI
						                            //
			ULONG32	RESERVED0           	:2;
			ULONG32	Valid               	:1; 	//if set the client data is valid
		} fields;
} UN_P_STATUS_CLIENT0;

// Register: P_STATUS_CLIENT1		Offset: OFFSET_P_STATUS_CLIENT1
// Description: 	Hold PECI Client polled data and status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Address             	:8; 	//Hold the PECI client address that this register holds
			ULONG32	PeciVersion10T      	:8; 	//Hold the client PECI version in 10T format
			ULONG32	ActualTjMax         	:8; 	//Hold the TjMax used for PECI temperature calculation. if using AutoTjMax is enabled, this field contain data that was read from the client, but if using Manual TjMax this value is taken from the Manual TjMax field in PECI_CFG register
			ULONG32	VttOk               	:1; 	//this bit is set if Vtt of this channel is ok
			ULONG32	Bus                 	:2; 	//Hold the PECI HW Bus that this register holds (0/1/2/3)
			ULONG32	MuxCtrlOnPolarity   	:1; 	//Hold the detected PECI Mux Control on Polarity :
						                            //0 - '0' for mux enable (default)
						                            //1 - '1' for mux enable
						                            //
						                            //
			ULONG32	TjMaxRxOnPECI       	:1; 	//For PECI listener mode, signals that TjMax data rxed on PECI bus and can switch to AutoTjMax from Manual value.
						                            //
						                            //TjMaxRxOnPECI
						                            //
			ULONG32	RESERVED0           	:2;
			ULONG32	Valid               	:1; 	//if set the client data is valid
		} fields;
} UN_P_STATUS_CLIENT1;

// Register: P_STATUS_CLIENT2		Offset: OFFSET_P_STATUS_CLIENT2
// Description: 	Hold PECI Client polled data and status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Address             	:8; 	//Hold the PECI client address that this register holds
			ULONG32	PeciVersion10T      	:8; 	//Hold the client PECI version in 10T format
			ULONG32	ActualTjMax         	:8; 	//Hold the TjMax used for PECI temperature calculation. if using AutoTjMax is enabled, this field contain data that was read from the client, but if using Manual TjMax this value is taken from the Manual TjMax field in PECI_CFG register
			ULONG32	VttOk               	:1; 	//this bit is set if Vtt of this channel is ok
			ULONG32	Bus                 	:2; 	//Hold the PECI HW Bus that this register holds (0/1/2/3)
			ULONG32	MuxCtrlOnPolarity   	:1; 	//Hold the detected PECI Mux Control on Polarity :
						                            //0 - '0' for mux enable (default)
						                            //1 - '1' for mux enable
						                            //
						                            //
			ULONG32	TjMaxRxOnPECI       	:1; 	//For PECI listener mode, signals that TjMax data rxed on PECI bus and can switch to AutoTjMax from Manual value.
						                            //
						                            //
						                            //
			ULONG32	RESERVED0           	:2;
			ULONG32	Valid               	:1; 	//if set the client data is valid
						                            //
		} fields;
} UN_P_STATUS_CLIENT2;

// Register: P_STATUS_CLIENT3		Offset: OFFSET_P_STATUS_CLIENT3
// Description: 	Hold PECI Client polled data and status
typedef union {
	ULONG32 value;
		struct {
			ULONG32	Address             	:8; 	//Hold the PECI client address that this register holds
			ULONG32	PeciVersion10T      	:8; 	//Hold the client PECI version in 10T format
			ULONG32	ActualTjMax         	:8; 	//Hold the TjMax used for PECI temperature calculation. if using AutoTjMax is enabled, this field contain data that was read from the client, but if using Manual TjMax this value is taken from the Manual TjMax field in PECI_CFG register
			ULONG32	VttOk               	:1; 	//this bit is set if Vtt of this channel is ok
			ULONG32	Bus                 	:2; 	//Hold the PECI HW Bus that this register holds (0/1/2/3)
			ULONG32	MuxCtrlOnPolarity   	:1; 	//Hold the detected PECI Mux Control on Polarity :
						                            //0 - '0' for mux enable (default)
						                            //1 - '1' for mux enable
						                            //
						                            //
			ULONG32	TjMaxRxOnPECI       	:1; 	//For PECI listener mode, signals that TjMax data rxed on PECI bus and can switch to AutoTjMax from Manual value.
						                            //
						                            //
			ULONG32	RESERVED0           	:2;
			ULONG32	Valid               	:1; 	//if set the client data is valid
						                            //
		} fields;
} UN_P_STATUS_CLIENT3;

// Register: P_TDTS0		Offset: OFFSET_P_TDTS0
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS0;

// Register: P_TDTS1		Offset: OFFSET_P_TDTS1
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS1;

// Register: P_TDTS2		Offset: OFFSET_P_TDTS2
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS2;

// Register: P_TDTS3		Offset: OFFSET_P_TDTS3
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS3;

// Register: P_TDTS4		Offset: OFFSET_P_TDTS4
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS4;

// Register: P_TDTS5		Offset: OFFSET_P_TDTS5
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS5;

// Register: P_TDTS6		Offset: OFFSET_P_TDTS6
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS6;

// Register: P_TDTS7		Offset: OFFSET_P_TDTS7
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS7;

// Register: P_TDTS8		Offset: OFFSET_P_TDTS8
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS8;

// Register: P_TDTS9		Offset: OFFSET_P_TDTS9
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS9;

// Register: P_TDTS10		Offset: OFFSET_P_TDTS10
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS10;

// Register: P_TDTS11		Offset: OFFSET_P_TDTS11
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS11;

// Register: P_TDTS12		Offset: OFFSET_P_TDTS12
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS12;

// Register: P_TDTS13		Offset: OFFSET_P_TDTS13
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS13;

// Register: P_TDTS14		Offset: OFFSET_P_TDTS14
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS14;

// Register: P_TDTS15		Offset: OFFSET_P_TDTS15
// Description: 	holds the DTS temperature
typedef union {
	LONG32 value;
		struct {
			ULONG32	Temp                	:16; 	//holds this sensor temperature
			ULONG32	AllocatedToClient   	:2; 	//Denotes which PECI Client this DTS is allocated to (0/1/2/3)
			ULONG32	RESERVED0           	:14;
		} fields;
} UN_P_TDTS15;

// Register: P_GET_ALL_DTS		Offset: OFFSET_P_GET_ALL_DTS
// Description: 	get all temperatures from all DTSs:
// 	TimeStamp,Valid,Temp0,Temp1,...,Temp15
typedef union {
	UCHAR value[40];
		struct {
			ULONG32	Timestamp           	:32; 	//holds the InTEC-D timestamp
			ULONG32	Valid               	:16; 	//holds which of the DTS temperature is valid
			ULONG32	Temp0               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp1               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp2               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp3               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp4               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp5               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp6               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp7               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp8               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp9               	:16; 	//Temperatures in InTEC format
			ULONG32	Temp10              	:16; 	//Temperatures in InTEC format
			ULONG32	Temp11              	:16; 	//Temperatures in InTEC format
			ULONG32	Temp12              	:16; 	//Temperatures in InTEC format
			ULONG32	Temp13              	:16; 	//Temperatures in InTEC format
			ULONG32	Temp14              	:16; 	//Temperatures in InTEC format
			ULONG32	Temp15              	:16; 	//Temperatures in InTEC format
			ULONG32	RESERVED0           	:16;
		} fields;
} UN_P_GET_ALL_DTS;

//****************************************************************************
//* P_PT Unit Registers Description
//****************************************************************************
#define PECI_PASS_THROUGH_MAX_LENGTH 50
// Register: P_PT_WR		Offset: OFFSET_P_PT_WR
// Description: 	Hold PECI PassThrough control & cfg data
typedef union {
	UCHAR value[54];
		struct {
			ULONG32	LoadPackets         	:1; 	//set this bit to load a new transaction (can contain sevral packets)
			ULONG32	LastPacket          	:1; 	//if bit is set this is the last packet in curent PT cmd
			ULONG32	UsePeciBus          	:2; 	//[0-3] select which PECI HW bus to use
			ULONG32	ReadLength          	:9; 	//Number of bytes to receive in PECI transaction (only PECI msg bytes, w/o header) BUT including the 2 FCS bytes.
						                            //EX: send readlen=4 for reading 2 data byts + 2 FCS bytes
			ULONG32	PacketNum           	:3; 	//Packet number
			ULONG32	Address             	:8; 	//PECI address
			ULONG32	WriteLength         	:8; 	//Number of bytes to write in PECI transaction (only PECI msg bytes, w/o header)
			UCHAR	DataToSend          [50]; 	//Contain packet bytes(50) to send.
						                            //first byte to send comes first
		} fields;
} UN_P_PT_WR;

// Register: P_PT_RD		Offset: OFFSET_P_PT_RD
// Description: 	holds PECI passthrough status and read data
typedef union {
	UCHAR value[54];
		struct {
			ULONG32	Busy                	:1; 	//Passthrough module is busy if bit is set, wait till this bit is clear before using P_PT_WR
			ULONG32	DataReady           	:1; 	//If this bit is set transaction finished and data is valid in the data field
			ULONG32	LastRxPacket        	:1; 	//if bit is set this is the last packet of rx data from transaction.
			ULONG32	FCSHeaderErr        	:1; 	//If bit is set - error in Header FCS
			ULONG32	FCSMessageErr       	:1; 	//If bit is set - error in Message FCS
			ULONG32	PacketNum           	:4; 	//Packet number
			ULONG32	ResetModule         	:1; 	//Passthrough module will be resetted after the user write 1 to this field
			ULONG32	ReadLength          	:6; 	//Number of bytes to read in current packet (inluding 2 FCS bytes)
			ULONG32	CalcFcsHeader       	:8; 	//Calculated (by InTEC) Header FCS
			ULONG32	CalcFcsMessage      	:8; 	//Calculated (by InTEC) Maessage FCS
			UCHAR	RxData              [50]; 	//contain Rx packet bytes.
						                            //first byte received comes first (usually this is the header FCS)
						                            //
		} fields;
} UN_P_PT_RD;

// Register: P_PT_STORE		Offset: OFFSET_P_PT_STORE
// Description: 	Holds PECI PassThrough data (used for multiple packets commands): 3 header bytes and 297 data bytes
typedef union {
	UCHAR value[303];
		struct {
			ULONG32	Address             	:8; 	//PECI address
			ULONG32	Writeln             	:8; 	//Write length
			ULONG32	Readln              	:8; 	//Read length
			ULONG32	RESERVED0           	:8;
			ULONG32	CalcFcsHeader       	:8; 	//Calculated FCS Header
			ULONG32	CalcFcsMessage      	:8; 	//Calculated FCS Msg
			UCHAR	StoredData          [297]; 	//Contains data bytes to send to DUT
		} fields;
} UN_P_PT_STORE;

//****************************************************************************
//* P_TESTABILITY Unit Registers Description
//****************************************************************************

// Register: P_TESTABILITY_START		Offset: OFFSET_P_TESTABILITY_START
// Description: 	write to this register to start PECI Module selftest, set the appropriate bit for the required test.
// 	Note: use the required HW & cables for each test.
//
typedef union {
	ULONG32 value;
		struct {
			ULONG32	BenchStart          	:1; 	//start bench selftest, selftest HW/cables are required. bit is cleared at the end of the test.
			ULONG32	StandaloneStart     	:1; 	//start Standalone selftest, no special HW/cable required. bit is cleared at the end of the test.
			ULONG32	RESERVED0           	:30;
		} fields;
} UN_P_TESTABILITY_START;

// Register: P_TESTABILITY_ABORT		Offset: OFFSET_P_TESTABILITY_ABORT
// Description: 	set the appropriate bit to abort the test.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	BenchAbort          	:1; 	//set to abort the bench selftest. bit is cleared at the start of new test.
			ULONG32	StandaloneAbort     	:1; 	//set to abort the standalone selftest. bit is cleared at the start of new test.
			ULONG32	RESERVED0           	:30;
		} fields;
} UN_P_TESTABILITY_ABORT;

// Register: P_BENCH_TEST_STATUS		Offset: OFFSET_P_BENCH_TEST_STATUS
// Description: 	Contains the Bench selftest status and result.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TestRun             	:1; 	//Test running if set. bit is cleared when test ended.
			ULONG32	TestEnded           	:1; 	//Test Ended if set. bit is cleared at the start of new test.
			ULONG32	TestPass            	:1; 	//Test finished successfuly (no errors) if set. bit is cleared if one of the modules has error. bit is cleared at the start of new test.
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
			ULONG32	PeciCtrlErr         	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //Not used, will always show 0
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
			ULONG32	PeciIntVttErr       	:1; 	//devInternal Vtt failed test if bit set. bit is cleared at the start of new test.
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
						                            //
			ULONG32	PeciMuxCtrlErr      	:1; 	//devPECI Mux Ctrl failed test if bit set. bit is cleared at the start of new test.
						                            //
						                            //test flow: cfg U32 (Mux8:1) to connect PECI Monitor input to MCU PECI Rx (3.3v level).
						                            //Set and clear MCU PECIMuxCtrl and check MCU PECI Rx.
						                            //Relevant components:
						                            //U32, R266, R488, R174.
						                            //R176.
						                            //R175, C43 - no stuff
			ULONG32	PeciSpiErr          	:1; 	//bad communication if bit is set.
			ULONG32	RESERVED0           	:21;
		} fields;
} UN_P_BENCH_TEST_STATUS;

// Register: P_STANDALONE_TEST_STATUS		Offset: OFFSET_P_STANDALONE_TEST_STATUS
// Description: 	Contains the Standalone selftest status and result.
typedef union {
	ULONG32 value;
		struct {
			ULONG32	TestRun             	:1; 	//Test running if set. bit is cleared when test ended.
			ULONG32	TestEnded           	:1; 	//Test Ended if set. bit is cleared at the start of new test.
			ULONG32	TestPass            	:1; 	//Test finished successfuly (no errors) if set. bit is cleared if one of the modules has error. bit is cleared at the start of new test.
			ULONG32	PeciMcuErr          	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
			ULONG32	PeciCircuitErr      	:1; 	//dev failed test if bit set. bit is cleared at the start of new test.
						                            //(Internal Vtt, PECI Rx/Tx, Level Shift & Switch)
			ULONG32	RESERVED0           	:2;
			ULONG32	PeciSpiErr          	:1; 	//spi communication error if set
			ULONG32	RESERVED1           	:24;
		} fields;
} UN_P_STANDALONE_TEST_STATUS;

// Enumeration for field PASSORFAIL of register: P_TESTABILITY_MASKS
#define P_TESTABILITY_ERROR_CHECK_MASK	0x000003f8

// Register: P_TESTABILITY_MASKS		Offset: OFFSET_P_TESTABILITY_MASKS
// Description: 	hold masks for checking pass/fail results for FW
typedef union {
	LONG64 value;
		struct {
			ULONG32	PassOrFail          	:32;
			ULONG32	TestLimits          	:32;
		} fields;
} UN_P_TESTABILITY_MASKS;

//****************************************************************************
//* Units Description
//****************************************************************************

// Unit: P_GENERAL		Offset: OFFSET_UNIT_P_GENERAL
typedef struct ST_P_GENERAL{
	UN_P_FW_VERSION P_FW_VERSION;
	UN_P_TIMESTAMP P_TIMESTAMP;
	UN_P_RESET_TIMESTAMP P_RESET_TIMESTAMP;
	UN_P_SERIAL P_SERIAL;
	UN_P_SERIAL_DUMMY P_SERIAL_DUMMY;
	UN_P_SYS_ERR_STATUS P_SYS_ERR_STATUS;
	UN_P_DEVICE_NAME P_DEVICE_NAME;
	UN_P_DEVICE_NAME_DUMMY P_DEVICE_NAME_DUMMY;
	UN_P_DEVICE_NAME_DUMMY_1 P_DEVICE_NAME_DUMMY_1;
	UN_P_DEVICE_NAME_DUMMY_2 P_DEVICE_NAME_DUMMY_2;
	UN_P_SW_RESET P_SW_RESET;
	UN_P_WORK_MODE P_WORK_MODE;
	UN_P_GEN_FLAGS P_GEN_FLAGS;
	UN_P_UPDATE_CFG P_UPDATE_CFG;
} ST_P_GENERAL_T;

// Unit: P_BOOTLOADING		Offset: OFFSET_UNIT_P_BOOTLOADING
typedef struct ST_P_BOOTLOADING{
	UN_P_BOOTLOADING_STATUS P_BOOTLOADING_STATUS;
	UN_P_BOOTLOADING_ENTER P_BOOTLOADING_ENTER;
	UN_P_BOOTLOADING_ABORT P_BOOTLOADING_ABORT;
	UN_P_BOOTLOADING_GET_DATA_FROM_DEV P_BOOTLOADING_GET_DATA_FROM_DEV;
	UN_P_BOOTLOADING_SEND_DATA_TO_DEV P_BOOTLOADING_SEND_DATA_TO_DEV;
} ST_P_BOOTLOADING_T;

// Unit: P_DTS_CFG		Offset: OFFSET_UNIT_P_DTS_CFG
typedef struct ST_P_DTS_CFG{
	UN_P_PECI_CFG P_PECI_CFG;
	UN_P_PECI_GEN_PARAMS P_PECI_GEN_PARAMS;
	UN_P_PECI_GEN_PARAMS_DUMMY P_PECI_GEN_PARAMS_DUMMY;
	UN_P_CFG_DTS0 P_CFG_DTS0;
	UN_P_CFG_DTS1 P_CFG_DTS1;
	UN_P_CFG_DTS2 P_CFG_DTS2;
	UN_P_CFG_DTS3 P_CFG_DTS3;
	UN_P_CFG_DTS4 P_CFG_DTS4;
	UN_P_CFG_DTS5 P_CFG_DTS5;
	UN_P_CFG_DTS6 P_CFG_DTS6;
	UN_P_CFG_DTS7 P_CFG_DTS7;
	UN_P_CFG_DTS8 P_CFG_DTS8;
	UN_P_CFG_DTS9 P_CFG_DTS9;
	UN_P_CFG_DTS10 P_CFG_DTS10;
	UN_P_CFG_DTS11 P_CFG_DTS11;
	UN_P_CFG_DTS12 P_CFG_DTS12;
	UN_P_CFG_DTS13 P_CFG_DTS13;
	UN_P_CFG_DTS14 P_CFG_DTS14;
	UN_P_CFG_DTS15 P_CFG_DTS15;
    UN_P_CFG_NAME_DTS0 P_CFG_NAME_DTS0;
    UN_P_CFG_NAME_DTS1 P_CFG_NAME_DTS1;
    UN_P_CFG_NAME_DTS2 P_CFG_NAME_DTS2;
    UN_P_CFG_NAME_DTS3 P_CFG_NAME_DTS3;
    UN_P_CFG_NAME_DTS4 P_CFG_NAME_DTS4;
    UN_P_CFG_NAME_DTS5 P_CFG_NAME_DTS5;
    UN_P_CFG_NAME_DTS6 P_CFG_NAME_DTS6;
    UN_P_CFG_NAME_DTS7 P_CFG_NAME_DTS7;
    UN_P_CFG_NAME_DTS8 P_CFG_NAME_DTS8;
    UN_P_CFG_NAME_DTS9 P_CFG_NAME_DTS9;
    UN_P_CFG_NAME_DTS10 P_CFG_NAME_DTS10;
    UN_P_CFG_NAME_DTS11 P_CFG_NAME_DTS11;
    UN_P_CFG_NAME_DTS12 P_CFG_NAME_DTS12;
    UN_P_CFG_NAME_DTS13 P_CFG_NAME_DTS13;
    UN_P_CFG_NAME_DTS14 P_CFG_NAME_DTS14;
    UN_P_CFG_NAME_DTS15 P_CFG_NAME_DTS15;
	UN_P_CFG_DTS_UPDATE P_CFG_DTS_UPDATE;
	UN_P_PECI_GEN_PARAMS_CONT1 P_PECI_GEN_PARAMS_CONT1;
	UN_P_PECI_GEN_PARAMS_CONT2 P_PECI_GEN_PARAMS_CONT2;
} ST_P_DTS_CFG_T;

// Unit: P_DTS_STATUS		Offset: OFFSET_UNIT_P_DTS_STATUS
typedef struct ST_P_DTS_STATUS{
	UN_P_PECI_STATUS P_PECI_STATUS;
	UN_P_STATUS_CLIENT0 P_STATUS_CLIENT0;
	UN_P_STATUS_CLIENT1 P_STATUS_CLIENT1;
	UN_P_STATUS_CLIENT2 P_STATUS_CLIENT2;
	UN_P_STATUS_CLIENT3 P_STATUS_CLIENT3;
	UN_P_TDTS0 P_TDTS0;
	UN_P_TDTS1 P_TDTS1;
	UN_P_TDTS2 P_TDTS2;
	UN_P_TDTS3 P_TDTS3;
	UN_P_TDTS4 P_TDTS4;
	UN_P_TDTS5 P_TDTS5;
	UN_P_TDTS6 P_TDTS6;
	UN_P_TDTS7 P_TDTS7;
	UN_P_TDTS8 P_TDTS8;
	UN_P_TDTS9 P_TDTS9;
	UN_P_TDTS10 P_TDTS10;
	UN_P_TDTS11 P_TDTS11;
	UN_P_TDTS12 P_TDTS12;
	UN_P_TDTS13 P_TDTS13;
	UN_P_TDTS14 P_TDTS14;
	UN_P_TDTS15 P_TDTS15;
	UN_P_GET_ALL_DTS P_GET_ALL_DTS;
} ST_P_DTS_STATUS_T;

// Unit: P_PT		Offset: OFFSET_UNIT_P_PT
typedef struct ST_P_PT{
	UN_P_PT_WR P_PT_WR;
	UN_P_PT_RD P_PT_RD;
	UN_P_PT_STORE P_PT_STORE;
} ST_P_PT_T;

// Unit: P_TESTABILITY		Offset: OFFSET_UNIT_P_TESTABILITY
typedef struct ST_P_TESTABILITY{
	UN_P_TESTABILITY_START P_TESTABILITY_START;
	UN_P_TESTABILITY_ABORT P_TESTABILITY_ABORT;
	UN_P_BENCH_TEST_STATUS P_BENCH_TEST_STATUS;
	UN_P_STANDALONE_TEST_STATUS P_STANDALONE_TEST_STATUS;
	UN_P_TESTABILITY_MASKS P_TESTABILITY_MASKS;
} ST_P_TESTABILITY_T;




#endif /* INC_LIBINTEC_PECIMODULE_DWDEFS_H_ */
