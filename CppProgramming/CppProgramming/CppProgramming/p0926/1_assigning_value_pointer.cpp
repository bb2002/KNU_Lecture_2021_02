#include <iostream>

int main() {
	int a = 1, b = 2;
	double c = 3;

	int* pa, *pb;
	double* pc;

	pa = &a;
	pb = pa;
	pc = &c;
	
	std::cout << std::endl;

	std::cout << "pa: " << pa << std::endl;
	std::cout << "pb: " << pb << std::endl;
	std::cout << "pc: " << pc << std::endl;
}
