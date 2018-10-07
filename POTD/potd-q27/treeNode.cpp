#include "treeNode.h"

#include <cstddef>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

TreeNode::TreeNode() : left(NULL), right(NULL),data(0) { }

int TreeNode::getHeight() {
  return getHeight(this);
}

int TreeNode::getHeight(TreeNode* subRoot){

  if(subRoot==NULL){
    return -1;
  }
  return 1+ max(getHeight(subRoot->left),getHeight(subRoot->right));
}

void TreeNode::preOrder(TreeNode* subRoot){
  if(subRoot!=NULL){
    cout<<subRoot->data<<" ";
    preOrder(subRoot->left);
    //cout<<"reached preOrder"<<endl;
    preOrder(subRoot->right);
  }
}

void TreeNode::inOrder(TreeNode* subRoot){
  if(subRoot!=NULL){
    inOrder(subRoot->left);
    cout<<subRoot->data<<" ";
    inOrder(subRoot->right);
  }
}

int TreeNode::postOrder(TreeNode* subRoot){
  if(subRoot!=NULL){
    int ret1 = postOrder(subRoot->left);
    int ret2 = postOrder(subRoot->right);
    return 1 + ret1 + ret2;
  }
  return 0;
}

int TreeNode::minHeight(TreeNode* subRoot){
  if(subRoot == NULL){
    return -1;
  }
  else{
    return 1 + min(getHeight(subRoot->left),getHeight(subRoot->right));
  }
}

int TreeNode::countOccurance(TreeNode* subRoot, int elem){
  if(subRoot == NULL){
    return 0;
  }
  else if(subRoot->data == elem){
    return 1 + countOccurance(subRoot->left,elem) + countOccurance(subRoot->right,elem);
  }
  else{
    return countOccurance(subRoot->left,elem) + countOccurance(subRoot->right,elem);
  }
}
