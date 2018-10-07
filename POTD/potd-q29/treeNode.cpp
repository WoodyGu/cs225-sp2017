#include "treeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left(NULL), right(NULL) { }

bool TreeNode::isComplete() {
  return isComplete(this);
}

bool TreeNode::isComplete(TreeNode* subRoot){
  if(subRoot == NULL){//not junk code, used to test if the node is NULL
    return true;
  }
  else if(subRoot->left==NULL&&subRoot->right==NULL){//if it is the last node(leaf)
    return true;
  }
  else{//normal condition, not at leaf, somewhere in between
    if(subRoot->left==NULL){
      return false;
    }
    else{
      return isComplete(subRoot->left)&&isComplete(subRoot->right);
    }
  }
}
