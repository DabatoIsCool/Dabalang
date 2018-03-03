CXX = g++
CXXFLAGS=-c -std=c++11

all: dabalang

dabalang: main.o util.o
	$(CXX) main.o util.o -o dabalang

main.o: main.cpp util.h
	$(CXX) $(CXXFLAGS) main.cpp util.h

util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) util.cpp util.h

clean:
	rm -rf *.o *.gch dabalang
