#include <iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int sum(TreeNode* subRoot){
  if(subRoot==NULL){
    return 0;
  }
  else {
    return subRoot->val + sum(subRoot->right)+sum(subRoot->left);
  }
}

TreeNode*& rightMostChild(TreeNode* &root){
  if(root->right == NULL){
    return root;
  }
  else{
    return rightMostChild(root->right);
  }
}

void oneChildRemove(TreeNode* &croot){
  if(croot->left == NULL){
    croot = croot->right;
  }
  else{
    croot = croot->left;
  }
}

void noChildRemove(TreeNode* &croot){
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

void insert(TreeNode* &croot,int key){
  if(croot == NULL){
    TreeNode n_new;
    n_new.val = key;
    croot = &n_new;
  }
  else if(croot->val==key){
    //nothing!!
  }
  else if(croot->val>key){
    insert(croot->left,key);//since key is smaller than the root, it should go to left subtree
  }
  else{
    insert(croot->right,key);//since key is larger than root, key should go to right subtree
  }
}

TreeNode* find(TreeNode* croot,int key){
  if(croot == NULL){
    return NULL;
  }
  if(croot->val == key){
    return croot;
  }
  if(croot->val<key){//the value of this root is smaller than key, we should go right to find large value
    return find(croot->right,key);
  }
  else{
    return find(croot->left,key);
  }
}
/*
TreeNode* copy(TreeNode* croot){//pre-order traversal
  if(croot!=NULL){
     t = new TreeNode(croot->data);
     t->left = copy(croot->left);
     t->right = copy(croot->right);
  }
  return t;
}
*/

int main() {
/*
 * Example:
 * key = 3
 *   5
 *  / \
 * 3   6
 * /\   \
 *2 4    7
 *
 * After delete 3:
 * (One valid answer, IoS)
 *      5
 *     / \
 *    4   6
 *   /     \
 *  2       7
 *
 * (Another valid answer, IoP)
 *       5
 *      / \
 *     2   6
 *      \   \
 *       4   7
 */

  TreeNode n_0, n_1, n_2, n_3, n_4, n_5;
  n_0.val = 5;
  n_1.val = 3;
  n_2.val = 6;
  n_3.val = 2;
  n_4.val = 4;
  n_5.val = 7;

  n_0.left = &n_1;
  n_0.right = &n_2;
  n_1.left = &n_3;
  n_1.right = &n_4;
  n_2.left = NULL;
  n_2.right = &n_5;
  n_3.left = NULL;
  n_3.right = NULL;
  n_4.left = NULL;
  n_4.right = NULL;
  n_5.left = NULL;
  n_5.right = NULL;

  cout << "Before removal: " << endl;
  inorderPrint(&n_0);
  TreeNode * test = &n_0;
  cout<<endl;
  //cout<<sum(&n_0)<<endl;
  TreeNode* ans = deleteNode(test, 7);
  cout << "After removal: " << endl;
  inorderPrint(ans);
  cout << endl;
  cout << "After insert: " << endl;
  insert(test,8);
  inorderPrint(&n_0);
  cout<<endl;
  //cout<<sum(&n_0)<<endl;
  return 0;

}
