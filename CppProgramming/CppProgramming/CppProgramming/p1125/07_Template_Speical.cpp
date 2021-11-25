#include<iostream>
#include<string>
using namespace std;

template<typename T, typename U>
class OOP {
private:
	T x;
	U y;

public:
	OOP(T v1, U v2) : x(v1), y(v2) {

	}
	T add() {
		return x + y;
	}
};

template<typename T>
class OOP<T, char> {
private:
	T x;
	char y;
public:
	OOP(T v1, char v2) :x(v1), y(v2) {}
	string add() {
		return "" + to_string(x) + y;
	}
};

int main() {
	OOP<int, double>* a = new OOP<int, double>(1111, 1222.22);
	OOP<int, char>* b = new OOP<int, char>(1, 'A');
	cout << a->add() << ", " << b->add() << endl;
}