/*
 * ClibIntecOperations.cpp
 *
 *  Created on: Apr 8, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com> 
 */

#include "ClibIntecOperations.h"

ClibIntecOperations::ClibIntecOperations(unsigned int DevIndex)
{
	m_device_index = DevIndex;
	m_initialization_flag = false;
}

ClibIntecOperations::~ClibIntecOperations()
{
}

void printbuffer(unsigned char* buffer, unsigned int size)
{
	for (unsigned int i=0; i < size; i++)
	{
		std::cout << std::hex << (unsigned int) buffer[i];
		if (i % 80 == 0 && i != 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

int ClibIntecOperations::Initialize(int reset)
{
	m_initialization_flag = false;
	memset(peci_dts_arr, 0, sizeof(PECI_DTS)*MAX_DTS);
	memset(peci_pkg_arr, 0, sizeof(PECI_PACKAGE)*MAX_PACKAGES);

	UN_DIODE_STATUS diode_status;

	m_readSize = sizeof(UN_DIODE_STATUS);

	if(libIntec_ReadDeviceByAddr(m_device_index, INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_DIODE_STATUS, (unsigned char *)&diode_status.value, &m_readSize) != STATUS_OK)
	{
		return ERROR_FAIL;
	}
	TDAUDetected_ = diode_status.fields.TDAUDetected;
	//update the InTECDCards_ , PECIModuleExist_
	if(IntecGetSysCardsConfiguration() != STATUS_OK)
		return ERROR_FAIL;

	if(reset)
	{
		// update the currentDiodeMask_
		currentDiodeMask_ = 0;
		if(IntecSetDiodeInputs(true, currentDiodeMask_) != STATUS_OK)
			return ERROR_FAIL;

		// update the currentPFMask_
		currentPFMask_ = 0;
		if(IntecSetPFInputs(true, currentPFMask_) != STATUS_OK)
			return ERROR_FAIL;
		// update the currentProcHOTMask_
		currentProcHOTMask_ = 0;
		if(IntecSetProcHotInputs(true, currentProcHOTMask_) != STATUS_OK)
			return ERROR_FAIL;

		// update the currentProcHOTMask_
		currentPeciMask_ = 0;
		if(IntecSetPeciInputs(true, currentPeciMask_) != STATUS_OK)
			return ERROR_FAIL;

		if(IntecClearPeciSensorsConfiguration() != STATUS_OK)
			return ERROR_FAIL;

		for (int i = 0; i < InTECDCards_; i++)
		{
			currentCaseMask_[i] = 0;
			if (IntecSetCaseInputs(i ,true, currentCaseMask_[i]) != STATUS_OK)
				return ERROR_FAIL;

			// read the actual mask back from HW since it can be forced by HW - case0 is forced
			if (IntecGetCaseInputs(i, &currentCaseMask_[i]) != STATUS_OK)
				return ERROR_FAIL;

			//char eventsFileName[256];
			getcwd(workingDir_, sizeof(workingDir_));
			//snprintf(eventsFileName,256, "%s%s.xml", workingDir_, EVENTS_FILE_NAME);
			IntecLoadandConfigureEvents(i,ConfigFileDir_, false);
		}
	}
	else
	{
		if(IntecGetDiodeInputs(&currentDiodeMask_) != STATUS_OK)
			return ERROR_FAIL;

		if(IntecGetPFInputs(&currentPFMask_) != STATUS_OK)
			return ERROR_FAIL;


		if(IntecGetProcHotInputs(&currentProcHOTMask_) != STATUS_OK)
			return ERROR_FAIL;


		if(IntecGetPeciInputs(&currentPeciMask_) != STATUS_OK)
			return ERROR_FAIL;

		for(int i=0; i < InTECDCards_; i++)
		{
			if(IntecGetCaseInputs(i,&currentCaseMask_[i]) != STATUS_OK)
				return ERROR_FAIL;
			//char eventsFileName[256];
			getcwd(workingDir_, sizeof(workingDir_));
			//GetWorkDir(sizeof(workingDir_), workingDir_);
			//sprintf_s(eventsFileName,256, "%s%s.xml", workingDir_, EVENTS_FILE_NAME);
			IntecLoadandConfigureEvents(i, ConfigFileDir_, false);
		}
	}

	// build Intec Tests Error messages vectors
//	if(buildIntecBenchSelfTestErrorMessages() != STATUS_OK)
//		return ERROR_FAIL;
//	if(buildIntecStandaloneSelfTestErrorMessages() != STATUS_OK)
//		return ERROR_FAIL;
//	if(buildIntecBasicFunctionalitySelfTestErrorMessages() != STATUS_OK)
//		return ERROR_FAIL;

//	// build IntecD Tests Error messages vectors
//	if(buildIntecDBenchSelfTestErrorMessages() != STATUS_OK)
//		return ERROR_FAIL;
//	if(buildIntecDStandaloneSelfTestErrorMessages() != STATUS_OK)
//		return ERROR_FAIL;
//	if(buildIntecDBasicFunctionalitySelfTestErrorMessages() != STATUS_OK)
//		return ERROR_FAIL;
//	if(buildIntecDWaterModuleBenchTestErrorMessages() != STATUS_OK)
//		return ERROR_FAIL;
//	if(peciFrequencyTablesInitialization() != STATUS_OK)
//		return ERROR_FAIL;

	m_initialization_flag = true;
	Initialized_= true;
	return STATUS_OK;
}

const int ClibIntecOperations::IntecGetSysCardsConfiguration()
{
	UN_CONNECTED_DEVICES connectedDevices;
	InTECDCards_= 0;
	PECIModuleExist_ = false;
	readSize_ = sizeof(UN_CONNECTED_DEVICES);

	if(libIntec_ReadDeviceByAddr(deviceIndex_, INTEC_BASE_ADDR|OFFSET_UNIT_GENERAL|OFFSET_CONNECTED_DEVICES, (unsigned char *)&connectedDevices.value, &readSize_) != STATUS_OK)
	{
		SetIntecLastError("IntecGetSysCardsConfiguration:: Failed to Read OFFSET_CONNECTED_DEVICES");
		return ERROR_FAIL;
	}
	if(connectedDevices.fields.PECIModule)
		PECIModuleExist_ = true;
	if(connectedDevices.fields.InTECD0)
		InTECDCards_++;
	if(connectedDevices.fields.InTECD1)
		InTECDCards_++;
	if(connectedDevices.fields.InTECD2)
		InTECDCards_++;
	if(connectedDevices.fields.InTECD3)
		InTECDCards_++;

	return STATUS_OK;
}

const int ClibIntecOperations::IntecSetDiodeInputs(bool enable, unsigned int mask)
{
	if(enable)
		currentDiodeMask_ |= mask;
	else
		currentDiodeMask_ &= ((~mask)&0xf);

	UN_DIODE_CFG diode_cfg;
	writeSize_=sizeof(UN_DIODE_CFG);
	diode_cfg.fields.PollDiodes=currentDiodeMask_;

	if(libIntec_WriteDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_DIODE_CFG,(UCHAR *)&diode_cfg.value,writeSize_))
	{
		return ERROR_FAIL;
	}
	return STATUS_OK;

}

const int ClibIntecOperations::IntecSetPFInputs(bool enable, unsigned int mask)
{
	if(enable)
		currentPFMask_ |=mask;
	else
		currentPFMask_ &=((~mask)&0xf);

	UN_PF_CFG pf_cfg;
	writeSize_= sizeof(UN_PF_CFG);
	pf_cfg.fields.PollPF = currentPFMask_;
	if(libIntec_WriteDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PF_CFG, (unsigned char *)&pf_cfg.value, writeSize_))
	{
		SetIntecLastError("IntecSetPFInputs: Failed to Write  OFFSET_PF_CFG");
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

const int ClibIntecOperations::IntecSetProcHotInputs(bool enable, unsigned int mask)
{
	//Clear Prochot status fields for a specific channel by setting the appropriate bit of ChResetCounter field in PROCHOT_CFG register. 
	if(IntecClearProcHotEventsCounter(-1) != STATUS_OK)
		return ERROR_FAIL;
	//Select which Prochot input to enable by setting the appropriate bits of the PollProchot field in PROCHOT_CFG register.
	if(enable)
		currentProcHOTMask_ |=mask;
	else
		currentProcHOTMask_ &=((~mask)&0xf);
	UN_PROCHOT_CFG prochot_cfg;
	readSize_=sizeof(UN_PROCHOT_CFG);
	if(libIntec_ReadDeviceByAddr(deviceIndex_, INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PROCHOT_CFG,(unsigned char *) &prochot_cfg.value, &readSize_) != STATUS_OK)
	{
		SetIntecLastError("IntecSetProcHotInputs::Failed to Read OFFSET_PROCHOT_CFG");
		return ERROR_FAIL;
	}
	prochot_cfg.fields.PollProchot=currentProcHOTMask_;


	writeSize_=sizeof(UN_PROCHOT_CFG);;

	if(libIntec_WriteDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PROCHOT_CFG,(unsigned char *)&prochot_cfg.value, writeSize_))
	{
		SetIntecLastError("IntecSetProcHotInputs: Failed to Write  OFFSET_PROCHOT_CFG");
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

const int ClibIntecOperations::IntecClearProcHotEventsCounter(int input_num)
{
	//Clear Prochot status fields for a specific channel by setting the appropriate bit of ChResetCounter field in PROCHOT_CFG register.

	int resetVal;
	if(input_num==-1)
		resetVal=0xf;
	else
		resetVal= (1<<input_num);

	UN_PROCHOT_CFG prochot_cfg;
	readSize_=sizeof(UN_PROCHOT_CFG);
	if (libIntec_ReadDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PROCHOT_CFG,(unsigned char *)&prochot_cfg.value, &readSize_) != STATUS_OK)
	{
		SetIntecLastError("IntecClearProcHotEventsCounter:: Failed to Read OFFSET_PROCHOT_CFG");
		return ERROR_FAIL;
	}

	prochot_cfg.fields.ChResetCounter=resetVal;

	writeSize_=sizeof(UN_PROCHOT_CFG);

	if (libIntec_WriteDeviceByAddr(deviceIndex_, INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PROCHOT_CFG,(unsigned char *)&prochot_cfg.value, writeSize_))
	{
		SetIntecLastError("IntecClearProcHotEventsCounter: Failed to Write  OFFSET_PROCHOT_CFG");
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

const int ClibIntecOperations::IntecSetPeciInputs(bool enable, unsigned int mask)
{
	if (!PECIModuleExist_)
	{
		SetIntecLastError("IntecSetPeciInputs() - Peci Module does not exist");
		return ERROR_FAIL;
	}

	if (enable)
		currentPeciMask_ |= mask;
	else
		currentPeciMask_ &=((~mask)&0xffff);

	UN_P_PECI_CFG peci_cfg;
	writeSize_= sizeof(UN_P_PECI_CFG);
	peci_cfg.fields.PollDts = currentPeciMask_;
	if (libIntec_WriteDeviceByAddr(deviceIndex_, PECI_DEVICE_BASE_ADDR |OFFSET_UNIT_P_DTS_CFG|OFFSET_P_PECI_CFG, (unsigned char *)&peci_cfg.value, writeSize_))
	{
		SetIntecLastError("IntecSetPeciInputs:: Failed to Write  OFFSET_P_PECI_CFG");
		return ERROR_FAIL;
	}
	return STATUS_OK;
}

const int ClibIntecOperations::IntecClearPeciSensorsConfiguration()
{
		// build the register and write it to HW.
		UN_P_CFG_DTS0 dts_cfg_reg;
		dts_cfg_reg.value=0;
		writeSize_= sizeof(UN_P_CFG_DTS0);
		for(int channel=0; channel< MAX_DTS; channel++)
		{
			if(libIntec_WriteDeviceByAddr(deviceIndex_,PECI_DEVICE_BASE_ADDR |OFFSET_UNIT_P_DTS_CFG|(OFFSET_P_CFG_DTS0+channel),(UCHAR *)&dts_cfg_reg.value,writeSize_))
			{
				SetIntecLastError("IntecClearPeciSensorsConfiguration:: Failed to Write  OFFSET_P_CFG_DTS0 +channel");
				return ERROR_FAIL;
			}
		}
		usleep(50);
		UN_P_CFG_DTS_UPDATE dts_update_reg;
		dts_update_reg.value=0;
		dts_update_reg.fields.UpdateDtsCfg=1;
		writeSize_=sizeof(UN_P_CFG_DTS_UPDATE);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,PECI_DEVICE_BASE_ADDR |OFFSET_UNIT_P_DTS_CFG|OFFSET_P_CFG_DTS_UPDATE,(UCHAR *)&dts_update_reg.value,writeSize_))
		{
			SetIntecLastError("IntecClearPeciSensorsConfiguration:: Failed to Write  OFFSET_P_CFG_DTS_UPDATE ");
			return ERROR_FAIL;
		}

		return STATUS_OK;
}

const int ClibIntecOperations::IntecSetCaseInputs(int cardId,bool enable, unsigned int mask)
{
	if (IsCardExist(cardId))
	{
		if(enable)
			currentCaseMask_[cardId] |=mask;
		else
			currentCaseMask_[cardId] &=((~mask)&0xf);
		UN_D_CASE_CFG case_cfg;
		writeSize_=readSize_=sizeof(UN_D_CASE_CFG);

		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|OFFSET_UNIT_D_CASE|OFFSET_D_CASE_CFG,(UCHAR *)&case_cfg.value,&readSize_))
		{
			SetIntecLastError("IntecSetCaseInputs:: Failed to Read  OFFSET_D_CASE_CFG");
			return ERROR_FAIL;
		}

		case_cfg.fields.PollTcase=currentCaseMask_[cardId];
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|OFFSET_UNIT_D_CASE|OFFSET_D_CASE_CFG,(UCHAR *)&case_cfg.value,writeSize_))
		{
			SetIntecLastError("Failed to Write  OFFSET_D_CASE_CFG");
			return ERROR_FAIL;
		}
		return STATUS_OK;

	}
	else
	{
		//sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecSetCaseInputs() :IntecDCard (%d) Not Exist ",cardId);
		SetIntecLastError(msg_buf);
	}

	return ERROR_FAIL;
}

bool ClibIntecOperations::IsCardExist(int cardId)
{
	// check if the IntecD cardId is connected
	if (cardId < InTECDCards_)
	{
		return true;
	}
	return false;
}

const int ClibIntecOperations::IntecGetCaseInputs(int cardId,unsigned int *mask)
{

	if (IsCardExist(cardId))
	{
		//*mask=currentCaseMask_[cardId];
		UN_D_CASE_CFG case_cfg;
		case_cfg.value = 0;
		readSize_ = sizeof(UN_D_CASE_CFG);

		if(libIntec_ReadDeviceByAddr(deviceIndex_, (INTECD0_DEVICE_BASE_ADDR<< cardId)|OFFSET_UNIT_D_CASE|OFFSET_D_CASE_CFG, (UCHAR *)&case_cfg.value, &readSize_) != STATUS_OK)
		{
			SetIntecLastError("IntecGetCaseInputs:: Failed to Read  OFFSET_D_CASE_CFG");
			return ERROR_FAIL;
		}
		*mask=case_cfg.fields.PollTcase;
		return STATUS_OK;

	}
	else
	{
		//sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecGetCaseInputs() :IntecDCard (%d) Not Exist ",cardId);
		SetIntecLastError(msg_buf);
	}

		return ERROR_FAIL;
}

unsigned short ClibIntecOperations::convertRealToIntecTemperature(float RealTemperature)
{
	return (unsigned short)((RealTemperature + 64)*10);
}

unsigned int ClibIntecOperations::calculateEventParamVal(std::string paramVal,std::string paramType)
{
	float fValue = (float)std::atof(paramVal.c_str());
	//unsigned int uValue = (unsigned int)std::atoi(paramVal.c_str());

	if(paramType=="1T")
		return (unsigned int)(fValue);
	if(paramType=="10T")
		return (unsigned int)(fValue*10);
	if(paramType=="100T")
		return (unsigned int)(fValue*100);
	if(paramType=="1000T")
		return (unsigned int)(fValue*100);
	return (unsigned int)convertRealToIntecTemperature(fValue);
}

//----------------------
// Events Functions
//----------------------
//load and configure Events XML file.
const int ClibIntecOperations::IntecLoadandConfigureEvents(int cardId,const char * eventsFileName, bool configureHW )
{

	//unsigned int address,bus,pkgId,channelId,sensorNum,enMaxTemp;
	//char dtsName[20];
	char sectionName[20];
	unsigned int paramIndex=0;
	auto eventsInfo_file( new ClibIntecXml(eventsFileName) );
	maxFailureId_=-1;
	maxWarningId_=-1;
	maxNotificationId_=-1;
	maxIntecHErrorId_=-1;
	maxIntecDErrorId_=-1;

	memset(failure_events,0,sizeof(SAFETY_EVENT) *MAX_EVENTS);
	memset(warning_events,0,sizeof(SAFETY_EVENT) *MAX_EVENTS);
	memset(notification_events,0,sizeof(SAFETY_EVENT) *MAX_EVENTS);

	memset(IntecH_HW_errors,0,sizeof(HARDWARE_ERROR) *MAX_ERRORS);
	memset(IntecD_HW_errors,0,sizeof(HARDWARE_ERROR) *MAX_ERRORS);

	if(!eventsInfo_file->FocusOnRoot())
	{
		//sprintf_s(errBuf,"CIntecOperations::IntecLoadandConfigureEvents,Can not find root node in file. Probably file %s doesn't exists or it is not valid xml file ",eventsFileName);
		SetIntecLastError(errBuf);
		return false;
	}
	eventsInfo_file->GetCurrentSectionName(sectionName);
	if(strcmp(sectionName,"SafetyEvents")!=0)
	{
		//sprintf_s(errBuf,"CIntecOperations::IntecLoadandConfigureEvents,Can not find root <SafetyEvents> in file. Probably file %s is not a valid events xml file file ",eventsFileName);
		SetIntecLastError(errBuf);
		return false;
	}

	// focus on Failures parse and configure it.
	if(eventsInfo_file->FocusOnSubSection(FAILURE_EVENTS))
	{
		unsigned int id;
		char buf[256];
		int bm;
		if(eventsInfo_file->FocusOnSubSection("Event"))
		{
			do
			{
			eventsInfo_file->GetCurrentSectionName(sectionName);
			if(strcmp(sectionName,"Event")==0)
			{
				eventsInfo_file->GetData("Id", id,false);
				failure_events[id].id=id;
				if((int)id> maxFailureId_)
					maxFailureId_=id;

				eventsInfo_file->GetData("Name",failure_events[id].name);
				eventsInfo_file->GetData("Description",failure_events[id].description);
				eventsInfo_file->GetData("Action",failure_events[id].action);
				failure_events[id].stopTesting=false;
				// check disable status
				bm=eventsInfo_file->SetBookmark();
				if(eventsInfo_file->FocusOnSubSection("IsDisable"))
				{
					failure_events[id].isDisable=true;
					memset(buf,0,256);
					eventsInfo_file->GetData("Disable",buf);
					if(!strcmp(buf,"No"))
						failure_events[id].disable=false;
					else
						failure_events[id].disable=true;
				}
				else
				{
					failure_events[id].isDisable=false;
					failure_events[id].disable=false;
				}

				//if(failure_events[id].isDisable  && configureHW)
				//	IntecSetEventDisableEnable(cardId,FailureEvent,id,failure_events[id].disable);
				eventsInfo_file->FocusOnBookmark(bm);
				eventsInfo_file->ClearBookmark(bm);

				//parse params
				bm=eventsInfo_file->SetBookmark();

				if(eventsInfo_file->FocusOnSubSection("Cfg"))
				{


					paramIndex=0;
					// params exist
					if(eventsInfo_file->FocusOnSubSection("Param"))
					{
						do
						{
							eventsInfo_file->GetCurrentSectionName(sectionName);
							if(strcmp(sectionName,"Param")==0)
							{
							eventsInfo_file->GetData("Name",failure_events[id].params[paramIndex].Name);
							eventsInfo_file->GetData("Type",failure_events[id].params[paramIndex].Type);
							memset(buf,0,256);
							eventsInfo_file->GetData("Val", buf);
							failure_events[id].params[paramIndex].value = calculateEventParamVal(std::string(buf),std::string(failure_events[id].params[paramIndex].Type));
							eventsInfo_file->GetData("Description",failure_events[id].params[paramIndex].Description);
							if(configureHW)
							{
								if(!IntecSetEventParam(cardId,FailureEvent,id, failure_events[id].params[paramIndex]))
									return false;
							}
							}
							else
								break;
							paramIndex++;
						} while(eventsInfo_file->FocusOnNextSection());   //while there are params for this event
						failure_events[id].numOfParams=paramIndex;
					}
				}
				eventsInfo_file->FocusOnBookmark(bm);
				eventsInfo_file->ClearBookmark(bm);
			}
			else
				break;
			} while(eventsInfo_file->FocusOnNextSection()); //while there are Events
			if(configureHW)
			{
				if(!IntecSetAllEventDisableEnable(cardId,FailureEvent))
					return false;
			}
		}
	}

	eventsInfo_file->FocusOnRoot();
	// focus on Warnings parse and configure it.
	if(eventsInfo_file->FocusOnSubSection(WARNING_EVENTS))
	{
		unsigned int id;
		char buf[256];
		int bm;
		if(eventsInfo_file->FocusOnSubSection("Event"))
		{
			do
			{
				eventsInfo_file->GetCurrentSectionName(sectionName);
				if(strcmp(sectionName,"Event")==0)
				{
					eventsInfo_file->GetData("Id", id,false);
					warning_events[id].id=id;
					if((int)id> maxWarningId_)
						maxWarningId_=id;
					eventsInfo_file->GetData("Name",warning_events[id].name);
					eventsInfo_file->GetData("Description",warning_events[id].description);
					eventsInfo_file->GetData("Action",warning_events[id].action);
					memset(buf,0,256);
					eventsInfo_file->GetData("StopTesting",buf);
					if(strcmp(buf,"Yes")==0)
						warning_events[id].stopTesting=true;
					else
						warning_events[id].stopTesting=false;
					// check disable status
					bm=eventsInfo_file->SetBookmark();
					if(eventsInfo_file->FocusOnSubSection("IsDisable"))
					{
						warning_events[id].isDisable=true;
						memset(buf,0,256);
						eventsInfo_file->GetData("Disable",buf);
						if(!strcmp(buf,"No"))
							warning_events[id].disable=false;
						else
							warning_events[id].disable=true;
					}
					else
					{
						warning_events[id].isDisable=false;
						warning_events[id].disable=false;
					}

					//if(warning_events[id].isDisable &&  configureHW)
					//	IntecSetEventDisableEnable(cardId,WarningEvent,id,warning_events[id].disable);
					eventsInfo_file->FocusOnBookmark(bm);
					eventsInfo_file->ClearBookmark(bm);

					//parse params
					bm=eventsInfo_file->SetBookmark();
					if(eventsInfo_file->FocusOnSubSection("Cfg"))
					{

						paramIndex=0;
						// params exist
						if(eventsInfo_file->FocusOnSubSection("Param"))
						{
							do
							{
								eventsInfo_file->GetCurrentSectionName(sectionName);
								if(strcmp(sectionName,"Param")==0)
								{
									eventsInfo_file->GetData("Name",warning_events[id].params[paramIndex].Name);
									eventsInfo_file->GetData("Type",warning_events[id].params[paramIndex].Type);
									memset(buf,0,256);
									eventsInfo_file->GetData("Val", buf);
									warning_events[id].params[paramIndex].value=calculateEventParamVal(std::string(buf),std::string(warning_events[id].params[paramIndex].Type));
									eventsInfo_file->GetData("Description",warning_events[id].params[paramIndex].Description);
									if(configureHW)
									{
										if(!IntecSetEventParam(cardId,WarningEvent,id, warning_events[id].params[paramIndex]))
											return false;
									}
								}
								else
									break;
								paramIndex++;
							} while(eventsInfo_file->FocusOnNextSection());   //while there are params for this event
							warning_events[id].numOfParams=paramIndex;
						}
					}
					eventsInfo_file->FocusOnBookmark(bm);
					eventsInfo_file->ClearBookmark(bm);
				}
				else
					break;
			} while(eventsInfo_file->FocusOnNextSection()); //while there are Events
			if(configureHW)
			{
				if(!IntecSetAllEventDisableEnable(cardId,WarningEvent))
					return false;
			}
		}
	}


	eventsInfo_file->FocusOnRoot();
	// focus on Notifications parse and configure it.
	if(eventsInfo_file->FocusOnSubSection(NOTIFICATION_EVENTS))
	{
		unsigned int id;
		char buf[256];
		int bm;
		if(eventsInfo_file->FocusOnSubSection("Event"))
		{
			do
			{
				eventsInfo_file->GetCurrentSectionName(sectionName);
				if(strcmp(sectionName,"Event")==0)
				{
					eventsInfo_file->GetData("Id", id,false);
					notification_events[id].id=id;
					if((int)id> maxNotificationId_)
						maxNotificationId_=id;
					eventsInfo_file->GetData("Name",notification_events[id].name);
					eventsInfo_file->GetData("Description",notification_events[id].description);
					eventsInfo_file->GetData("Action",notification_events[id].action);
					notification_events[id].stopTesting=false;
					// check disable status
					bm=eventsInfo_file->SetBookmark();
					if(eventsInfo_file->FocusOnSubSection("IsDisable"))
					{
						notification_events[id].isDisable=true;
						memset(buf,0,256);
						eventsInfo_file->GetData("Disable",buf);
						if(!strcmp(buf,"No"))
							notification_events[id].disable=false;
						else
							notification_events[id].disable=true;
					}
					else
					{
						notification_events[id].isDisable=false;
						notification_events[id].disable=false;
					}

					//if(notification_events[id].isDisable  && configureHW)
					//	IntecSetEventDisableEnable(cardId,NotificationEvent,id,notification_events[id].disable);
					eventsInfo_file->FocusOnBookmark(bm);
					eventsInfo_file->ClearBookmark(bm);

					//parse params
					bm=eventsInfo_file->SetBookmark();
					if(eventsInfo_file->FocusOnSubSection("Cfg"))
					{

						paramIndex=0;
						// params exist
						if(eventsInfo_file->FocusOnSubSection("Param"))
						{
							do
							{
								eventsInfo_file->GetCurrentSectionName(sectionName);
								if(strcmp(sectionName,"Param")==0)
								{
									eventsInfo_file->GetData("Name",notification_events[id].params[paramIndex].Name);
									eventsInfo_file->GetData("Type",notification_events[id].params[paramIndex].Type);
									memset(buf,0,256);
									eventsInfo_file->GetData("Val", buf);
									notification_events[id].params[paramIndex].value=calculateEventParamVal(std::string(buf),std::string(notification_events[id].params[paramIndex].Type));
									eventsInfo_file->GetData("Description",notification_events[id].params[paramIndex].Description);
									if(configureHW)
									{
										if(!IntecSetEventParam(cardId,NotificationEvent,id, notification_events[id].params[paramIndex]))
											return false;
									}
								}
								else
									break;
								paramIndex++;
							} while(eventsInfo_file->FocusOnNextSection());   //while there are params for this event
							notification_events[id].numOfParams=paramIndex;
						}
					}
					eventsInfo_file->FocusOnBookmark(bm);
					eventsInfo_file->ClearBookmark(bm);
				}
				else
					break;
			} while(eventsInfo_file->FocusOnNextSection()); //while there are Events
			if(configureHW)
			{
				if(!IntecSetAllEventDisableEnable(cardId,NotificationEvent))
					return false;
			}

		}

	}

	eventsInfo_file->FocusOnRoot();
	// focus on Hardware parse and get IntecH Errors.
	if(eventsInfo_file->FocusOnSubSection(HARDWARE_ERRORS))
	{
		unsigned int id;
		if(eventsInfo_file->FocusOnSubSection("IntecH"))
		{
			if(eventsInfo_file->FocusOnSubSection("Error"))
			{
				do
				{
					eventsInfo_file->GetCurrentSectionName(sectionName);
					if(strcmp(sectionName,"Error")==0)
					{
						eventsInfo_file->GetData("Id", id,false);
						IntecH_HW_errors[id].id=id;
						if((int)id> maxIntecHErrorId_)
							maxIntecHErrorId_=id;
						eventsInfo_file->GetData("Name",IntecH_HW_errors[id].name);
						eventsInfo_file->GetData("Description",IntecH_HW_errors[id].description);
						eventsInfo_file->GetData("Action",IntecH_HW_errors[id].action);
					}
					else
						break;
				} while(eventsInfo_file->FocusOnNextSection()); //while there are Events

			}
		}
	}
	eventsInfo_file->FocusOnRoot();
	// focus on Hardware parse and get IntecD Errors.
	if(eventsInfo_file->FocusOnSubSection(HARDWARE_ERRORS))
	{
		unsigned int id;
		if(eventsInfo_file->FocusOnSubSection("IntecD"))
		{
			if(eventsInfo_file->FocusOnSubSection("Error"))
			{
				do
				{
					eventsInfo_file->GetCurrentSectionName(sectionName);
					if(strcmp(sectionName,"Error")==0)
					{
						eventsInfo_file->GetData("Id", id,false);
						IntecD_HW_errors[id].id=id;
						if((int)id> maxIntecDErrorId_)
							maxIntecDErrorId_=id;
						eventsInfo_file->GetData("Name",IntecD_HW_errors[id].name);
						eventsInfo_file->GetData("Description",IntecD_HW_errors[id].description);
						eventsInfo_file->GetData("Action",IntecD_HW_errors[id].action);
					}
					else
						break;
				} while(eventsInfo_file->FocusOnNextSection()); //while there are Events

			}
		}
	}
	return true;
}

const int ClibIntecOperations::IntecSetEventParam(int cardId, EventType evType, int eventId, EventConfigurationParam eventParam)
{
	if(strcmp(eventParam.Name,"WPS")==0)
	{
		UN_D_COOLANT coolant_reg;
		readSize_=sizeof(UN_D_COOLANT);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_COOLANT,(UCHAR *)&coolant_reg.value,&readSize_)!= STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_COOLANT register ");
			return false;
		}
		coolant_reg.fields.WpsTreshold=eventParam.value;
		writeSize_=sizeof(UN_D_COOLANT);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_COOLANT,(UCHAR *)&coolant_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_COOLANT register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_COOLANT,(UCHAR *)&coolant_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_COOLANT register ");
			return false;
		}
		if(coolant_reg.fields.WpsTreshold!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :write validation Failed coolant_reg.fields.WpsTreshold %d != eventParam.value %d",coolant_reg.fields.WpsTreshold,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}
	if(strcmp(eventParam.Name,"GPM")==0)
	{
		UN_D_COOLANT coolant_reg;
		readSize_=sizeof(UN_D_COOLANT);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_COOLANT,(UCHAR *)&coolant_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_COOLANT register ");
			return false;
		}
		coolant_reg.fields.GpmTreshold=eventParam.value;
		writeSize_=sizeof(UN_D_COOLANT);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_COOLANT,(UCHAR *)&coolant_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_COOLANT register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_COOLANT,(UCHAR *)&coolant_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_COOLANT register ");
			return false;
		}
		if(coolant_reg.fields.GpmTreshold!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :write validation Failed coolant_reg.fields.GpmTreshold %d != eventParam.value %d",coolant_reg.fields.GpmTreshold,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}
	if(strcmp(eventParam.Name,"PPT")==0)
	{
		UN_D_PURGE purge_reg;
		readSize_=sizeof(UN_D_PURGE);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_PURGE,(UCHAR *)&purge_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_PURGE register ");
			return false;
		}
		purge_reg.fields.PptTreshold=eventParam.value;
		writeSize_=sizeof(UN_D_PURGE);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_PURGE,(UCHAR *)&purge_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_PURGE register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_PURGE,(UCHAR *)&purge_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_PURGE register ");
			return false;
		}
		if(purge_reg.fields.PptTreshold!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed purge_reg.fields.PptTreshold %d != eventParam.value %d",purge_reg.fields.PptTreshold,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}
	if(strcmp(eventParam.Name,"OverrunErrMargin")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.OverrunErrMargin=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.OverrunErrMargin != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.OverrunErrMargin %d != eventParam.value %d",feedback_limits_reg.fields.OverrunErrMargin,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}
	if(strcmp(eventParam.Name,"OverrunErrSlope")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.OverrunErrSlope=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.OverrunErrSlope != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.OverrunErrSlope %d != eventParam.value %d",feedback_limits_reg.fields.OverrunErrSlope,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"OverrunErrTime")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.OverrunErrTime=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.OverrunErrTime != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation  Failed feedback_limits_reg.fields.OverrunErrTime %d != eventParam.value %d",feedback_limits_reg.fields.OverrunErrTime,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"SpTime")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.SpTime=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.SpTime != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation  Failed feedback_limits_reg.fields.SpTime %d != eventParam.value %d",feedback_limits_reg.fields.SpTime,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}
	if(strcmp(eventParam.Name,"SpMargin")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.SpMargin=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.SpMargin != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.SpMargin %d != eventParam.value %d",feedback_limits_reg.fields.SpMargin,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"MaxT")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.MaxT=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.MaxT != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.MaxT %d != eventParam.value %d",feedback_limits_reg.fields.MaxT,eventParam.value);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"MaxTime")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.MaxTime=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.MaxTime != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation  Failed feedback_limits_reg.fields.MaxTime %d != eventParam.value %d",feedback_limits_reg.fields.MaxTime,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"MinT")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.MinT=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.MinT != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.MinT %d != eventParam.value %d",feedback_limits_reg.fields.MinT,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}
	if(strcmp(eventParam.Name,"MinTime")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.MinTime=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.MinTime != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.MinTime %d != eventParam.value %d",feedback_limits_reg.fields.MinTime,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}
	if(strcmp(eventParam.Name,"TtpSetpoint")==0)
	{
		UN_D_TH_POSITION th_position_reg;
		readSize_=sizeof(UN_D_TH_POSITION);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_THERMAL_HEAD |OFFSET_D_TH_POSITION,(UCHAR *)&th_position_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_TH_POSITION register ");
			return false;
		}
		th_position_reg.fields.TtpSetpoint=eventParam.value;
		writeSize_=sizeof(UN_D_TH_POSITION);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_THERMAL_HEAD |OFFSET_D_TH_POSITION,(UCHAR *)&th_position_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_TH_POSITION register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_THERMAL_HEAD |OFFSET_D_TH_POSITION,(UCHAR *)&th_position_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_TH_POSITION register ");
			return false;
		}
		if(th_position_reg.fields.TtpSetpoint != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation  Failed th_position_reg.fields.TtpSetpoint %d != eventParam.value %d",th_position_reg.fields.TtpSetpoint,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"TtpTimeout")==0)
	{
		UN_D_TH_POSITION th_position_reg;
		readSize_=sizeof(UN_D_TH_POSITION);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_THERMAL_HEAD |OFFSET_D_TH_POSITION,(unsigned char *)&th_position_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_TH_POSITION register ");
			return false;
		}
		th_position_reg.fields.TtpTimeout=eventParam.value;
		writeSize_=sizeof(UN_D_TH_POSITION);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_THERMAL_HEAD |OFFSET_D_TH_POSITION,(UCHAR *)&th_position_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_TH_POSITION register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_THERMAL_HEAD |OFFSET_D_TH_POSITION,(UCHAR *)&th_position_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_TH_POSITION register ");
			return false;
		}
		if(th_position_reg.fields.TtpTimeout != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed th_position_reg.fields.TtpTimeout %d != eventParam.value %d",th_position_reg.fields.TtpTimeout,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"DeltaTemp")==0)
	{
		UN_D_FEEDBACK_DELTA_CFG feedback_delta_reg;
		readSize_=sizeof(UN_D_FEEDBACK_DELTA_CFG);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_DELTA_CFG,(UCHAR *)&feedback_delta_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_DELTA_CFG register ");
			return false;
		}
		feedback_delta_reg.fields.DeltaTemp=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_DELTA_CFG);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_DELTA_CFG,(UCHAR *)&feedback_delta_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_DELTA_CFG register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_DELTA_CFG,(UCHAR *)&feedback_delta_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_DELTA_CFG register ");
			return false;
		}
		if(feedback_delta_reg.fields.DeltaTemp != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_delta_reg.fields.DeltaTemp %d != eventParam.value %d",feedback_delta_reg.fields.DeltaTemp,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"DeltaTempTime")==0)
	{
		UN_D_FEEDBACK_DELTA_CFG feedback_delta_reg;
		readSize_=sizeof(UN_D_FEEDBACK_DELTA_CFG);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_DELTA_CFG,(UCHAR *)&feedback_delta_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_DELTA_CFG register ");
			return false;
		}
		feedback_delta_reg.fields.DeltaTempTime=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_DELTA_CFG);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_DELTA_CFG,(UCHAR *)&feedback_delta_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_DELTA_CFG register ");
			return false;
		}

		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_DELTA_CFG,(UCHAR *)&feedback_delta_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_DELTA_CFG register ");
			return false;
		}
		if(feedback_delta_reg.fields.DeltaTempTime != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_delta_reg.fields.DeltaTempTime %d != eventParam.value %d",feedback_delta_reg.fields.DeltaTempTime,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"OverrunWarnMargin")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.OverrunWarnMargin=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.OverrunWarnMargin != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.OverrunWarnMargin %d != eventParam.value %d",feedback_limits_reg.fields.OverrunWarnMargin,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"OverrunWarnSlope")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.OverrunWarnSlope=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.OverrunWarnSlope != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.OverrunWarnSlope %d != eventParam.value %d",feedback_limits_reg.fields.OverrunWarnSlope,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"OverrunWarnTime")==0)
	{
		UN_D_FEEDBACK_LIMITS feedback_limits_reg;
		readSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		feedback_limits_reg.fields.OverrunWarnTime=eventParam.value;
		writeSize_=sizeof(UN_D_FEEDBACK_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_CONTROL |OFFSET_D_FEEDBACK_LIMITS,(UCHAR *)&feedback_limits_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_FEEDBACK_LIMITS register ");
			return false;
		}
		if(feedback_limits_reg.fields.OverrunWarnTime != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed feedback_limits_reg.fields.OverrunWarnTime %d != eventParam.value %d",feedback_limits_reg.fields.OverrunWarnTime,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}
	if(strcmp(eventParam.Name,"PurgeOffTemp")==0)
	{
		UN_D_PURGE purge_reg;
		readSize_=sizeof(UN_D_PURGE);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_PURGE,(UCHAR *)&purge_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_PURGE register ");
			return false;
		}
		purge_reg.fields.PurgeOffTemp=eventParam.value;
		writeSize_=sizeof(UN_D_PURGE);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_PURGE,(UCHAR *)&purge_reg.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to write OFFSET_D_PURGE register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_PURGE,(UCHAR *)&purge_reg.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecSetEventParam() :Failed to Read OFFSET_D_PURGE register ");
			return false;
		}
		if(purge_reg.fields.PurgeOffTemp != eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed purge_reg.fields.PurgeOffTemp %d != eventParam.value %d",purge_reg.fields.PurgeOffTemp,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}

		return true;
	}

	if(strcmp(eventParam.Name,"CondensationLimit")==0)
	{
		UN_D_LEAK_BOARD_LIMITS leak_board_limits;
		readSize_=sizeof(UN_D_LEAK_BOARD_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		leak_board_limits.fields.CondensationLimit=eventParam.value;
		writeSize_=sizeof(UN_D_LEAK_BOARD_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		if(leak_board_limits.fields.CondensationLimit!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed leak_board_limits.fields.CondensationLimit %d != eventParam.value %d",leak_board_limits.fields.CondensationLimit,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}

	if(strcmp(eventParam.Name,"TimeTillEventOn")==0)
	{
		UN_D_LEAK_BOARD_LIMITS leak_board_limits;
		readSize_=sizeof(UN_D_LEAK_BOARD_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		leak_board_limits.fields.TimeTillEventOn=eventParam.value;
		writeSize_=sizeof(UN_D_LEAK_BOARD_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		if(leak_board_limits.fields.TimeTillEventOn!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed leak_board_limits.fields.TimeTillEventOn %d != eventParam.value %d",leak_board_limits.fields.TimeTillEventOn,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}

	if(strcmp(eventParam.Name,"ThInternalLeakLimit")==0)
	{
		UN_D_LEAK_BOARD_LIMITS leak_board_limits;
		readSize_=sizeof(UN_D_LEAK_BOARD_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		leak_board_limits.fields.ThInternalLeakLimit=eventParam.value;
		writeSize_=sizeof(UN_D_LEAK_BOARD_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_ENVIRONMENT |OFFSET_D_LEAK_BOARD_LIMITS,(UCHAR *)&leak_board_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) OFFSET_D_LEAK_BOARD_LIMITS register ");
			return false;
		}
		if(leak_board_limits.fields.ThInternalLeakLimit!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed leak_board_limits.fields.ThInternalLeakLimit %d != eventParam.value %d",leak_board_limits.fields.ThInternalLeakLimit,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}


	if(strcmp(eventParam.Name,"LeakWaterModuleImpLimit")==0)
	{
		UN_D_WATER_MODULE_LIMITS  water_module_limits;
		readSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		water_module_limits.fields.LeakWaterModuleImpLimit=eventParam.value;
		writeSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		if(water_module_limits.fields.LeakWaterModuleImpLimit!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed water_module_limits.fields.LeakWaterModuleImpLimit %d != eventParam.value %d",water_module_limits.fields.LeakWaterModuleImpLimit,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}

	if(strcmp(eventParam.Name,"LeakWaterModuleTimeTillEventOn")==0)
	{
		UN_D_WATER_MODULE_LIMITS  water_module_limits;
		readSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		water_module_limits.fields.LeakWaterModuleTimeTillEventOn=eventParam.value;
		writeSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) v register ");
			return false;
		}
		if(water_module_limits.fields.LeakWaterModuleTimeTillEventOn!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed water_module_limits.fields.LeakWaterModuleTimeTillEventOn %d != eventParam.value %d",water_module_limits.fields.LeakWaterModuleTimeTillEventOn,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}

	if(strcmp(eventParam.Name,"LeakChillerImpLimit")==0)
	{
		UN_D_WATER_MODULE_LIMITS  water_module_limits;
		readSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		water_module_limits.fields.LeakChillerImpLimit=eventParam.value;
		writeSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		if(water_module_limits.fields.LeakChillerImpLimit!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed water_module_limits.fields.LeakChillerImpLimit %d != eventParam.value %d",water_module_limits.fields.LeakChillerImpLimit,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}

	if(strcmp(eventParam.Name,"LeakChillerTimeTillEventOn")==0)
	{
		UN_D_WATER_MODULE_LIMITS  water_module_limits;
		readSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		water_module_limits.fields.LeakChillerTimeTillEventOn=eventParam.value;
		writeSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)&water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		if(water_module_limits.fields.LeakChillerTimeTillEventOn!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed water_module_limits.fields.LeakChillerTimeTillEventOn %d != eventParam.value %d",water_module_limits.fields.LeakChillerTimeTillEventOn,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}

	if(strcmp(eventParam.Name,"LeakFloorImpLimit")==0)
	{
		UN_D_WATER_MODULE_LIMITS  water_module_limits;
		readSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		water_module_limits.fields.LeakFloorImpLimit=eventParam.value;
		writeSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)&water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		if(water_module_limits.fields.LeakFloorImpLimit!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed water_module_limits.fields.LeakFloorImpLimit %d != eventParam.value %d",water_module_limits.fields.LeakFloorImpLimit,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}

	if(strcmp(eventParam.Name,"LeakFloorTimeTillEventOn")==0)
	{
		UN_D_WATER_MODULE_LIMITS  water_module_limits;
		readSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		water_module_limits.fields.LeakFloorTimeTillEventOn=eventParam.value;
		writeSize_=sizeof(UN_D_WATER_MODULE_LIMITS);
		if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)water_module_limits.value,writeSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Write OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		// verify
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|  OFFSET_UNIT_D_WATER_MODULE |OFFSET_D_WATER_MODULE_LIMITS,(UCHAR *)&water_module_limits.value,&readSize_)!=STATUS_OK)
		{
			SetIntecLastError("IntecGetEventParam() :Failed to Read (verifY) OFFSET_D_WATER_MODULE_LIMITS register ");
			return false;
		}
		if(water_module_limits.fields.LeakFloorTimeTillEventOn!=eventParam.value)
		{
			sprintf (errBuf,"IntecSetEventParam() :Write validation Failed water_module_limits.fields.LeakFloorTimeTillEventOn %d != eventParam.value %d",water_module_limits.fields.LeakFloorTimeTillEventOn,eventParam.value);
			SetIntecLastError(errBuf);
			return false;
		}
		return true;
	}

	return false;
}


const int ClibIntecOperations::IntecGetDiodeInputs(unsigned int *mask)
{
	UN_DIODE_CFG diode_cfg;
	readSize_=sizeof(UN_DIODE_CFG);
	if (libIntec_ReadDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_DIODE_CFG,(UCHAR *)&diode_cfg.value,&readSize_) != STATUS_OK)
	{
		SetIntecLastError("IntecGetDiodeInputs:: Failed to Read  OFFSET_P_PECI_CFG");
		return false;
	}
	*mask=diode_cfg.fields.PollDiodes;
	return true;
}

const int ClibIntecOperations::IntecGetPFInputs(unsigned int *mask)
{
	UN_PF_CFG pf_cfg;
	readSize_=sizeof(UN_PF_CFG);
	if(libIntec_ReadDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PF_CFG,(UCHAR *)&pf_cfg.value,&readSize_) != STATUS_OK)
	{
		SetIntecLastError("IntecGetPFInputs:: Failed to Read OFFSET_PF_CFG");
		return false;
	}
	*mask=pf_cfg.fields.PollPF;
	return true;
}

const int ClibIntecOperations::IntecGetProcHotInputs(unsigned int *mask)
{
	UN_PROCHOT_CFG prochot_cfg;
	readSize_=sizeof(UN_PROCHOT_CFG);
	if(libIntec_ReadDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PROCHOT_CFG,(UCHAR *)&prochot_cfg.value,&readSize_)!=STATUS_OK)
	{
		SetIntecLastError("IntecGetProcHotInputs:: Failed to Read OFFSET_PROCHOT_CFG");
		return false;
	}
	*mask=prochot_cfg.fields.PollProchot;
	return true;
}

const int ClibIntecOperations::IntecGetPeciInputs(unsigned int *mask)
{
	UN_P_PECI_CFG peci_cfg;
	peci_cfg.value=0;
	readSize_=sizeof(UN_P_PECI_CFG);

	if(!PECIModuleExist_)
	{
		SetIntecLastError("IntecGetPeciInputs() - Peci Module does not exist");
		return false;
	}

	if(libIntec_ReadDeviceByAddr(deviceIndex_,PECI_DEVICE_BASE_ADDR |OFFSET_UNIT_P_DTS_CFG|OFFSET_P_PECI_CFG,(UCHAR *)&peci_cfg.value,&readSize_))
	{
		SetIntecLastError("IntecGetPeciInputs ::Failed to Read  OFFSET_P_PECI_CFG");
		return false;
	}
	*mask=peci_cfg.fields.PollDts;
	return true;

}

bool ClibIntecOperations::buildIntecBenchSelfTestErrorMessages()
{
	// Fill the BenchSelfTest map with the coresponded messages
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(1,"Adc Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(2,"EEprom Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(3,"Flash Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(4,"LCD Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(5,"IO EXP Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(6,"Ethernet Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(7," I2C Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(8," SPI Master Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(9," UARTTest Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(10,"USB Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(11,"Current SRC Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(12,"Fast Cal Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(13,"ArmBtn Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(14,"UpBtn Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(15,"DownBtn Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(16,"SelectBtn Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(17,"Run Led Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(18,"Failed Led Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(19,"SevSeg Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(20,"DetLeds Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(21,"PF Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(22,"Prochot Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(23,"PeciMcu Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(24,"PeciMonitor Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(25,"PeciCtrl Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(26,"PeciCircuit Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(27,"Peci Internal Vtt  Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(28,"Peci Vtt/Listener Mux  Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(29,"Peci PECI Mux Ctrl Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(30,"Peci  SPI communication Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(31,"IntecD communication Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(32,"Tdau Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(33,"Peci Leds Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(34,"Main Leds Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(35,"Buzzer Test Failed"));
	IntecBenchSelfTestErrorMessages.insert(Int2String::value_type(36,"Timeout occurred during Test "));
	return true;
}

bool ClibIntecOperations::buildIntecStandaloneSelfTestErrorMessages()
{
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(1,"Adc Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(2,"EEprom Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(3,"Flash Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(4,"LCD Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(5,"IO EXP Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(7," I2C Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(8," SPI Master Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(11,"Current SRC Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(12,"Fast Cal Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(23,"PeciMcu Test Failed"));
	IntecStandaloneSelfTestErrorMessages.insert(Int2String::value_type(24,"Tdau Test Failed"));
	return true;
}

bool ClibIntecOperations::buildIntecBasicFunctionalitySelfTestErrorMessages()
{
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(1,"Adc Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(2,"EEprom Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(3,"Flash Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(4,"LCD Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(5,"IO EXP Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(6,"Ethernet Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(7," I2C Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(8," SPI Master Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(9," UARTTest Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(10,"USB Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(11,"Current SRC Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(12,"Fast Cal Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(13,"ArmBtn Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(14,"UpBtn Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(15,"DownBtn Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(16,"SelectBtn Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(17,"Run Led Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(18,"Failed Led Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(19,"SevSeg Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(20,"DetLeds Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(21,"PF Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(22,"Prochot Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(23,"PeciMcu Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(24,"PeciMonitor Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(25,"PeciCtrl Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(26,"PeciCircuit Test Failed"));
	IntecBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(27,"Tdau Test Failed"));
	return true;
}

bool ClibIntecOperations::buildIntecDBenchSelfTestErrorMessages()
{
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(1,"AdcTC1TC2 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(2,"AdcTC3CP Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(3,"EEPROM Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(4,"DAC1 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(5,"DAC2 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(6,"IO Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(7,"FAN Driver Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(8,"UI Sense Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(9,"HI Sense Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(10,"TEC Safe Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(11,"TEC PS Relay Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(12,"PWM OutTest Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(13,"TEC OutTest Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(14,"TEC Current Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(15,"Actuations1 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(16,"Actuations2 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(17,"Actuations3 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(18,"Actuations4 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(19,"ValveControl1 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(20,"ValveControl2 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(21,"Analog Out1 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(22,"Analog Out2 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(23,"Analog Out3 Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(24,"Chiller Relay Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(25,"DUT PS Relay Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(26,"Purge Relay Test Failed"));
	IntecDBenchSelfTestErrorMessages.insert(Int2String::value_type(27,"Impedance Test Failed"));
	return true;
}

bool ClibIntecOperations::buildIntecDStandaloneSelfTestErrorMessages()
{
	IntecDStandaloneSelfTestErrorMessages.insert(Int2String::value_type(1,"AdcTC1TC2 Test Failed"));
	return true;
}

bool ClibIntecOperations::buildIntecDBasicFunctionalitySelfTestErrorMessages()
{
	IntecDBasicFunctionalitySelfTestErrorMessages.insert(Int2String::value_type(1,"AdcTC1TC2 Test Failed"));
	return true;
}

bool ClibIntecOperations::buildIntecDWaterModuleBenchTestErrorMessages()
{
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(1,"ADCErr Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(2,"EEPROMErr Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(3,"ImpCh0Err Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(4,"ImpCh1Err Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(5,"ImpCh2Err Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(6,"ImpCh3Err Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(7,"AlertOutErr Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(8,"Relay3v3Err Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(9,"RelayI2CErr Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(10,"RelayChillerStopErr Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(11,"MainValveErr Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(12,"Relay12vErr Test Failed"));
	IntecDWaterModuleBenchTestErrorMessages.insert(Int2String::value_type(13,"Timeout Test Failed"));
	return true;
}

const int ClibIntecOperations::peciFrequencyTablesInitialization()
{
	/*
	index	Digital		Freq
	1		5			2.000MHz
	2		6			1.667MHz
	3		7			1.429MHz
	4		8			1.250MHz
	5		9			1.111MHz
	6		10			1.000MHz
	7		11			0.909MHz
	8		12			0.833MHz
	9		13			0.769MHz
	10		14			0.714MHz
	11		15			0.667MHz
	12		16			0.625MHz
	13		18			0.556MHz
	14		20			0.500MHz
	15		22			0.455MHz
	16		25			0.400MHz
	17		29			0.345MHz
	18		33			0.303MHz
	19		40			0.250MHz
	20		50			0.200MHz
	21		67			0.149MHz
	22		100			0.100MHz
	23		200			0.050MHz
	24		250			0.040MHz
	25		333			0.030MHz
	26		500			0.020MHz
	27		667			0.015MHz
	28		1000		0.010MHz
	29		1111		0.009MHz
	30		1250		0.008MHz
	31		1428		0.007MHz
	32		1667		0.006MHz
	33		2001		0.005MHz
	34		2500		0.004MHz
	35		3334		0.003MHz
	36		5000		0.002MHz

	*/

	peciFreq_IndexToDigital[1]=5;
	peciFreq_IndexToDigital[2]=6;
	peciFreq_IndexToDigital[3]=7;
	peciFreq_IndexToDigital[4]=8;
	peciFreq_IndexToDigital[5]=9;
	peciFreq_IndexToDigital[6]=10;
	peciFreq_IndexToDigital[7]=11;
	peciFreq_IndexToDigital[8]=12;
	peciFreq_IndexToDigital[9]=13;
	peciFreq_IndexToDigital[10]=14;
	peciFreq_IndexToDigital[11]=15;
	peciFreq_IndexToDigital[12]=16;
	peciFreq_IndexToDigital[13]=18;
	peciFreq_IndexToDigital[14]=20;
	peciFreq_IndexToDigital[15]=22;
	peciFreq_IndexToDigital[16]=25;
	peciFreq_IndexToDigital[17]=29;
	peciFreq_IndexToDigital[18]=33;
	peciFreq_IndexToDigital[19]=40;
	peciFreq_IndexToDigital[20]=50;
	peciFreq_IndexToDigital[21]=67;
	peciFreq_IndexToDigital[22]=100;
	peciFreq_IndexToDigital[23]=200;
	peciFreq_IndexToDigital[24]=250;
	peciFreq_IndexToDigital[25]=333;
	peciFreq_IndexToDigital[26]=500;
	peciFreq_IndexToDigital[27]=667;
	peciFreq_IndexToDigital[28]=1000;
	peciFreq_IndexToDigital[29]=1111;
	peciFreq_IndexToDigital[30]=1250;
	peciFreq_IndexToDigital[31]=1428;
	peciFreq_IndexToDigital[32]=1667;
	peciFreq_IndexToDigital[33]=2001;
	peciFreq_IndexToDigital[34]=2500;
	peciFreq_IndexToDigital[35]=3334;
	peciFreq_IndexToDigital[36]=5000;

	peciFreq_DigitalToIndex[5]=1;
	peciFreq_DigitalToIndex[6]=2;
	peciFreq_DigitalToIndex[7]=3;
	peciFreq_DigitalToIndex[8]=4;
	peciFreq_DigitalToIndex[9]=5;
	peciFreq_DigitalToIndex[10]=6;
	peciFreq_DigitalToIndex[11]=7;
	peciFreq_DigitalToIndex[12]=8;
	peciFreq_DigitalToIndex[13]=9;
	peciFreq_DigitalToIndex[14]=10;
	peciFreq_DigitalToIndex[15]=11;
	peciFreq_DigitalToIndex[16]=12;
	peciFreq_DigitalToIndex[18]=13;
	peciFreq_DigitalToIndex[20]=14;
	peciFreq_DigitalToIndex[22]=15;
	peciFreq_DigitalToIndex[25]=16;
	peciFreq_DigitalToIndex[29]=17;
	peciFreq_DigitalToIndex[33]=18;
	peciFreq_DigitalToIndex[40]=19;
	peciFreq_DigitalToIndex[50]=20;
	peciFreq_DigitalToIndex[67]=21;
	peciFreq_DigitalToIndex[100]=22;
	peciFreq_DigitalToIndex[200]=23;
	peciFreq_DigitalToIndex[250]=24;
	peciFreq_DigitalToIndex[333]=25;
	peciFreq_DigitalToIndex[500]=26;
	peciFreq_DigitalToIndex[667]=27;
	peciFreq_DigitalToIndex[1000]=28;
	peciFreq_DigitalToIndex[1111]=29;
	peciFreq_DigitalToIndex[1250]=30;
	peciFreq_DigitalToIndex[1428]=31;
	peciFreq_DigitalToIndex[1667]=32;
	peciFreq_DigitalToIndex[1250]=33;
	peciFreq_DigitalToIndex[2500]=34;
	peciFreq_DigitalToIndex[3334]=35;
	peciFreq_DigitalToIndex[5000]=36;
	return true;
}

const int ClibIntecOperations::IntecGetTemperature(int cardId, float *temprature, unsigned int *timestamp)
{

	unsigned short intecTemperature;
	int rc;
	rc = IntecGetTemperature(cardId, &intecTemperature, timestamp);
	if (rc != STATUS_OK)
		return rc;
	*temprature = convertIntecToRealTemperature(intecTemperature);
	return STATUS_OK;
}

const int ClibIntecOperations::IntecGetTemperature(int cardId, unsigned short *temprature, unsigned int *timestamp)
{
	if (IsCardExist(cardId))
	{
		// first that the D_FEEDBACK status  that at least one source is available
		UN_D_FEEDBACK_STATUS feedback_status;
		UN_D_FEEDBACK_TEMP  feedback_temperature;


		readSize_=sizeof(UN_D_FEEDBACK_STATUS);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|OFFSET_UNIT_D_CONTROL|OFFSET_D_FEEDBACK_STATUS,(unsigned char *)&feedback_status.value,&readSize_) != STATUS_OK)
		{
//			sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecGetTemperature:Failed to Read  IntecDCard (%d) OFFSET_D_FEEDBACK_STATUS",cardId);
			//SetIntecLastError(msg_buf);
			return ERROR_FAIL;
		}

		if(feedback_status.fields.SourceValid == 0)
		{
//			sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecGetTemperature: No valid source for temperature IntecDCard (%d)",cardId);
//			SetIntecLastError(msg_buf);
			return ERROR_FAIL;
		}
		readSize_=sizeof(UN_D_FEEDBACK_TEMP);
		if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|OFFSET_UNIT_D_CONTROL|OFFSET_D_FEEDBACK_TEMP,(unsigned char *)&feedback_temperature.value,&readSize_) != STATUS_OK)
		{
//			sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecGetTemperature:Failed to Read  IntecDCard (%d) OFFSET_D_FEEDBACK_TEMP",cardId);
//			SetIntecLastError(msg_buf);
			return ERROR_FAIL;
		}
		if(feedback_temperature.fields.TempValid == 0)
		{
//			sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecGetTemperature:feedback_temperature is NOT valid  IntecDCard (%d) ",cardId);
			SetIntecLastError(msg_buf);
			return ERROR_FAIL;
		}

		*temprature = feedback_temperature.fields.Temp;
		*timestamp = feedback_temperature.fields.TimeStamp;
		return STATUS_OK;
	}
	else
	{
		//sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecGetTemperature() :IntecDCard (%d) Not Exist ",cardId);
		//SetIntecLastError(msg_buf);
	}
	return ERROR_FAIL;
}

float ClibIntecOperations::convertIntecToRealTemperature(unsigned short IntecTemperature)
{
	return	((float)(IntecTemperature)/10 - 64);
}

const int ClibIntecOperations::IntecSetTemperature(int cardId, unsigned short temprature)
{
	if (IsCardExist(cardId))
	{
		// first that the D_FEEDBACK status  that at least one source is available
		UN_D_FEEDBACK_STATUS	feedback_status;
		UN_D_FEEDBACK_SETPOINT  feedback_setpoint;
		readSize_=sizeof(UN_D_FEEDBACK_STATUS);
		if (libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|OFFSET_UNIT_D_CONTROL|OFFSET_D_FEEDBACK_STATUS,(unsigned char *)&feedback_status.value,&readSize_)!= STATUS_OK)
		{
//			sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecSetTemperature: Failed to Read  IntecDCard (%d) OFFSET_D_FEEDBACK_STATUS",cardId);
//			SetIntecLastError(msg_buf);
			return ERROR_FAIL;
		}
		if(feedback_status.fields.SourceValid==0)
		{
//			sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecSetTemperature: No valid input for temperature IntecDCard (%d)",cardId);
//			SetIntecLastError(msg_buf);
			return ERROR_FAIL;
		}
		feedback_setpoint.fields.SetPoint=temprature;
		writeSize_=sizeof(UN_D_FEEDBACK_SETPOINT);
		if (libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)|OFFSET_UNIT_D_CONTROL|OFFSET_D_FEEDBACK_SETPOINT,(unsigned char *)&feedback_setpoint.value,writeSize_) != STATUS_OK)
		{
//			sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecSetTemperature:Failed to Write  IntecDCard (%d) OFFSET_D_FEEDBACK_SETPOINT",cardId);
//			SetIntecLastError(msg_buf);
			return ERROR_FAIL;
		}
		return STATUS_OK;

	}
	else
	{
//		sprintf_s(msg_buf,MSG_BUF_SIZE,"IntecSetTemperature :IntecDCard (%d) Not Exist ",cardId);
//		SetIntecLastError(msg_buf);
	}
	return ERROR_FAIL;
}

const int ClibIntecOperations::IntecSetTemperature(int cardId, float temprature)
{
	return IntecSetTemperature(cardId, convertRealToIntecTemperature(temprature));
}

const int ClibIntecOperations::IntecSetAllEventDisableEnable(int cardId, EventType evType)
{
	switch(evType)
		{
		case FailureEvent:
			UN_D_FAILURES_DISABLE failures_disable_status;
			readSize_=sizeof(UN_D_FAILURES_DISABLE);
			if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_EVENTS |OFFSET_D_FAILURES_DISABLE,(UCHAR *)&failures_disable_status.value,&readSize_)!=STATUS_OK)
			{
				SetIntecLastError("IntecSetEventDisableEnable() :Failed to Read UN_D_FAILURES_DISABLE register ");
				return false;
			}
			for(int eventId=0;eventId<=maxFailureId_;eventId++)
			{
				if(failure_events[eventId].isDisable)
				{
					if(failure_events[eventId].disable)

						failures_disable_status.value |= (1<<eventId);
					else
						failures_disable_status.value &= ~(1<<eventId);
				}
			}
			writeSize_=sizeof(UN_D_FAILURES_DISABLE);
			if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_EVENTS |OFFSET_D_FAILURES_DISABLE,(UCHAR *)&failures_disable_status.value,writeSize_)!=STATUS_OK)
			{
				SetIntecLastError("IntecSetEventDisableEnable() :Failed to write UN_D_FAILURES_DISABLE register ");
				return false;
			}

			break;
		case WarningEvent:
			UN_D_WARNINGS_DISABLE warnings_disable_status;
			readSize_=sizeof(UN_D_WARNINGS_DISABLE);
			if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_EVENTS |OFFSET_D_WARNINGS_DISABLE,(UCHAR *)&warnings_disable_status.value,&readSize_)!=STATUS_OK)
			{
				SetIntecLastError("IntecSetEventDisableEnable() :Failed to Read OFFSET_D_WARNINGS_DISABLE register ");
				return false;
			}
			for(int eventId=0;eventId<=maxWarningId_;eventId++)
			{
				if(warning_events[eventId].isDisable)
				{

					if(warning_events[eventId].disable)
						warnings_disable_status.value |= (1<<eventId);
					else
						warnings_disable_status.value &= ~(1<<eventId);
				}
			}

			writeSize_=sizeof(UN_D_WARNINGS_DISABLE);
			if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_EVENTS |OFFSET_D_WARNINGS_DISABLE,(UCHAR *)&warnings_disable_status.value,writeSize_)!=STATUS_OK)
			{
				SetIntecLastError("IntecSetEventDisableEnable() :Failed to write OFFSET_D_WARNINGS_DISABLE register ");
				return false;
			}
			break;

		case NotificationEvent:

			UN_D_NOTIFICATION_DISABLE notifications_disable_status;
			readSize_=sizeof(UN_D_NOTIFICATION_DISABLE);
			if(libIntec_ReadDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_EVENTS |OFFSET_D_NOTIFICATION_DISABLE,(UCHAR *)&notifications_disable_status.value,&readSize_)!=STATUS_OK)
			{
				SetIntecLastError("IntecSetEventDisableEnable() :Failed to Read OFFSET_D_NOTIFICATION_DISABLE register ");
				return false;
			}
			for(int eventId=0;eventId<=maxNotificationId_;eventId++)
			{
				if(notification_events[eventId].isDisable)
				{

					if(notification_events[eventId].disable)
						notifications_disable_status.value |= (1<<eventId);
					else
						notifications_disable_status.value &= ~(1<<eventId);
			}

			writeSize_=sizeof(UN_D_NOTIFICATION_DISABLE);
			if(libIntec_WriteDeviceByAddr(deviceIndex_,(INTECD0_DEVICE_BASE_ADDR<< cardId)| OFFSET_UNIT_D_EVENTS |OFFSET_D_NOTIFICATION_DISABLE,(UCHAR *)&notifications_disable_status.value,writeSize_)!=STATUS_OK)
			{
				SetIntecLastError("IntecSetEventDisableEnable() :Failed to write OFFSET_D_NOTIFICATION_DISABLE register ");
				return false;
			}
			return true;
			}
			break;

		default:
			SetIntecLastError("IntecSetEventDisableStatus:: Invalid Event Type");
			return false;
			break;
		}

		return true;
}
