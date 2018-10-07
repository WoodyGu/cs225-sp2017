#include "heap.h"
#include <vector>
#include <iostream>
using namespace std;

int main(){
  std::vector<int> v = {5,6,3,8,4,3};
  heap test(v);
  test.printHeap();
  return 0;
}
