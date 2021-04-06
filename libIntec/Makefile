CC= g++
FLAGS= -Wall
LDLIBUSB= `pkg-config --libs --cflags libusb-1.0`
INC= -I/inc


all: lib/libIntec.so
	libIntec.so

libIntec.so: src/libIntec.cpp inc/libIntec.h
	$(CC) $(FLAGS) $(INC) src/libIntec.cpp -o lib/libIntec.so



