#include <iostream>
#include <string>
using namespace std;
#include "square.h"

int main(){
    Square a;
    Square b = a;
    Square c(a);
    cout<<b.getLength()<<endl;
	cout<<c.getLength()<<endl;
	cout<<c.getName()<<endl;
	Square d = a+b;
	cout<<d.getLength()<<endl;
	cout<<d.getName()<<endl;
    return 0;
}
/*We need to overload operator because by default,C++ implements bitwise copying or"=". So if we allow the default '=', the pointer will be pointing
to the same memory address, which is a shallow copy. If we delete the dynamic memory, that part of the copied object will also disappear.
*/
