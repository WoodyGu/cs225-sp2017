#include "Queue.h"
#include<iostream>
using namespace std;
//constructor
Queue::Queue(){
  entry = NULL;
  exit = NULL;
  length = 0;
}
// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return length;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  return length == 0;
}

// `void enqueue()`- puts an item to the queue in O(1) time
void Queue::enqueue(int value) {
  queueNode* temp = new queueNode;
  temp->data = value;
  if(entry==NULL||exit==NULL){
    entry = temp;
    exit = temp;
    length++;
    return;
  }
  entry->next = temp;
  temp->next = NULL;
  entry = temp;
  length++;
}

int Queue::front(){
  return exit->data;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  queueNode* temp = exit;
  int retval = exit->data;
  exit = exit->next;
  delete temp;
  length--;
  return retval;
}
