#include<iostream>

class Node {
private:
	int val;
	Node* next;

public:
	Node(int val) : val(val), next(nullptr) {}

	int& getVal() {
		return this->val;
	}

	Node* getNext() {
		return this->next;
	}

	void setNext(Node* next) {
		this->next = next;
	}
};

class LinkedList {
private:
	Node* firstNode = nullptr;
	int size = 0;

public:
	LinkedList() {};

	~LinkedList();

	void insert(int);

	void remove(int);

	inline int getSize() const {
		return this->size;
	}

	void printList();
};

LinkedList::~LinkedList()
{
	Node* current = this->firstNode;

	while (current != nullptr) {
		Node* next = current->getNext();
		delete current;
		current = next;
	}
	this->size = 0;
}

void LinkedList::insert(int val)
{
	Node* newNode = new Node(val);
	Node* current = this->firstNode;
	Node* prev = this->firstNode;

	while (current != nullptr && current->getVal() < val) {
		if (current != this->firstNode) {
			prev = prev->getNext();
		}

		current = current->getNext();
	}
	
	if (current == this->firstNode) {
		newNode->setNext(this->firstNode);
		this->firstNode = newNode;
	}
	else {
		if (current == nullptr) {
			prev->setNext(newNode);
		}
		else {
			newNode->setNext(current);
			prev->setNext(newNode);
		}
	}

	++this->size;
}

void LinkedList::remove(int val)
{
	Node* current = this->firstNode;
	Node* prev = this->firstNode;

	while (current != nullptr && current->getVal() != val) {
		if (current != this->firstNode) {
			prev = prev->getNext();
		}

		current = current->getNext();
	}

	if (current != nullptr) {
		if (current == this->firstNode) {
			this->firstNode = current->getNext();
			delete current;
			size--;
		}
		else {
			prev->setNext(current->getNext());
			delete current;
			size--;
		}
	}
}

void LinkedList::printList()
{
	Node* cursor = firstNode;

	while (cursor != nullptr) {
		std::cout << cursor->getVal() << "-->";
		cursor = cursor->getNext();
	}

	std::cout << std::endl;
}


int main() {
	LinkedList ll;
	ll.insert(1);
	ll.printList();
	ll.insert(7);
	ll.printList();
	ll.insert(3);
	ll.printList();
	ll.insert(5);
	ll.printList();

	ll.remove(1);
	ll.printList();
	ll.remove(5);
	ll.printList();
}