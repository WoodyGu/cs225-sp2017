/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace. Heavily based on
 * old MP4 by CS225 Staff, Fall 2010.
 *
 * @author Chase Geigle
 * @date Fall 2012
 */
#include "filler.h"
#include <math.h>

animation filler::dfs::fillSolid(PNG& img, int x, int y, RGBAPixel fillColor,
                                 int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    solidColorPicker solidPixel(fillColor);//how to implement a stack?
    return filler::dfs::fill(img,x,y,solidPixel,tolerance,frameFreq);
}

animation filler::dfs::fillGrid(PNG& img, int x, int y, RGBAPixel gridColor,
                                int gridSpacing, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    gridColorPicker gridPixel(gridColor,gridSpacing);
    return filler::dfs::fill(img,x,y,gridPixel,tolerance,frameFreq);
}

animation filler::dfs::fillGradient(PNG& img, int x, int y,
                                    RGBAPixel fadeColor1, RGBAPixel fadeColor2,
                                    int radius, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    gradientColorPicker gradientPixel(fadeColor1,fadeColor2,radius,x,y);
    return filler::dfs::fill(img,x,y,gradientPixel,tolerance,frameFreq);
}

animation filler::dfs::fill(PNG& img, int x, int y, colorPicker& fillColor,
                            int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to filler::fill with the correct template parameter
     * indicating the ordering structure to be used in the fill.
     */
    return filler::fill<Stack>(img,x,y,fillColor,tolerance,frameFreq);//all arguments)
}

animation filler::bfs::fillSolid(PNG& img, int x, int y, RGBAPixel fillColor,
                                 int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
     solidColorPicker solidPixel(fillColor);//how to implement a stack?
     return filler::bfs::fill(img,x,y,solidPixel,tolerance,frameFreq);
}

animation filler::bfs::fillGrid(PNG& img, int x, int y, RGBAPixel gridColor,
                                int gridSpacing, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
     gridColorPicker gridPixel(gridColor,gridSpacing);
     return filler::bfs::fill(img,x,y,gridPixel,tolerance,frameFreq);
}

animation filler::bfs::fillGradient(PNG& img, int x, int y,
                                    RGBAPixel fadeColor1, RGBAPixel fadeColor2,
                                    int radius, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
     gradientColorPicker gradientPixel(fadeColor1,fadeColor2,radius,x,y);
     return filler::bfs::fill(img,x,y,gradientPixel,tolerance,frameFreq);
}

animation filler::bfs::fill(PNG& img, int x, int y, colorPicker& fillColor,
                            int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to filler::fill with the correct template parameter
     * indicating the ordering structure to be used in the fill.
     */
    return filler::fill<Queue>(img,x,y,fillColor,tolerance,frameFreq);
}

template <template <class T> class OrderingStructure>
animation filler::fill(PNG& img, int x, int y, colorPicker& fillColor,
                       int tolerance, int frameFreq)
{
    /**
     * @todo You need to implement this function!
     *
     * This is the basic description of a flood-fill algorithm: Every fill
     * algorithm requires an ordering structure, which is passed to this
     * function via its template parameter. For a breadth-first-search
     * fill, that structure is a Queue, for a depth-first-search, that
     * structure is a Stack. To begin the algorithm, you simply place the
     * given point in the ordering structure. Then, until the structure is
     * empty, you do the following:
     *
     * 1.     Remove a point from the ordering structure.
     *
     *        If it has not been processed before and if its color is
     *        within the tolerance distance (up to and **including**
     *        tolerance away in square-RGB-space-distance) to the original
     *        point's pixel color [that is, \f$(currentRed - OriginalRed)^2 +
              (currentGreen - OriginalGreen)^2 + (currentBlue -
              OriginalBlue)^2 \leq tolerance\f$], then:
     *        1.    indicate somehow that it has been processed (do not mark it
     *              "processed" anywhere else in your code)
     *        2.    change its color in the image using the appropriate
     *              colorPicker
     *        3.    add all of its neighbors to the ordering structure, and
     *        4.    if it is the appropriate frame, send the current PNG to the
     *              animation (as described below).
     * 2.     When implementing your breadth-first-search and
     *        depth-first-search fills, you will need to explore neighboring
     *        pixels in some order.
     *
     *        While the order in which you examine neighbors does not matter
     *        for a proper fill, you must use the same order as we do for
     *        your animations to come out like ours! The order you should put
     *        neighboring pixels **ONTO** the queue or stack is as follows:
     *        **RIGHT(+x), DOWN(+y), LEFT(-x), UP(-y). IMPORTANT NOTE: *UP*
     *        here means towards the top of the image, so since an image has
     *        smaller y coordinates at the top, this is in the *negative y*
     *        direction. Similarly, *DOWN* means in the *positive y*
     *        direction.** To reiterate, when you are exploring (filling out)
     *        from a given pixel, you must first try to fill the pixel to
     *        it's RIGHT, then the one DOWN from it, then to the LEFT and
     *        finally UP. If you do them in a different order, your fill may
     *        still work correctly, but your animations will be different
     *        from the grading scripts!
     * 3.     For every k pixels filled, **starting at the kth pixel**, you
     *        must add a frame to the animation, where k = frameFreq.
     *
     *        For example, if frameFreq is 4, then after the 4th pixel has
     *        been filled you should add a frame to the animation, then again
     *        after the 8th pixel, etc.  You must only add frames for the
     *        number of pixels that have been filled, not the number that
     *        have been checked. So if frameFreq is set to 1, a pixel should
     *        be filled every frame.
     */
    //1. remove a point from ordering structure
    OrderingStructure<int>coordX;
    OrderingStructure<int>coordY;
    //OrderingStructure<RGBAPixel>pixels;
    int counter = 0;//count if we should add a frame to animation
    animation anime;
    bool **visited = new bool*[img.width()];//a array of pointer to show if we have processed our objects
    for(size_t i = 0;i<img.width();i++){
      visited[i] = new bool[img.height()];//create a array of pointers
      for(size_t j = 0;j<img.height();j++){
        visited[i][j] = false;//set everything to false before processing
      }
    }
    //save the color at (x,y) original and the color for comparison
    coordX.add(x);
    coordY.add(y);
    RGBAPixel original = *(img(x,y));
    while(!coordX.isEmpty()){
      //pop out x and y coords for processing
      x = coordX.remove();
      y = coordY.remove();
      int distance = pow((img(x,y)->red-original.red),2)+pow((img(x,y)->green-original.green),2)+pow((img(x,y)->blue-original.blue),2);
      if(!visited[x][y]&&distance<=tolerance){//if the condition complies,we process the data
        visited[x][y] = true;
        *(img(x,y)) = fillColor(x,y);//how to change color
        //greater or equal to 0
        if(x+1>=0&&x+1<int(img.width())){//checking conditions if it is valid
          coordX.add(x+1);//how to add pictures
          coordY.add(y);
        }
        if(y+1>=0&&y+1<int(img.height())){//checking conditions if it is valid
          coordX.add(x);//how to add pictures
          coordY.add(y+1);
        }
        if(x-1>=0&&x-1<int(img.width())){//checking conditions if it is valid
          coordX.add(x-1);//how to add pictures
          coordY.add(y);
        }
        if(y-1>=0&&y-1<int(img.height())){//checking conditions if it is valid
          coordX.add(x);//how to add pictures
          coordY.add(y-1);
        }
          //pixels.add();
          counter++;
          if(counter%frameFreq==0){
            anime.addFrame(img);
          }
      }
    }
//clean up the memory
    for(size_t k = 0;k<img.width();k++){//the first [] means width, go through all of them to free memory
      delete[] visited[k];
    }
    delete[]visited;
    return anime;
}
