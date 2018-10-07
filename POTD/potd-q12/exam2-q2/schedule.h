#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class schedule{
  public:
    schedule(int size);
    int getSize() const;
    int getItems() const;
    string *getCourses() const;
    void addCourses(string className);
	  schedule operator-(const schedule& other);

  private:
    int size;
    int items;
    string* courses;
};
#endif
