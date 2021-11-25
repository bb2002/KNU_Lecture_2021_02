#include<iostream>
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

int main() {
	OOP<int, double>* a = new OOP<int, double>(111, 401);
	OOP<int, char>* b = new OOP<int, char>(1, 'A');
	cout << a->add() << ", " << b->add() << endl;
}