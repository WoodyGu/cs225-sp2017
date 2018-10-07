// Your code here! :)
#include "student.h"

string student::getName(){
	return name;
}

int student::getGrade(){
	return grade;
}

void student::setName(string newName){
	this->name = newName;
}

void student::setGrade(int newGrade){
	this->grade = newGrade;
}
