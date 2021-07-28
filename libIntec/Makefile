CCPP=g++
CC=gcc
FLAGS=-Wall
LDLIBUSB=$(shell pkg-config --libs --cflags libusb-1.0) -lstdc++ 
USER_SITE=$(shell python3 utils/pypaths.py -p site-packages)

SRC=src
INC=inc
BIN=bin
LIB=lib

SRCS=$(wildcard $(SRC)/*.cpp)
HDRS=$(wildcard $(INC)/*.h)
ADD_HDRS=$(INC)/libIntec_InTEC_DeDefs.h $(INC)/
BINS=$(patsubst $(SRC)/%.cpp, $(BIN)/%.o, $(SRCS))
EXCLUDE=
PYAPI=pyApi/libIntec.py

TARGET= $(LIB)/libIntec.so

all: $(TARGET)

install: $(TARGET)
	sudo cp -rf $(TARGET) /usr/lib64/libIntec.so
	sudo cp $(LIB)/libIntec.h /usr/include/libIntec.h 
	sudo mkdir -p /etc/libIntec
	sudo cp -rf cfg/InTECEventsConfiguration.xml /etc/libIntec/.
	sudo cp -rf $(PYAPI) $(USER_SITE)/libIntec.py

$(TARGET): $(filter-out $(EXCLUDE),$(BINS))
	$(CC) -fPIC $(FLAGS) $(LDLIBUSB) -shared -Wl,-soname,libIntec.so $^ -o $@
	cp $(INC)/libIntec.h $(LIB)/libIntec.h 

$(BIN)/%.o: $(SRC)/%.cpp $(INC)/%.h 
	$(CCPP) -fPIC $(FLAGS) $(LDLIBUSB)-I$(INC) -c $< -o $@ 
 

test:
	make -C tests
clean:
	rm -rf bin/*.o
	rm -rf lib/*.so lib/*.h
	rm -rf inc/*.gch
