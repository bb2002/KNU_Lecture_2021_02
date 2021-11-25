#include<iostream>
using namespace std;

class Queue {
	class Value {
	private:
		int value;
		Value* next;
	
	public:
		Value(int val, Value* next) : value(val), next(next) {

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

	void push(int val) {
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

	int front() const { return mFront->value; }
	int back() const { return mBack->value; }
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
	Queue* q = new Queue();
	q->push(111);
	q->push(401);
	q->push(409);
	q->printQueue();
	if (q->size() > 0)
		cout << "front : " << q->front() << " back : "
		<< q->back() << endl;
	q->pop();
	q->pop();
	q->printQueue();
	if (q->size() > 0)
		cout << "front : " << q->front() << " back : "
		<< q->back() << endl;
}
