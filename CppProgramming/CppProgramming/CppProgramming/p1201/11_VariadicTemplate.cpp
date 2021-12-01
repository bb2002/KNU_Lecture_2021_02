#include<iostream>
using namespace std;

void print() {
	cout << "called lastly" << endl;
}

template<typename T, typename... Types>
void print(T val1, Types... val2) {
	cout << val1 << ", ";
	print(val2...);
}

int main() {
	print(401, 111, 3.14, "OOP", "Fun");
	return 0;
}