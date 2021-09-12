#include <iostream>

int main() {
	for (int i = 1; i < 10; ++i) {
		for (int j = 2; j < 10; ++j) {
			int sum = i * j;
			bool isPrintable = true;

			while (sum != 0) {
				if (sum % 10 == 3 || sum % 10 == 6 || sum % 10 == 9) {
					isPrintable = false;
				}
				sum /= 10;
			}

			if (isPrintable) {
				std::cout << j << " x " << i << " = " << i * j;
				std::cout << "\t";
			}
			else {
				std::cout << "         \t";
			}

		}

		std::cout << std::endl;
	}
}