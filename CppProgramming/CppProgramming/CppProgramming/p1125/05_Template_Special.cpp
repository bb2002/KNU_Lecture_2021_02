#include<iostream>
using namespace std;

template <typename T>
T getMax(T a, T b) {
	return a > b ? a : b;
}

template <>
string getMax(string a, string b) {
	return a;
}

int main() {
	cout << getMax<int>(401, 409) << endl;
	cout << getMax<char>('A', 'B') << endl;
	cout << getMax<string>("OOP", "fun") << endl;
	return 0;
}
