#include <iostream>

int main() {
	std::cout << "입력을 통한 마름모 만들기" << std::endl;
	std::cout << "마름모를 구성할 숫자를 입력해주세요: ";

	char c;
	std::cin >> c;

	for (int i = 2; i >= -2; --i) {
		int newI = i > 0 ? i : i * -1;

		for (int j = 0; j < newI; ++j) {
			std::cout << " ";
		}

		for (int j = newI * 2; j < 5; ++j) {
			std::cout << c;
		}

		std::cout << std::endl;
	}
}