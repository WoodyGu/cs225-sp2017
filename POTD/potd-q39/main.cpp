#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) {
      left = NULL;
      right = NULL;
      parent = NULL;
      val = x;
    }
};
/*
int getHeight(TreeNode* subRoot){
  if(subRoot==NULL){
    return -1;
  }
  else{
    return 1 + max(getHeight(subRoot->left),getHeight(subRoot->right));
  }
}


int distance(TreeNode* subRoot,int key){
  if(subRoot == NULL){
      return -1;
  }
  if(subRoot->val == key){
    return 0;
  }
  else if(subRoot->val>key){
    return 1 + distance(subRoot->left,key);
  }
  else{
    return 1 + distance(subRoot->right,key);
  }
}

vector<vector<int>> printFromButtom(TreeNode* root) {//level order traversal
  // your code here
  vector<vector<int>> v(getHeight(root)+1,std::vector<int>());
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    TreeNode* t = q.front();
    q.pop();
    if(t!=NULL){
      int key = t->val;
      int dist = distance(root,key);//need to find the distance from tree root
      v[dist].push_back(t->val);
      q.push(t->left);
      q.push(t->right);
    }
  }
  std::reverse(v.begin(), v.end());
  return v;
}

void printAns(vector<vector<int>> v) {
  cout << "[" << endl;
  for(size_t i = 0; i<v.size(); i++) {
    cout << "[";
    for(size_t j = 0; j<v[i].size(); j++) {
      cout << v[i][j];
      if(j < v[i].size()-1) {
        cout << ", ";
      }
    }
    cout << "]," << endl;
  }
  cout << "]" << endl;
}
*/
void rightRotate(TreeNode*& root) {
  // Your Code Here
    if(root!=NULL&&root->left!=NULL){
      TreeNode* temp = root->left;
      root->left = temp->right;
      temp->right = root;
      temp->parent = root->parent;
      root->parent = temp;
    }
}


void leftRotate(TreeNode*& root) {
  // your code here
  if(root!=NULL&&root->right!=NULL){
    TreeNode* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    temp->parent = root->parent;
    root->parent = temp;
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
  TreeNode * n1 = new TreeNode(2);
  TreeNode * n2 = new TreeNode(5);
  TreeNode * n3 = new TreeNode(8);
  TreeNode * n4 = new TreeNode(10);
  TreeNode * n5 = new TreeNode(13);
  n4->left = n3;
  n3->parent = n4;
  n4->right = n5;
  n5->parent = n4;
  n3->left = n2;
  n2->parent = n3;
  n2->left = n1;
  n1->parent = n2;

 // Your Code Here (Right or left rotate to balance above tree? )
 rightRotate(n3);

  cout << "Ex 1 Inorder traversal : "
       << ((n4->left)->left)->val << ", " << (n4->left)->val << ", " <<((n4->left)->right)->val << ", " << n4->val << ", " << (n4->right)->val << endl;

  n1 = new TreeNode(2);

  n2 = new TreeNode(5);

  n3 = new TreeNode(8);

  n4 = new TreeNode(10);

  n5 = new TreeNode(13);

  n2->right = n3;

  n3->parent = n2;

  n2->left = n1;

  n1->parent = n2;

  n3->right = n4;

  n4->parent = n3;

  n4->right = n5;

  n5->parent = n4;



 // Your Code Here (Right or left rotate to balance above tree? )

  cout << "Ex 2 Inorder traversal : " << (n2->left)->val << ", " << n2->val << ", " << ((n2->right)->left)->val << ", " << (n2->right)->val << ", " << ((n2->right)->right)->val << endl;

  deleteTree(n2);

  return 0;
}
