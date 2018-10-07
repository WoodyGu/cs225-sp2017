#ifndef _PIECE_H
#define _PIECE_H
#include <iostream>
using namespace std;
class piece {
	public:
	piece(){cout<<"Unknown piece constructed"<<endl;}
	void printType();
 	virtual ~piece(){cout<<"Piece destructor"<<endl;}
};

#endif
