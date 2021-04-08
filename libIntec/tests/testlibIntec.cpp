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
		std::cout << "TEST PASS - libtIntec_GetNumOfUsbDevices" << std::endl;
		std::cout << "number of devices found on this machine " << num_of_devices << std::endl;
	}




	libIntec_Exit();
	return 0;
}
