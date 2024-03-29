/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num){
  if(num<=0){
    return;
  }
  for(int i = 0;i < num;i++){
    v.push_back(-1);//initial size are all -1
  }
}

int DisjointSets::find(int elem){
  if(elem<0){
    return -1;//bad inputs!
  }
  if(v[elem] < 0){
    return elem;
  }
  else{
    v[elem] = find(v[elem]);
    return find(v[elem]);
  }
}
bool DisjointSets::isBigger(int root1, int root2){
  return abs(v[root1])>=abs(v[root2]);
}

void DisjointSets::setunion(int a, int b){
  int root1 = find(a);
  int root2 = find(b);
  int newSize = v[root1]+v[root2];
  if(isBigger(root1,root2)){
    v[root2] = root1;
    v[root1] = newSize;
  }
  else{
    v[root1] = root2;
    v[root2] = newSize;
  }
}
