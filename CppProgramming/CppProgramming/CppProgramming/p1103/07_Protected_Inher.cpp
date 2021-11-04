#include<iostream>
using namespace std;
class A {
public:
	int x;
protected:
	int y;
private:
	int z;
public:
	A() :x(0), y(1), z(2) {}
};

class B : protected A {
public:
	B() :A() {
		cout << "B(x): " << x << endl;
		cout << "B(y): " << y << endl;
		//cout << z << endl;
	}
};
class C : public B {
public:
	C() :B() {
		cout << "C(x): " << x << endl;
		cout << "C(y): " << y << endl;
		//cout << z << endl;
	}
};

int main() {
	A* a = new A();
	C* c = new C();
}
