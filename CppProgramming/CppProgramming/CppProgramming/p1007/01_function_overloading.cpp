#include<iostream>
using namespace std;

void printValue(int val) {
	cout << "Integer Value: " << val << endl;
}

void printValue(int val1, int val2) {
	cout << "Integer Values: " << val1 << " and " << val2 << endl;
}

void printValue(double val) {
	cout << "Double Value: " << val << endl;
}

int main() {
	int a = 401, b = 409;
	char c = 'c';
	double d = 3.14;

	printValue(a);
	printValue(a, b);
	printValue(c);
	printValue(d);

	return 0;
}