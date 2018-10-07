#ifndef _CHARA_H
#define _CHARA_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;
using std::queue;

class Chara {
public:
  string getStatus();
  void addToQueue(string name);
  string popFromQueue();
private:
  queue <string> q;
};

#endif
