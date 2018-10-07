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

void sortList(node **head) {
  	// your code here
	if(*head == NULL){		//empty list!
		return;
	}
	
}


int main() {
  // Create an unsorted list:
  node one, two, three, four, five;
  one.val = 1;
  two.val = 2;
  three.val = 3;
  four.val = 4;
  five.val = 5;

  // 2 -> 4 -> 1 -> 5 -> 3
  node *head = &two;
  two.next = &four;
  four.next = &one;
  one.next = &five;
  five.next = &three;
  three.next = NULL;

  // Unsorted List:
  cout<<"Unsorted List:"<<endl;
  printList(head);

  // Sorted List:
  sortList(&head);
  cout<<"Sorted List:"<<endl;
  printList(head);

  return 0;
}
