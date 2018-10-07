// Your code here
#include <iostream>
#include <string>
#include "food.h"

using namespace std;


void increaseQuantity(food *f){
	int n = f->getQuantity();
	n++;
	f->setQuantity(n);
}

int main(){
food* f = new food;
f->setQuantity(5);
f->setName("apples");
cout<<"You have "<<(*f).getQuantity()<<" "<<f->getName()<<"."<<endl;
increaseQuantity(f);
cout<<"You have "<<(*f).getQuantity()<<" "<<f->getName()<<"."<<endl;
return 0;
}
