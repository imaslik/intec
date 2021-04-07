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
	std::cout << "libIntec test" << std::endl;
	IntecUsbDeviceType DevType = IntecH;
	if (libIntec_Initialize(DevType) != STATUS_OK)
	{
		std::cout << "libIntec driver initialization failed" << std::endl;
		exit(1);
	}

	int num_of_devices;
	libtIntec_GetNumberOfDevices(num_of_devices);
	std::cout << "number of devices found on this machine " << num_of_devices << std::endl;
	libIntec_Exit();
	return 0;
}
