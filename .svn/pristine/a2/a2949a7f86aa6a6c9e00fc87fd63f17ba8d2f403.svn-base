#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

PNG Rotate(PNG original){
    PNG imageOut(original.width(),original.height());
    for (size_t yi = 0; yi < original.height(); yi++) {
        for (size_t xi = 0; xi < original.width(); xi++) {
		*imageOut(xi,yi) = *original(original.width()-xi-1,original.height()-yi-1);	
}
}
    return imageOut;	
}

int main(){

PNG image("in.png");
PNG imageOut = Rotate(image);
imageOut.writeToFile("out.png");
return 0;
}
