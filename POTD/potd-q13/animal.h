// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H
#include<string>
#include<iostream>
using namespace std;

class animal{
	public:
		animal();
		animal(string newName,string newFood);
		string getType();
		void setType(string name);
		string getFood();
		void setFood(string food);
		virtual void print();
	private:
		string name;
	protected:
		string food;
};
#endif
		
