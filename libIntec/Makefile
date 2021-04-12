CCPP=g++
CC=gcc
FLAGS=-Wall
LDLIBUSB=$(shell pkg-config --libs --cflags libusb-1.0) -lstdc++ 

SRC=src
INC=inc
BIN=bin
LIB=lib

SRCS=$(wildcard $(SRC)/*.cpp)
HDRS=$(wildcard $(INC)/*.h)
ADD_HDRS=$(INC)/libIntec_InTEC_DeDefs.h $(INC)/
BINS=$(patsubst $(SRC)/%.cpp, $(BIN)/%.o, $(SRCS))
EXCLUDE=

TARGET= $(LIB)/libIntec.so

all: $(TARGET)

$(TARGET): $(filter-out $(EXCLUDE),$(BINS))
	$(CC) -fPIC $(FLAGS) $(LDLIBUSB) -shared $^ -o $@
	cp $(INC)/libIntec.h $(LIB)/libIntec.h 

$(BIN)/%.o: $(SRC)/%.cpp $(INC)/%.h
	$(CCPP) -fPIC $(FLAGS) $(LDLIBUSB)-I$(INC) -c $(filter-out %.h, $^) -o $@ 
 

test:
	make -C tests
clean:
	rm -rf bin/*.o
	rm -rf lib/*.so lib/*.h
	rm -rf inc/*.gch
