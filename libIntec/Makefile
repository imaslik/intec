CC=g++
FLAGS=-Wall 
LDLIBUSB=$(shell pkg-config --libs --cflags libusb-1.0)

SRC=src
INC=inc
BIN=bin
LIB=lib

SRCS=$(wildcard $(SRC)/*.cpp)
HDRS=$(wildcard $(INC)/*.h)
OBJS=$(patsubst $(SRC)/%.cpp, $(BIN)/%.o, $(SRCS))

TARGET= $(LIB)/libIntec.so

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -shared -fPIC -lc $^ -o $@ 
	cp $(INC)/libIntec.h $(LIB)/libIntec.h
	
$(BIN)/%.o: $(SRC)/%.cpp $(INC)/%.h
	$(CC) $(FLAGS) -c $^ $(LDLIBUSB) -I$(INC) -o $@ 
 
clean:
	rm -rf *.o
	rm -rf bin/*.o
	rm -rf lib/*.so lib/*.h
 