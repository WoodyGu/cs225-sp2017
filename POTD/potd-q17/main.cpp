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

void insertSorted(node **head, node *insert) {
  // your code here
	if(*head == NULL){//if it is an empty list
		*head = insert;
		return;
	}
	if(insert->val<(*head)->val){//if the insert is a head
		insert->next = *head;
		*head = insert;
		return;
	}
	//normal condition
	node* curr = *head;
	node* holder;//to hold the prev of curr
	while(insert->val > curr->val){
		holder = curr;
		if(curr->next!=NULL)
			curr = curr->next;
		else
			break;
	}
	node* temp = holder->next;
	holder->next = insert;
	insert->next = temp;
}


int main() {
  // Empty List:
  node *head = NULL;
  printList(head);

  // Add 3 to list:
  node three;
  three.val = 3;
  three.next = NULL;
  insertSorted(&head, &three);
  printList(head);

  // Add 9 to list:
  node nine;
  nine.val = 9;
  nine.next = NULL;
  insertSorted(&head, &nine);
  printList(head);

  // Add 1 to list:
  node one;
  one.val = 1;
  one.next = NULL;
  insertSorted(&head, &one);
  printList(head);

  // Add 5 to list:
  node five;
  five.val = 5;
  five.next = NULL;
  insertSorted(&head, &five);
  printList(head);
  
  // Add 6 to list:
  node six;
  six.val = 6;
  six.next = NULL;
  insertSorted(&head, &six);
  printList(head);
  return 0;
}
