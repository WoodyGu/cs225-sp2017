#ifndef _FOOD_H
#define _FOOD_H

#include <iostream>
#include <string>
using namespace std;

class Food {
  private:
    string name;
    int quantity;
  public:
    Food();
    void setName(string newName);
    void setQuantity(int newQuantity);
    string getName();
    int getQuantity() const;
	bool operator>(Food b);
};

#endif
