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

int ClibIntecOperations::Initialize(int reset)
{
	DBG("ClibIntecOperations::Initialize")
	m_initialization_flag = false;

	memset(peci_dts_arr, 0, sizeof(PECI_DTS)*MAX_DTS);
	memset(peci_pkg_arr, 0, sizeof(PECI_PACKAGE)*MAX_PACKAGES);

	UN_DIODE_STATUS diode_status;

	m_readSize = sizeof(UN_DIODE_STATUS);

	if(libIntec_ReadDeviceByAddr(m_device_index, INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_DIODE_STATUS,(unsigned char *)&diode_status.value,&m_readSize) != STATUS_OK)
	{
		return ERROR_FAIL;
	}

	TDAUDetected_= diode_status.fields.TDAUDetected;

	if(reset)
	{

		// update the currentDiodeMask_
		currentDiodeMask_=0;
		if(!IntecSetDiodeInputs(true,currentDiodeMask_))
			return false;

		// update the currentPFMask_
		currentPFMask_=0;
		if(!IntecSetPFInputs(true,currentPFMask_))
			return false;

		// update the currentProcHOTMask_
		currentProcHOTMask_=0;
		if(!IntecSetProcHotInputs(true,currentProcHOTMask_))
			return false;

		// update the currentProcHOTMask_
		currentPeciMask_=0;
		if(!IntecSetPeciInputs(true,currentPeciMask_))
			return false;

		if(!IntecClearPeciSensorsConfiguration())
			return false;

		for(int i=0; i < InTECDCards_; i++)
		{
			currentCaseMask_[i]=0;
			if(!IntecSetCaseInputs(i,true,currentCaseMask_[i]))
				return false;
			// read the actual mask back from HW since it can be forced by HW - case0 is forced
			if(!IntecGetCaseInputs(i,&currentCaseMask_[i]))
				return false;

			char eventsFileName[256];
			GetWorkDir(sizeof(workingDir_), workingDir_);
			sprintf_s(eventsFileName,256, "%s%s.xml", workingDir_, EVENTS_FILE_NAME);
			IntecLoadandConfigureEvents(i,eventsFileName,false);
		}
	}
	else
	{
		if(!IntecGetDiodeInputs(&currentDiodeMask_))
			return false;

		if(!IntecGetPFInputs(&currentPFMask_))
			return false;


		if(!IntecGetProcHotInputs(&currentProcHOTMask_))
			return false;


		if(!IntecGetPeciInputs(&currentPeciMask_))
			return false;

		for(int i=0; i < InTECDCards_; i++)
		{
			if(!IntecGetCaseInputs(i,&currentCaseMask_[i]))
				return false;
			char eventsFileName[256];
			GetWorkDir(sizeof(workingDir_), workingDir_);
			sprintf_s(eventsFileName,256, "%s%s.xml", workingDir_, EVENTS_FILE_NAME);
			IntecLoadandConfigureEvents(i,eventsFileName,false);
		}
	}
	// build Intec Tests Error messages vectors
	if(!buildIntecBenchSelfTestErrorMessages())
		return false;
	if(!buildIntecStandaloneSelfTestErrorMessages())
		return false;
	if(!buildIntecBasicFunctionalitySelfTestErrorMessages())
		return false;

	// build IntecD Tests Error messages vectors
	if(!buildIntecDBenchSelfTestErrorMessages())
		return false;
	if(!buildIntecDStandaloneSelfTestErrorMessages())
		return false;
	if(!buildIntecDBasicFunctionalitySelfTestErrorMessages())
		return false;

	if(!buildIntecDWaterModuleBenchTestErrorMessages())
		return false;

	if(!peciFrequencyTablesInitialization())
		return false;


	m_initialization_flag = true;
	Initialized_= true;
	return Initialized_;

}

const int ClibIntecOperations::IntecGetSysCardsConfiguration()
{
	UN_CONNECTED_DEVICES connectedDevices;

	InTECDCards_=0;
	PECIModuleExist_=false;
	readSize_=sizeof(UN_CONNECTED_DEVICES);
	if(libIntec_ReadDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_GENERAL|OFFSET_CONNECTED_DEVICES,(UCHAR *)&connectedDevices.value,&readSize_)!= STATUS_OK)
	{
		//SetIntecLastError("IntecGetSysCardsConfiguration:: Failed to Read OFFSET_CONNECTED_DEVICES");
		return ERROR_FAIL;
	}
	printf("connectedDevices.value=%x\n",connectedDevices.value);
	if(connectedDevices.fields.PECIModule)
			PECIModuleExist_=true;
	if(connectedDevices.fields.InTECD0)
		InTECDCards_++;
	if(connectedDevices.fields.InTECD1)
		InTECDCards_++;
	if(connectedDevices.fields.InTECD2)
		InTECDCards_++;
	if(connectedDevices.fields.InTECD3)
		InTECDCards_++;

	return true;
}

const int ClibIntecOperations::IntecSetDiodeInputs(bool enable, unsigned int mask)
{
	if(enable)
		currentDiodeMask_ |=mask;
	else
		currentDiodeMask_ &=((~mask)&0xf);
	UN_DIODE_CFG diode_cfg;
	writeSize_=sizeof(UN_DIODE_CFG);
	diode_cfg.fields.PollDiodes=currentDiodeMask_;
	if(libIntec_WriteDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_DIODE_CFG,(UCHAR *)&diode_cfg.value,writeSize_))
	{
		return false;
	}
	return true;

}

const int ClibIntecOperations::IntecSetPFInputs(bool enable, unsigned int mask)
{
	if(enable)
		currentPFMask_ |=mask;
	else
		currentPFMask_ &=((~mask)&0xf);

	UN_PF_CFG pf_cfg;
	writeSize_=sizeof(UN_PF_CFG);
	pf_cfg.fields.PollPF=currentPFMask_;
	if(libIntec_WriteDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PF_CFG,(unsigned char *)&pf_cfg.value,writeSize_))
	{
		SetIntecLastError("IntecSetPFInputs: Failed to Write  OFFSET_PF_CFG");
		return false;
	}
	return true;
}

const int ClibIntecOperations::IntecSetProcHotInputs(bool enable, unsigned int mask)
{
	//Clear Prochot status fields for a specific channel by setting the appropriate bit of ChResetCounter field in PROCHOT_CFG register. 
	if(!IntecClearProcHotEventsCounter(-1))
		return false;
	//Select which Prochot input to enable by setting the appropriate bits of the PollProchot field in PROCHOT_CFG register.
	if(enable)
		currentProcHOTMask_ |=mask;
	else
		currentProcHOTMask_ &=((~mask)&0xf);
	UN_PROCHOT_CFG prochot_cfg;
	readSize_=sizeof(UN_PROCHOT_CFG);
	if(ReadDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PROCHOT_CFG,(unsigned char *)&prochot_cfg.value,&readSize_)!=S_OK)
	{
		SetIntecLastError("IntecSetProcHotInputs::Failed to Read OFFSET_PROCHOT_CFG");
		return false;
	}
	prochot_cfg.fields.PollProchot=currentProcHOTMask_;


	writeSize_=sizeof(UN_PROCHOT_CFG);;

	if(WriteDeviceByAddr(deviceIndex_,INTEC_BASE_ADDR|OFFSET_UNIT_JUNCTION|OFFSET_PROCHOT_CFG,(unsigned char *)&prochot_cfg.value,writeSize_))
	{
		SetIntecLastError("IntecSetProcHotInputs: Failed to Write  OFFSET_PROCHOT_CFG");
		return false;
	}
	return true;
}
