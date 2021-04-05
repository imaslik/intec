#ifndef _libIntec_H_
#define _libIntec_H_
#include "libIntecDefs.h"

extern "C"{

// Initialize 
// Initialize the Driver search for all USB devices of type 'dev' that are connected
// open the devices and connect to them.
HRESULT Initialize(IntecUsbDeviceType dev);
HRESULT InitializeOverEthernet(IntecUsbDeviceType dev, UINT numOfDevices, char * devicesAddress[]);

//Terminate
HRESULT Terminate();

// return the # of USB device that were found in Initialize
HRESULT  GetNumOfUSBDevices(UINT *numDevices);

// Return the mode of USB device buy Index  (the index needs to be in range 0 -  GetNumOfUSBDevices()-1)
HRESULT GetDeviceMode(UINT index, IntecDeviceOperationMode *mode);

// Set the mode of USB device buy Index  (the index needs to be in range 0 -  GetNumOfUSBDevices()-1)
// with this function the device can change modes between NormalOpMode <-> BootLoaderOpMode
// this function can be used to restart the device in normal mode after burning or it can use to jump into boot mode in order to burn.
// Note: calling this function to change he mode of the device will cause that the mapping of the devices in windows ins changed 
// so after calling this function you need to call terminate () and Initialize again()
HRESULT SetDeviceMode(UINT index, IntecDeviceOperationMode mode);

// return the Device Name by Index
HRESULT GetDeviceName(UINT index,UCHAR *szBuffer);

// return the Device Version by Index
HRESULT GetDeviceVersion(UINT index,UCHAR *szBuffer);
// return a mask of all the sub devices that are connected to by Index
// bit 0 is always ON - it represent the device itself

// Get/Set the Device Site # by Index
// when multiple Intec devices are connected to the same host it can be identified by the Site #,
// the user can change the Site # of intec by calling the SetDeviceSiteNumber(UINT index,UINT siteNum)
HRESULT GetDeviceSiteNumber(UINT index,UINT  *siteNum);

HRESULT SetDeviceSiteNumber(UINT index, UINT  siteNum);

HRESULT GetNumOfSubDevices(UINT index,UINT *subDevicesMask);

// Get a subDevice name
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
HRESULT GetSubDeviceName(UINT deviceIndex, UINT subDeviceIndex, UCHAR *szBuffer);

// Get a subDevice version
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
HRESULT GetSubDeviceVersion(UINT deviceIndex, UINT subDeviceIndex, UCHAR *szBuffer);

// Get a subDevice Mode
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
HRESULT GetSubDeviceMode(UINT index, UINT subDeviceIndex, IntecDeviceOperationMode *mode);

// Start a subDevice Boot Mode
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
// The function writes to the master register in inform it to enter subdevice into boot loader
// it has 2 effects: - the subdevice is enter to bootloader mode (jump into the boot code)
//					 - the master application enter to special bypass mode that transfer reads & writes to the sub device
// you must use StopSubDeviceBootMode to return the master to normal mode after you finished the programming of the sub device or you needs to abort this mode
HRESULT StartSubDeviceBootMode(UINT deviceIndex, UINT subDeviceIndex);

// Stop a subDevice Boot Mode
// The subDevice is located  in USB with DeviceIndex and and with subDeviceIndex
// the subDeviceIndex is the bit index that is returned from *subDevicesMask
// The function writes to the master register in inform it to abort  to special bypass mode that used to transfer reads & writes to the sub device for programming
// this function is closed after  you finished the programming of the sub device or you needs to abort this mode
HRESULT StopSubDeviceBootMode(UINT deviceIndex, UINT subDeviceIndex);


// Write to USB device
HRESULT WriteDevice(UINT index ,UCHAR *szBuffer,UINT cbSize);
// Read from USB device
HRESULT ReadDevice(UINT index,UCHAR *szBuffer,UINT *cbRead);


// Write to USB device by address
HRESULT WriteDeviceByAddr(UINT index ,UINT addr,UCHAR *szBuffer,UINT cbSize);
// Read from USB device
HRESULT ReadDeviceByAddr(UINT index,UINT addr,UCHAR *szBuffer,UINT *cbRead);



//-------------------------
//Intec Operation functions
//-------------------------
// Initialize specific Intec card
HRESULT InitializeCard(UINT index);

// Initialize specific Intec card
HRESULT InitializeCardNoReset(UINT index);

// Configure a Peci package  that the Intec device will handle
HRESULT IntecConfigurePeciPackage(UINT index,int package, int bus, int address);

// Get a Peci package configured parameters
HRESULT IntecGetPeciPackageConfiguration(UINT index,int package,int *bus, int *address);

// Configure a Peci input (channel ) that the Intec device will read the temperatures ()
HRESULT IntecConfigurePeciInput(UINT index,int channel,int package, int sensor_num, char * sensor_name,bool enMaxTemp);


// Get a Peci input (channel ) configured parameters
HRESULT IntecGetPeciInputConfiguration(UINT index,int channel,int *bus, int *address, int * sensor_num, char * sensor_name, BOOL *enMaxTemp);

// Enable/Disable the Peci inputs (channels ) that the Intec device will read the temperatures ()
HRESULT IntecSetPeciInputs(UINT index,bool enable, UINT mask);

// Get Peci inputs (channels) that are currently active  
HRESULT IntecGetPeciInputs(UINT index,UINT *mask);

//Retrieve the  Address ,PeciVersion,ActualTjMax ,VttOk  ,Bus ,MuxCtrlOnPolarity from the peciClient (0..3)
// if the client is NOT connected an error is returned
HRESULT  IntecGetPeciClientParams(UINT index,UINT peciClient, UINT	*Address ,char *PeciVersion, UINT *ActualTjMax ,UINT *VttOk  ,UINT *Bus ,UINT *MuxCtrlOnPolarity );

//load and configure XML file that map between the source logical name (e.g core0) it’s PECI address (e.g addres 31) and the physical channel in Intec card.
HRESULT IntecLoadandConfigurePeciMapping(UINT index,char * peciConfFileName);

HRESULT IntecConfigurePeciGenParams(UINT index,UINT EnMasterMode,UINT EnOnBoardVtt,UINT EnAutoTjMax,UINT frequencyIndex,UINT CmdsDelayUs,UINT LoopsDelayMs,UINT ManualTjMax);

HRESULT IntecGetPeciGenParams(UINT index,UINT * EnMasterMode,UINT *EnOnBoardVtt,UINT *EnAutoTjMax,UINT *frequencyIndex,UINT *CmdsDelayUs,UINT *LoopsDelayMs,UINT *ManualTjMax);

HRESULT IntecExecutePassThroughPeciCommand(UINT index, UINT8 peciAddress, UINT8 peciBusNumber, UINT totalWriteLength, UINT totalReadLength, UCHAR * dataBufferToSend, UCHAR *dataBufferToReceive, bool  * FCSHeaderErr, bool * FCSMessageErr, UCHAR *CalcFCSHeader, UCHAR *CalFCSMessage);

//this API will load an XML file into the TDAU device. 
HRESULT IntecLoadandConfigureTDAUConfiguration(UINT index, char * TdauConFileName);
HRESULT IntecLoadandConfigureTDAUConfigurationNew(UINT index, char * TdauConFileName, char * TdauChnlMapFileName, bool loadHot = true);

//this API will load an XML file into the FastCal device. 
HRESULT IntecFastCalConfigurationRTD(UINT index,float slope0, float intercept0,float slope1, float intercept1,float slope2, float intercept2);

HRESULT IntecGetFastCalDiode(UINT index,int diode,float *slope, float *intercept);

HRESULT IntecGetFastCalRTDStatus(UINT index,bool *RTDstatus );

	//Load the Tcase xml file that contains the  Tcase  configuration for each channels on Intecd cards
// actually it holds the manual calibration offset in InTEC Temp format
HRESULT IntecLoadandConfigureCaseConfiguration(UINT index,char * caseFileName);

//Calibrate the FASTcal RTD - this API calibrate the FAST cal on specific Temperature
HRESULT IntecFastCalCalibrationRTD(UINT index);

// Enable/Disable the Diode inputs (channels ) that the Intec device will read the temperatures ()
HRESULT IntecSetDiodeInputs(UINT index,bool enable, UINT mask);

// Get the Diodes inputs (channels) that are active status. 
HRESULT IntecGetDiodeInputs(UINT index,UINT *mask);

// Enable/Disable the Case inputs (channels ) that the Intec device will read the temperatures ()
HRESULT IntecSetCaseInputs(UINT index,int cardId,bool enable, UINT mask);

// Get the Case inputs (channels) that the Intec device will read the temperatures 
HRESULT IntecGetCaseInputs(UINT index,int cardId,UINT* mask);

// Set the parameters for temperature calculation for specific Intecd ,the mode of calculation can bb avg/min/max, sources can be  DTS/
HRESULT IntecSetFeedBackControlParameters(UINT index,int cardId,IntecTemperatureCalcType calcMode,IntecTemperatureSourceType srcType,int sourceMask); 

// Get the parameters for temperature calculation for specific Intecd ,the mode of calculation can bb avg/min/max, sources can be  DTS
HRESULT IntecGetFeedBackControlParameters(UINT index,int cardId,IntecTemperatureCalcType *calcMode,IntecTemperatureSourceType *srcType,int *sourceMask);

// Get the actual feedback type from IntecD
HRESULT IntecGetActualFeedBackType(UINT index,int cardId,IntecTemperatureSourceType *actualSrcType);

// Get the actual feedback temperature sources from IntecD
HRESULT IntecGetActualFeedBackTemperatureSources(UINT index,int cardId,UINT *actualFeedBackTempSources);

// Reset the FeedBack Min and Max Temperature values
HRESULT IntecResetMinMaxFeedBackTemperature(UINT index,int cardId);

// Get the FeedBack Min and Max Temperature values
HRESULT IntecGetMinMaxFeedBackTemperature(UINT index,int cardId,float *minTemp, float *maxTemp,float *avgTemp);

HRESULT IntecSetMultiDiodePeciAllocation(UINT index, int diode_map_size,unsigned short diode_map[],int peci_map_size,unsigned short peci_map[]);


// Get the PCB Temperature values
HRESULT IntecGetPCBTemperature(UINT index,int cardId,float *DcDcModuleTemp, float *HBridgeModuleTemp);

HRESULT IntecConfigureFallBack(UINT index, int cardId,IntecTemperatureCalcType  equation,IntecTemperatureSourceType source_type,unsigned short selected_Sources ,unsigned short caseWithOffsetTimeout, bool manualOffsetEnable, float manualOffset );

HRESULT IntecGetFallBackConfiguration(UINT index,int cardId,IntecTemperatureCalcType  *equation,IntecTemperatureSourceType *source_type,unsigned short *selected_Sources ,unsigned short *caseWithOffsetTimeout, bool *manualOffsetEnable, float *manualOffset );

// Configure the temperature that we want to reach  
HRESULT IntecSetTemperature(UINT index,int cardId,float temprature);

// Configure the temperature that we want to reach (IntecFormat)  
HRESULT IntecSetTemperatureIF(UINT index,int cardId,unsigned short temprature);

// get the feedback temperature  feedback in all InTEC-D.
HRESULT IntecGetAllFeedBackTemperaturesIF( UINT index, int * sources_size, short  sources[], unsigned int *timestamp ,int * valid_mask); 

// get the feedback temperature  feedback in all InTEC-D.
HRESULT IntecGetAllFeedBackTemperatures(UINT index, int *sources_size,float  sources[], unsigned int *timestamp ,int * valid_mask); 

// Get  the temperature that calculated for specific card  
HRESULT IntecGetTemperature(UINT index,int cardId,float *temprature, unsigned int * timestamp);

// Get  the temperature that was requested from specific intecd card  
HRESULT IntecGetRequestedTemperature(UINT index,int cardId,float *temprature, unsigned int * timestamp);

// Get  the temperature that calculated for specific card  IntecFormat of temperature
HRESULT IntecGetTemperatureIF(UINT index,int cardId,unsigned short *temprature, unsigned int * timestamp);

// get the temperature  from the  source that the user request (this enable the user to get the temperature  from various sources).
HRESULT IntecGetTemperatureSources(UINT index,IntecTemperatureSourceType src , int * sources_size,float  sources[], unsigned int *timestamp ,int * valid_mask); 

// get the temperature  from the  source that the user request IntecFormat of temperature (this enable the user to get the temperature  from various sources).
HRESULT IntecGetTemperatureSourcesIF(UINT index,IntecTemperatureSourceType src , int * sources_size, short  sources[], unsigned int *timestamp ,int * valid_mask); 

HRESULT IntecEnableDisableVariableSetPointTemperature(UINT index,int cardId,bool enable);

HRESULT IntecSetVariableSetPointTemperature(UINT index,int cardId,float temperature );

HRESULT IntecGetVariableSetPointTemperature(UINT index,int cardId,bool  *enable, float *temperature );

// get the voltage  from the  sources that the user request (this enable the user to get the temperature  from various sources).
HRESULT IntecGetVoltageSources(UINT index,IntecVoltageSourceType src , int * sources_size, short sources[], unsigned int * timestamp ,int * valid_mask);

// Enable/Disable the ProcHot inputs (channels ) that the Intec device will sense
HRESULT IntecSetProcHotInputs(UINT index,bool enable, UINT mask);

// Get the ProcHot input mask that the Intec device will sense
HRESULT IntecGetProcHotInputs(UINT index,UINT *mask);

// Enable/Disable the PowerFollowing inputs (channels ) that the Intec device will sense
HRESULT IntecSetPFInputs(UINT index,bool enable, UINT mask);

// Get the PowerFollowing input mask that the Intec device will sense
HRESULT IntecGetPFInputs(UINT index,UINT *mask);

// Configure the PowerFollowing parameters of pf_channel (channels ) that the Intec device will sense 
HRESULT IntecConfPFInputsParams(UINT index,int pf_channel, float slope, float intercept);

// Get the PowerFollowing parameters of pf_channel (channels ) that the Intec device sense 
HRESULT IntecGetPFInputsParams(UINT index,int pf_channel, float *slope, float *intercept);

// Get the counter of prochot events that occured on specific input channel
HRESULT IntecGetProcHotEventsCounter(UINT index,int input_num,int *Num_of_events);

// Clear  the ProcHot inputs (channels ) that the Intec device will sense
HRESULT IntecClearProcHotEventsCounter(UINT index,int input_num) ;	

// Get the status of prochot event on specific input channel
HRESULT IntecGetProcHotActualStatus(UINT index,int input_num,bool *procHot_detect_status);

HRESULT IntecGetTcaseBelowProchotStatus(UINT index,int input_num,bool * TcaseBelowProchotInProcess,float *prochotTemp);
HRESULT IntecSetTcaseBelowProchot(UINT index,int input_num,float offset);

// Enable/Disable the TEC head
HRESULT IntecTECEnableDisable(UINT index,int cardId,bool enable);

// return the number of cards (intecD ) that installed on the system
HRESULT IntecGetNumberIntecDCards(UINT index,int *cards);

// Check if the PECI Module card is connected 
HRESULT IntecCheckPECIModuleConnected(UINT index,int * connected);

// return the Intec Firmware version 
HRESULT IntecGetFirmWareVersion(UINT index,IntecCardType card_type,int card_id, int *ver);

//return the Intec FW bundle version
HRESULT IntecGetFirmWareBundleVersion(UINT index,int *intecBundleVer);

// return the Intec Driver software version 
HRESULT IntecGetSoftwareVersion(UINT index,char *ver,int bufferSize);


HRESULT IntecGetIPAddress(UINT index,char *ip_addr,int bufferSize);

// Set the Intec IP address according to  dot notation ip_addr
HRESULT IntecSetIPAddress(UINT index, const char *ip_addr);

HRESULT IntecSetIPMode(UINT index, IntecIpMode mode);
HRESULT  IntecGetIPMode(UINT index, IntecIpMode * mode);
HRESULT  IntecApplyIPChanges(UINT index);
// return the Intec Device Serial
HRESULT IntecGetDeviceSerialNumber(UINT index, IntecCardType card_type,int card_id, char *serial);

HRESULT IntecGetDeviceTimeStamp(UINT index,IntecCardType card_type,int card_id, unsigned int *hours, unsigned int *minutes, unsigned int *seconds);

// TDAU Functions

// Read TDAU register
HRESULT IntecReadTDAURegister(unsigned int index,unsigned short regAddr, unsigned char regSize,unsigned char *actualReadSize,unsigned char *readData);

// Write TDAU register
HRESULT IntecWriteTDAURegister(unsigned int index,unsigned short regAddr, unsigned char regSize, char *writeData);


// Read TDAU register
HRESULT IntecReadTDAURegisterInt(unsigned int index,unsigned short regAddr, unsigned char regSize,unsigned char *actualReadSize,unsigned int *readData);

// Write TDAU register
HRESULT IntecWriteTDAURegisterInt(unsigned int index,unsigned short regAddr, unsigned char regSize, unsigned  int writeData);

// Get TDAU status 
HRESULT IntecGetTDAUStatus(unsigned int index,IntecTDAUStatus *status);

// Get TDAU status 
HRESULT IntecGetTDAUVersion(unsigned int index,unsigned short *version);


// calibrate the TDAU
HRESULT IntecTDAUCalibrate(unsigned int index);

// Testability functions
HRESULT IntecTestabilityStart(UINT index,IntecTestabiliyMode test,IntecCardType card_type,int card_id)  ;		
HRESULT IntecTestabilityAbort(UINT index,IntecTestabiliyMode test,IntecCardType card_type,int card_id)  ;	
HRESULT IntecTestabilityGetResults(UINT index,IntecTestabiliyMode test,IntecCardType card_type,int card_id ,UINT * testStatus,UINT64 *testErrorMask) ;
HRESULT IntecTestabilityGetErrorMessage(UINT index,IntecTestabiliyMode test,IntecCardType card_type,UINT errorId,char *errorMsg ,UINT errorMsgSize) ;


//Events

//load and configure Events XML file.
HRESULT IntecLoadandConfigureEvents(UINT index,int cardId,char * eventsFileName);
//load the Events XML file into the Intec driver structures - don't configure HW
HRESULT  IntecLoadEvents(UINT index,int cardId,char * eventsFileName);
// Get a Event configuration
HRESULT IntecGetEventParam(UINT index,int cardId,EventType evType,int eventId,  char *paramName,UINT *paramValue);
// Set a Event configuration
HRESULT IntecSetEventParam(UINT index,int cardId,EventType evType,int eventId,   char *paramName,UINT paramValue);

// Get a Event disable
HRESULT IntecGetEventDisableStatus(UINT index,int cardId,EventType evType,int eventId, bool * isDisable, bool *disableStatus);
// Get a Event StopTesting status
HRESULT  IntecGetEventStopTestingStatus(UINT index,int cardId,EventType evType,int eventId, bool * stopTesting);
// Set a Event disable or enable
HRESULT IntecSetEventDisableEnable(UINT index,int cardId,EventType evType,int eventId, bool disable_enable);

// Get Events status
HRESULT IntecGetEventsStatus(UINT index,int cardId,EventType evType,UINT32 * eventsStatus);

// Get Events Name
HRESULT IntecGetEventName(UINT index,int cardId,EventType evType,int eventId,int maxMsgLen, char * msg);

// Get Events Description
HRESULT IntecGetEventDescription(UINT index,int cardId,EventType evType,int eventId,int maxMsgLen, char * msg);

// Get Events Action
HRESULT IntecGetEventAction(UINT index,int cardId,EventType evType,int eventId,int maxMsgLen, char * msg);

// Get Events params size
HRESULT IntecGetEventParamsSize(UINT index,int cardId,EventType evType,int eventId,unsigned int *paramsSize);

// Get Events param[paramId]
HRESULT IntecGetEventParamName(UINT index,int cardId,EventType evType,int eventId,unsigned int paramId,int maxMsgLen, char * msg);

// Disarm Intec  and enable the operator to fix issues
HRESULT IntecDisarm(UINT index,int cardId, UINT TimeOutMiliSec);

// Arm Intec  after the operator to fix issues
HRESULT IntecRearm(UINT index,int cardId, UINT TimeOutMiliSec);

// Fast Disarm Intec  and enable the operator to fix issues
HRESULT IntecFastDisarm(UINT index,int cardId);

// Fast Arm Intec  after the operator to fix issues
HRESULT IntecFastRearm(UINT index,int cardId);

// Get Disarm Intec status and enable the operator to fix issues
HRESULT IntecGetDisarmStatus(UINT index,int cardId,  bool * isDisarmed);

// choose RTD Sensor Type
HRESULT IntecSetRTDSensor(UINT index,int cardId,IntecRTDSensorType sensor_type);

// Get RTD Sensor Type
HRESULT IntecGetRTDSensor(UINT index,int cardId,IntecRTDSensorType *sensor_type);

// Set The Gang Auto Cfg mode : 1- enable, 0-disable
HRESULT  IntecGetGangAutoCfg(UINT index,int cardId,bool * gangAutoCfgMode);

// Get The Gang Auto Cfg mode : 1- enabled, 0-disabled
HRESULT   IntecSetGangAutoCfg(UINT index,int cardId,bool gangAutoCfgMode);
// Get The RTD Sensor Type
HRESULT IntecGetTCaseType(UINT index,int cardId,IntecTCASEType *tcase_type);

//General functions


//General functions 

// Reset Intec HW
// resetType:  0 – reset device
// 			 1  - reset to EEPROM default params
HRESULT IntecReset(UINT index,int resetType);

// Disable/Enable the Intec buzzer
HRESULT  IntecBuzzerDisableEnable(UINT index,bool disable);
// EEPROm Functions

// Get EEPROM Status and Type
HRESULT IntecGetThermalHeadEEpromStatus(UINT index,int card_id,bool *ThEEpormNotDetected,bool *THEEpromType );

// clear EEPROM configuration to default and restart software.
HRESULT IntecClearConfigurationFromEEPROM(UINT index);
// Store configuration to EEPROM .
HRESULT IntecStoreConfigurationToEEPROM(UINT index);

// Reset Microchip Software
// after this call user need to call Terminate() and  Initialize() functions
HRESULT IntecSoftwareReset(UINT index);
// IntecD TEC functions
// These functions controls the TES (thermal Head)

// Enable/Disable the TEC head
HRESULT IntecTECEnableDisable(UINT index,int cardId,bool enable);
// Set Proportional gain,Integral,Derivative parameters
HRESULT IntecTECSetControlParams(UINT index,int cardId,UINT proportional, UINT integral, UINT derivative);
// Get Proportional gain,Integral,Derivative parameters
HRESULT IntecTECGetControlParams(UINT index,int cardId,UINT *proportional, UINT *integral, UINT *derivative);

// Get the  CurrentSense ,VoltageSense , PowerOutCalc and PowerSupplySense  Fields in D_POWER_OUT_SENSE 
HRESULT IntecTECGetParams(UINT index,int cardId,float *currentSense, float *voltageSense, float *powerOutCalc, float *powerSupplySense, UINT *PWMCalc);
// Get the TEC head status enable/disable, cooling/heating
HRESULT IntecTECStatus(UINT index,int cardId,int *enable, int *heat_status, int *cool_status);

// Set PRBS Low and High voltages
HRESULT IntecTECSetPRBSVoltage(UINT index,int cardId,float lowVoltage, float highVoltage);

// Get PRBS Low and High voltages
HRESULT IntecTECGetPRBSVoltage(UINT index,int cardId,float *lowVoltage, float *highVoltage);

// Set OpenLoop  voltage
HRESULT  IntecTECSetOpenLoopVoltage(UINT index,int cardId,float Voltage);

// Get Open Loop voltage
HRESULT IntecTECGetOpenLoopVoltage(UINT index,int cardId,float *Voltage);

// Set Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
HRESULT IntecTECSetVmax(UINT index,int cardId,float Voltage);

// Get Output Max voltage (for outputting to devices that are rated lower than the TEC power supply)
HRESULT  IntecTECGetVmax(UINT index,int cardId,float *Voltage);


// Set Output Max Heat voltage (for outputting to devices that are rated lower than the TEC power supply)
HRESULT IntecTECSetVmaxHeatTec(UINT index,int cardId,float Voltage);

// Get Output Max Heat voltage (for outputting to devices that are rated lower than the TEC power supply)
HRESULT  IntecTECGetVmaxHeatTec(UINT index,int cardId,float *Voltage);
// Set PRBS Control Mode
HRESULT  IntecTECSetControlMode(UINT index,int cardId,IntecTecMode mode);

// Get PRBS Control Mode
HRESULT IntecTECGetControlMode(UINT index,int cardId,IntecTecMode *mode);

//Thermal Head APIs
HRESULT IntecGetThermalHeadParam(UINT index,int cardId,IntecThermalHeadRegId paramType, unsigned int maxdataLen, char * data, unsigned int *actualDataLen );


//Ramp Rate Control
HRESULT IntecConfigureRampRateControlParam(UINT index,int cardId,bool  EnableRampRateControl,bool EnableFullRampRateControl, unsigned short   DesRampRate, unsigned short RampRateSPMargin );

HRESULT IntecGetRampRateControlParam(UINT index,int cardId,bool * EnableRampRateControl,bool *EnableFullRampRateControl, unsigned short  * DesRampRate, unsigned short * RampRateSPMargin,unsigned short * MesRampRate );

// WRITE to BLT TH EEPROM
HRESULT IntecWriteBLTEEprom(UINT index,int card_id, UINT offset, unsigned char * buffer, unsigned int size);


// Read to BLT TH EEPROM
HRESULT IntecReadBLTEEprom(UINT index,int card_id, UINT offset, unsigned char * buffer, unsigned int size);



//configuration by file
HRESULT IntecConfigureByFile(UINT index,char * configFileName);


//  Diagnostic
HRESULT  IntecDiagnosticConfigure(UINT index,char *configureDiagnosticFileName);
HRESULT  IntecDiagnosticStart(UINT index);
HRESULT  IntecDiagnosticAbort(UINT index) ;
HRESULT  IntecDiagnosticGetResult(UINT index,bool * running,bool *passed, int * num_of_errors ,char* error_msgs[],int max_messages);
HRESULT IntecDiagnosticGetXMLFileName(UINT index, char *configureDiagnosticFileName, unsigned int bufferSize);
HRESULT IntecGetDiagnosticTestStatus(UINT index, unsigned int testID, bool * enabled);
HRESULT IntecGetDiagnosticParamVal(UINT index, const char * paramName,const char * paramType, float * calcVal);
HRESULT  IntecGetImpedance(UINT index,int cardId,bool * valid,float *impedance);
HRESULT  IntecEnvGetCondensationVoltage(UINT index, int cardId, float * voltage);
HRESULT  IntecGetWaterModuleStatus(UINT index,int cardId,bool *connected);
HRESULT  IntecGetWaterModuleParams(UINT index,int cardId,bool *moduleConnected,bool *WaterModuleMeasEnabled,bool *ChillerMeasEnabled,bool *FloorMeasEnabled, float *WaterModuleImp ,float *ChillerImp , float *FloorImp);
HRESULT  IntecGetCoolentFlowsense(UINT index,int cardId,float *flowsense);

//Error handling functions
void GetIntecLastError(char *buff, UINT bufsize);
void SetIntecLastError(const char * err);



}

//Mutex APIs - internal usage not exposed
HRESULT CreateIntecMutex();
HRESULT DeleteIntecMutex();
HRESULT LockMutex();
HRESULT UnlockMutex();
#endif
