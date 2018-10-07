

struct tsTree{
  void insert;
  bool find;
  void traverseHelper
  struct treeNode{
    TreeNode(char data){
    char val;
    treeNode* left;
    treeNode* mid;
    treeNode* right;
    bool endStr;
    };
  }
  treeNode* root;
}

void insert(treeNode* croot, string word, int index){
  if(croot == NULL){//if the root is NULL, we dynamically allocate like BST
    croot = new TreeNode(word[index]);
  }
  if(word[index]<croot->val){//go left
    insert(croot->left,word,index);
  }
  else if(word[index]>croot->val){//go right
    insert(croot->right,word,index);
  }
  else{
    if(index+1 < word.size()){//it is not the last char in the string, continue go to mid
      insert(croot->mid,word,index+1);
    }
    else{
      croot->endStr = 1;
    }
  }
}

bool find(treeNode* croot, string word,int index){
  if(croot == NULL){
    return false;
  }
  if(word[index]<croot->val){
    return find(croot->left,word,index);
  }
  else if(word[index]>croot->val){
    return find(croot->right,word,index);
  }
  else{
    if(index+1 == word.size()){//it is the last char but we still not find it
      return croot->endStr;
    }
    else{
      return find(croot->mid,word,index+1);
    }
  }
}

void traverseHelper(treeNode* croot, string s,int depth){
  if(croot!=NULL){
    traverseHelper(croot->left,s,depth);
    s.append(croot->val);
    if(croot->endStr){//if we reach the end of the string, we are done, set endstr char and print it
      s[depth+1] = NULL;
      cout<<s<<endl;
    }
    traverseHelper(croot->mid,s,depth+1);
    traverseHelper(croot->right,s,depth);
  }
}

void traverse(treeNode* root){
  traverseHelper(root,"",0);
}
