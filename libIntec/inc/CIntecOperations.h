#ifndef _CIntec_Operations_H_
#define _CIntec_Operations_H_

#include "IntecDLL.h"
#include "IIntecOperations.h"

#include <map>
#include "IntecXMLAPI.h"
#include "TDAUDefines.h"


#define __stringize(n) #n
#define __eval(line) __stringize(line)
#define todo(task) message(__FILE__ "(" __eval(__LINE__) ") : TODO: " task)
#define info(task) message(__FILE__ "(" __eval(__LINE__) ") : INFO: " task)

#define MAX_BUF_SIZE 512

typedef struct
{
	BYTE id;
	BYTE address;
	byte bus;
	bool valid;
} PECI_PACKAGE;

typedef struct
{
	char name[DTS_NAME_LEN];
	BYTE channel_id;
	BYTE pkg_id;
	BYTE sensor_num;
	bool EnMaxTemp;
	bool valid;
} PECI_DTS;

typedef struct
{
	bool EnMasterMode;	
	bool EnOnBoardVtt;	
	bool EnAutoTjMax;
	USHORT frequency;
	USHORT CmdsDelayUs;
	USHORT LoopsDelayMs;
	USHORT ManualTjMax;


} PECI_GEN_PARAMS;

typedef struct 
{
	short address;
	char length;
	unsigned char* data;
} TDAU_REGISTER;



// Safety Events

typedef struct
{
	char name[50];
	UINT typeMultiplier;
	UINT value;
	char description[100];
} SAFETY_EVENT_PARAM;


typedef struct
{
	char name[256];
	UINT id;
	bool disable;
	char description[512];
	char action[512];
	bool isDisable;
	bool stopTesting;
	UINT numOfParams;
	EventConfigurationParam params[5];
} SAFETY_EVENT;

typedef struct
{
	char name[256];
	UINT id;
	char description[512];
	char action[512];
} HARDWARE_ERROR;

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
class CIntecOperations : public IIntecOperations
{

public : 

	// 
	
	const int IntecConfigureByFile(char * configFileName);
	const int IntecConfigureByFileRev1(char * configFileName);
	const int IntecConfigureByFileRev2(char * configFileName);

	const int IntecLoadandConfigureTDAUConfiguration(const char * TdauConFileName);
	const int IntecLoadandConfigureTDAUConfiguration(const char * TdauConFileName, char * TdauChnlMapFileName, bool loadHot = true);

	const int IntecLoadTDAUConfiguration(const char* TDAUConFileName);
	const int IntecLoadTDAUConfiguration(const char* TDAUConFileName, char * TdauChnlMapFileName, bool loadHot = true);
	
	const int IntecConfigureTDAU();
	const int IntecFastCalConfigurationRTD(float slope0, float intercept0,float slope1, float intercept1,float slope2, float intercept2);
	const int IntecGetFastCalRTDStatus(bool *RTDstatus );
	const int IntecGetFastCalDiode(int diode,float *slope, float *intercept);
	const int IntecLoadandConfigureCaseConfiguration(char * caseFileName);
	
	//const int IntecFastCalCalibration(int cardId, IntecTemperatureSourceType feadback_src,int feadback_src_mask, int final_diode_mask, int temprature);
	const int IntecFastCalCalibrationRTD( );
	const int IntecSetDiodeInputs(bool enable, UINT mask);
	const int IntecGetDiodeInputs(UINT *mask);
										


	const int IntecConfPFInputsParams(int pf_channel, float slope, float intercept);
	const int IntecGetPFInputsParams(int pf_channel, float &slope, float &intercept);
	const int IntecSetPFInputs(bool enable, UINT mask);	
	const int IntecGetPFInputs(UINT *mask);



	const int IntecConfigurePeciPackage(int package, int bus, int address);
	const int IntecGetPeciPackageConfiguration(int package,int *bus, int *address);
	const int IntecConfigurePeciGenParams(UINT EnMasterMode,UINT EnOnBoardVtt,UINT EnAutoTjMax,UINT frequencyIndex,UINT CmdsDelayUs,UINT LoopsDelayMs,UINT ManualTjMax);
	const int IntecGetPeciGenParams(UINT & EnMasterMode,UINT &EnOnBoardVtt,UINT &EnAutoTjMax,UINT &frequencyIndex,UINT &CmdsDelayUs,UINT &LoopsDelayMs,UINT &ManualTjMax);
	const int IntecConfigurePeciInput(int channel,int package, int sensor_num, char * sensor_name,bool enMaxTemp);
	const int IntecGetPeciInputConfiguration(int channel,int *bus, int *address, int * sensor_num, char * sensor_name, bool *enMaxTemp);

	const int IntecGetPeciInputConfiguration(int channel,int *bus, int *address, int * sensor_num, char * sensor_name);

	const int IntecSetPeciInputs(bool enable, UINT mask) ;

	const int IntecGetPeciInputs(UINT *mask);


	const int IntecLoadandConfigurePeciMapping(const char * peciConfFileName);
	const int IntecGetPeciClientParams(UINT peciClient, UINT	& Address ,char * PeciVersion, UINT &ActualTjMax ,UINT &	VttOk  ,UINT &	Bus ,UINT & MuxCtrlOnPolarity );

	const int IntecExecutePassThroughPeciCommand(UINT8 peciAddress, UINT8 peciBusNumber, UINT totalWriteLength, UINT totalReadLength, UCHAR * dataBufferToSend, UCHAR *dataBufferToReceive, bool  & FCSHeaderErr, bool & FCSMessageErr, UCHAR &CalcFCSHeader, UCHAR &CalFCSMessage);

	const int IntecSetCaseInputs(int cardId,bool enable, UINT mask);
	const int IntecGetCaseInputs(int cardId,UINT *mask) ;


	// Set the parameters for temperature calculation for specific Intecd ,the mode of calculation can bb avg/min/max, sources can be  DTS/
	// params:
	//		cardId- can be 0-3 indicates the IntecD
	//		calcMode - define how to calculate the Temperature from the selected Feedback sources :min/max/avg 
	//		srcType - Case/Diode/DTS
	//		sourceMask -set the appropriate bit to use the input temperature source for feedback
	const int IntecSetFeedBackControlParameters(int cardId,IntecTemperatureCalcType calcMode,IntecTemperatureSourceType srcType,int sourceMask); 

	// Get the parameters for temperature calculation for specific Intecd ,the mode of calculation can bb avg/min/max, sources can be  DTS/
	// params:
	//		cardId- can be 0-3 indicates the IntecD
	//		calcMode - define how to calculate the Temperature from the selected Feedback sources :min/max/avg 
	//		srcType - Case/Diode/DTS
	//		sourceMask -set the appropriate bit to use the input temperature source for feedback
	const int IntecGetFeedBackControlParameters(int cardId,IntecTemperatureCalcType &calcMode,IntecTemperatureSourceType &srcType,int &sourceMask); 


	// Get the Actual FeedBack control
	// in the case of fallback the actual feedback control can be differ from what user requested
	// params:
	//		input:
	//			cardId- can be 0-3 indicates the IntecD 
	//		output:
	//		actualSrcType - Case/Diode/DTS
	const int IntecGetActualFeedBackType(int cardId,IntecTemperatureSourceType &actualSrcType);


	// Get the Actual FeedBack Temperature sources
	// This API returns the actual mask of sources that the intecd is calculating the feedback temperature
	//  it gives the user the ability to know that all the sensors that selected are used or what sensors are active
	// params:
	//		input:
	//			cardId- can be 0-3 indicates the IntecD 
	//		output:
	//		actualFeedBackTempSources - The actual feedback sources mask
	const int  IntecGetActualFeedBackTemperatureSources(int cardId,UINT &actualFeedBackTempSources);

	// Reset the FeedBack Min and Max Temperature values
	// params:
	//		input:
	//			cardId- can be 0-3 indicates the IntecD 
	//		output:
	virtual const int IntecResetMinMaxFeedBackTemperature(int cardId);

	// Get the FeedBack Min and Max Temperature values
	// params:
	//		input:
	//			cardId- can be 0-3 indicates the IntecD 
	//		output:
	//			minTemp - Min Temperature
	//			minTemp - Max Temperature
	virtual const int IntecGetMinMaxFeedBackTemperature(int cardId,float &minTemp, float &maxTemp,float &avgTemp );

	virtual const int  IntecGetPCBTemperature(int cardId,float &DcDcModuleTemp, float &HBridgeModuleTemp);

	virtual const int IntecSetMultiDiodePeciAllocation(int diode_map_size,unsigned short diode_map[],int peci_map_size,unsigned short peci_map[]);

	// Enable/Disable the ProcHot inputs (channels ) that the Intec device will sense
	// params:
	//		enable = 1 -enable 0 disable
	//		mask - the prochot channel 0001b - 1111b
	//
	const int IntecSetProcHotInputs(bool enable, UINT mask);

	// Get the ProcHot input mask that the Intec device will sense
	// params:
	//		mask - the prochot channels
	//
	const int IntecGetProcHotInputs(UINT *mask);


	

	// Get the counter of prochot events that occured on specific input channel
	// params:
	//		input_num = 0-3 of prochot channels
	//		Num_of_events - the number of events that occured
	const int IntecGetProcHotEventsCounter(int input_num,int *Num_of_events) ;

	// Get the status of prochot event on specific input channel
	// params:
	//		input_num = 0-3 of prochot channels
	//		procHot_detect_status - the status of the prochot on channel
	const int IntecGetProcHotActualStatus(int input_num,bool *procHot_detect_status);

	// Clear  the ProcHot inputs (channels ) that the Intec device will sense
	// params:
	//		input_num = 0-3 of prochot channels
	//		if (input_num ==-1) ALL events will be cleared
	const int IntecClearProcHotEventsCounter(int input_num) ;


	// Configure and Run Auto Tcase SetPoint Below Prochot
	// To check if the configuration is finished call IntecGetTcaseBelowProchotStatus
	// params:
	//		input_num = 0-3 of prochot channels
	//		offset - the offset below Prochot temp to set 
	const int IntecSetTcaseBelowProchot(int input_num,float offset);

	// Get  Auto Tcase SetPoint Below Prochot configuration status
	// enable the SetPoint in the HW according to the configuration in IntecConfigureTcaseBelowProchot()
	// params:
	//		input_num = 0-3 of prochot channels
	//		inProcessStatus  = 1- the configuration is still in process, 0 - configuration terminated
	//		prochotTemp - the Prochot temperature that was found 
	const int IntecGetTcaseBelowProchotStatus(int input_num,bool * TcaseBelowProchotInProcess,float *prochotTemp);
	// Configure the temperature that we want to reach  
	// params:
	//		cardId- can be 0-3 indicates the IntecD
	//		temperature - target temperature that we want to reach
	const int IntecSetTemperature(int cardId,unsigned short temprature);

	// Configure the temperature that we want to reach  
	// params:
	//	Input:
	//		cardId- can be 0-3 indicates the IntecD
	//		temperature - target temperature that we want to reach (real temperature)
	const int IntecSetTemperature(int cardId,float temprature);

	// Get  the temperature that calculated for specific card  
	// params:
	//		cardId- can be 0-3 indicates the IntecD
	//		temperature - target temperature that we want to reach
	//		timestamp  - the timestamp that this temperature calculated
	//Note: The IntecSelectInput() and IntecSelectInputFeedBack() need to be called before this function
	const int IntecGetTemperature(int cardId,unsigned short *temprature, unsigned int * timestamp);



	// Get  the last requested temperature that for specific card  
	// params:
	//	Input:
	//		cardId- can be 0-3 indicates the IntecD
	//  Output:
	//		temperature - target temperature that we want to reach (Real Temperature)
	//		timestamp  - the timestamp that this temperature calculated
	//Note: The IntecSelectInput() and IntecSelectInputFeedBack() need to be called before this function
	const int IntecGetRequestedTemperature(int cardId,float *temprature, unsigned int * timestamp);

	// Get  the temperature that calculated for specific card  
	// params:
	//	Input:
	//		cardId- can be 0-3 indicates the IntecD
	//  Output:
	//		temperature - target temperature that we want to reach (Real Temperature)
	//		timestamp  - the timestamp that this temperature calculated
	//Note: The IntecSelectInput() and IntecSelectInputFeedBack() need to be called before this function
	virtual const int IntecGetTemperature(int cardId,float *temprature, unsigned int * timestamp);


	const int IntecEnableDisableVariableSetPointTemperature(int cardId,bool enable);

	const int IntecSetVariableSetPointTemperature(int cardId,float temperature );

	const int IntecGetVariableSetPointTemperature(int cardId,bool  *enable, float *temperature );


	// get the feedback temperature  feedback in all InTEC-D.
	// params:
	//	Output:
	//		sources_size- size of the sources array that will be filed
	//		sources - the array of temperature sources that will be filled in Intec format
	//		timestamp - the Time stamp of the Temp update by HW.
	//		valid-mask - mask the represent which sensor is valid (Tp - up to 16 sensors, , Tj - 4 sensors, Tc -up to 16 sensors (4 per card) Pf-4 
	//Note: Sources array is allocated by the client and is of MAX_SOURCES_SIZE
	const int IntecGetAllFeedBackTemperatures( int & sources_size,unsigned short  sources[], unsigned int &timestamp ,int & valid_mask); 

	// get the feedback temperature  feedback in all InTEC-D.
	// params:
	//	Output:
	//		sources_size- size of the sources array that will be filed
	//		sources - the array of temperature sources that will be filled in regular format
	//		timestamp - the Time stamp of the Temp update by HW.
	//		valid-mask - mask the represent which sensor is valid (Tp - up to 16 sensors, , Tj - 4 sensors, Tc -up to 16 sensors (4 per card) Pf-4 
	//Note: Sources array is allocated by the client and is of MAX_SOURCES_SIZE
	const int IntecGetAllFeedBackTemperatures( int & sources_size,float  sources[], unsigned int &timestamp ,int & valid_mask); 


	// get the temperature  from the  source that the user request (this enable the user to get the temperature  from various sources).
	// params:
	//		src- src- can be from 	Tc, Tj,Tp,PowerFollowing
	//		sources_size- size of the sources array that will be filed
	//		sources - the array of temperature sources that will be filled
	//		timestamp - the Time stamp of the Temp update by HW.
	//		valid-mask - mask the represent which sensor is valid (Tp - up to 16 sensors, , Tj - 4 sensors, Tc -up to 16 sensors (4 per card)
	//Note: Sources array is allocated by the client and is of MAX_SOURCES_SIZE
	const int IntecGetTemperatureSources(IntecTemperatureSourceType src , int & sources_size,unsigned short  sources[], unsigned int &timestamp ,int & valid_mask); 

	const int IntecGetTemperatureSources(IntecTemperatureSourceType src , int & sources_size,float  sources[], unsigned int &timestamp ,int & valid_mask); 


	// get the voltage  from the  sources that the user request (this enable the user to get the temperature  from various sources).
	// params:
	//		src- src- can be from 	Tc, Tj,Tp,PowerFollowing
	//		sources_size- size of the sources array that will be filed
	//		sources - the array of temperature sources that will be filled
	//		timestamp - the Time stamp of the Volt update by HW.
	//		valid-mask - mask the represent which sensor is valid (  powerFollowing -4)
	//Note: Sources array is allocated by the client and is of MAX_SOURCES_SIZE
	const int IntecGetVoltageSources(IntecVoltageSourceType src , int & sources_size,unsigned short sources[], unsigned int &timestamp ,int & valid_mask);
	
	
	// Enable/Disable the TEC head
	const int IntecTECEnableDisable(int cardId,bool enable);
	// Set Proportional gain,Integral,Derivative parameters
	const int IntecTECSetControlParams(int cardId,UINT proportional, UINT integral, UINT derivative);
	// Get Proportional gain,Integral,Derivative parameters
	const int IntecTECGetControlParams(int cardId,UINT *proportional, UINT *integral, UINT *derivative);
	// Get the  CurrentSense ,VoltageSense , PowerOutCalc and PowerSupplySense  Fields in D_POWER_OUT_SENSE 
	const int IntecTECGetParams(int cardId,float *currentSense, float *voltageSense, float *powerOutCalc, float *powerSupplySense, UINT *PWMCalc);
	// Get the TEC head status enable/disable, cooling/heating
	const int IntecTECStatus(int cardId,int *enable, int *heat_status, int *cool_status);

	// Set PRBS Low and High voltages
	const int IntecTECSetPRBSVoltage(int cardId,float lowVoltage, float highVoltage);

	// Get PRBS Low and High voltages
	const int IntecTECGetPRBSVoltage(int cardId,float &lowVoltage, float &highVoltage);

	// Set OpenLoop  voltage
	const int IntecTECSetOpenLoopVoltage(int cardId,float Voltage);

	// Set Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
	const int IntecTECSetVmax(int cardId,float Voltage);

	// Get Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
    const int IntecTECGetVmax(int cardId,float &Voltage);

	// Set Heating Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
	const int IntecTECSetVmaxHeatTec(int cardId,float Voltage);

	// Get Heating Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
	const int IntecTECGetVmaxHeatTec(int cardId,float &Voltage);

	// Get Open Loop voltage
	const int IntecTECGetOpenLoopVoltage(int cardId,float &Voltage);

	// Set TEC Control Mode
	const int  IntecTECSetControlMode(int cardId,IntecTecMode mode);

	// Get TEC Control Mode
	const int IntecTECGetControlMode(int cardId,IntecTecMode & mode);


	//Events APIs

	//load and configure Events XML file.
	const int IntecLoadandConfigureEvents(int cardId,const char * eventsFileName, bool configureHW=true);
	// Get a Event configuration
	const int IntecGetEventParam(int cardId,EventType evType,int eventId,  EventConfigurationParam * eventParam);
	// Set a Event configuration
	const int IntecSetEventParam(int cardId,EventType evType,int eventId,  EventConfigurationParam eventParam);
	// Get a Event disable
	const int IntecGetEventDisableStatus(int cardId,EventType evType,int eventId, bool * isDisable, bool *disableStatus);
	// Set a Event disable or enable
	const int IntecSetEventDisableEnable(int cardId,EventType evType,int eventId, bool disable_enable);
	// Get a Event StopTesting status
	const int IntecGetEventStopTestingStatus(int cardId,EventType evType,int eventId, bool * stopTesting);
	// Get Events status
	const int IntecGetEventsStatus(int cardId,EventType evType,UINT32 * eventsStatus);
	// Get Event Name
	const int IntecGetEventName(int cardId,EventType evType,int eventId,int maxMsgLen, char * msg);
	// Get Event Name
	const int IntecGetEventDescription(int cardId,EventType evType,int eventId,int maxMsgLen, char * msg);
	// Get Event Name
	const int IntecGetEventAction(int cardId,EventType evType,int eventId,int maxMsgLen, char * msg);
	// Get Events params size
	const int IntecGetEventParamsSize(int cardId,EventType evType,int eventId,unsigned int * paramsSize);
	// Get Events param[paramId]
	const int IntecGetEventParamName(int cardId,EventType evType,int eventId,unsigned int paramId,int maxMsgLen, char * msg);
	// Disarm Intec  and enable the operator to fix issues
	const int IntecDisarm(int cardId, UINT TimeOutMiliSec);
	// Arm Intec  afetr the operator to fix issues
	const int IntecRearm(int cardId, UINT TimeOutMiliSec);


	// Disarm Intec  and enable the operator to fix issues
	virtual const int IntecFastDisarm(int cardId);
	// Arm Intec  after the operator to fix issues
	virtual const int IntecFastRearm(int cardId);

	// Get Disarm Intec status and enable the operator to fix issues
	const int IntecGetDisarmStatus(int cardId,  bool * isDisarmed);

	// Set The RTD Sensor Type
	virtual const int IntecSetRTDSensor(int cardId,IntecRTDSensorType sensor_type);

	// Get The RTD Sensor Type
	virtual const int IntecGetRTDSensor(int cardId,IntecRTDSensorType &sensor_type);
	virtual const int IntecGetTCaseType(int cardId,IntecTCASEType &sensor_type);

	// Set The Gang Auto Cfg mode : 1- enable, 0-disable
	virtual const int IntecGetGangAutoCfg(int cardId,bool * gangAutoCfgMode);

	// Get The Gang Auto Cfg mode : 1- enabled, 0-disabled
	virtual const int IntecSetGangAutoCfg(int cardId,bool gangAutoCfgMode);

	//fallback functions
	const int IntecConfigureFallBack(int cardId,IntecTemperatureCalcType  equation,IntecTemperatureSourceType source_type,unsigned short selected_Sources ,unsigned short caseWithOffsetTimeout, bool manualOffsetEnable, float manualOffset );
	const int IntecGetFallBackConfiguration(int cardId,IntecTemperatureCalcType & equation,IntecTemperatureSourceType &source_type,unsigned short &selected_Sources ,unsigned short &caseWithOffsetTimeout, bool &manualOffsetEnable, float &manualOffset );

	// TEstability Functions
	const int IntecTestabilityStart(IntecTestabiliyMode test,IntecCardType card_type,int card_id);		
	const int IntecTestabilityAbort(IntecTestabiliyMode test,IntecCardType card_type,int card_id);	
	const int IntecTestabilityGetResults(IntecTestabiliyMode test,IntecCardType card_type,int card_id ,UINT * testStatus,UINT64 *testErrorMask);
	const int IntecTestabilityGetErrorMessage(IntecTestabiliyMode test,IntecCardType card_type,UINT errorId,char *errorMsg,UINT errorMsgSize);

	const int  IntecDiagnosticGetXMLFileName(char *configureDiagnosticFileName, unsigned int bufferSize);
	const int  IntecDiagnosticConfigure(char *configureDiagnosticFileName);
	const int  IntecGetDiagnosticTestStatus(unsigned int testID, bool & enabled);
	const int  IntecGetDiagnosticParamVal(std::string paramName,std::string paramType, float & calcVal);
	const int  IntecDiagnosticStart();
	const int  IntecDiagnosticAbort();
	const int  IntecDiagnosticGetResult(bool & running, bool &passed, int & num_of_errors ,char* error_msgs[], int max_messages);


	// Get the impefdance test resuly
	// in the case of fallback the actual feedback control can be differ from what user requested
	// params:
	//		input:
	//			cardId- can be 0-3 indicates the IntecD 
	//		output:
	//		valid  - true if the Impedance retuned value is valid.
	//		impedance - the value.
	const int IntecGetImpedance(int cardId,bool & valid,float &impedance);

	const int  IntecEnvGetCondensationVoltage(int cardId, float & voltage);

	// Water Module Functions
	const int IntecGetWaterModuleStatus(int cardId,bool & connected);
	const int IntecGetWaterModuleParams(int cardId,bool & moduleConnected,bool & WaterModuleMeasEnabled,bool & ChillerMeasEnabled,bool & FloorMeasEnabled, float &WaterModuleImp ,float &ChillerImp , float & FloorImp);
	// TDAU functions

	const int IntecReadTDAURegister(unsigned short regAddr, unsigned char regSize,unsigned char *actualReadSize,unsigned char *readData);

	const int IntecWriteTDAURegister(unsigned short regAddr, unsigned char regSize,unsigned char *writeData);

	const int IntecGetTDAUStatus(IntecTDAUStatus &status);
	const int IntecGetTDAUVersion(unsigned short &version);
	// Calibrate the TDAU on demand
	const int IntecTDAUCalibrate();

	// return the number of cards (intecD ) that installed on the system
	inline const int IntecGetNumberIntecDCards(int & cards)
	{
		cards=InTECDCards_;
		return true;
	}

	// EEPROm Functions
	// clear EEPROM configuration to defaule and restart software.
	virtual const int IntecClearConfigurationFromEEPROM();
	// Store configuration to EEPROM .
	virtual const int IntecStoreConfigurationToEEPROM();

	virtual const int IntecGetThermalHeadEEpromStatus(int card_id,bool & ThEEpormNotDetected,bool &THEEpromType );

	// Write to TH EEPROM
	const int IntecWriteBLTEEprom(int card_id, UINT offset, unsigned char * buffer, unsigned int size);
	// Write to TH EEPROM
	const int IntecReadBLTEEprom(int card_id, UINT offset, unsigned char * buffer, unsigned int size);

	// Disable/Enable the Intec buzzer
	virtual const int IntecBuzzerDisableEnable(bool disable);
	// Reset Microchip Software
	// after this call user need to call Terminate() and  Initialize() functions
	virtual const int IntecSoftwareReset();

	const int IntecReset(int resetType);
	// Check if the PECI Module card is connected 
	const int IntecCheckPECIModuleConnected(int & connected);

	// return the Intec/IntecD/Peci Firmware version 
	const int IntecGetFirmWareVersion(IntecCardType card_type,int card_id, int *ver) ;

	// return the Intec FW bundle version
	const int  IntecGetFirmWareBundleVersion(int *intecBundleVer);
	
	// return the Intec/IntecD/Peci card name
	const int IntecGetDeviceName(IntecCardType card_type,int card_id, char *name);
		
	// return the Intec Driver software version 
	 const int IntecGetSoftwareVersion(char *ver_buffer,int bufferSize);
	 
	 // return the Intec IP address in dot notation x.y.z.w
	 const int IntecGetIPAddress(char *ip_addr,int bufferSize);

	 // Set the Intec IP address according to  dot notation ip_addr
	 const int IntecSetIPAddress(const char *ip_addr);

	 // Apply IP changes
	 const int IntecApplyIPChanges();

	 // Set IP mode DHCP or Static
	 virtual const int IntecSetIPMode(IntecIpMode mode);
	 // Get IP Mode DHCP or static
	 virtual const int IntecGetIPMode(IntecIpMode * mode);
	 // return the Intec Device Serial
	 const int IntecGetDeviceSerialNumber(IntecCardType card_type,int card_id, char *serial);
	 //return the Itec or IntecD timeStamp

	 const int IntecGetDeviceTimeStamp(IntecCardType card_type,int card_id, unsigned int &hours, unsigned int &minutes, unsigned int &seconds);
	 //Thermal Head APIs

	 // Get Thermal Head Parameter
	 const int IntecGetThermalHeadParam(int cardId,IntecThermalHeadRegId paramType,UINT maxdataLen, char * data,UINT &actualParamSize);


	 virtual const int IntecConfigureRampRateControlParam(int cardId,bool  EnableRampRateControl,bool EnableFullRampRateControl, unsigned short   DesRampRate, unsigned short RampRateSPMargin );
	 virtual const int IntecGetRampRateControlParam(int cardId,bool * EnableRampRateControl,bool *EnableFullRampRateControl, unsigned short  * DesRampRate, unsigned short * RampRateSPMargin,unsigned short * MesRampRate );
	
    CIntecOperations(int deviceIndex);
	int Initialize(int reset);
	int  Terminate();

	//dtor
	~CIntecOperations();
protected:

	bool IsCardExist(int cardId);
	bool IsTDAUConnected(bool &TDAUconnected);
	const int IntecGetSysCardsConfiguration();
	float convertIntecToRealTemperature(unsigned short IntecTemperature);
	unsigned short convertRealToIntecTemperature(float RealTemperature);
	bool buildIntecBenchSelfTestErrorMessages();
	bool buildIntecStandaloneSelfTestErrorMessages();
	bool buildIntecBasicFunctionalitySelfTestErrorMessages();

	bool buildIntecDBenchSelfTestErrorMessages();
	bool buildIntecDStandaloneSelfTestErrorMessages();
	bool buildIntecDBasicFunctionalitySelfTestErrorMessages();
	bool buildIntecDWaterModuleBenchTestErrorMessages();


	const int IntecClearPeciSensorsConfiguration();

	// Set a Event disable or enable
	const int IntecSetAllEventDisableEnable(int cardId,EventType evType);
	UINT calculateEventParamVal(std::string paramVal,std::string paramType);


	const int  IntecReadDiagnosticParam(std::string paramName, UINT& value);
	const int  IntecWriteDiagnosticParam(std::string paramName, UINT value);
	const int calculateDiagnosticParamValToIntecFormat(std::string paramType,std::string paramVal,std::string minVal,std::string maxVal, UINT & calcVal);
	const int calculateDiagnosticParamValFromIntecFormat(std::string paramType,UINT registerVal, float & calcVal);
	const int getDiagnosticErrorMessage(std::string module, UINT errorId,char *errorMsg,UINT errorMsgSize);
	// Write to TH EEPROM
	const int IntecWriteThermalHeadEEprom(int card_id, UINT offset, unsigned char * buffer, unsigned int size);
	// Write to TH EEPROM
	const int IntecReadThermalHeadEEprom(int card_id, UINT offset, unsigned char * buffer, unsigned int size);
	const int CheckThermalHeadEEpromBusy(int card_id, unsigned int retries);
	void GetWorkDir(size_t sz, char * path);
	const int getHWErrorEventDescription(int maxMsgLen, char * msg);
	int ftoi(float f);
	const int peciFrequencyTablesInitialization();
	const int SleepAndCheckBusy();
private:
	
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

	UINT currentDiodeMask_;
	UINT currentPFMask_;
	UINT currentProcHOTMask_;
	UINT currentPeciMask_;
	UINT currentCaseMask_[4];
	std::map <std::string, TDAU_REGISTER*> gTDAUMap;

	std::map <unsigned int,unsigned int> peciFreq_IndexToDigital;
	std::map <unsigned int,unsigned int> peciFreq_DigitalToIndex;
	PECI_DTS peci_dts_arr[MAX_DTS];
	PECI_PACKAGE peci_pkg_arr[MAX_PACKAGES];
	UN_P_PECI_GEN_PARAMS peci_general_params;

	SAFETY_EVENT failure_events[MAX_EVENTS];
	SAFETY_EVENT warning_events[MAX_EVENTS];
	SAFETY_EVENT notification_events[MAX_EVENTS];

	HARDWARE_ERROR IntecH_HW_errors[MAX_ERRORS] ;
	HARDWARE_ERROR IntecD_HW_errors[MAX_ERRORS] ;

	UINT readSize_;
	UCHAR readBuff_[READ_BUF_SIZE];
	UINT writeSize_;
	UCHAR writeBuff_[READ_BUF_SIZE];
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
	// Validate bool string value = true or false other value considered as error  
	const int CIntecOperations::IntecValidateBoolString(std::string  boolStr,const char* nodeName);
};

#endif //_CIntec_Services_H_
