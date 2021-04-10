/*
 * libIntec_DwDefs.h
 *
 *  Created on: Apr 8, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#ifndef INC_LIBINTEC_DWDEFS_H_
#define INC_LIBINTEC_DWDEFS_H_

#define ULONG32 unsigned int


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

typedef union {
	unsigned int value;
		struct {
		unsigned int	DetectedDiodes      	:4; 	//bitwise for indication of which thermal diode detected (set if ok)
		unsigned int	TDAUDetected        	:1; 	//set if TDAU detected,else implies working in FastCal mode
		unsigned int	RESERVED0           	:2;
		unsigned int	ModuleOk            	:1; 	//set if Tjunction module is ok, if cleared there is an error in one of the Tjunction modules
		unsigned int	FastCalFinished     	:4; 	//Bitwise, FastCal calibration finished successfully.
						                            //The appropriate bit is cleared when FastCalGo command received, set after successful calibration and cleared after reading this register
		unsigned int	RESERVED1           	:20;
		} fields;
} UN_DIODE_STATUS;


#endif /* INC_LIBINTEC_DWDEFS_H_ */
