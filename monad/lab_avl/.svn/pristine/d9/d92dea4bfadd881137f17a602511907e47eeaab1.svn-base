/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
template <class K, class V>
int AVLTree<K, V>::height(Node* subtree){
  if(subtree == NULL){
    return -1;
  }
  else{
    return 1 + max(height(subtree->left),height(subtree->right));
  }
}

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    if(t == NULL){
      return;
    }
    Node* temp = t->right;
    t->right = temp->left;
    temp->left = t;
    t = temp;
    t->left->height =1 + max(heightOrNeg1(t->left->left),heightOrNeg1(t->left->right));//the height of final t's left child must change, since it is moved down
    t->height =1 + max(heightOrNeg1(t->left),heightOrNeg1(t->right));//the height of t may change
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{//the height of all the subtrees will not change, only 2 node changes
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    if(t == NULL){
      return;
    }
    Node* temp = t->left;
    t->left = temp->right;
    temp->right = t;
    t = temp;
    t->right->height =1 + max(heightOrNeg1(t->right->left),heightOrNeg1(t->right->right));//final t's right child must change since it is moved down
    t->height = 1 + max(heightOrNeg1(t->right),heightOrNeg1(t->left));
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if(subtree==NULL){
      return;
    }
    int balance = heightOrNeg1(subtree->right)-heightOrNeg1(subtree->left);
    if(balance<=-2){//left heavy and heightbalance will never be greater than +-2
    //since we assume its subtree are all balanced
      int leftBalance = heightOrNeg1(subtree->left->right)-heightOrNeg1(subtree->left->left);
      if(leftBalance == -1){
        rotateRight(subtree);
      }
      else{
        rotateLeftRight(subtree);
      }
    }
    else if(balance>=2){//right heavy
      int rightBalance = heightOrNeg1(subtree->right->right)-heightOrNeg1(subtree->right->left);
      if(rightBalance==1){
        rotateLeft(subtree);
      }
      else{
        rotateRightLeft(subtree);
      }
    }
    else{
      return;//balanced tree, do nothing
    }
    subtree->height = 1 + max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right));
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL){
      subtree = new Node(key,value);
    }
    else if(key<subtree->key){
      insert(subtree->left,key,value);

      int balance = heightOrNeg1(subtree->right)-heightOrNeg1(subtree->left);
      int leftBalance = heightOrNeg1(subtree->left->right)-heightOrNeg1(subtree->left->left);
      if(balance == -2){
        if(leftBalance==-1){
          rotateRight(subtree);
        }
        else{
          rotateLeftRight(subtree);
        }
      }
    }
    else if(key>subtree->key){
      insert(subtree->right,key,value);

      int balance = heightOrNeg1(subtree->right)-heightOrNeg1(subtree->left);
      int rightBalance = heightOrNeg1(subtree->right->right)-heightOrNeg1(subtree->right->left);
      if(balance == 2){
        if(rightBalance==1){
          rotateLeft(subtree);
        }
        else{
          rotateRightLeft(subtree);
        }
      }
    }
    subtree->height = 1 + max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right));
    //rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL){
        return;
    }
    if (key < subtree->key) {
        // your code here
        remove(subtree->left,key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            Node* temp = subtree;
            subtree = NULL;
            delete temp;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node*& iop = rightMostChild(subtree->left);
            swap(subtree,iop);
            if(iop->left == NULL){
              Node* temp = iop;
              iop = NULL;
              delete temp;
            }
            else{
              Node* temp = iop;
              iop = iop->left;
              delete temp;
            }
        } else {
            /* one-child remove */
            // your code here
            Node* temp = subtree;
            if(subtree->left == NULL){
              subtree = subtree->right;
            }
            else{
              subtree = subtree->left;
            }
            delete temp;
        }
        // your code here
        rebalance(subtree);
    }
    rebalance(subtree);
}

template <class K, class V>
typename AVLTree<K,V>::Node*& AVLTree<K, V>::rightMostChild(Node*& subtree){
  if(subtree->right==NULL){
    return subtree;
  }
  else{
    return rightMostChild(subtree->right);
  }
}
