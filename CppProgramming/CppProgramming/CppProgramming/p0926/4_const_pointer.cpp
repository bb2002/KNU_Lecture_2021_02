#include <iostream>

int main() {
	double a = 3.1415;
	const double* pa = &a;
	
	// *pa = 4; const pointer 는 포인터가 가리키는 값 수정 불가.
	std::cout << "pa: " << *pa << std::endl;
}