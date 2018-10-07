#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int value){
		val = value;
		next = NULL;
	}
};

struct compare {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val < l2->val;
    }
};


ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, compare> q;
    // q is a max-heap of ListNode*, to compare two ListNode we just compare their "val" members.

    for(auto l : lists) {
        if(l)  q.push(l);
    }
    if(q.empty())  return NULL;

    // Your codes here.
		ListNode* retval = NULL;
		ListNode* temp;
		while(!(q.empty())){
			if(retval == NULL){
				retval = q.top();
				q.pop();
				temp = retval;//they are pointing to the same place
				q.push(retval->next);
			}
			else{
				//temp is going down but retval stays at the same place
				temp->next = q.top();//these 2 steps are cricical steps!!!!! it put the staff at temp's next
				temp = temp->next;//move temp a step downwards
				q.pop();
				if(temp->next!=NULL){
					q.push(temp->next);
				}
			}
		}
		return retval;
}


int main() {
	ListNode *a0 = new ListNode(10);
	ListNode *a1 = new ListNode(6);
	ListNode *a2 = new ListNode(4);
	ListNode *a3 = new ListNode(1);
	a0->next = a1; a1->next = a2; a2->next = a3;

	ListNode *b0 = new ListNode(13);
	ListNode *b1 = new ListNode(7);
	ListNode *b2 = new ListNode(2);
	b0->next = b1; b1->next = b2;

	ListNode *c0 = new ListNode(9);
	ListNode *c1 = new ListNode(5);
	ListNode *c2 = new ListNode(3);
	ListNode *c3 = new ListNode(2);
	ListNode *c4 = new ListNode(1);
	c0->next = c1; c1->next = c2; c2->next = c3; c3->next = c4;

	vector<ListNode *> lists = {a0, b0, c0};

	ListNode *res = mergeKLists(lists);
	while (res != NULL){
		cout << res -> val << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
}
