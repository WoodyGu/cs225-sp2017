#include <map>
#include <iostream>
using namespace std;

int fibonacci(int n) {
  static std::map<unsigned long, unsigned long> memo = {{0,1},{1,1}};
  auto lookup = memo.find(n);
  if(lookup != memo.end()){
    return lookup->second;
  }
  else{
    unsigned long result = fibonacci(n-1)+fibonacci(n-2);
    memo[n] = result;
    return result;
  }
}

 int main() {
   cout<<"fibonacci(1000) = "<<fibonacci(1000)<<endl;
   cout<<"fibonacci(10000) = "<<fibonacci(10000)<<endl;
   return 0;
 }
