#include <iostream>
#include "treeNode.h"
using namespace std;

int main() {
  TreeNode n1, n2, n3, n4, n5, n6, n7, n8;

  n1.data = 1;
  n2.data = 2;
  n3.data = 3;
  n4.data = 2;
  n5.data = 5;
  n6.data = 6;
  n7.data = 2;
  n8.data = 8;
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.right = &n6;
  n5.left = &n7;
  n5.right = &n8;

  /*cout<<"preOrder: ";
  n1.preOrder(&n1);
  cout<<"inOrder: ";
  n1.inOrder(&n1);*/
  /*int value = n1.postOrder(&n1);
  cout<<"postOrder: ";
  cout<<value<<endl;
  */
  /*cout<<"Height of n1: "<<n1.getHeight()<<endl;
  cout<<"Height of n2: "<<n2.getHeight()<<endl;
  cout<<"Height of n3: "<<n3.getHeight()<<endl;
  cout<<"Height of n4: "<<n4.getHeight()<<endl;
  */
  int minHeight = n1.minHeight(&n1);
  cout<<minHeight<<endl;
  int occurance = n1.countOccurance(&n1,2);
  cout<<occurance<<endl;
  return 0;
}
