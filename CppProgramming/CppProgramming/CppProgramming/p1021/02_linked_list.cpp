#include<iostream>

using namespace std;

struct node {
	int val;
	struct node* next;
};

void printLinkedList(struct node* n) {
	while (n != nullptr) {
		cout << n->val << " --> ";
		n = n->next;
	}
	std::cout << std::endl;
}

int main() {
	struct node* myLinkedList = nullptr;

	struct node* n1 = new struct node;
	n1->val = 21;
	n1->next = nullptr;

	myLinkedList = n1;

	struct node* n2 = new struct node;
	n2->val = 33;
	n2->next = nullptr;

	struct node* curPos = myLinkedList;
	while (curPos->next != nullptr) {
		curPos = curPos->next;
	}
	curPos->next = n2;

	printLinkedList(myLinkedList);
}