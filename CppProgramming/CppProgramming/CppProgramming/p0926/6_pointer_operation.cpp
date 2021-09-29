#include <iostream>
using namespace std;

int main() {
	double a = 3.14;
	int b = 401;
	double* pa = &a;
	int* pb = &b;

	cout << "pa: " << pa << endl;
	cout << "(pa+1): " << pa + 1 << endl;

	cout << "pb: " << pb << endl;
	cout << "(pb+1): " << pb + 1 << endl;

	cout << "pb: " << pb << endl;
	cout << "(pb-1): " << pb - 1 << endl;
}