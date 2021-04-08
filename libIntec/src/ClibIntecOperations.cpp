/*
 * ClibIntecOperations.cpp
 *
 *  Created on: Apr 8, 2021
 *      Author: svshared
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
