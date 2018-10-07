EXENAME = main
OBJS = main.o TST.o 

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp TST.h
	$(CXX) $(CXXFLAGS) main.cpp

TST.o: TST.h TST.cpp
	$(CXX) $(CXXFLAGS) TST.cpp
clean:
	-rm -f *.o $(EXENAME)
