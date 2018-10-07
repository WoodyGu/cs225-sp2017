#ifndef _STACK_H
#define _STACK_H

class Stack {
public:
	Stack();
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
private:
	struct stackNode{
		int data;
		stackNode* next;
	};
	stackNode* top;
	int length;
};

#endif
