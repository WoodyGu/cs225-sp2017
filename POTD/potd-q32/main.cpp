bool TST::find1(const string& query){
  vector<string> v;
  string result = "";
  return findHelper(query, root, result,v);
}

bool TST::findHelper(const string& query, TSTNode* curr, string result, vector<string> v){
  if(curr == NULL){
    return false;
  }
  if(curr->left == NULL&& curr->mid == NULL&&curr->right == NULL){
    result = result+curr->c;
    v.push_back(result);
    for(auto x:v){
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
}

bool TST::find2(TSTNode* curr, const string query, int index){
  if(curr == NULL){
    return false;
  }
  if(word[index]>curr->val){
    return find(curr->left,query,index);
  }
  else if(word[index]>curr->val){
    return find(curr->right,query,index);
  }
  else{
    if(index+1 == word.size()){
      return curr->endStr;
    }
    else{
      return find(curr->mid,word,index+1);
    }
  }
}
