#include<iostream>

int main() {
	double a = 3.14;
	double b = 401.14;
	double* const pa = &a;

	// 포인터 변수 자체에 const 를 달아서 포인터 값 변경 불가
	// pa = &b;
	std::cout << "pa: " << *pa << std::endl;
}