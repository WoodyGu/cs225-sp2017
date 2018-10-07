#include <iostream>
using namespace std;

#include "queen.h"
#include "piece.h"

void printPiece(queen* p) {
  //cout<<"In printPiece, printType() of the same memory address is:"<<endl;
  p->printType();
}

int main() {
  /*
  queen *q = new queen();

  cout<<"In main, printType() of queen *q is:"<<endl;
  q->printType();

  printPiece(q);

  delete q;  // Don't forget to free your memory! :)
  */

  queen q;//large limit
  piece p;//small limit
  queen* q2 = new queen();
  printPiece(&q);//will print piece, this means queen is sliced to piece
  //p = &q;
  //p->printType();
  /*
  piece* P = new queen();
  delete P;
  */
  return 0;
}
