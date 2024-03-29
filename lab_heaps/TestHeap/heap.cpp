/**
 * @file heap.cpp
 * Implementation of a heap class.
 */
#include "heap.h"
template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    /// @todo Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the left child.
    return 2 * currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the right child.
    return 2 * currentIdx + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    /// @todo Update to return the index of the parent.
    return currentIdx/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    /// @todo Update to return whether the given node has a child
    return (2 * currentIdx) < this->_elems.size();
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
   if(currentIdx*2+1>=_elems.size()){//forgot to deal with case with only one child!!!!
     return leftChild(currentIdx);
   }
   if(higherPriority(_elems[leftChild(currentIdx)],_elems[rightChild(currentIdx)])){
     return leftChild(currentIdx);
   }
   else{
     return rightChild(currentIdx);
   }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    /// @todo Implement the heapifyDown algorithm.
    //should not check if it is the root, should only check if it have child(moving to the end of the array)
    //since if root does not satisfy heap property, we should still move it down, until it doesn't have any child.
    if(hasAChild(currentIdx)){
      size_t minChildIndex = maxPriorityChild(currentIdx);
      if(higherPriority(_elems[minChildIndex],_elems[currentIdx])){
        std::swap(_elems[currentIdx],_elems[minChildIndex]);
        heapifyDown(minChildIndex);
      }
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    //we should check if it is the root.(moving to the front of the array)
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    /// @todo Depending on your implementation, this function may or may
    ///   not need modifying
    this->_elems.push_back(T());
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    /// @todo Construct a heap using the buildHeap algorithm
    this->_elems = {};
    this->_elems.push_back(T());
    for(size_t i = 0;i<elems.size();i++){
      this->_elems.push_back(elems[i]);
    }
    for(int i = parent(_elems.size());i>0;i--){
      heapifyDown(i);
    }
}

template <class T, class Compare>
T heap<T, Compare>::pop()//(removeMin)
{
    /// @todo Remove, and return, the element with highest priority
    T minVal = this->_elems[1];
    _elems[1] = _elems[_elems.size()-1];
    _elems.pop_back();
    heapifyDown(1);
    return minVal;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    /// @todo Return, but do not remove, the element with highest priority
    return this->_elems[1];;
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    /// @todo Add elem to the heap
    this->_elems.push_back(elem);
    heapifyUp(this->_elems.size()-1);
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    /// @todo Determine if the heap is empty
    return this->_elems.size()<=1;
}

template <class T,class Compare>
void heap<T, Compare>::printHeap(){
  for(size_t i = 0;i<_elems.size();i++){
    cout<<_elems[i]<<" ";
  }
  cout<<endl;
}
