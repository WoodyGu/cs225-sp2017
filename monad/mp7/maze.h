/* Your code here! */
#ifndef MAZE_H
#define MAZE_H

#include "rgbapixel.h"
#include "png.h"
#include "dsets.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <time.h>       /* time */
using namespace std;

class SquareMaze{
  public:
    SquareMaze();
    void makeMaze(int width,int height);
    bool canTravel(int x, int y, int dir) const;
    void setWall(int x, int y,int dir, bool exists);
    vector<int> solveMaze();
    PNG* drawMaze()	const;
    PNG* drawMazeWithSolution();
    //need a destructor
    ~SquareMaze();

  private:
    int width;
    int height;
    DisjointSets mazeSet;
    struct mazeCell{
      //if true, there is a wall and cannot travel through
      bool rightWall;
      bool downWall;
      //for solveMaze(), store the point before arriving this point
      pair<int, int> previous;
    };
    mazeCell** mazeArray;
};
#endif
