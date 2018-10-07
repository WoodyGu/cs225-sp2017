EXENAME = main
OBJS = main.o heap.o 

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp heap.h
	$(CXX) $(CXXFLAGS) main.cpp

heap.o: heap.h heap.cpp
	$(CXX) $(CXXFLAGS) heap.cpp
clean:
	-rm -f *.o $(EXENAME)
