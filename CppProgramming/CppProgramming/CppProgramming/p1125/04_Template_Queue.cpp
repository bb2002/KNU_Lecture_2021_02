#include<iostream>
using namespace std;

template <typename T>
class Queue {
	class Value {
	private:
		T value;
		Value* next;

	public:
		Value(T val, Value* next) : value(val), next(next) {

		}
		friend class Queue;
	};

private:
	int mLen;
	Value* mValues;
	Value* mFront;
	Value* mBack;

public:
	Queue() : mLen(0), mValues(nullptr), mFront(nullptr), mBack(nullptr) {

	}

	void push(T val) {
		Value* v = new Value(val, nullptr);

		if (mLen == 0) {
			mValues = mFront = mBack = v;
		}
		else {
			mBack->next = v;
			mBack = v;
		}
		++mLen;
	}

	void pop() {
		if (mLen > 0) {
			mValues = mFront->next;
			delete mFront;
			mFront = mValues;
			mLen--;
		}
		else {
			cout << "No values in the quqeue" << endl;
		}
	}

	T front() const { return mFront->value; }
	T back() const { return mBack->value; }
	int size() const { return mLen; }

	void printQueue() const {
		if (mLen > 0) {
			Value* v = mValues;
			while (v != nullptr) {
				cout << v->value << " -> ";
				v = v->next;
			}
			cout << endl;
		}
	}

	~Queue() {
		if (mLen > 0) {
			while (mValues != nullptr) {
				Value* v = mValues;
				mValues = mValues->next;
				delete v;
			}
		}
	}
};

int main() {
	Queue<int>* qInt = new Queue<int>();
	qInt->push(111);
	qInt->push(401);
	qInt->push(409);
	qInt->pop();
	qInt->printQueue();
	if (qInt->size() > 0) {
		cout << "front : " << qInt->front() << " back : " << qInt->back() << endl;
	}
		
	Queue<string>* qStr = new Queue<string>();
	qStr->push("CSE");
	qStr->push("OOP");
	qStr->push("fun");
	qStr->pop();
	qStr->printQueue();
	if (qStr->size() > 0) {
		cout << "front : " << qStr->front() << " back : " << qStr->back() << endl;
	}
}
