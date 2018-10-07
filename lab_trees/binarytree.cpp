/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

template <typename T>
int BinaryTree<T>::sumElements(Node* subRoot){
  if(subRoot==NULL){
    return 0;
  }
  else{
    return subRoot->elem + sumElements(subRoot->left)+sumElements(subRoot->right);
  }
}
/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const//in order traversal
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
  mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node* subRoot){
  if(subRoot==NULL){
    return;
  }

  //swap the left and right node of that subRoot
  Node* temp;
  temp = subRoot->left;
  subRoot->left = subRoot->right;
  subRoot->right = temp;
  mirror(subRoot->left);
  mirror(subRoot->right);
}

/**
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
  return isOrdered(root);
}

template <typename T>
bool BinaryTree<T>::isOrdered(const Node* subRoot) const
{
  if(subRoot->left==NULL||subRoot->right==NULL){
    return true;
  }
  T LeftMax = leftMax(subRoot->left);
  T RightMin = rightMin(subRoot->right);
  //needs to pay attention to the subroot it self because we can use this funtion to find the max of the whole tree, including the root itself
  if(LeftMax>RightMin||LeftMax>subRoot->elem||RightMin<subRoot->elem){
    return false;
  }
  return isOrdered(subRoot->left)&&isOrdered(subRoot->right);
}

template <typename T>
T BinaryTree<T>::leftMax(Node* subRoot) const{
  T temp = T();
  if(subRoot == NULL){
    return temp;
  }
  if(subRoot->elem>temp){
    temp = subRoot->elem;
  }
  temp = max(max(leftMax(subRoot->left),leftMax(subRoot->right)),subRoot->elem);
  return temp;
}

template <typename T>
T BinaryTree<T>::rightMin(Node* subRoot) const{
  T temp = 10000;//some very large number to avoid temp is initialized to 0 that will always return 0
  if(subRoot == NULL){
    return temp;
  }
  if(subRoot->elem<temp){
    temp = subRoot->elem;
  }
  temp = min(min(rightMin(subRoot->left),rightMin(subRoot->right)),subRoot->elem);
  return temp;
}
/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards,
 * ending at a leaf node. Paths ending in a left node should be printed before
 * paths ending in a node further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
    std::vector<T> v;
    printPaths(root,v);
}

template <typename T>
void BinaryTree<T>::printPaths(const Node* subRoot, std::vector<T> v) const{
  //cannot be if(subRoot==NULL), or it will never be reached
  if(subRoot->left==NULL&&subRoot->right==NULL){
    v.push_back(subRoot->elem);//without this line, we will always missing the last element
    cout<<"Path: ";
    for(size_t i = 0;i<v.size() - 1;i++){
      cout<<v[i]<<" ";
    }
    cout<<v[v.size()-1]<<endl;
    return;
  }
  //we first need to save each element in the vector first and then treverse to left or right, or the vector we print will always be null
    v.push_back(subRoot->elem);

  if(subRoot->left!=NULL){
    printPaths(subRoot->left,v);
  }
  if(subRoot->right!=NULL){
    printPaths(subRoot->right,v);
  }
}
/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    return sumDistances(root,0);
}

template <typename T>
int BinaryTree<T>::sumDistances(const Node* subRoot, int sum) const{
  if(subRoot->left==NULL&&subRoot->right==NULL){//we reached the leaf and we can return our sum
    return sum;
  }
  else if(subRoot->left!=NULL&&subRoot->right==NULL){
    return sumDistances(subRoot->left,sum+1)+sum;//we have to return sum, or it will not count the distance of non-leaf element
  }
  else if(subRoot->right!=NULL&&subRoot->left==NULL){
    return sumDistances(subRoot->right,sum+1)+sum;
  }
  else{
    return sumDistances(subRoot->left,sum+1)+sumDistances(subRoot->right,sum+1)+sum;
  }
}
