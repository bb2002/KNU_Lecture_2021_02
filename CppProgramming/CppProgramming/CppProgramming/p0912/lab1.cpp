#include <iostream>
#include <cstdlib>
#include <ctime>


int generateNumber() {
	while (true) {
		srand(time(NULL));
		int data = /*rand() % 899 + 100*/753;
		int rvData = data;
		int dataSeg[3] = { 0,0,0 };


		for (int i = 2; i >= 0; --i) {
			int seg = data % 10;
			data /= 10;
			dataSeg[i] = seg;
		}

		if (dataSeg[0] == dataSeg[1] || dataSeg[0] == dataSeg[2] || dataSeg[1] == dataSeg[2]) {
			continue;
		}
		else {
			return rvData;
		}
	}
}

bool testAnswer(int ans, int me) {
	int ansSeg[] = { 0,0,0 };		// �信 ���� ���� ����
	int meSeg[] = { 0,0,0 };		// ����� �Է¿� ���� ���� ����
	int ballCnt = 0;				// �� ī��Ʈ
	int striCnt = 0;				// ��Ʈ����ũ ī��Ʈ

	for (int i = 2; i >= 0; --i) {
		int seg = ans % 10;
		ans /= 10;
		ansSeg[i] = seg;

		seg = me % 10;
		me /= 10;
		meSeg[i] = seg;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (meSeg[i] == ansSeg[j]) {
				if (i == j) ++striCnt;
				else ++ballCnt;
			}
		}
	}

	std::cout << striCnt << " strikes, " << ballCnt << " balls" << std::endl;
	return striCnt == 3;
}

int main() {
	int ans = generateNumber();

	while (true) {
		int in;
		std::cout << "Input your guess: ";
		std::cin >> in;

		if (testAnswer(ans, in)) {
			std::cout << "You succeed!";
			break;
		}
	}

	return 0;
}