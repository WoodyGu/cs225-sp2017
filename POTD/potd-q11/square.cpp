// square.cpp
#include"square.h"

square::square(){
	name = "mysquare";
	length = new double;
	*length=2.0;
}

square::square(const square & other){
	name = other.name;
	length = new double;
	*(length) = *(other.length);
	cout<<"I am copying!"<<endl;
}

square::~square(){
	delete length;
}

void square::setName(string newName){
	name = newName;
}
