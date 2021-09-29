#include <iostream>
int main() {
	int a, b;
	int* pa;

	a = 401;
	pa = &a;
	b = *pa;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "pa: " << pa << std::endl;
}