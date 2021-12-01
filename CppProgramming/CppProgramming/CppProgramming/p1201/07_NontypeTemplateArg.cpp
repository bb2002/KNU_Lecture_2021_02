#include<iostream>
using namespace std;

template<typename T, int num>
T add(T val) {
	return val + num;
}

int main() {
	int x = 401;
	cout << "x: " << add<int, 1>(x) << endl;
}