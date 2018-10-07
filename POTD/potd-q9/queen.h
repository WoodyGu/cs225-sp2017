#ifndef _QUEEN_H
#define _QUEEN_H
#include "piece.h"
#include <iostream>
using namespace std;
class queen: public piece {
	public:
	queen(){cout<<"Queen constructed"<<endl;}
	void printType();
	~queen(){cout<<"Queen destructor"<<endl;}
};

#endif
