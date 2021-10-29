#include<iostream>

struct IntElement {
	int value;
	struct IntElement* next;
};

class IntList {
private:
	IntElement* mElements = nullptr;
	int mSize = 0;

public:
	IntList() : mElements(nullptr), mSize(0) {}

	IntList(int* arr, int n);

	int find(int val);

	inline int size() const {
		return this->mSize;
	}

	inline IntElement* getElements() const {
		return this->mElements;
	}

	void insert(int val);

	void remove(int val);

	void clear();

	~IntList();

public:
	std::ostream& operator<<(std::ostream& stream);
};

IntList::IntList(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		this->insert(arr[i]);
	}
}

int IntList::find(int val) {
	IntElement* current = mElements;
	int index = -1;

	while (current != nullptr) {
		++index;
		if (current->value == val) {
			return index;
		}
		current = current->next;
	}

	return -1;
}

void IntList::insert(int val) {
	if (this->find(val) == -1) {
		IntElement* newElement = new IntElement{ val, nullptr };

		if (mElements == nullptr) {
			mElements = newElement;
		}
		else {
			IntElement* last = mElements;
			
			while (last->next != nullptr) {
				last = last->next;
			}

			last->next = newElement;
		}

		++this->mSize;
	}
}

void IntList::remove(int val) {
	IntElement* current = mElements;
	IntElement* before = mElements;

	while (current != nullptr) {
		if (current->value == val) {
			before->next = current->next;
			delete current;
			--this->mSize;
			break;
		}

		if (current != mElements) {
			before = current;
		}
		current = current->next;
	}
}

void IntList::clear() {
	IntElement* current = mElements;

	while (current != nullptr) {
		IntElement* target = current;
		current = current->next;
		delete target;
	}

	this->mSize = 0;
}

IntList::~IntList()
{
	this->clear();
}

std::ostream& IntList::operator<<(std::ostream& stream)
{
	IntElement* current = this->mElements;

	while (current != nullptr) {
		std::cout << current->value << " ";
	}

	std::cout << std::endl;

	return stream;
}

int main() {
	int* arr = new int[] { 1,2,3,4,5 };
	IntList* newList = new IntList(arr, 5);

	newList->remove(1);
	newList->remove(3);
	newList->remove(5);

	std::cout << "list: " << newList;
}