#include <iostream>

int main() {
	double a = 3.1415;
	const double* pa = &a;
	
	// *pa = 4; const pointer �� �����Ͱ� ����Ű�� �� ���� �Ұ�.
	std::cout << "pa: " << *pa << std::endl;
}