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
	IntecUsbDeviceType DevType = IntecH;
	if (libIntec_Initialize(DevType) != STATUS_OK)
	{
		std::cout << "libIntec driver initialization failed" << std::endl;
		exit(1);
	}
	libIntec_Exit();
	return 0;
}
