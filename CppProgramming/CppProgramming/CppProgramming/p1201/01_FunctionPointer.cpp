#include<iostream>

void func(int a) {
	printf("Values of a is %d", a);
}

int main() {
	void (*fptr)(int);
	fptr = &func;

	fptr(10);
}