CC=g++
FLAGS=-Wall
LDLIBUSB=$(shell pkg-config --libs --cflags libusb-1.0)

SRC=src
INC=inc
BIN=bin
LIB=lib

SRCS=$(wildcard $(SRC)/*.cpp)
HDRS=$(wildcard $(INC)/*.h)
BINS=$(patsubst $(SRC)/%.cpp, $(BIN)/%.o, $(SRCS))

TARGET= $(LIB)/libIntec.so
TARGETOBJ=$(BIN)/libIntec.obj

all: $(TARGET)

$(TARGET): $(BINS)
	$(CC) -fPIC $(FLAGS) $(LDLIBUSB) -shared $^ -o $@
	cp $(INC)/libIntec.h $(LIB)/libIntec.h 

$(BIN)/%.o: $(SRC)/%.cpp $(INC)/%.h
	$(CC) -fPIC $(FLAGS) $(LDLIBUSB)-I$(INC) -c $(filter-out %.h, $^) -o $@ 
 
clean:
	rm -rf bin/*.o
	rm -rf lib/*.so lib/*.h
	rm -rf inc/*.gch
