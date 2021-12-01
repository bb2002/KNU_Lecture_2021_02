#include<iostream>
using namespace std;

int add(int left, int right) {
	return left + right;
}
int sub(int left, int right) {
	return left - right;
}

typedef int (*func)(int, int);

func getFunc(int op) {
	if (op == 1) return add;
	return sub;
}

int main() {
	int (*ptr)(int, int);
	int op, val1, val2;

	cout << "Input left operand: ";
	cin >> val1;
	cout << "Input right operand: ";
	cin >> val2;
	cout << "Input your operation: " << endl;
	cout << "(1: add, otherwise: sub)" << endl;
	cin >> op;

	ptr = getFunc(op);

	cout << ptr(val1, val2) << endl;
}