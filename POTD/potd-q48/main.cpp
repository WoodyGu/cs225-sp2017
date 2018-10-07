#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
using namespace std;



bool wordPattern(string pattern, string str) {
    //write your code here
    std::vector<string> v;
    string temp = "";
    //map the long string into a vector of short strings
    for(size_t i = 0;i<str.size();i++){
      if(str[i] == 0x20){
        v.push_back(temp);
        temp = "";
      }
      else{
        temp = temp+str[i];
      }
      if(i == str.size()-1){
        v.push_back(temp);
      }
    }
    if(pattern.size()!=v.size()){
      return false;
    }
    std::map<char,string> dict;
    //map the pattern and vector into a dictionary
    for(size_t j = 0;j<pattern.size();j++){
      auto lookup = dict.find(str[j]);
      if(lookup == dict.end()){
        dict.insert({pattern[j],v[j]});
      }
    }
    /*
    //check if we have keys with same value
    for(size_t key = 0;key<dict.size();key++){
      for(size_t key2 = key+1;key2<dict.size();key2++){
        if(dict[key] == dict[key2]){
          return false;//different key with same value!
        }
      }
    }
    */
    //check of all the entries in dictionary maps the string: same key,same value
    for(size_t k = 0;k<pattern.size();k++){
      auto lookup2 = dict.find(pattern[k]);
      if(lookup2->second!=v[k]){
        return false;
      }
    }
    return true;
}

int main(){

string s1= "dog cat cat cat cat cat cat cat dog";
string p1 = "abbbbbbba";
string s2 = "fish dog dog dog dog dog dog cat";
string p2 = "abbbbbba";

cout << " The pattern p1 matches string s1 " << wordPattern(p1,s1)<< endl;
cout << " The pattern p2 matches string s2 " << wordPattern(p2,s2)<< endl;
/*
string pattern1 = "abba";
string str1 = "dog cat cat dog";
string pattern2 = "abba";
string str2= "dog cat cat fish";
string pattern3 = "aaaa";
string str3 = "dog cat cat dog";
string pattern4 = "abba";
string str4 = "dog dog dog dog";

cout<< wordPattern(pattern1,str1)<< endl;
cout<< wordPattern(pattern2,str2)<< endl;
cout<< wordPattern(pattern3,str3)<< endl;
cout<< wordPattern(pattern4,str4)<< endl;
*/




return 0;

}
