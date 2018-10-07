/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 * @date Spring 2008
 */
#include "quadtree.h"
#include <iostream>
using namespace std;

//no argument constructor
Quadtree::Quadtree(){
  root = NULL;
  resolution = 0;
}

//buildTree function
void Quadtree::buildTree(PNG const & source,int resolution ){//need to set resolution also in build tree function
  clear(root);
  this->resolution = resolution;
  root = buildTreeHelper(source,resolution,0,0);
}
  // x,y = upper-left pixel
Quadtree::QuadtreeNode* Quadtree::buildTreeHelper(PNG const & source,int resolution, int x,int y){
  if(resolution == 1){
    QuadtreeNode* leafNode = new QuadtreeNode(*(source(x,y)));//store the pixel in the leaf node!
    return leafNode;
  }
  QuadtreeNode* newNode = new QuadtreeNode();
  //its 4 children will get pixels from 4 divided regions
  newNode->nwChild = buildTreeHelper(source,resolution/2,x,y);
  newNode->neChild = buildTreeHelper(source,resolution/2,x+resolution/2,y);
  newNode->swChild = buildTreeHelper(source,resolution/2,x,y+resolution/2);
  newNode->seChild = buildTreeHelper(source,resolution/2,x+resolution/2,y+resolution/2);
  uint8_t redAvg = (newNode->nwChild->element.red + newNode->neChild->element.red + newNode->swChild->element.red + newNode->seChild->element.red)/4;
  uint8_t blueAvg = (newNode->nwChild->element.blue + newNode->neChild->element.blue + newNode->swChild->element.blue + newNode->seChild->element.blue)/4;
  uint8_t greenAvg = (newNode->nwChild->element.green + newNode->neChild->element.green + newNode->swChild->element.green + newNode->seChild->element.green)/4;
  RGBAPixel average(redAvg,greenAvg,blueAvg);
  newNode->element = average;
  return newNode;
}

//two argument constructor
Quadtree::Quadtree(PNG const &source,int resolution){
  root = buildTreeHelper(source,resolution,0,0);
  this->resolution = resolution;
}

//copy constructor
Quadtree::Quadtree(Quadtree const &other){
  this->resolution = other.resolution;
  root = copy(other.root);
}

//overloading operator
const Quadtree& Quadtree::operator=(Quadtree const &other){
  if(this != &other){
    clear(root);
    this->resolution = other.resolution;
    root = copy(other.root);
  }
  return *this;
}

Quadtree::QuadtreeNode* Quadtree::copy(QuadtreeNode* root){
    if(root == NULL){
      return NULL;
    }
    QuadtreeNode* t = new QuadtreeNode(root->element);
    t->nwChild = copy(root->nwChild);
    t->neChild = copy(root->neChild);
    t->swChild = copy(root->swChild);
    t->seChild = copy(root->seChild);
    return t;
  }
//Destructor
Quadtree::~Quadtree(){
  clear(root);
}

void Quadtree::clear(QuadtreeNode*& croot){
  if(croot!=NULL){
    clear(croot->nwChild);
    clear(croot->neChild);
    clear(croot->swChild);
    clear(croot->seChild);
    delete croot;
    croot = NULL;
  }
}

RGBAPixel Quadtree::getPixel(int x, int y) const{
  return getPixelHelper(x,y,this->resolution,this->root);
}

RGBAPixel Quadtree::getPixelHelper(int x, int y, int resolution, QuadtreeNode* root) const{
  if(root == NULL||x>resolution||y>resolution||x<0||y<0){//check for null root or coords are out of bound
    return RGBAPixel();
  }
  //base case, if any of the child is null, it is a leaf node
  if(root->nwChild==NULL){//if any of the child is null, it is a leafNode
    return root->element;
  }
  else{
  //check condition to locate the coords of the node , 4 recursive cases resolution/2...
  //"bigger than" relation should be used >= since if the resolution is 4, we want 0,1||2,3
    if(x<resolution/2&&y<resolution/2){//nwChild
      return getPixelHelper(x,y,resolution/2,root->nwChild);
    }
    else if(x>=resolution/2&&y<resolution/2){//neChild
      return getPixelHelper(x-resolution/2,y,resolution/2,root->neChild);
    }
    else if(x<resolution/2&&y>=resolution/2){//swChild
      return getPixelHelper(x,y-resolution/2,resolution/2,root->swChild);//the coords will be relative to the small square
    }
    else{//seChild
      return getPixelHelper(x-resolution/2,y-resolution/2,resolution/2,root->seChild);
    }
  }
}

PNG Quadtree::decompress() const{
  //construct a PNG object with width = height = resolution
  //traverse until the leaf nodes and get the rgbapixel at that node
  //set the (x,y) location at the png object
  if(this->root == NULL) return PNG();//can i just build it on stack?????
  PNG retimg(this->resolution,this->resolution);
  for(size_t i = 0;i<resolution;i++){
    for(size_t j = 0;j<resolution;j++){
      *(retimg(i,j)) = getPixel(i,j);
    }
  }
  return retimg;
}
//root and resolution

void Quadtree::clockwiseRotate(){
  if(this->root!=NULL){
    rotateHelper(this->root);
  }
}

void Quadtree::rotateHelper(QuadtreeNode* croot){
  if(croot->nwChild != NULL){
    //swap all the pointers clockwise
    QuadtreeNode* temp = croot->nwChild;
    croot->nwChild = croot->swChild;
    croot->swChild = croot->seChild;
    croot->seChild = croot->neChild;
    croot->neChild = temp;
    rotateHelper(croot->nwChild);
    rotateHelper(croot->neChild);
    rotateHelper(croot->swChild);
    rotateHelper(croot->seChild);
  }
}

void Quadtree::prune(int tolerance){
  if(this->root!=NULL){
    pruneHelper(this->root,tolerance);
  }
}

void Quadtree::pruneHelper(QuadtreeNode* croot, int tolerance){
  if(croot->nwChild == NULL){//it is the leafNode, no need to go on anymore, so we return
    return;
  }
  if(canPruneCurr(croot,tolerance,croot->element.red,croot->element.green,croot->element.blue)){
    //if we can prune, we can clear up all its children
    clear(croot->nwChild);
    clear(croot->neChild);
    clear(croot->swChild);
    clear(croot->seChild);
    return;
  }
  pruneHelper(croot->nwChild,tolerance);
  pruneHelper(croot->neChild,tolerance);
  pruneHelper(croot->swChild,tolerance);
  pruneHelper(croot->seChild,tolerance);
}

bool Quadtree::canPruneCurr(QuadtreeNode* croot, int tolerance,int redAvg,int greenAvg,int blueAvg) const{
  //only calculate this particular node, not all the tree
  if(croot->nwChild == NULL){
    int diff = pow((croot->element.red-redAvg),2)+pow((croot->element.green-greenAvg),2)+pow((croot->element.blue-blueAvg),2);
    return diff<=tolerance;
  }
  else{
    return canPruneCurr(croot->nwChild,tolerance,redAvg,greenAvg,blueAvg)
          &&canPruneCurr(croot->neChild,tolerance,redAvg,greenAvg,blueAvg)
          &&canPruneCurr(croot->swChild,tolerance,redAvg,greenAvg,blueAvg)
          &&canPruneCurr(croot->seChild,tolerance,redAvg,greenAvg,blueAvg);
  }
  /*int diffNW = pow((croot->nwChild->element.red-redAvg),2)+pow((croot->nwChild->element.green-greenAvg),2)+pow((croot->nwChild->element.blue-blueAvg),2);
  int diffNE = pow((croot->neChild->element.red-redAvg),2)+pow((croot->neChild->element.green-greenAvg),2)+pow((croot->neChild->element.blue-blueAvg),2);
  int diffSW = pow((croot->swChild->element.red-redAvg),2)+pow((croot->swChild->element.green-greenAvg),2)+pow((croot->swChild->element.blue-blueAvg),2);
  int diffSE = pow((croot->seChild->element.red-redAvg),2)+pow((croot->seChild->element.green-greenAvg),2)+pow((croot->seChild->element.blue-blueAvg),2);
  */
}

//need 2 more functions:1. check only one node with its all leaves 2.traverse thorugh the whole tree
/*bool Quadtree::canPrune(QuadtreeNode* croot,int tolerance){
  if(croot->nwChild==NULL){//a leaf node, can prune
    return true;
  }
  else{
    //check if this node can be pruned and all its children can be pruned, if any of children cannot be pruned, will return false
    return canPruneCurr(croot,tolerance)
          &&canPrune(croot->nwChild,tolerance)
          &&canPrune(croot->neChild,tolerance)
          &&canPrune(croot->swChild,tolerance)
          &&canPrune(croot->seChild,tolerance);
  }
}
*/
int Quadtree::pruneSize(int tolerance) const{
  return pruneSizeHelper(this->root,tolerance);
}

int Quadtree::pruneSizeHelper(QuadtreeNode* croot,int tolerance) const{
  if(croot == NULL){
    return 0;
  }
  if(croot->nwChild == NULL){//it is the leafNode, no need to go on anymore, so we return
    return 1;
  }
  if(canPruneCurr(croot,tolerance,croot->element.red,croot->element.green,croot->element.blue)){
    //if we can prune, it will be a leaf Node
    return 1;
  }
  else{
    return pruneSizeHelper(croot->nwChild,tolerance)
          + pruneSizeHelper(croot->neChild,tolerance)
          + pruneSizeHelper(croot->swChild,tolerance)
          + pruneSizeHelper(croot->seChild,tolerance);
  }
}

int Quadtree::idealPrune(int numLeaves) const{
  return idealPruneHelper(numLeaves,0,(255*255*3));
}

int Quadtree::idealPruneHelper(int numLeaves,int mintol,int maxtol) const{//algorithm for binary search
  int mid = (mintol+maxtol)/2;
  if(mintol == maxtol){
    return mintol;
  }
  if(mintol == maxtol-1){
    if(pruneSize(mintol) == numLeaves){
      return mintol;
    }
    else{
      return maxtol;
    }
  }
  /*if(pruneSize(mid) == numLeaves){
    while(pruneSize(mid)==numLeaves){//there is a region in between that many pruneSize(tolerance) will produce same numLeaves
      mid--;//we have to find the smallest tolerance that satisfies the condition
    }
    return mid+1;
    //another binary search
    //int midPruneSize = pruneSize(mid);
  }*/
  if(pruneSize(mid)>numLeaves){
    return idealPruneHelper(numLeaves,mid,maxtol);//cannot be mid+1
  }
  else{
    return idealPruneHelper(numLeaves,mintol,mid);//cannot be mid-1
  }
}
/* this function will accept 2 varible tolerance and target pixel, we should find the number of leaves
   that are within the tolerance of the target pixel
*/
int Quadtree::numGoodsLeaves(RGBAPixel target, int tolerance){
  return numLeavesHelper(this->root,target,tolerance);
}

int Quadtree::numLeavesHelper(QuadtreeNode* croot, RGBAPixel target, int tolerance){
  if(croot->nwChild == NULL){//it is a leaf node!! so we can compare
    int diff = pow((croot->element.red-target.red),2)
              +pow((croot->element.green-target.green),2)
              +pow((croot->element.blue-target.blue),2);
    if(diff<tolerance){//the leaf is within tolerance, we return 1
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    //recursively treaverse thorugh the whole tree to find leaves
    return numLeavesHelper(croot->nwChild,target,tolerance)
          +numLeavesHelper(croot->neChild,target,tolerance)
          +numLeavesHelper(croot->swChild,target,tolerance)
          +numLeavesHelper(croot->seChild,target,tolerance);
  }
}
