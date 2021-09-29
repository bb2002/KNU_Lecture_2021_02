#include <iostream>
using namespace std;

int& func(int val) {
	val -= 1;
	return val;
}

int main() {
	int a = 401;
	cout << "res : " << func(a) << endl;
	return 0;
}