CC= g++
FLAGS= -Wall
INC= -I/inc


all: lib/libIntec.so
	libIntec.so

libIntec.so: src/libIntec.cpp inc/libIntec.h
	$(CC) $(FLAGS) $(INC) src/libIntec.cpp -o lib/libIntec.so



