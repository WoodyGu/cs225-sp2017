#include "chara.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

using std::queue;

string Chara::getStatus(){
  if(q.size() == 0){
    return "Empty";
  }
  else if(q.size()>0&&q.size()<4){
    return "Light";
  }
  else if(q.size()>3&&q.size()<7){
    return "Moderate";
  }else{
    return "Heavy";
  }
}

void Chara::addToQueue(string name){
  q.push(name);
}

string Chara::popFromQueue(){
  string retval = q.front();
  q.pop();
  cout<<retval<<" has left"<<endl;
  return retval;
}
