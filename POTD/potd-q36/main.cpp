#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
string outPut = "Play Overwatch and Gundam Online!!!";
cout<< outPut <<endl;
*/
//problematic!!! you wen ti
bool isPalindromePermutation(string s){
	std::map<char,int> dict;
	//initialize the dictionary
	for(size_t i = 0;i<s.length();i++){
		auto lookup = dict.find(s[i]);
		if(lookup == dict.end()){//not exist yet
			dict.insert({s[i],1});//char s[i] has appeared once
		}
		else{
			lookup->second++;//the char has already appeared
		}
	}
	int oddNumber = 0;
	for(auto lookup2:dict){
		if(lookup2.second%2 == 1){
			oddNumber++;
		}
	}
	return oddNumber<=1;
}


bool isIsomorphic(string s1, string s2){
	if(s1.length()!=s2.length()){
		return false;
	}
	std::map<char,char> dict;
	//initialize the dictionary
	for(size_t i = 0;i<s1.length();i++){
		if(dict.find(s1[i]) == dict.end()){//not exist in the dictionary yet
			dict.insert({s1[i],s2[i]});//insert must need a {}!
		}
	}
	for(size_t i = 0;i<s1.length();i++){
		auto lookup = dict.find(s1[i]);//need a lookup iterator, cannot directly compare
		if(lookup->second != s2[i]){//a single key is maped to more than one value
			return false;
		}
	}
	return true;
}

int main() {
	string a = "ega";
	string b = "add";
	cout<<isIsomorphic(a,b)<<endl;
	/*string c = "qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm";
	cout<<isPalindromePermutation(c)<<endl;
	*/
	return 0;
}
