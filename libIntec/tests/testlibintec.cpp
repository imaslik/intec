/*
 * testlibintec.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: svshared
 */

#include "libIntec.h"
#include <iostream>
#define test_main main

int test_main(int argc, char ** argvv)
{
	IntecUsbDeviceType DevType = IntecH;
	if (libintec_initialize(DevType) != STATUS_OK)
	{
		std::cout << "libIntec driver initialization failed" << std::endl;
	}

}
