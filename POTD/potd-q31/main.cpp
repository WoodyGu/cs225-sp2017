#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool testDict(string s, vector<string> v){
  if(s.size()!=v.size()){//first compare the sizes, if different,just return false
    return false;
  }
  std::map<char,string> dict;//create a dictionary using a std::map
  for(size_t i = 0;i<s.size();i++){//first traverse through the string and vector to create a dictionary
    auto lookup = dict.find(s[i]);//find if the string[i](key) is already in the dictionary
    if(lookup == dict.end()){//if it is still not in, we insert a pair in
      dict.insert({s[i],v[i]});
    }
  }
  for(size_t j = 0;j<s.size();j++){//now traverse the string/vector agian to find if it obey the law
    auto lookup2 = dict.find(s[j]);//first find the string key(must exist!)
    if(v[j]!=lookup2->second){//see if the content in vector is equal to the value in dict
      return false;
    }
  }
  return true;//everything passed, return true
}

bool isSubset(std::vector<int> v1,std::vector<int> v2){

  //size_t count = 0;
  bool found_flag;
  for(size_t i = 0;i<v1.size() - v2.size()+1;i++){
    if (v1[i] == v2[0]) {//must be the first element for v2,
      std::cout<<"matched for index "<<i<<" and value "<<v1[i]<<std::endl;
      found_flag = 1;//"a pattern is found!"
    for(size_t j = 0;j<v2.size();j++,i++){
      if(v1[i] != v2[j]){
        found_flag = 0;//this pattern does not match, we continue finding a new pattern
        break;
      }
    }//if j = size, break and return true!
  }
  }
  if(found_flag){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  string testString = "abba";
  vector<string> testVector;
  testVector.push_back("Cat");
  testVector.push_back("Cat");
  testVector.push_back("Cat");
  testVector.push_back("Cat");

  cout<<"result is "<<testDict(testString,testVector)<<endl;
  std::vector<int> vector1 = {1,2,45,3,6,5,67,9,47,36,6,67};
  std::vector<int> vector2 = {36,6,67};
  cout<<"result for is subset: "<<isSubset(vector1,vector2)<<endl;
}
