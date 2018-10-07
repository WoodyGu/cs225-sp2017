#include "schedule.h"

schedule::schedule(int size){
  this->courses = new string[size];
  this->items = 0;
  this->size = size;
}

int schedule::getSize() const{
  return this->size;
}

int schedule::getItems() const{
  return this->items;
}

string* schedule::getCourses() const{
  return this->courses;
}

void schedule::addCourses(string className){
  if(items == size){
    return;
  }
  else{
    this->courses[items] = className;
    this->items++;
  }
}

schedule schedule::operator-(const schedule& other){
  schedule retval(this->size - other.size);
  retval.items = this->items - other.items;
  for(int i = 0;i<this->items;i++){
    bool canAdd = true;;
    for(int j = 0;j<other.items;j++){
      if(this->courses[i]==other.courses[j]){
        canAdd = false;
      }
    }
    if(canAdd){
      retval.addCourses(this->courses[i]);
    }
  }
  return retval;
}
