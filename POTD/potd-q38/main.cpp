#include <iostream>
#include <stdlib.h>

using namespace std;

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

TreeNode* findLastUnbalanced(TreeNode* root) {
	//your code here
  if(root == NULL){
    return NULL;
  }
  TreeNode* retval = root;
  if(getHeightBalance(root)>1){
    return root;
  }
  retval = findLastUnbalanced(root->left);
  retval = findLastUnbalanced(root->right);
  return retval;
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

  TreeNode * n1 = new TreeNode(4);

  TreeNode * n2 = new TreeNode(7);

  TreeNode * n3 = new TreeNode(11);

  TreeNode * n4 = new TreeNode(13);

  TreeNode * n5 = new TreeNode(14);

  TreeNode * n6 = new TreeNode(22);

  TreeNode * n7 = new TreeNode(2);

  TreeNode * n8 = new TreeNode(24);

  TreeNode * n9 = new TreeNode(27);

  n5->left = n3;

  n5->right = n6;

	n3->right = n4;

  n3->left = n2;

  n2->left = n1;

  n1->left = n7;

  n6->right = n8;

  n8->right = n9;

  cout << "Last Unbalanced Node: " << (findLastUnbalanced(n5))->val << endl;

  deleteTree(n5);

  return 0;

}
