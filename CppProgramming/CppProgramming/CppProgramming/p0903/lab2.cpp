#include <iostream>

int main() {
	std::cout << "�Է��� ���� ������ �����" << std::endl;
	std::cout << "������ ������ ���ڸ� �Է����ּ���: ";

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