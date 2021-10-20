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
	struct node n1, n2, n3;
	n1.val = 1;
	n1.next = &n2;

	n2.val = 2;
	n2.next = &n3;

	n3.val = 3;
	n3.next = nullptr;

	printLinkedList(&n1);
}