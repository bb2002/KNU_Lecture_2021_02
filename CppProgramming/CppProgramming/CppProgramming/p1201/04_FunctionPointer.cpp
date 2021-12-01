#include<iostream>
using namespace std;

void func1() {
	cout << "func1" << endl;
}

void func2() {
	cout << "func2" << endl;
}

void wrapper(void (*fptr)()) {
	fptr();
}

int main() {
	wrapper(func1);
	wrapper(func2);
}