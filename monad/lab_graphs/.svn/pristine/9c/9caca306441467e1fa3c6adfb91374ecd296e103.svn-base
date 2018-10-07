/* Your code here! */
#ifndef DSET_H
#define DSET_H

#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

class DisjointSets
{
  public:
    /*
    this function creates n unconnected root nodes at the end of the vector.
    */
    void addelements(int num);

    /*
    This function should compress paths and works as described in lecture.
    */
    int find(int elem);

    /*
    This function should be implemented as union-by-size.
    setunion function SHOULD find the roots of its arguments before combining the trees.
    If the two sets are the same size, make the tree containing the second argument point to the tree containing the first.
    */
    void setunion(int a, int b);

  private:
    bool isBigger(int root1, int root2);
    std::vector<int> v;
};
#endif
