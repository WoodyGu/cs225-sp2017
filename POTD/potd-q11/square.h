// square.h
#ifndef SQUARE_H
#define SQUARE_H
#include<string>
#include<iostream>
using namespace std;

class square{
	public:
	square();
	square(const square & other);
	~square();
	void setName(string name);
	private:
	double* length;
	string name;
};
#endif
