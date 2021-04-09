
CC=g++
FLAGS=-Wall 
LDLIBUSB=$(shell pkg-config --libs --cflags libusb-1.0)
LDLIBINTEC=-L../lib -lIntec -I../lib
EXPORT_CMD=export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(shell pwd)/../lib

all: libIntec.test

libusb.test: testlibusb.cpp
	$(CC) $(FLAGS) testlibusb.cpp -o testlibusb.test $(LDLIBUSB)

runlibusb.test: testlibusb.test
	./libusb.test
	
libIntec.test: testlibIntec.cpp ../lib/libIntec.so
	$(CC) $(LDLIBINTEC) -o $@ $^

env:
	echo ${EXPORT_CMD} >> ~/.bashrc

runlibIntec.test:
	./libIntec.test

clean:
	rm -rf *.test
