#include <iostream>
using namespace std;

struct node {
  int val;
  node *next;
};

void printList(node *head) {
  if (head == NULL) {
    cout << "Empty list" << endl;
    return;
  }

  node *temp = head;
  int count = 0;
  while(temp != NULL) {
    cout << "Node " << count << ": " << temp ->val << endl;
    count++;
    temp = temp->next;
  }
}

void mergeList(node *first, node *second) {
  // your code here
	node* curr1 = NULL;
	node* newHead = NULL;
	node* curr2 = NULL;
	node* holder = NULL;
	if(first==NULL&&second!=NULL){
		first = second;
		return;
	}
	if(second==NULL&&first!=NULL){
		return;
	}
		
	if(first->val<second->val){
		newHead = first;
		curr1 = first;
		curr2 = second;
	}
	else{
		newHead = second;
		curr1 = second;
		curr2 = first;
	}
	while(curr1->next!=NULL&&curr2->next!=NULL){
		if(curr1->val<curr2->val){
			curr1 = curr1->next;
		}
		else{
			holder = curr1->next;
			curr1->next = curr2;
			curr2->next = holder;
			curr1 = curr2;
			curr2 = holder;
		}
	}
	if(curr1->next==NULL){
		curr1->next = curr2;
	}
	if(curr2->next == NULL){
		curr2->next = curr1;
	}
		
	first = newHead;	
}

int main() {
  // Example #1
  node n0, n2, n4, n11, n33, n55;
  n0.val = 0;
  n2.val = 2;
  n4.val = 4;
  n11.val = 11;
  n33.val = 33;
  n55.val = 55;

  n0.next = &n2;
  n2.next = &n4;
  n4.next = NULL;

  n11.next = &n33;
  n33.next = &n55;
  n55.next = NULL;

  cout<<"First List:"<<endl;
  printList(&n0);
  cout<<"Second List:"<<endl;
  printList(&n11);

  mergeList(&n0, &n11);

  cout<<"Merged List:"<<endl;
  printList(&n0);
  cout<<endl;

  // Example #2
  node p0, p2, p11, p33, p33_2, p44;
  p0.val = 0;
  p2.val = 2;
  p11.val = 11;
  p33.val = 33;
  p33_2.val = 33;
  p44.val = 44;

  p0.next = &p2;
  p2.next = NULL;

  p11.next = &p33;
  p33.next = &p33_2;
  p33_2.next = &p44;
  p44.next = NULL;

  cout<<"First List:"<<endl;
  printList(&p0);
  cout<<"Second List:"<<endl;
  printList(&p11);

  mergeList(&p0, &p11);

  cout<<"Merged List:"<<endl;
  printList(&p0);

  return 0;
}
