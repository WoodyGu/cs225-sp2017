#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
	length = 0;
	cout<<"size of the stack is"<<length<<endl;
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return length;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  return length == 0;
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
	stackNode* newNode = new stackNode;
	newNode->data = value;
	newNode->next = top;
	top = newNode;
	length++;
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  stackNode* temp = top;
  int retval = temp->data;
  top = top->next;
  delete temp;
  length--;
  return retval;
}
