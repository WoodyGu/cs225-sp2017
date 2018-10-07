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

TreeNode*& rightMostChild(TreeNode* &root){
  if(root->right == NULL){
    return root;
  }
  else{
    return rightMostChild(root->right);
  }
}

void oneChildRemove(TreeNode* &croot){
  TreeNode* temp = croot;
  if(croot->left == NULL){
    croot = croot->right;
  }
  else{
    croot = croot->left;
  }
  delete temp;
}

void noChildRemove(TreeNode* &croot){
  delete croot;
  croot = NULL;
}

void twoChildRemove(TreeNode* &croot){
  TreeNode*& iop = rightMostChild(croot->left);
  croot->val = iop->val;
  noChildRemove(iop);
}

void doRemoval(TreeNode* &croot){
  if(croot->left == NULL&&croot->right == NULL){
    noChildRemove(croot);
  }
  else if(croot->left!=NULL&&croot->right!=NULL){
    twoChildRemove(croot);
  }
  else{
    oneChildRemove(croot);
  }
}

TreeNode* deleteNode(TreeNode*& root, int key) {
  // your code here
  if(root ==NULL){
    return NULL;
  }
  if(key == root->val){
    doRemoval(root);
  }
  else if(key<root->val){
    deleteNode(root->left,key);
  }
  else{
    deleteNode(root->right,key);
  }
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left);
    cout << node->val << " ";
    inorderPrint(node->right);
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
/*
 * Example 1: Deleting a leaf node
 * key = 14
 *     9
 *    / \
 *   5   12
 *  /\   / \
 * 2  7 10 14
 *
 * After deleteNode(14):
 *      9
 *     / \
 *    5   12
 *   /\  /
 *  2  7 10
 *
 * Example 2: Deleting a node which has only
 * one child.
 *       9
 *      / \
 *     5   12
 *    / \  /
 *   2   7 10
 *
 * After deleteNode(12):
 *       9
 *      / \
 *     5   10
 *    / \
 *   2   7
 *
 * Example 3: Deleting a node with 2 children
 * After deleteNode(5):
 * Method 1 (IOS)
 *       9
 *      / \
 *     7   10
 *    /
 *   2
 *
 * Method 2 (IOP)
 *       9
 *      / \
 *     2   10
 *      \
 *       7
 */

  TreeNode * root = new TreeNode(9);
  root->left = new TreeNode(5);
  root->right = new TreeNode(12);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(14);

  cout << "Before deleting a leaf: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 14);
  cout << "After deleting a leaf: " << endl;
  inorderPrint(root);
  cout << endl;

  cout << "Before deleting a node with 1 child: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 12);
  cout << "After deleting a node with 1 child: " << endl;
  inorderPrint(root);
  cout << endl;

  cout << "Before deleting a node with 2 child: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 5);
  cout << "After deleting a node with 2 child: " << endl;
  inorderPrint(root);
  cout << endl;

  deleteTree(root);
  return 0;

}
