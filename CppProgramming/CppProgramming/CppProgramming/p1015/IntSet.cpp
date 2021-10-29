#include<iostream>

using namespace std;
class IntSet;

class IntElement {
private:
	int value;
	IntElement* next;

public:
	IntElement(int val) : value(val), next(nullptr) {};

	int getValue() {
		return value;
	};

	IntElement* getNext() {
		return this->next;
	}

	void setNext(IntElement* next) {
		this->next = next;
	}

	void setValue(int val) {
		this->value = val;
	}
};

class IntSet {
private:
	IntElement* mElement;
	int mSize;

public:
	IntSet() : mElement(nullptr), mSize(0) {};
	IntSet(int* arr, int n);
	~IntSet() { this->clear(); }

	bool IntSet::find(int val)
	{
		return false;
	}

	bool find(int val) const;
	int size() const { return this->mSize; }
	IntElement* getElements() const { return this->mElement; }

	void insert(int val);
	void remove(int val);
	void clear();

public:
	IntSet& operator++();				// 모든 원소 가감
	IntSet& operator--(int);			// 모든 원소 차감
	IntSet& operator+(const IntSet& rts);		// 우측 원소와 합집합
	IntSet& operator-(const IntSet& rts);		// 우측 원소와 차집합
	IntSet& operator*(const IntSet& rts);		// 우측 원소와 교집합
	bool operator==(const IntSet&) const;			// 우측 원소와 비교
};

std::ostream& operator<<(ostream& stream, const IntSet& rts);

int main() {
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[5] = { 5, 3, 1, 2, 5 };

	IntSet set1(arr1, 10);
	IntSet set2(arr2, 5);
	set1.insert(10);
	set1.insert(11);
	set1.insert(1);

	++set1;
	set2--;

	cout << "elements in set : " << set1 << endl;
	cout << "elements in set2 : " << set2 << endl;
	cout << "set1: " << set1 + set2 << endl; // 합집합
	cout << "set1: " << set1 * set2 << endl; // 교집합
	cout << "set1: " << set1 - set2 << endl; // 차집합
	return 0;

	/*
	int arr1[10] = { 1,2,3,4,5,5,4,3,2,1 };
	IntSet set(arr1, 10);
	std::cout << "set data: " << set << std::endl;
	std::cout << "++set data: " << ++set << std::endl;
	std::cout << "set-- data: " << set-- << std::endl;
	std::cout << "current set data: " << set << std::endl;

	int arr2[5] = { 4,5,6,7,8 };
	IntSet set2(arr2, 5);

	int arr3[5] = { 6,7,8,9,10 };
	IntSet set3(arr3, 5);

	std::cout << "set1 과 set2 합집합: " << set + set2 << std::endl;		// 예상 1 2 3 4 5 6 7 8
	std::cout << "set1 과 set2 교집합: " << set * set2 << std::endl;		// 예상 4 5 6 7 8
	std::cout << "set1 과 set3 차집합: " << set - set3 << std::endl;		// 예상 4 5
	*/
}

IntSet& IntSet::operator++() {
	IntElement* next = mElement;

	for (int i = 0; i < mSize; ++i) {
		if (next != nullptr) {
			next->setValue(next->getValue() + 1);
			next = next->getNext();
		}
	}

	return *this;
}

IntSet& IntSet::operator--(int) {
	IntSet* newSet = new IntSet();
	IntElement* next = mElement;

	for (int i = 0; i < mSize; ++i) {
		if (next != nullptr) {
			newSet->insert(next->getValue() - 1);
			next->setValue(next->getValue() - 1);
			next = next->getNext();
		}
	}

	return *newSet;
}

IntSet& IntSet::operator+(const IntSet& rts) {
	IntElement* next = rts.getElements();

	while (next != nullptr) {
		this->insert(next->getValue());
		next = next->getNext();
	}

	return *this;
}

IntSet& IntSet::operator-(const IntSet& rts) {
	IntElement* next = mElement;

	while (next != nullptr) {
		if (rts.find(next->getValue())) {
			IntElement* tmpNext = next->getNext();
			this->remove(next->getValue());
			next = tmpNext;
		}
		else {
			next = next->getNext();
		}
	}

	return *this;
}

IntSet& IntSet::operator*(const IntSet& rts) {
	IntElement* next = mElement;

	while (next != nullptr) {
		if (!rts.find(next->getValue())) {
			IntElement* tmpNext = next->getNext();
			this->remove(next->getValue());
			next = tmpNext;
		}
		else {
			next = next->getNext();
		}
	}

	return *this;
}

bool IntSet::operator==(const IntSet& rts) const {
	IntElement* next = mElement;

	for (int i = 0; i < mSize; ++i) {
		if (next != nullptr) {
			if (!rts.find(next->getValue())) {
				return false;
			}
		}
	}

	return rts.size() == this->mSize;
}

std::ostream& operator<<(std::ostream& stream, const IntSet& rts) {
	IntElement* next = rts.getElements();
	for (int i = 0; i < rts.size(); ++i) {
		if (next == nullptr) break;

		std::cout << next->getValue() << " ";
		next = next->getNext();
	}

	return stream;
}

IntSet::IntSet(int* arr, int n) : mElement(nullptr), mSize(0)
{
	for (int i = 0; i < n; ++i) this->insert(arr[i]);
}

bool IntSet::find(int val) const
{
	IntElement* target = mElement;
	for (int i = 0; i < this->mSize; ++i) {
		if (target == nullptr) {
			return false;
		}
		else {
			if (target->getValue() == val) {
				return true;
			}
			else {
				target = target->getNext();
			}
		}
	}

	return false;
}

void IntSet::insert(int val)
{
	if (!this->find(val)) {
		IntElement* tmp = new IntElement(val);
		tmp->setNext(mElement);
		mElement = tmp;
		++this->mSize;
	}
}

void IntSet::remove(int val)
{
	IntElement* before = nullptr;
	IntElement* current = mElement;
	IntElement* next = mElement->getNext();

	while (current != nullptr) {
		if (current->getValue() == val) {
			if (before == nullptr) {
				mElement = next;
			}
			else {
				before->setNext(next);
			}

			delete current;
			--mSize;
			current = next;
			if(next != nullptr) next = next->getNext();
		}
		else {
			before = current;
			current = next;
			if(next != nullptr) next = next->getNext();
		}
	}
}

void IntSet::clear()
{
	if (mElement != nullptr) {
		IntElement* target = mElement;
		IntElement* nxt = nullptr;

		for (int i = 0; i < mSize; ++i) {
			if (target == nullptr) {
				break;
			}
			else {
				nxt = target->getNext();
				delete target;
				target = nxt;
			}
		}

		mElement = nullptr;
		mSize = 0;
	}
}
