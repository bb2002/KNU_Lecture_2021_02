#include<iostream>

int main() {
	double a = 3.14;
	double b = 401.14;
	double* const pa = &a;

	// ������ ���� ��ü�� const �� �޾Ƽ� ������ �� ���� �Ұ�
	// pa = &b;
	std::cout << "pa: " << *pa << std::endl;
}