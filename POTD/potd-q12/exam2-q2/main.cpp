#include "schedule.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
  schedule a(10);
  schedule b(3);
  a.addCourses("A");
  a.addCourses("B");
  a.addCourses("C");
  a.addCourses("D");
  a.addCourses("E");
  a.addCourses("F");
  b.addCourses("B");
  b.addCourses("R");
  b.addCourses("G");

  schedule result(6);
  result = a - b;
  string* resultClass = result.getCourses();
  for(int i = 0;i<result.getItems();i++){
    cout<<resultClass[i]<<" ";
  }
  cout<<endl;
  return 0;
}
