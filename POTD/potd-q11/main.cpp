#include <iostream>
using namespace std;

#include "square.h"
void modify(square s,string newName){
	s.setName(newName);
}

int main() {
	square a;
	square b(a);
	modify(a,"good");
  return 0;
}
