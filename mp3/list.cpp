/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
#include<iostream>
using namespace std;
template <class T>
List<T>::~List()
{
    /// @todo Graded in MP3.1//////////////////////////////////////////////ok
    ListNode* temp;
    while(head !=NULL){
    	temp = head;
    	head = head->next;
    	delete temp;
	}
	tail = NULL;
	length = 0;
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    /// @todo Graded in MP3.1////////////////////////////////////////////ok
    ListNode* temp;
    while(head !=NULL){
    	temp = head;
    	head = head->next;
    	delete temp;
	}
	tail = NULL;
	length = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{
    /// @todo Graded in MP3.1////////////////////////////////////////////////////////ok
    
    ListNode* temp = new ListNode(ndata);
    if(head==NULL||tail==NULL){
    	head = temp;
    	tail = temp;
    	temp->prev = NULL;
    	temp->next = NULL;
    }
    else{
		temp->next = head;
		head->prev = temp;//forget this, need also to take care of the prev pointer!!!!!
		temp->prev = NULL;
		head = temp;
		temp = NULL;
    }
    length++;//if head = null, buxing
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
    /// @todo Graded in MP3.1////////////////////////////////////////////////////////ok
    ListNode* temp = new ListNode(ndata);
    if(head==NULL||tail==NULL){
    	head = temp;
		tail = temp;
		temp->prev = NULL;
		temp->next = NULL;
    }
    else{
    	tail->next = temp;
    	temp->prev = tail;
    	temp->next = NULL;
    	tail = temp;
	}
	length++;
	temp = NULL;
}
/* why this doesn't work? but why the first case work?
	temp->next = NULL;
	temp->prev = tail;
	tail = temp;
	temp = NULL;
	length++;
	cout<<"insert back complete"<<endl;
*/

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::insertBack(ListNode *temp)
{
    if(head==NULL||tail==NULL){
    	head = temp;
		tail = temp;
		temp->prev = NULL;
		temp->next = NULL;
    }
    else{
    	tail->next = temp;
    	temp->prev = tail;
    	temp->next = NULL;
    	tail = temp;
	}
	length++;
}
template <class T>
void List<T>::reverse()
{
    reverse(head,tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint)
{
    /// @todo Graded in MP3.1///////////////////////////////////////////////////////////////
   	ListNode* temp = startPoint;
	ListNode* holder;
	ListNode* startPrev = startPoint -> prev;
    ListNode* start = startPoint;
	ListNode* end = endPoint;
    ListNode* endNext = endPoint -> next;
    ListNode* tempNext = endNext;
    if(startPoint == NULL||endPoint == NULL){
    		return;
    }
    
    while (temp != end) {//swap the element that temp is pointing to
        if (temp != startPoint) {
            tempNext = temp->prev;
        }
        temp->prev = temp->next;
        temp->next = tempNext;
        temp = temp->prev;
    }
    //swap the prev and next of the final temp pointer
    holder = temp->prev;
    temp->prev = startPrev;
    temp->next = holder;
    //if it is a tail, then tail will be equal to start
    if (endNext != NULL) {
        endNext->prev = start;
    } else {
        tail = start;
    }
    //if it is a head, then end will be the head
    if (startPrev != NULL) {
        startPrev->next = end;
    } else {
        head = end;
    }
    //swap the pointers for startpoints and end points
    startPoint = end;
    endPoint = start;
} 

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n)
{
    /// @todo Graded in MP3.1/////////////////////////////////////////////////////////////////
    if(head==NULL){
    	return;
    }
	ListNode* curr = head;
	ListNode* start = head;
	ListNode* end = NULL;
	while(curr->next!=NULL&&start->next!=NULL){
		curr = start;
		for(int i = 0;i<n-1;i++){
			if(curr->next!=NULL){
				curr = curr->next;
			}
		}
		reverse(start,curr);
		start = curr->next;
	}		
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    /// @todo Graded in MP3.1///////////////////////////////////////////////////////////////////OK
    if(head == NULL||head->next==NULL){
    	return;//empty list or list with only one element,gun
    }
    ListNode* curr;
    ListNode* temp;
    curr = head;
    while(curr->next!=tail){
    	/*temp = curr->next;
    	cout<<"line 198 reached"<<endl;
    	insertBack(temp);
    	cout<<"insert OK"<<endl;
    	remove(temp);
    	cout<<"remove OK"<<endl;
    	tail = tail->next;
    	cout<<"reached line 204"<<endl;
    	curr = curr->next;
    	*/
    	temp = curr->next;
    	curr->next = temp->next;
    	temp->next->prev = curr;
    	temp->prev = tail;
    	temp->next = NULL;
    	tail->next = temp;
    	tail = temp;
    	curr = curr->next;
    }
}

template <class T>
void List<T>::remove(ListNode* temp){
	if(temp==NULL){
		delete temp;
		return;
	}else if(temp->prev==NULL){
		head = temp->next;
		temp->next->prev = NULL;
	}else if(temp->next==NULL){
		tail = temp->prev;
		temp->prev->next = NULL;
	}
	else{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->prev = NULL;
		temp->next = NULL;
		}
		length--;
		delete temp;
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
    /// @todo Graded in MP3.2
   	if(start==NULL){
   		return NULL; //empty list!
   	}
   	int count = splitPoint-1;
   	ListNode* curr = start;
   	while(count>0){
   		if(curr!=NULL){
   			curr = curr->next;
   			count--;
   		}
   	}
   	//after we find the pointer to the last node before the second list
   	ListNode* secHead = curr->next;
   	curr->next = NULL;
   	secHead->prev = NULL;
   	return secHead;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the seco Sylvia Haas nd sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{
    /// @todo Graded in MP3.2///problem on consecutive insert////////////////////////////////////////////////////////
    //printForward(first);
    //printForward(second);
    /*
    ListNode* curr1 = NULL;
	ListNode* newHead = NULL;
	ListNode* curr2 = NULL;
	ListNode* holder = NULL;
	if(first==NULL&&second!=NULL){
		newHead = second;
		return newHead;
	}
	if(second==NULL&&first!=NULL){
		newHead = first;
		return newHead;
	}
		
	if(first->data<second->data){
		newHead = first;
		curr1 = first;
		curr2 = second;
	}
	else{
		newHead = second;
		curr1 = second;
		curr2 = first;
	}
	while(curr1!=NULL&&curr2!=NULL){
		if(curr1->next!=NULL&&curr1->next->data<curr2->data){
			curr1 = curr1->next;
			continue;
		}
		else{
			holder = curr1->next;
			curr1->next = curr2;
			curr2->prev = curr1;
			curr1 = curr2;
			curr2 = holder;
		}
	}
	return newHead;
}	*/
    //printForward(first);
    //printForward(second);
	ListNode* newHead = NULL;
    ListNode* curr = newHead;
    ListNode* temp = NULL;
    ListNode* tempF = NULL;
    ListNode* tempS = NULL;
    if(first == NULL){
    	newHead = second;
    	return newHead;
    }
     if(second == NULL){
    	newHead = first;
    	return newHead;
    }
    if(first == NULL&&second == NULL){
    	return NULL;
    }
    	
    if(first->data<second->data){
    	newHead = first;
    	first = first->next;
    	curr = first;
    	if(first==NULL){//situation with only one element
    		newHead->next = second;
    		second->prev = newHead;
    		return newHead;
    	}
    	while(first!=NULL&&second!=NULL){
			if(first->data<second->data){
				tempF = first;
				first = first->next;
				curr = first;
			}
			else{
				temp = second->next;
				curr->prev->next = second;
				second->prev = curr->prev;
				second->next = curr;
				curr->prev = second;
				second = temp;
				curr = first;
			}
	}
	if(second!=NULL){
		tempF->next = second;
		second->prev = tempF;
	}
	//cout<<"finished"<<endl;
	return newHead;
}
    else{
    	newHead = second;
    	second = second->next;
    	curr = second;
    	if(second==NULL){
    		newHead->next = first;
    		first->prev = newHead;
    		return newHead;
    	}
			while(first!=NULL&&second!=NULL){
				if(first->data<second->data){
					temp = first->next;
					curr->prev->next = first;
					first->prev = curr->prev;
					first->next = curr;
					curr->prev = first;
					first = temp;
					curr = second;//shao le zhe yi bu!!! qi ta dou dui, curr should be pass back to the main holder list
			}						//if still point to first, unable to insert continously
			else{
				tempS = second;
				second = second->next;
				curr = second;
			}
	}
	if(first!=NULL){
		tempS->next = first;
		first->prev =tempS;//wang le jiu chi shi le
	}
	//cout<<"finished"<<endl;
	return newHead;
	}
}


/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{
    /// @todo Graded in MP3.2//////////////////////////////////////////////////////////////////////////
    if(chainLength == 1){
    	//cout<<"reached 0"<<endl;
    	return start;//it is left with list with only one node, so cannot
    }
    else{
    	int mid = chainLength/2;
    	ListNode* start2 = split(start,mid);
    		//cout<<"split complete"<<endl;
    	start = mergesort(start,mid);
    		//cout<<"sorted first part"<<endl;
    	start2 = mergesort(start2,chainLength-mid);
    		//cout<<"can return "<<"start: "<<start->data<<"start2 "<<start2->data<<endl;
    	return merge(start,start2);
    }
}

template <class T>
void List<T>::printForward(ListNode* subHead) {
	ListNode* curr = subHead;
    while (curr != NULL) {
        cout<< " " << curr->data;
        curr = curr->next;
    }
    cout<<endl;
}		
