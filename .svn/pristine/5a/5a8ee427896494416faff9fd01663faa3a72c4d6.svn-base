/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    /**
     * @todo Implement this function!
     */
     /*creates a new dynamically allocated MosaicCanvas, with the same number of rows and columns as the SourceImage,
     *and returns a pointer to this object
     */
    MosaicCanvas* retval = new MosaicCanvas(theSource.getRows(),theSource.getColumns());
    /*
      For every region in the SourceImage, mapTiles() should take the TileImage with average color closest to the average color of that region
      and place that TileImage into the MosaicCanvas in the same tile position as the SourceImage’s region
    */
    std::vector<Point<3>> vPoint;
    for(size_t i = 0;i<theTiles.size();i++){
      Point<3> temp(theTiles[i].getAverageColor().red, theTiles[i].getAverageColor().green, theTiles[i].getAverageColor().blue);
      vPoint.push_back(temp);
    }
    std::map<Point<3>, TileImage> dict;
    for(size_t k = 0;k<vPoint.size();k++){
      dict.insert({vPoint[k],theTiles[k]});
    }
    //build a KDTree
    KDTree<3> tree(vPoint);
    for(int row = 0;row<theSource.getRows();row++){
      for(int col = 0;col<theSource.getColumns();col++){
        RGBAPixel sourcePixel = theSource.getRegionColor(row,col);
        Point<3> sourcePoint(sourcePixel.red, sourcePixel.green, sourcePixel.blue);
        Point<3> nearestNeighbour = tree.findNearestNeighbor(sourcePoint);
        auto lookup = dict.find(nearestNeighbour);
        retval->setTile(row,col,lookup->second);
      }
    }
    return retval;
}
