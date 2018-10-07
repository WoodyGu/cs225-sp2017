#include <iostream>
using namespace std;

#include "queue.h"

int main() {
  Queue q;
  int r;

  cout<<"enqueue(1) to the queue..."<<endl;
  q.enqueue(1);
  cout<<"Stack size: "<<q.size()<<endl;

  cout<<"enqueue(2) to the queue..."<<endl;
  q.enqueue(2);
  cout<<"Stack size: "<<q.size()<<endl;

  cout<<"enqueue(3) to the queue..."<<endl;
  q.enqueue(3);
  cout<<"Stack size: "<<q.size()<<endl;

  cout<<"enqueue(4) to the queue..."<<endl;
  q.enqueue(4);
  cout<<"Stack size: "<<q.size()<<endl;

  cout<<"enqueue(5) to the queue..."<<endl;
  q.enqueue(5);
  cout<<"Stack size: "<<q.size()<<endl;

  cout<<"enqueue(6) to the queue..."<<endl;
  q.enqueue(6);
  cout<<"Stack size: "<<q.size()<<endl;

  for(int i = 1;i<7;i++){
    if(i>0){
      q.enqueue(q.front());
      int temp = q.dequeue();
    }
  }

  int a = q.dequeue();
  int b = q.dequeue();
  int c = q.dequeue();
  int d = q.dequeue();
  int e = q.dequeue();
  int f = q.dequeue();

  cout<<a<<b<<c<<d<<e<<f<<endl;

  /*cout<<"dequeue()"<<endl;
  r = q.dequeue();
  cout<<"Returned Value: "<<r<<", Queue size: "<<q.size()<<endl;

  cout<<"dequeue()"<<endl;
  r = q.dequeue();
  cout<<"Returned Value: "<<r<<", Queue size: "<<q.size()<<endl;

  cout<<"dequeue()"<<endl;
  r = q.dequeue();
  cout<<"Returned Value: "<<r<<", Queue size: "<<q.size()<<endl;
*/
  return 0;
}
