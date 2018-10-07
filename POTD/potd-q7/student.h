// Your code here! :)
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class student{
	public:
		void setName(string newName);
		void setGrade(int newGrade);
		string getName();
		int getGrade();
	private:
		string name;
		int grade;
};
#endif
