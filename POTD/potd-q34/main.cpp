#include <iostream>
#include <algorithm>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
      left = NULL;
      right = NULL;
      val = x;
    }
};

int getHeight(TreeNode* subRoot){
  if(subRoot==NULL){
    return -1;
  }
  else{
    return 1 + max(getHeight(subRoot->left),getHeight(subRoot->right));
  }
}

int getHeightBalance(TreeNode* root) {
  // your code here
  if(root == NULL){
    return 0;
  }
  else{
    return abs(getHeight(root->left)-getHeight(root->right));
  }
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
  root = NULL;
}


int main() {

  TreeNode * n1 = new TreeNode(8);
  TreeNode * n2 = new TreeNode(5);
  TreeNode * n3 = new TreeNode(13);
  TreeNode * n4 = new TreeNode(10);
  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = new TreeNode(14);
  n4->right = new TreeNode(11);
  n4->right->right = new TreeNode(12);

  cout << "Height balance of n1: " << getHeightBalance(n1) << endl;
  cout << "Height balance of n2: " << getHeightBalance(n2) << endl;
  cout << "Height balance of n3: " << getHeightBalance(n3) << endl;
  cout << "Height balance of n4: " << getHeightBalance(n4) << endl;

  deleteTree(n1);
  return 0;

}
