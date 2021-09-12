#include <iostream>
using namespace std;

void question1() {
	int a;
	char b = 'a';
	a = b;
	cout << "a : " << a << endl;
}

void question2() {
	char a;
	int b = 100;
	a = b;
	cout << "a : " << a << endl;
}

void question3() {
	double a;
	int b = 401;
	a = b;
	cout << "a : " << a << endl;
}

void question4() {
	int a;
	double b = 3.141592;
	a = b;
	cout << "a : " << a << endl;
}

int main() {
	question1();
	question2();
	question3();

	return 0;
}
