#include <iostream>
#include <math.h>
using namespace std;

//
// Write the function `raise` that accepts an array of integers and
// an integer as the input parameters.
//
int* raise(int* array,int arrLength){
	int* newArray = new int[arrLength];
	for(int i = 0; i<arrLength-2;i++){
		newArray[i] = pow(array[i],array[i+1]);
	}
	newArray[arrLength-2] = array[arrLength-2];
	newArray[arrLength-1] = array[arrLength-1];
	return newArray;
}

int main() {
  int arr_in[5] = { 1, 2, 3, 4, -1 };
  int *arr_out = raise(arr_in, 5);
  for(int i = 0;i<4;i++){
  	cout<<arr_out[i]<<", ";
  }
  cout<<arr_out[4]<<endl;
  return 0;
}
