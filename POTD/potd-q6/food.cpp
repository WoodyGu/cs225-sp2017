// Your code here
#include "food.h"

string food::getName(){
	return this->name;
}
	
int food::getQuantity(){
	return this->quantity;
}

void food::setName(string newName){
	this->name = newName;
}	

void food::setQuantity(int newQuantity){
	this->quantity = newQuantity;
}	
