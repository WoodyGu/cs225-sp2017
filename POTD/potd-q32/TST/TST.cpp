#include "TST.h"

void TST::insert(string word)
{
  root = put(root, word, 0);
}

TST::TSTNode* TST::put(TSTNode *node, const string &str, size_t index){
  if(node == NULL){
      node = new TSTNode(str[index]);
  }
  if(node->c > str[index])
      node->left = put(node->left, str, index);
  else if(node->c < str[index])
      node->right = put(node->right, str, index);
  else if(index < str.size()-1){
      node->mid = put(node->mid, str, index+1);
  }else{
      node->is_end = true;
  }
  return node;
}


bool TST::find1(const string& query){
  vector<string> v;//empty vector
  string result = "";//empty string
  return findHelper(query, root, result,v);
}

bool TST::findHelper(const string& query, TSTNode* curr, string result, vector<string> v){
  if(curr == NULL){
    return false;
  }
  if(curr->left == NULL&&curr->right == NULL&&curr->mid == NULL){
    result = result+curr->c;
    v.push_back(result);
    for(size_t i = 0;i<v.size();i++){
      if(v[i] == query){
        return true;
      }
    }
  }
  if(curr->mid == NULL){
    v.push_back(result+curr->c);
    return findHelper(query,curr->left,result,v)||findHelper(query,curr->right,result,v);
  }
  else{
    return findHelper(query,curr->left,result,v)||findHelper(query,curr->right,result,v)||findHelper(query,curr->mid,result+curr->c,v);
  }

  /*
  if(curr == NULL){
    return false;
  }
  if(curr->left == NULL&& curr->mid == NULL&&curr->right == NULL){//if we reach the leaf of the tree
    result = result+curr->c;
    v.push_back(result);
    for(auto x:v){//check if the vector of string contains the query string
      if(x == query){
        return true;
      }
    }
  }
  if(curr->mid == NULL){
    v.push_back(result+curr->c);
    return findHelper(query,curr->left,result,v)||findHelper(query,curr->right,result,v);
  }
  else{
    return findHelper(query,curr->left,result,v)||findHelper(query,curr->right,result,v)||findHelper(query,curr->mid,result+curr->c,v);
  }
  */
}

/*
bool TST::find2(TSTNode* curr, const string query, int index){
  if(curr == NULL){
    return false;
  }
  if(query[index]>curr->c){
    return find2(curr->left,query,index);
  }
  else if(query[index]>curr->c){
    return find2(curr->right,query,index);
  }
  else{
    if(index+1 == query.size()){
      return true;
    }
    else{
      return find2(curr->mid,query,index+1);
    }
  }
}
*/

bool TST::find2(const string& query){
  return find2Helper(root,query,0);
}

bool TST::find2Helper(TSTNode* curr, const string& query, size_t index)
{
  if(curr == NULL){
    return false;
  }
  if(curr->c>query[index]){
    return find2Helper(curr->left,query,index);
  }
  else if(curr->c<query[index]){
    return find2Helper(curr->right,query,index);
  }
  else{
    if(query[index+1] == NULL){
      return curr->is_end;
    }
    else{
      return find2Helper(curr->mid,query,index+1);
    }
  }
}
