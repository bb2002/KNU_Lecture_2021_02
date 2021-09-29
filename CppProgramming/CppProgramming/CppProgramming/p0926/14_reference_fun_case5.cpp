#include <iostream>
using namespace std;

int func(int val) {
	val -= 1;
	return val;
}

int main() {
	int a = 401;
	const int& b = func(a);
	cout << "res : " << b << endl;
	return 0;
}