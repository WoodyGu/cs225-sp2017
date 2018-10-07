/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>

using std::map;

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{
    /* Your code goes here! */
    if(n == 0){
      return 0;
    }
    if(n==1){
      return 1;
    }
    else{
      return fib(n-1)+fib(n-2);
    }
}

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n)
{
    /* Your code goes here! */
    static map<unsigned long, unsigned long> memo = {{0, 0},{1,1}};//the "static" is very important
    auto lookup = memo.find(n);//n is the key and the result of fib number is ->second
    if (lookup != memo.end()) {//if find the value(already calc it before, we return)
      return lookup->second;//we have already calculated the value, so we just return
    }
    else {
      unsigned long result = memoized_fib(n - 2) + memoized_fib(n - 1);//recursively calculate the result
      memo[n] = result;//save the result in the map
      return result;
    }
}
