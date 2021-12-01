#include<iostream>

void func(int a) {
	printf("Value of a is %d\n", a);
}

int main() {
	void (*fptr)(int) = func;
	fptr(10);
}