#include <iostream>
#include "chara.h"
using namespace std;


int main() {
   Chara cs225;
   cs225.addToQueue("a");
   cs225.addToQueue("b");
   cs225.addToQueue("c");
   cs225.addToQueue("d");
   cs225.addToQueue("e");
   cs225.addToQueue("f");
   cs225.addToQueue("g");
   string condition = cs225.getStatus();
   cout<<"Condition for CS 225 office hour is: "<<condition<<endl;
   string gone1 = cs225.popFromQueue();
   string gone2 = cs225.popFromQueue();
   string gone3 = cs225.popFromQueue();
   string gone4 = cs225.popFromQueue();
   string gone5 = cs225.popFromQueue();
   condition = cs225.getStatus();
   cout<<"Condition for CS 225 office hour is: "<<condition<<endl;
  return 0;
}
