#include<cstdint>
#include "png.h"
#ifndef IMAGE_H
#define IMAGE_H
using std::uint8_t;
// ... code goes here
class Image : public PNG
{
    // the function definitions from the Doxygen go here
    public:
    	void  flipleft();
    	void 	adjustbrightness (int r, int g, int b);
    	void 	invertcolors ();
};
#endif
