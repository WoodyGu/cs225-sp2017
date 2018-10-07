OBJS1 = testscene.o image.o png.o rgbapixel.o scene.o
OBJS2 = testimage.o png.o rgbapixel.o image.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

all: testscene testimage

testscene: $(OBJS1)
	$(LD) $(OBJS1) $(LDFLAGS) -o testscene

testimage: $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o testimage

testscene.o: testscene.cpp scene.h image.h
	$(CXX) $(CXXFLAGS) testscene.cpp

testimage.o: testimage.cpp image.h png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) testimage.cpp

scene.o: scene.cpp scene.h image.h
	$(CXX) $(CXXFLAGS) scene.cpp

image.o: image.cpp image.h png.h
	$(CXX) $(CXXFLAGS) image.cpp

png.o : png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

clean :
	-rm -f *.o testscene testimage


