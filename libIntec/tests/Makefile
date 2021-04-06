
CC= g++
FLAGS= -Wall 
LDLIBUSB= `pkg-config --libs --cflags libusb-1.0`
LDLIBINTEC= -L/lib -lIntec

libusb.test: testlibusb.cpp
	$(CC) $(FLAGS) testlibusb.cpp -o testlibusb.test $(LDLIBUSB)

runlibusb.test: testlibusb.test
	./libusb.test
	
libIntec.test: testlibIntec.cpp
	export LD_LIBRARY_PATH=$HOME/intec/libintec/lib:$LD_LIBRARY_PATH
	$(CC) $(LDLIBINTEC) -o $@ $^

runlibIntec.test:
	./libIntec.test

clean:
	rm -rf *.test