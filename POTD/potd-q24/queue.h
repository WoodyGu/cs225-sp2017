#ifndef _QUEUE_H
#define _QUEUE_H

class Queue {
public:
  Queue();
  int size() const;
  bool isEmpty() const;
  void enqueue(int value);
  int dequeue();
  int front();
private:
  struct queueNode{
      int data;
      queueNode* next;
  };
  queueNode* entry;
  queueNode* exit;
  int length;
};

#endif
