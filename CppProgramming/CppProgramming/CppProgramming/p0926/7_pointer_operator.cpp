#include<iostream>
using namespace std;

int main() {
	int a = 401;
	int b = 409;
	int* pa = &a;
	int* pb = &b;

	cout << "(pa-pb): " << pa - pb << endl;
	//cout << "(pa+pb): " << pa + pb << endl;
}