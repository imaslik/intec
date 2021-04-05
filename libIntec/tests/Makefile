
CC= g++
flags= -Wall 
ldlibusb= `pkg-config --libs --cflags libusb-1.0`


testlibusb: testlibusb.cpp
	$(CC) $(flags) testlibusb.cpp -o testlibusb  $(ldlibusb)

runtestlibusb: testlibusb
	./testlibusb

