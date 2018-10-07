#ifndef _TREENODE_H
#define _TREENODE_H

#include <cstddef>
#include <math.h>
#include <iostream>
using namespace std;

class TreeNode {
public:
  TreeNode *left;
  TreeNode *right;
  int data;
  TreeNode();
  int getHeight();
  int getHeight(TreeNode* subRoot);
  void preOrder(TreeNode* subRoot);
  void inOrder(TreeNode* subRoot);
  int postOrder(TreeNode* subRoot);
  int minHeight(TreeNode* subRoot);
  int countOccurance(TreeNode* subRoot, int elem);
};

#endif
