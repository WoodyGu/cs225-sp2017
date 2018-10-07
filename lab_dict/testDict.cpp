#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool testDict(string s, vector<string> v){
  if(s.size()!=v.size()){
    return false;
  }
  std::map<char,string> dict;
  for(size_t i = 0;i<s.size();i++){
    auto lookup = dict.find(s[i]);
    if(lookup == dict.end(){
      dict.insert({s[i],v[i]});
    }
  }
  for(size_t j = 0;j<s.size();j++){
    aut0 lookup2 = dict.find(s[j]);
    if(v[i]!=lookup2->second){
      return false;
    }
  }
  return true;
}

int main(){
  string testString = "abba";
  vector<string> testVector;
  testVector.push_back("Dog");
  testVector.push_back("Cat");
  testVector.push_back("Cat");
  testVector.push_back("Dog");
  cout<<"result is "<<testDict(testString,testVector)<<endl;
}
