#include <cmath>
using namespace std;
#include "MinHeap.h"
#include <math.h>
#include <algorithm>

vector<int> lastLevel(MinHeap heap)
{
    // Your code here
    size_t index = 0;
    for(size_t i = 0;i<heap.elements.size();i++){
      if(pow(2,i)>heap.elements.size()-1){
        index = pow(2,i-1);
        break;
      }
    }
    std::vector<int> retval;
    for(size_t j = index;j<heap.elements.size();j++){
      retval.push_back(heap.elements[j]);
    }
    return retval;
}
