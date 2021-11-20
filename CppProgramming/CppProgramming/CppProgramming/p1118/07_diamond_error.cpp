#include<iostream>
using namespace std;

class A {
public:
	int a;
	A() { cout << "A's constructor called" << endl; }
};

class B : virtual public A {
public:
	int b;
	B() { cout << "B's constructor called" << endl; }
};

class C : virtual public A {
public:
	int c;
	C() { cout << "C's constructor called" << endl; }
};

class D : public B, public C {
public:
	int d;
	D() { cout << "D's constructor called" << endl; }
};

int main() {
	cout << "--- D object is created ---" << endl;
	D* d = new D();

	d->a = 111;
	d->b = 401;
	d->c = 409;
	d->d = 1;

	printf("D's a, b, c, d : %d %d %d %d", d->a, d->b, d->c, d->d);
}