
CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread
#format
# exename: all the object file(e.g main.o, a.o, b.o)
#	clang++ all the object file + $(LDFLAGS) + -o +exename

#main.o: main.cpp and .h that main.cpp #include
#	clang++ (CXXFLAGS) + main.cpp

#a.o: a.h + a.cpp(one header file and one .cpp file)
#	clang++ $(CXXFLAG) a.cpp

#b.o: b.h + b.cpp
#	clang++ $(CXXFLAG) b.cpp

mp1 : main.o png.o rgbapixel.o
	clang++ main.o png.o rgbapixel.o $(LDFLAGS) -o mp1

main.o: main.cpp png.h rgbapixel.h
	clang++ $(CXXFLAGS) main.cpp

png.o: png.cpp png.h
	clang++ $(CXXFLAGS) png.cpp

rgbapixel.o: rgbapixel.cpp rgbapixel.h
	clang++ $(CXXFLAGS) rgbapixel.cpp

clean: 
	-rm -f *.o mp1
