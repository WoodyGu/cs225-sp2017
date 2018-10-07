#include <iostream>
#include "circle.h"

using namespace std;

// Include the following line in pass_by_value:
//   cout<<"In pass_by_value, the memory address of c is: "<<(&c)<<endl;

// Include the following line in pass_by_pointer:
//   cout<<"In pass_by_pointer, the memory address of c is: "<<(c)<<endl;

// Include the following line in pass_by_ref:
//   cout<<"In pass_by_ref, the memory address of c is: "<<(&c)<<endl;

void pass_by_value(circle C){
	cout<<"In pass_by_value, the memory address of c is: "<<(&C)<<endl;
}

void pass_by_pointer(circle* ptr){
	cout<<"In pass_by_pointer, the memory address of c is: "<<(ptr)<<endl;
}

void pass_by_ref(circle& C){
	cout<<"In pass_by_ref, the memory address of c is: "<<(&C)<<endl;
}
	

int main() {
  circle c;
  c.setRadius(5);

  circle *ptr = &c;

  cout<<"In main, the memory address of c is: "<<(&c)<<endl;

  pass_by_value(c);
  pass_by_pointer(ptr);
  pass_by_ref(c);

  return 0;
}

