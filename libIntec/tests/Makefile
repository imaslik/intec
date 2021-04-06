
CC= g++
FLAGS= -Wall 
LDLIBUSB= `pkg-config --libs --cflags libusb-1.0`

testlibusb.test: testlibusb.cpp
	$(CC) $(FLAGS) testlibusb.cpp -o testlibusb.test $(LDLIBUSB)

runtestlibusb: testlibusb.test
	./testlibusb.test

