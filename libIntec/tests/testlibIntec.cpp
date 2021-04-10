/*
 * testlibintec.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: Shady Ganem <shady.ganem@intel.com>
 */

#include "libIntec.h"
#include <iostream>
#define test_main main

int test_main(int argc, char ** argvv)
{
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
		std::cout << "TEST FAIL: GetNumOfUsbDevices returned error" << std::endl;
		libIntec_Exit();
		exit(1);
	}
	else
	{
		std::cout << "number of device founce " << num_of_devices << std::endl;
		std::cout << "TEST PASS - libtIntec_GetNumOfUsbDevices" << std::endl;
	}

	for (unsigned int index = 0; index < num_of_devices; index++)
	{
		if (libIntec_InitializeCard(index) != STATUS_OK)
		{
			std::cout << "TEST FAIL: libIntec_InitializeCard return error" << std::endl;
		}
		else
		{
			std::cout << "TEST PASS - libIntec_InitializeCard" << std::endl;
		}

		int CardId = 0;
		float Temperature = 0;
		unsigned int TimeStamp = 0;

//		if (libIntec_GetTemperature(index, CardId, &Temperature, &TimeStamp) != STATUS_OK)
//		{
//			std::cout << "TEST FAIL: libIntec_GetTemperature return error" << std::endl;
//			libIntec_Exit();
//			exit(1);
//		}
//		else
//		{
//			std::cout << "TEST PASS - libIntec_GetTemperature" << std::endl;
//			std::cout << "ReadTemparture = " << Temperature << std::endl;
//			std::cout << "Timestamp: " << TimeStamp << std::endl;
//		}
	}

	libIntec_Exit();
	return 0;
}
