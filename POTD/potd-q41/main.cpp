#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct BTreeNode {
    bool is_leaf=true;
    std::vector<int> elements;
    std::vector<BTreeNode*> children;
    BTreeNode() {}
    BTreeNode (std::vector<int> v) {
      this->elements = v;
    }
};

BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
  size_t i = 0;
  while((i<root->elements.size())&& (key>root->elements[i])){
    i++;//if the elements is in the current node, when it ends, tell which children it should go to
  }
  if((i<root->elements.size())&&(key==root->elements[i])){
    return root;
  }
  if(root->is_leaf == true){//if it is at leaf, we did not find it
    return NULL;//not found!
  }
  else{
    BTreeNode* b = root->children[i];//(i th subtree)
    return find(b,key);
  }
}

string convert(BTreeNode* root) {
  string s = "";
  if (root==NULL) return s;
  for (int i=0; i<root->elements.size(); i++)
    s += to_string(root->elements[i]) + " ";
  return s;
}

int main() {
  std::vector<int> v1 {30, 60}; std::vector<int> v2 {10, 20};
  std::vector<int> v3 {40, 50}; std::vector<int> v4 {70, 80};
  BTreeNode n_0(v1), n_2(v2), n_3(v3), n_4(v4);
  n_0.children.push_back(&n_2);
  n_0.children.push_back(&n_3);
  n_0.children.push_back(&n_4);

  n_0.is_leaf = false;
  BTreeNode* ans;
  ans = find(&n_0, 110);
  string found = (ans != NULL? "Yes :) In Node    ":"No. ");
  cout << "find(root, 110):  Was found? " << endl<< found << convert(ans) << " " <<endl<<endl;;

  ans = find(&n_0, 80);
  found = (ans != NULL? "Yes :) In Node    ":"No. ");
  cout << "find(root, 80):  Was found? " << endl<< found << convert(ans) << " " <<endl<<endl;

  ans = find(&n_0, 10);
  found = (ans != NULL? "Yes :) In Node    ":"No. ");
  cout << "find(root, 10):  Was found? " << endl<< found << convert(ans) << " " <<endl<<endl;

  ans = find(&n_0, 30);
  found = (ans != NULL? "Yes :) In Node    ":"No. ");
  cout << "find(root, 30):  Was found? " << endl<< found << convert(ans) << " " <<endl<<endl;

  return 0;
}
