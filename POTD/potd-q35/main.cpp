#include <iostream>
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

bool isHeightBalanced(TreeNode* root) {
  if(root == NULL){
    return true;
  }
  else{
    if(getHeightBalance(root)>1){
      return false;
    }
    else{
      return isHeightBalanced(root->left)&&isHeightBalanced(root->right);
    }
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
  TreeNode * n4 = new TreeNode(11);
  n1->left = n2;
  n1->right = n3;
  n2->right = new TreeNode(7);
  n3->left = new TreeNode(10);
  n3->right = new TreeNode(14);
  n3->left->right = n4;
  n4->right = new TreeNode(12);

  cout << "n1.isHeightBalanced() : " << isHeightBalanced(n1) << endl;
  cout << "n2.isHeightBalanced() : " << isHeightBalanced(n2) << endl;
  cout << "n3.isHeightBalanced() : " << isHeightBalanced(n3) << endl;
  cout << "n4.isHeightBalanced() : " << isHeightBalanced(n4) << endl;

  deleteTree(n1);
  return 0;

}
