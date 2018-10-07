// Your code here! :)
#include "student.h"

void graduate(student& s){
	int a = s.getGrade();
	a++;
	s.setGrade(a);
}

int main(){
	student sally;
	sally.setGrade(5);
	sally.setName("Sally");
	cout<<sally.getName()<<" "<<"is in grade "<<sally.getGrade()<<"."<<endl;
	graduate(sally);
	cout<<sally.getName()<<" "<<"is in grade "<<sally.getGrade()<<"."<<endl;
	return 0;
}
