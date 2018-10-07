#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

void printList(node *head) {
  // printList function
  	int i = 0;
  	node* curr;
  	curr=head;
	if(head==NULL){
		cout<<"Empty list"<<endl;
		return;
	}
	else if(head->next==NULL){
		cout<<"Node "<<i<<": "<<head->val<<endl;
	}else{
		while(curr!=NULL){
			cout<<"Node "<<i<<": "<<curr->val<<endl;
			i++;
			curr = curr->next;
		}
	}
}

int main() {
  // Test 1: An empty list
  node * head1 = NULL;
  printList(head1);
  cout<<endl;

  // Test 2: A list with exactly one node
	node* head2 = new node;
	head2->val = 100;
	printList(head2);
	cout<<endl;

  // Test 3: A list with more than one node
	node* head3 = new node;
	head3->val = 100;
	head3->next = new node;
	head3->next->val = 200;
	head3->next->next = new node;
	head3->next->next->val = 300;
	printList(head3);

  return 0;
}
