
CC=g++
FLAGS=-Wall 
LDLIBUSB=$(shell pkg-config --libs --cflags libusb-1.0)
LDLIBINTEC=-L../lib -lIntec -I../lib

all: libIntec.test

libusb.test: testlibusb.cpp
	$(CC) $(FLAGS) testlibusb.cpp -o testlibusb.test $(LDLIBUSB)

runlibusb.test: testlibusb.test
	./libusb.test
	
libIntec.test: testlibIntec.cpp ../lib/libIntec.so
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(shell pwd)/../lib
	$(CC) $(LDLIBINTEC) -o $@ $^

runlibIntec.test:
	./libIntec.test

clean:
	rm -rf *.test
