#include<iostream>

using namespace std;

int add(int left, int right) {
	return left + right;
}
int sub(int left, int right) {
	return left - right;
}
int mul(int left, int right) {
	return left * right;
}

int main() {
	int (*fptr[])(int left, int right) = { add, sub, mul };
	int op, v1, v2;

	cout << "Input left operand: ";
	cin >> v1;
	cout << "Input right operand: ";
	cin >> v2;
	cout << "Input your operation: " << endl;
	cout << "(0:add, 1:subtract, 2:multi)" << endl;
	cin >> op;

	if (op == 0 || op == 1 || op == 2) {
		cout << "res : " << fptr[op](v1, v2) << endl;
	}
}