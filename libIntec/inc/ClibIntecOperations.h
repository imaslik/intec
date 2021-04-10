/*
 * ClibIntecOperations.h
 *
 *  Created on: Apr 8, 2021
 *      Author: svshared
 */

#ifndef SRC_CLIBINTECOPERATIONS_H_
#define SRC_CLIBINTECOPERATIONS_H_


#include "libIntec.h"
#include <iostream>
#include <string.h>
#include "libIntec_DwDefs.h"
#include "libIntec_InTEC_DwDefs.h"
#include "libIntec_PECIModule_DwDefs.h"
#include "libIntec_InTEC_D_DwDefs.h"
#include <unistd.h>
#include <memory>
#include <map>
#include <cstdlib>
#include "ClibIntecXml.h"

typedef std::map<int, std::string,std::less<int>> Int2String;



#define MAX_EVENTS 32
#define MAX_ERRORS 32
#define FAILURE_EVENTS "Failures"
#define WARNING_EVENTS "Warnings"
#define NOTIFICATION_EVENTS "Notifications"
#define HARDWARE_ERRORS "HardWare_Errors"
#define HW_ERROR_EVENT_ID 15
#define TDAU_MODULE_STANDALONE_MASK_BIT 0x80000000
#define PECI_MODULE_STANDALONE_MASK_BIT 0x40000000
#define TH_MODULE_STANDALONE_MASK_BIT 0x20000000
#define COMM_AND_IC_MODULE_STANDALONE_MASK_BIT 0x10000000
#define UI_MODULE_STANDALONE_MASK_BIT 0x8000000

#define MAX_BUF_SIZE 512

typedef struct
{
	unsigned char id;
	unsigned char address;
	unsigned char bus;
	bool valid;
} PECI_PACKAGE;

typedef struct
{
	char name[DTS_NAME_LEN];
	unsigned char channel_id;
	unsigned char pkg_id;
	unsigned char sensor_num;
	bool EnMaxTemp;
	bool valid;
} PECI_DTS;

typedef struct
{
	bool EnMasterMode;
	bool EnOnBoardVtt;
	bool EnAutoTjMax;
	unsigned short frequency;
	unsigned short CmdsDelayUs;
	unsigned short LoopsDelayMs;
	unsigned short ManualTjMax;
} PECI_GEN_PARAMS;

typedef struct
{
	short address;
	char length;
	unsigned char* data;
} TDAU_REGISTER;

typedef struct
{
	char name[50];
	unsigned int typeMultiplier;
	unsigned int value;
	char description[100];
} SAFETY_EVENT_PARAM;

typedef struct
{
	char name[256];
	unsigned int id;
	bool disable;
	char description[512];
	char action[512];
	bool isDisable;
	bool stopTesting;
	unsigned int numOfParams;
	EventConfigurationParam params[5];
} SAFETY_EVENT;

typedef struct
{
	char name[256];
	unsigned int id;
	char description[512];
	char action[512];
} HARDWARE_ERROR;

class ClibIntecOperations {
public:
	ClibIntecOperations(unsigned int DevIndex);
	virtual ~ClibIntecOperations();
	virtual int Initialize(int reset);
	virtual const int IntecGetSysCardsConfiguration();
	virtual const int IntecSetDiodeInputs(bool enable, unsigned int mask);
	virtual const int IntecSetPFInputs(bool enable, unsigned int mask);	
	virtual const int IntecSetProcHotInputs(bool enable, unsigned int mask);
	virtual const int IntecClearProcHotEventsCounter(int input_num);
	virtual const int IntecSetPeciInputs(bool enable, unsigned int mask);
	virtual const int IntecClearPeciSensorsConfiguration();
	virtual const int IntecSetCaseInputs(int cardId,bool enable, unsigned int mask);
	virtual bool IsCardExist(int cardId);
	virtual const int IntecGetCaseInputs(int cardId,unsigned int *mask);
	virtual const int IntecLoadandConfigureEvents(int cardId,const char * eventsFileName, bool configureHW );
	virtual unsigned int calculateEventParamVal(std::string paramVal,std::string paramType);
	virtual unsigned short convertRealToIntecTemperature(float RealTemperature);
	virtual float convertIntecToRealTemperature(unsigned short IntecTemperature);
	virtual const int IntecSetEventParam(int cardId,EventType evType,int eventId,  EventConfigurationParam eventParam);
	virtual const int IntecGetDiodeInputs(unsigned int *mask);
	virtual const int IntecGetPFInputs(unsigned int *mask);
	virtual const int IntecGetProcHotInputs(unsigned int *mask);
	virtual const int IntecGetPeciInputs(unsigned int *mask);
	virtual bool buildIntecBenchSelfTestErrorMessages();
	virtual bool buildIntecStandaloneSelfTestErrorMessages();
	virtual bool buildIntecBasicFunctionalitySelfTestErrorMessages();
	virtual bool buildIntecDBenchSelfTestErrorMessages();
	virtual bool buildIntecDStandaloneSelfTestErrorMessages();
	virtual bool buildIntecDBasicFunctionalitySelfTestErrorMessages();
	virtual bool buildIntecDWaterModuleBenchTestErrorMessages();
	virtual const int peciFrequencyTablesInitialization();



	virtual const int IntecGetTemperature(int cardId,float *temprature, unsigned int * timestamp);
	virtual const int IntecGetTemperature(int cardId,unsigned short *temprature, unsigned int * timestamp);

protected:
	virtual const int IntecSetAllEventDisableEnable(int cardId,EventType evType);

public:
	int m_device_index;
	bool m_initialization_flag;

private:
	unsigned int m_readSize;

	bool Initialized_;
	bool TDAUDetected_;
	int  deviceIndex_;

	int maxFailureId_;
	int maxWarningId_;
	int maxNotificationId_;

	int maxIntecHErrorId_;
	int maxIntecDErrorId_;
	int InTECDCards_;
	bool PECIModuleExist_;

	unsigned int currentDiodeMask_;
	unsigned int currentPFMask_;
	unsigned int currentProcHOTMask_;
	unsigned int currentPeciMask_;
	unsigned int currentCaseMask_[4];
	std::map <std::string, TDAU_REGISTER*> gTDAUMap;

	std::map <unsigned int,unsigned int> peciFreq_IndexToDigital;
	std::map <unsigned int,unsigned int> peciFreq_DigitalToIndex;
	PECI_DTS peci_dts_arr[MAX_DTS];
	PECI_PACKAGE peci_pkg_arr[MAX_PACKAGES];
	//TODO look into why the compiler doesn't accept this line
	UN_P_PECI_GEN_PARAMS peci_general_params;

	SAFETY_EVENT failure_events[MAX_EVENTS];
	SAFETY_EVENT warning_events[MAX_EVENTS];
	SAFETY_EVENT notification_events[MAX_EVENTS];

	HARDWARE_ERROR IntecH_HW_errors[MAX_ERRORS] ;
	HARDWARE_ERROR IntecD_HW_errors[MAX_ERRORS] ;

	unsigned int readSize_;
	unsigned char readBuff_[READ_BUF_SIZE];
	unsigned int writeSize_;
	unsigned char writeBuff_[READ_BUF_SIZE];
	char msg_buf[MSG_BUF_SIZE];
	char workingDir_[MAX_BUF_SIZE];
	Int2String IntecBenchSelfTestErrorMessages;
	Int2String IntecStandaloneSelfTestErrorMessages;
	Int2String IntecBasicFunctionalitySelfTestErrorMessages;
	Int2String IntecDBenchSelfTestErrorMessages;
	Int2String IntecDStandaloneSelfTestErrorMessages;
	Int2String IntecDBasicFunctionalitySelfTestErrorMessages;
	Int2String IntecDWaterModuleBenchTestErrorMessages;
	char errBuf[512];
};

#endif /* SRC_CLIBINTECOPERATIONS_H_ */
