#include<iostream>
using namespace std;

template<typename T>
class OOP {
public:
	OOP() {
		cout << "General template object" << endl;
	}
};

template<>
class OOP<int> {
public:
	OOP() {
		cout << "Specialized template object" << endl;
	}
};

int main() {
	OOP<int> a;
	OOP<char> b;
	OOP<float> c;
}