#include<iostream>
#include<string>

int main() {
	std::cout << "Input String: ";

	std::string text;
	std::getline(std::cin, text);

	std::string word[100];
	int next = 0;

	// 문장을 띄어쓰기 단위로 Split 한다. (여기에는 split 함수가 없는 모양이다)
	while (true) {
		int wordSegIdx = text.find(' ');

		if (wordSegIdx == -1) {
			break; 
		}
		else {
			word[next++] = text.substr(0, wordSegIdx);
			text = text.substr(wordSegIdx+1, text.length());
		}
	}
	word[next++] = text;

	// Split 한 단어들을 첫 알파벳 기준으로 정렬한다.
	for (int i = 1; i < next; ++i) {
		for (int j = 0; j < i; ++j) {
			char key = word[i][0];
			char target = word[j][0];

			if (key < target) {
				std::string tmp = word[i];
				word[i] = word[j];
				word[j] = tmp;
			}
		}
	}

	std::cout << "convert string: ";
	for (int i = 0; i < next; ++i) {
		std::cout << word[i] << " ";
	}
	std::cout << std::endl;



	return 0;
}