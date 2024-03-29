#include"image.h"

void Image::flipleft(){
	for (size_t yi = 0; yi < this->height(); yi++) {
        for (size_t xi = 0; xi < this->width()/2; xi++) {
        RGBAPixel temp = *(*this)(xi,yi);
        *(*this)(xi,yi) = *(*this)((this->width()-1-xi),yi);
        *(*this)((this->width()-1-xi),yi) = temp;
        }
   }
}

void Image::adjustbrightness(int r,int g,int b){
	for (size_t yi = 0; yi < this->height(); yi++) {
  	for (size_t xi = 0; xi < this->width(); xi++) {
  		if((*this)(xi,yi)->red+r > 255)
  			(*this)(xi,yi)->red = 255;
  		else if((*this)(xi,yi)->red+r < 0)
  			(*this)(xi,yi)->red = 0;
  		else
  			(*this)(xi,yi)->red = (*this)(xi,yi)->red + r;
  		
 //green part 		
  	 if((*this)(xi,yi)->green + g > 255)
  			(*this)(xi,yi)->green = 255;
  		else if((*this)(xi,yi)->green + g < 0)
  			(*this)(xi,yi)->green = 0;
  		else
  			(*this)(xi,yi)->green = (*this)(xi,yi)->green + g;
  			
  //blue part
  		if((*this)(xi,yi)->blue + b > 255)
  			(*this)(xi,yi)->blue = 255;
  		else if((*this)(xi,yi)->blue + b < 0)
  			(*this)(xi,yi)->blue = 0;
  		else
  			(*this)(xi,yi)->blue = (*this)(xi,yi)->blue + b;
  	}
  }
}

void Image::invertcolors(){
	for (size_t yi = 0; yi < this->height(); yi++) {
  	for (size_t xi = 0; xi < this->width(); xi++) {
  		(*this)(xi,yi)->red = 255 - (*this)(xi,yi)->red;
  		(*this)(xi,yi)->green = 255 - (*this)(xi,yi)->green;
  		(*this)(xi,yi)->blue = 255- (*this)(xi,yi)->blue;
  	}
  }
}
