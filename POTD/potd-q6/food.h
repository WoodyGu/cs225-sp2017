#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <iostream>
using namespace std;

class food{
	public:

		string getName();
		int getQuantity();
		void setName(string newName);
		void setQuantity(int newQuantity);
	private:
		string name;
		int quantity;
}; 
#endif
