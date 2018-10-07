// pet.h
#ifndef PET_H
#define PET_H
#include "animal.h"
#include <string>
#include<iostream>
using namespace std;

class pet:public animal{
	private:
	string name;
	string owner_name;
	public:
	pet();
	pet(string newType,string newFood,string newName,string newOwner);
	string getName();
	string getOwnerName();
	string getFood();
	void setName(string newName);
	void setOwnerName(string newOwner);
	void setFood(string newFood);
	void print();
};
#endif
