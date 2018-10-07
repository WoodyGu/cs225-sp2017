// animal.cpp
#include "animal.h"
#include<string>
#include<iostream>
using namespace std;

animal::animal(){
	name = "cat";
	food = "fish";
}

animal::animal(string newName,string newFood){
	name = newName;
	food = newFood;
}

string animal::getType(){
	return name;
}

string animal::getFood(){
	return this->food;
}

void animal::setType(string newName){
	this->name = newName;
}

void animal::setFood(string newFood){
	this->food = newFood;
}


void animal::print(){
	cout<<"I am a "<<name<<"."<<endl;
}
