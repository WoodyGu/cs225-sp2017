#include <cstdlib>
#include <iostream>
#include "png.h"
#include "rgbapixel.h"
using namespace std;
//
// sets up the output image
PNG* setupOutput(int w, int h)
{
    PNG* image = new PNG(w, h);
    return image;
}

// Returns my favorite color
RGBAPixel myFavoriteColor(int intensity)
{
    RGBAPixel color;
    color.red   = 0;
    color.green = intensity / 2;
    color.blue  = intensity;
    return color;
}

void sketchify()
{
    // Load in.png
    PNG* original;
    original = new PNG();//return the memory address of the object on heap
    cout << "Reached line 28" << endl;
    original->readFromFile("in.png");//you cannot dereferencing a pointer if it is not properly initialized
    int width = original->width();
    int height = original->height();
    cout << "Reached line 32" << endl;
    // Create out.png
    PNG* output;
    output = setupOutput(width, height);//a heap memory is assigned to output, so we can use delete on it and will not get segmentation fault

    // Load our favorite color to color the outline
    RGBAPixel* myPixel = new RGBAPixel();
    *myPixel = myFavoriteColor(0);

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (int y = 1; y < height; y++) {
        for (int x = 1;x < width; x++) {
            // Calculate the pixel difference
            RGBAPixel* prev = (*original)(x - 1, y - 1);
            RGBAPixel* curr = (*original)(x, y);
            int diff = abs(curr->red - prev->red)
                       + abs(curr->green - prev->green)
                       + abs(curr->blue - prev->blue);
//if(diff>100), curoutpixel = mypixel
            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            RGBAPixel* currOutPixel = (*output)(x, y);
            if (diff > 100)
                *currOutPixel = *myPixel;//we want the pixel
        }
    }

    // Save the output file
    cout << "Reached line 61" << endl;
    output->writeToFile("out.png");
    cout << "Reached line 63" << endl;
    // Clean up memory
    delete original;
    delete myPixel;
    delete output;
    myPixel = NULL;
    original = NULL;
    output = NULL;
}
