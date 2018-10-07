#include "functions.h"
#include <iostream>
using namespace std;
void mystery(){
    // There are a number of functions defined in "functions.h" and
    // implemented in "functions.cpp". Your job is to call those
    // functions with the correct arguments so that the Alma Mater lyrics
    // are printed when this function is called.

    // If you're successful, this is the output you'll see:

    // Hail to the Orange.
    // Hail to the Blue.
    // Hail Alma Mater,
    // Ever so true.
    // We love no other,
    // So let our motto be
    // Victory, Illinois, Varsity.

    // Your code here!
    function1(1);
    function2(64);
    function3(2,2);
    function4("11111111c++");
    function5(0);
    int* ptr = new int[3];
    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 5;
    //cout<<2[ptr]<<endl;
    function6(ptr);
}
