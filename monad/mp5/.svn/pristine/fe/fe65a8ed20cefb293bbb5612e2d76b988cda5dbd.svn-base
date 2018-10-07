/**
 * @file quadtree.h
 * Quadtree class definition.
 * @date Spring 2008
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"
#include<math.h>

/**
 * A tree structure that is used to compress PNG images.
 */
class Quadtree
{
  public:
    Quadtree();
    Quadtree(PNG const &source,int resolution);
    Quadtree(Quadtree const &other);
    ~Quadtree();
    void buildTree(PNG const & source,int resolution);
    const Quadtree& operator=(Quadtree const &other);
    RGBAPixel getPixel(int x, int y) const;
    PNG decompress() const;
    void clockwiseRotate();
    void prune(int tolerance);
    int pruneSize(int tolerance) const;
    int idealPrune(int numLeaves) const;
  private:
    /**
     * A simple class representing a single node of a Quadtree.
     * You may want to add to this class; in particular, it could
     * probably use a constructor or two...
     */
    class QuadtreeNode
    {
      public:
        QuadtreeNode* nwChild; /**< pointer to northwest child */
        QuadtreeNode* neChild; /**< pointer to northeast child */
        QuadtreeNode* swChild; /**< pointer to southwest child */
        QuadtreeNode* seChild; /**< pointer to southeast child */

        RGBAPixel element; /**< the pixel stored as this node's "data" */

        QuadtreeNode(){element = RGBAPixel();nwChild = NULL;neChild = NULL;swChild = NULL;swChild = NULL;};
        QuadtreeNode(RGBAPixel pixel) {element = pixel; nwChild = neChild = swChild = seChild = NULL;}
    };

    QuadtreeNode* root; /**< pointer to root of quadtree */
    size_t resolution;
    void clear(QuadtreeNode*& croot);
    QuadtreeNode* copy(QuadtreeNode* subRoot);
    QuadtreeNode* buildTreeHelper(PNG const & source,int resolution, int x,int y);
    RGBAPixel getPixelHelper(int x, int y, int resolution, QuadtreeNode* root) const;
    void rotateHelper(QuadtreeNode* croot);
    void pruneHelper(QuadtreeNode* croot, int tolerance);
    bool canPruneCurr(QuadtreeNode* croot, int tolerance,int redAvg,int greenAvg,int blueAvg) const;
    //bool canPrune(QuadtreeNode* croot,int tolerance);
    int pruneSizeHelper(QuadtreeNode* croot,int tolerance) const;
    int idealPruneHelper(int numLeaves,int mintol,int maxtol) const;
/**** Functions for testing/grading                      ****/
/**** Do not remove this line or copy its contents here! ****/
#include "quadtree_given.h"
};

#endif
