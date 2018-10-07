#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long bernstein(string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	for(size_t i = 0;i<str.size();i++){
		b_hash =b_hash*33+str[i];
	}
	return b_hash % M;
}

string reverse(string str)
{
	string output = str;
	//Your code here
	std::reverse(output.begin(),output.end());
	return output;
}

int main()
{
	string s = "POTS";
	int M = 13;
	cout<<"Bernstein hash of "<<s<<" with range "<<M<<" is: "<<bernstein(s, M)<<'\n';
	cout<<"Bernstein hash of the reverse of "<<s<<" - " <<reverse(s)<<" - with range "<<M<<", is: "<<bernstein(reverse(s), M)<<'\n';
}
