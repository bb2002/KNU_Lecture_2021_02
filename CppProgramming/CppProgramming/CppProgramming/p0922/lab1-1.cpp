#include <iostream>
#include <string>

using namespace std;

void insertionSort(string arr[100], int size);

int main() {
	std::cout << "Input String: ";

	string text;
	getline(std::cin, text);

	string word[100];
	int next = 0;

	while (true) {
		int wordSegIdx = text.find(' ');

		if (wordSegIdx == -1) {
			break;
		}
		else {
			word[next++] = text.substr(0, wordSegIdx);
			text = text.substr(wordSegIdx + 1, text.length());
		}
	}
	word[next++] = text;

	// 일반적인 파라미터로 구현된 insertionSort 사용, swap 은 없음.
	insertionSort(word, next);

	std::cout << "convert string with basic param: ";
	for (int i = 0; i < next; ++i) {
		std::cout << word[i] << " ";
	}
}

void insertionSort(string arr[100], int size) {
	for (int i = 1; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			char key = arr[i][0];
			char target = arr[j][0];

			if (key < target) {
				std::string tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

