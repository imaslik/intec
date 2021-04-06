
#include <iostream>
#include <libusb-1.0/libusb.h>
#include <cassert>

#define test_main main

#define VENDOR_NUMBER 0x04d8
#define DEVICE_NUMBER 0x0053

int test_main(int argc, char** argv)
{
	std::cout << "running libusbtest" << std::endl;
	libusb_device **devv;
	libusb_context *ctx = NULL;

	//Initializing libusb
	 assert(libusb_init(&ctx) == 0);

	 ssize_t devc;
	 devc = libusb_get_device_list(ctx, &devv);
	 assert(devc > 0);

	 for (int i; i < devc; i++)
	 {
		 libusb_device *device = devv[i];
		 libusb_device_descriptor desc;
		 assert(libusb_get_device_descriptor(device, &desc) == 0);
		 std::cout << "Vendor:Device - " << std::hex << desc.idVendor << ":" << std::hex << desc.idProduct << std::endl;

	 }

	libusb_free_device_list(devv, 1);
	libusb_exit(ctx);
	return 0;
}
