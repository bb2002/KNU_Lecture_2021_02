#include <iostream>

int main() {
	for (int i = 1; i < 10; ++i) {
		for (int j = 2; j < 10; ++j) {
			std::cout << j << " x " << i << " = " << i * j;
			std::cout << "\t";
		}

		std::cout << std::endl;
	}
}