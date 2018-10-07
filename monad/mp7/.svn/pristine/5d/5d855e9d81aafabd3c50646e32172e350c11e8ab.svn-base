/* Your code here! */
#include "maze.h"
#include <stdlib.h>

SquareMaze::SquareMaze(){
  height = 0;
  width = 0;
}

SquareMaze::~SquareMaze(){
  for(int i = 0;i<width;i++){
    delete[] mazeArray[i];
  }
  delete[] mazeArray;
  mazeArray = NULL;
}

void SquareMaze::makeMaze(int width, int height)
{
  //initialize a grid
  this->width = width;
  this->height = height;
  mazeArray = new mazeCell*[width];
  for(int i = 0;i<width;i++){
    mazeArray[i] = new mazeCell[height];
    for(int j = 0;j<height;j++){
      mazeArray[i][j].rightWall = true;
      mazeArray[i][j].downWall = true;
    }
  }
  //return;
  srand(time(NULL));
  //delete walls
  mazeSet.addelements(width*height);
  //pick a random starting point
  std::vector<pair<int,int>> sequence;
  for(int i = 0;i<width;i++){
    for(int j = 0;j<width;j++){
      std::pair<int,int> coords(i,j);
      sequence.push_back(coords);
    }
  }
  //random shuffle may be problematic
  std::random_shuffle(sequence.begin(),sequence.end());
  //should delete both walls as much as we can
  for(size_t i = 0;i<sequence.size();i++){
    //check for edge cases
    if(sequence[i].first == width-1 &&sequence[i].second == height-1){//the bottom right one
      continue;//can delete neither walls
    }
    else if(sequence[i].first == width-1){//cannot delete right wall
      /*
      if((rand()% 2) == 0){//delete right wall
        continue;
      }
      */
      //else{//delete down wall
      int x = sequence[i].first;
      int y = sequence[i].second;
      int root1 = mazeSet.find(y*width+x);
      int root2 = mazeSet.find((y+1)*width+x);
      if(root1!=root2){
        mazeArray[x][y].downWall = false;
        mazeSet.setunion(y*width+x,(y+1)*width+x);
      }
      //}
    }
    else if(sequence[i].second == height-1){//cannot delete down wall
      /*
      if((rand()% 2) == 1){//delete downwall
        continue;
      }
      */
      //else{//delete rightWall
      int x = sequence[i].first;
      int y = sequence[i].second;
      int root1 = mazeSet.find(y*width+x);
      int root2 = mazeSet.find(y*width+x+1);
      if(root1!=root2){
        mazeArray[x][y].rightWall = false;
        mazeSet.setunion(y*width+x,y*width+x+1);
      }
      //}
    }
    else{
      //if((rand()% 2) == 1){//delete downwall
      int x = sequence[i].first;
      int y = sequence[i].second;
      int root1 = mazeSet.find(y*width+x);
      int root2 = mazeSet.find((y+1)*width+x);
      if(root1!=root2){
        mazeArray[x][y].downWall = false;
        mazeSet.setunion(y*width+x,(y+1)*width+x);
      }
      //}
      //else{//delete rightWall
        //int x = sequence[i].first;
        //int y = sequence[i].second;
      root1 = mazeSet.find(y*width+x);
      root2 = mazeSet.find(y*width+x+1);
      if(root1!=root2){
        mazeArray[x][y].rightWall = false;
        mazeSet.setunion(y*width+x,y*width+x+1);
      }
      //}
    }
  }
}

bool SquareMaze::canTravel(int x, int y, int dir) const
{
  //bad inputs
  if(x<0||x>width-1||y<0||y>height-1){
    return false;
  }
  //rightward step: x must not be out of bound
  if(dir == 0){
    if(x == this->width-1){
      return false;
    }
    else{
      return !(mazeArray[x][y].rightWall);
    }
  }
  //downward step
  else if(dir == 1){
    if(y == this->height-1){
      return false;
    }
    else{
      return !(mazeArray[x][y].downWall);
    }
  }
  //leftward step
  else if(dir == 2){
    if(x == 0){
      return false;
    }
    else{
      return !(mazeArray[x-1][y].rightWall);
    }
  }
  else{
    if(y == 0){
      return false;
    }
    else{
      return !(mazeArray[x][y-1].downWall);
    }
  }
}

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
  //check for bad inputs
  if(x<0||x>width-1||y<0||y>height-1){
    return;
  }
  if(dir == 0){
    mazeArray[x][y].rightWall = exists;
  }
  if(dir == 1){
    mazeArray[x][y].downWall = exists;
  }
}

vector<int> SquareMaze::solveMaze()//bfs
{
  //first create a boolean array to determine if we have visited that point
  bool** visited = new bool*[width];
  for(int i = 0;i<width;i++){
    visited[i] = new bool[height];
    for(int j = 0;j<height;j++){
      visited[i][j] = false;
    }
  }

  //carry out BFS
  pair<int,int> coords(0,0);//first two are current coords
  queue<pair<int,int>> q;
  visited[0][0] = true;
  vector<pair<int,int>> destination;//store the possible exits on the bottom row
  q.push(coords);
  while(!q.empty()){
    //create temp cord
    pair<int,int> currCoord = q.front();
    //set visited to true
    visited[currCoord.first][currCoord.second] = true;
    if(currCoord.second == height-1){//reached the bottom of the maze
      destination.push_back(currCoord);//store the possible exits on the bottom row
    }
    q.pop();
    if(canTravel(currCoord.first,currCoord.second,0)&&!visited[currCoord.first+1][currCoord.second]){
      visited[currCoord.first+1][currCoord.second] = true;
      mazeArray[currCoord.first+1][currCoord.second].previous = currCoord;
      pair<int,int> nextR(currCoord.first+1,currCoord.second);
      q.push(nextR);
    }
    if(canTravel(currCoord.first,currCoord.second,1)&&!visited[currCoord.first][currCoord.second+1]){
      visited[currCoord.first][currCoord.second+1] = true;
      mazeArray[currCoord.first][currCoord.second+1].previous = currCoord;
      pair<int,int> nextD(currCoord.first,currCoord.second+1);
      q.push(nextD);
    }
    if(canTravel(currCoord.first,currCoord.second,2)&&!visited[currCoord.first-1][currCoord.second]){
      visited[currCoord.first-1][currCoord.second] = true;
      mazeArray[currCoord.first-1][currCoord.second].previous = currCoord;
      pair<int,int> nextL(currCoord.first-1,currCoord.second);
      q.push(nextL);
    }
    if(canTravel(currCoord.first,currCoord.second,3)&&!visited[currCoord.first][currCoord.second-1]){
      visited[currCoord.first][currCoord.second-1] = true;
      mazeArray[currCoord.first][currCoord.second-1].previous = currCoord;
      pair<int,int> nextU(currCoord.first,currCoord.second-1);
      q.push(nextU);
    }
  }
  vector<vector<int>> validPaths = {};
  /*use a pair to store temp coords
  * in each mazecell, create a pair varible to store the predecessor for each point
  */
  cout<<destination.size()<<endl;
  for(size_t i = 0;i<destination.size();i++){
    //have to save the pre for every cell
    vector<int> path = {};
    int currX = destination[i].first;
    int currY = destination[i].second;
    while(currX>0||currY>0){
      if(mazeArray[currX][currY].previous.first-currX == 1){//went left to the point
        path.push_back(2);
        currX = mazeArray[currX][currY].previous.first;
      }
      if(mazeArray[currX][currY].previous.first-currX == -1){//went right to the point
        path.push_back(0);
        currX = mazeArray[currX][currY].previous.first;
      }
      if(mazeArray[currX][currY].previous.second-currY == 1){//went up to the point
        path.push_back(3);
        currY = mazeArray[currX][currY].previous.second;
      }
      if(mazeArray[currX][currY].previous.second-currY == -1){//went down to the point
        path.push_back(1);
        currY = mazeArray[currX][currY].previous.second;
      }
    }
    validPaths.push_back(path);
  }
  //determine the longest distance from the starting point
  //delete the visited bool array
  //return the soln vector
  std::vector<int> solution;
  pair<int,int> exit;
  //find the longest path;
  for(size_t i = 0;i<validPaths.size();i++){
    if(validPaths[i].size()>solution.size()){
      solution = validPaths[i];
      exit = destination[i];
    }
    //tie breaking
    if(validPaths[i].size() == solution.size()){
      if(destination[i].first<exit.first){
        solution = validPaths[i];
      }
    }
  }
  //clear up the memory
  for(int k = 0;k<width;k++){
    delete[] visited[k];
  }
  delete[] visited;
  std::reverse(solution.begin(),solution.end());
  return solution;
}

PNG* SquareMaze::drawMaze()	const
{
  PNG* retimg = new PNG(this->width*10+1,this->height*10+1);
  //set the boundries to black
  RGBAPixel black(0,0,0);
  for(int i = 0;i<=(width)*10;i++){
    *((*retimg)(i,0)) = black;
  }
  for(int i = 0;i<=(height)*10;i++){
    *((*retimg)(0,i)) = black;
  }
  RGBAPixel white(255,255,255);
  for(int i = 1;i<10;i++){
    *((*retimg)(i,0)) = white;
  }
  for(int x = 0;x<width;x++){//the coords for the boolean array
    for(int y = 0;y<height;y++){
      //color the right wall black
      if(mazeArray[x][y].rightWall){
        for(int k = 0;k<11;k++){
          *((*retimg)((x+1)*10,y*10+k)) = black;
        }
      }
      //color the downwall black
      if(mazeArray[x][y].downWall){
        for(int k = 0;k<11;k++){
          *((*retimg)(x*10+k,(y+1)*10)) = black;
        }
      }
    }
  }
  return retimg;
}

PNG * SquareMaze::drawMazeWithSolution()//okay
{
  PNG* retimg = drawMaze();
  std::vector<int> solution = solveMaze();
  //if(solution.empty()) return retimg;
  RGBAPixel red(255,0,0);
  int xCoords = 5;
  int yCoords = 5;
  for(size_t i = 0;i<solution.size();i++){
    if(solution[i] == 0){//right x+1
      //set the path to red
      for(int j = 0;j<11;j++){
        *((*retimg)(xCoords+j,yCoords)) = red;
      }
      //update the coords for next operation
      xCoords = xCoords + 10;
    }
    else if(solution[i] == 1){//down y+1
      //set the path to red
      for(int j = 0;j<11;j++){
        *((*retimg)(xCoords,yCoords+j)) = red;
      }
      //update the coords for next operation
      yCoords = yCoords + 10;
    }
    else if(solution[i] == 2){//left x-1
      //set the path to red
      for(int j = 0;j<11;j++){
        *((*retimg)(xCoords-j,yCoords)) = red;
      }
      //update the coords for next operation
      xCoords = xCoords - 10;
    }
    else{//up y-1
      //set the path to red
      for(int j = 0;j<11;j++){
        *((*retimg)(xCoords,yCoords-j)) = red;
      }
      //update the coords for next operation
      yCoords = yCoords - 10;
    }
  }
  //open the exit
  RGBAPixel white(255,255,255);
  //find the destination cell
  xCoords = xCoords-5;
  yCoords = yCoords+5;
  for(int k = 1;k<10;k++){//cannot change the left boundry and right boundry, so 1 and 10
    *((*retimg)(xCoords+k,yCoords)) = white;
  }
  return retimg;
}
