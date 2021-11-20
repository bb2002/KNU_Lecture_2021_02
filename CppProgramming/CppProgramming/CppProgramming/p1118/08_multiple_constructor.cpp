#include<iostream>
using namespace std;

class A {
public:
	A(int val) {
		cout << "A's constructor : " << val << endl;
	}
};

class B : public A {
public:
	B(int val) :A(val) {
		cout << "B's constructor : " << val << endl;
	}
};

class C : public A {
public:
	C(int val) :A(val) {
		cout << "C's constructor : " << val << endl;
	}
};

class D : public B, public C {
public:
	D(int val) : C(val), B(val) {
		cout << "D's constructor : " << val << endl;
	}
};

int main() {
	cout << "--- D object is created ---" << endl;
	D* d = new D(401);

	return 0;
}