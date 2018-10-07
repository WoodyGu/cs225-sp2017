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
};

int getHeight(TreeNode* subRoot){
  if(subRoot==NULL){
    return -1;
  }
  else{
    return 1 + max(getHeight(subRoot->left),getHeight(subRoot->right));
  }
}

void levelOrderTraversal(TreeNode* croot){
  queue<TreeNode*> q;//first specify what gonna be in the queue
  q.push(croot);//first push the current root into the queue
  while(!q.empty()){//while the queue is not empty
    TreeNode* t = q.front();
    q.pop();//dequeue
    if(t!=NULL){//check for seg-fault
      cout<<t->val<<" ";//yell it out
      q.push(t->left);//push in t's children, it is fine even NULL is in the queue
      q.push(t->right);
    }
  }
  cout<<endl;
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

/*int distance(TreeNode* subRoot,TreeNode* root){
  if(root==subRoot){
    return 0;
  }

  else{
    return 1 + distance(subRoot,root->left) + distance(subRoot,root->right);
  }
}*/

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

int main() {
/*
 * Example 1:
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 *return:
 * [
 *  [15,7],
 *  [9,20],
 *  [3]
 * ]
 */
  TreeNode n_0, n_1, n_2, n_3, n_4;
  n_0.val = 3;
  n_1.val = 9;
  n_2.val = 20;
  n_3.val = 15;
  n_4.val = 7;

  n_0.left = &n_1;
  n_0.right = &n_2;
  n_2.left = &n_3;
  n_2.right = &n_4;
  n_1.left = NULL;
  n_1.right = NULL;
  n_3.left = NULL;
  n_3.right = NULL;
  n_4.left = NULL;
  n_4.right = NULL;


  vector<vector<int>> ans = printFromButtom(&n_0);
  cout << "Result 1:" << endl;
  printAns(ans);
  levelOrderTraversal(&n_0);

/*
* Example 2
*        10
*       /  \
*      8   13
*     / \    \
*    3   9   16
* Return:
* [
*  [3, 9, 16],
*  [8, 13],
*  [10]
* ]
*/

  TreeNode n_00, n_01, n_02, n_03, n_04, n_05;
  n_00.val = 10;
  n_01.val = 8;
  n_02.val = 13;
  n_03.val = 3;
  n_04.val = 9;
  n_05.val = 16;

  n_00.left = &n_01;
  n_00.right = &n_02;
  n_01.left = &n_03;
  n_01.right = &n_04;
  n_02.left = NULL;
  n_02.right = &n_05;
  n_03.left = NULL;
  n_04.left = NULL;
  n_05.left = NULL;
  n_03.right = NULL;
  n_04.right = NULL;
  n_05.right = NULL;


  vector<vector<int>> ans2 = printFromButtom(&n_00);
  cout << "Result 2:" << endl;
  printAns(ans2);
  levelOrderTraversal(&n_00);


  return 0;

}
