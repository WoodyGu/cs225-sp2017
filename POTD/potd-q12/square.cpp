#include <iostream>
#include <string>
using namespace std;

#include "square.h"

Square::Square() {
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName) {
  name = newName;
}

void Square::setLength(double newVal) {
  *lengthptr = newVal;
}

string Square::getName() const {
  return name;
}

double Square::getLength() const {
  return *lengthptr;
}

Square::Square(const Square & other) {//copy constructor
    cout << "I am copying!" << endl;
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square() {
    delete lengthptr;
}

Square Square::operator=(const Square& orig){
	//check aginst self-assignment
	if(this!=&orig){//cannot be (*this != rhs), or we need to overload things like !=
		delete lengthptr;//clear the object that is calling the function because we will change it
		name = orig.name;
		lengthptr = new double;
		*lengthptr = orig.getLength();
	}
	return *this;
}

Square Square::operator+(const Square& a){//three objects, one is calling function, one is paremeter, the other is result c = a.operator+(b)
	Square s;	//create a new sphere object
	s.name = name+a.name;	//name is added, do the same thing as the constructor
	s.lengthptr = new double(this->getLength()+a.getLength());  //if there is a pointer member varible on heap, first create a space on the heap 
	//*(s.lengthptr) = this->getLength()+a.getLength();   //dereference it and store the added value of dereferenced a and b
	return s;  //return by value
}
