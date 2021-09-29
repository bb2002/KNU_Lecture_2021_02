#include <iostream>
int main() {
	int a;
	int& ra = a;

	a = 401;
	std::cout << "a: " << a << std::endl;
	std::cout << "ra: " << ra << std::endl;
	ra = 1;
	std::cout << "a: " << a << std::endl;
	std::cout << "ra: " << ra << std::endl;
}
