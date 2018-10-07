#include "treeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left(NULL), right(NULL) { }

bool TreeNode::isPerfect() {
  return isPerfect(this);
}

bool TreeNode::isPerfect(TreeNode* subRoot){
  if(subRoot == NULL){
    return true;
  }
  if((subRoot->left!=NULL&&subRoot->right!=NULL)||(subRoot->left==NULL&&subRoot->right==NULL)){
    return isPerfect(subRoot->left)&&isPerfect(subRoot->right);
  }
  else{
    return false;
  }
}
