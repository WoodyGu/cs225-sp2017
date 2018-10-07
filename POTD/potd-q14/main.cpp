// main.cpp
#include "animal.h"
#include "pet.h"
#include<string>
#include<iostream>
using namespace std;

int main(){
	animal* a = new animal;
	a->print();
	pet *b = new pet;
	b->setName("Garfield");
	a = b;
	a->print();
	delete a;
	delete b;
	return 0;
}
	
	
	
