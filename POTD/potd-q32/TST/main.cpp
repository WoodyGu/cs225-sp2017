#include "TST.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
  TST testTree;
  testTree.insert("as");
  testTree.insert("at");
  testTree.insert("by");
  testTree.insert("mix");
  testTree.insert("mum");
  testTree.insert("tag");
  testTree.insert("tab");

  cout<<testTree.find1("mix")<<endl;
  cout<<testTree.find2("tag")<<endl;

  return 0;
}
