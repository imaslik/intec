/*
 * testlibintec.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#include "libIntec.h"
#include <iostream>
#include <unistd.h>
#define test_main main

int test_main(int argc, char ** argvv)
{
	argc--;
	argvv++;
	char ERROR_MSG[512];
	std::cout << "libIntec API test" << std::endl;

	unsigned int major, minor;
	libIntec_GetlibVersion(major, minor);
	std::cout << "libIntec Version: " << major << "." << minor << std::endl;

	IntecUsbDeviceType DevType = IntecH;
	if (libIntec_Initialize(DevType) != STATUS_OK)
	{
		std::cout << "TEST FAIL: libIntec driver initialization failed" << std::endl;
		libIntec_Exit();
		exit(1);
	}
	else
	{
		std::cout << "TEST PASS - llibIntec_Initialize" << std::endl;
	}

	int num_of_devices;
	if(libtIntec_GetNumOfUsbDevices(num_of_devices) != STATUS_OK)
	{
		std::cout << "TEST FAIL: libtIntec_GetNumOfUsbDevices returned error" << std::endl;
		libIntec_Exit();
		exit(1);
	}
	else
	{
		std::cout << "number of device found " << num_of_devices << std::endl;
		std::cout << "TEST PASS - libtIntec_GetNumOfUsbDevices" << std::endl;
	}

	char DeviceVersion[4];
	if(libIntec_GetDeviceVersion(0, DeviceVersion) != STATUS_OK)
	{
		std::cout << "TEST FAIL: libIntec_GetDeviceVersion returned error" << std::endl;
		libIntec_Exit();
		exit(1);
	}
	else
	{
		int version = DeviceVersion[1] << 8 | DeviceVersion[0];
		std::cout << "version " << version << std::endl;
		std::cout << "TEST PASS - libIntec_GetDeviceVersion" << std::endl;
	}
	for (int index = 0; index < num_of_devices; index++)
	{
		if (libIntec_InitializeCard(index) != STATUS_OK)
		{
			std::cout << "TEST FAIL: libIntec_InitializeCard return error" << std::endl;
			libintec_GetLastError(ERROR_MSG, (unsigned int)512);
			std::cout << "LAST ERROR " << ERROR_MSG << std::endl;

			libIntec_Exit();
			exit(1);
		}
		else
		{
			std::cout << "TEST PASS - libIntec_InitializeCard" << std::endl;
		}

		int CardId = 0;
		float Temperature;
		try
		{
			if (argc > 0)
			 Temperature = atof(argvv[0]);
			else
				throw "ERROR";

			if (Temperature > 100 || Temperature < 0)
				throw "ERROR";
		}
		catch (...)
		{
			Temperature = 25;
		}
		float Error = 0.5;
		float ReadTemp;
		std::cout << "Setting temperature to " << Temperature << std::endl;
		if (libIntec_SetTemperature(index, CardId, Temperature) != STATUS_OK)
		{
			std::cout << "TEST FAIL: libIntec_GetTemperature return error" << std::endl;
			libIntec_Exit();
			exit(1);
		}
		std::cout << "TEST PASS - libIntec_SetTemperature" << std::endl;

		unsigned int TimeStamp = 0;
		int stability_couter = 0;
		do
		{
			if (libIntec_GetTemperature(index, CardId, &ReadTemp, &TimeStamp) != STATUS_OK)
			{
				std::cout << "TEST FAIL: libIntec_GetTemperature return error" << std::endl;
				libIntec_Exit();
				exit(1);
			}

			std::cout << "Temparture = " << ReadTemp << std::endl;
			if ((ReadTemp > (Temperature + Error)) || (ReadTemp < (Temperature - Error)))
			{
				stability_couter = 0;
			}
			else
			{
				stability_couter++;
			}
			usleep(500000);
		}
		while (stability_couter < 4);
	}
	std::cout << "TEST PASS - libIntec_GetTemperature" << std::endl;

	libIntec_Exit();
	return 0;
}
