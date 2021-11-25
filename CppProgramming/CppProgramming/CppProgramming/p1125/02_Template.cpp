#include<iostream>
using namespace std;

template<typename T>
T getMax(T x, T y) {
	return x > y ? x : y;
}

int main() {
	cout << getMax<int>(455,3739) << endl;
	cout << getMax<char>('A', 'B') << endl;
}