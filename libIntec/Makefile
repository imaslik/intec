CC= g++
FLAGS= -Wall 
LDLIBUSB= `pkg-config --libs --cflags libusb-1.0`
INC= -I../inc
DEP= inc/*.h src/*.cpp

all: lib/libIntec.so

lib/libIntec.so: bin/libIntec.o
	$(CC) -shared $(FLAGS) -fPIC -o $@ $^
	cp inc/libIntec.h lib/libIntec.h
	
bin/libIntec.o: $(DEP)
	$(CC) $(FLAGS) $(LDLIBUSB) $(INC) -o $@ $(DEP)

clean:
	rm -rf bin/*.o
	rm -rf lib/*.so lib/*.h