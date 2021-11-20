#include<iostream>
using namespace std;

class A {
public:
	int a;
	A() {
		cout << "A's constructor called" << endl;
	}
};

class B {
public:
	int b;
	B() {
		cout << "B's constructor called" << endl;
	}
};

class C : public A, public B {
public:
	int c;
	C() {
		cout << "C's constructor called" << endl;
	}
};

class D : public A, public B {
public:
	int d;
	D() {
		cout << "D's constructor called" << endl;
	}
};

int main() {
	cout << "--- C object is created --- " << endl;
	C* c = new C();

	cout << "--- D object is created ---" << endl;
	D* d = new D();

	c->a = 111;
	c->b = 401;
	c->c = 409;

	printf("C's a, b, c : %d %d %d", c->a, c->b, c->c);
}