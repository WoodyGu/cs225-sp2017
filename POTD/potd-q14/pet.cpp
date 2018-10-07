// pet.cpp
#include "pet.h"
#include<iostream>
using namespace std;

pet::pet():animal(){
	name = "Fluffy";
	owner_name = "Cinda";
}

pet::pet(string newType,string newFood,string newName,string newOwner):animal(newType,newFood){
	name = newName;
	owner_name = newOwner;
}

string pet::getName(){
	return name;
}

string pet::getOwnerName(){
	return owner_name;
}

void pet::setName(string newName){
	name = newName;
}

void pet::setOwnerName(string newOwner){
	owner_name = newOwner;
}

void pet::print(){
	cout<<"My name is "<<name<<"."<<endl;
}
