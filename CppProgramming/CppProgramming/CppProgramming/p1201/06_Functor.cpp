#include<iostream>
using namespace std;

class ArithOpr {
public:
	ArithOpr() = default;
	virtual int operator() (int left, int right) = 0;
};

class Add : public ArithOpr {
public:
	Add() = default;
	virtual int operator() (int left, int right) {
		return left + right;
	}
};

class Multiply : public ArithOpr {
public:
	Multiply() = default;
	virtual int operator()(int left, int right) {
		return left * right;
	}
};

double binaryOp(int left, int right, ArithOpr* arith) {
	return (*arith)(left, right);
}

int main() {
	int a = 111;
	int b = 401;

	ArithOpr* pAdd = new Add();
	ArithOpr* pMulti = new Multiply();

	cout << "Add: " << binaryOp(a, b, pAdd) << endl;
	cout << "Mul: " << binaryOp(a, b, pMulti) << endl;

	delete pAdd;
	delete pMulti;
}