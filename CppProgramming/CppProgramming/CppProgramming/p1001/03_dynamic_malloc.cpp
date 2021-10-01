#include<iostream>
using namespace std;

int main() {
	int num = 5;
	int* scores = new int[num];

	for (int i = 0; i < num; ++i) {
		*(scores + i) = 99;
	}

	int* tmpScores = scores;
	scores = new int[num + 1];
	for (int i = 0; i < num; ++i) {
		*(scores + i) = *(tmpScores + i);
	}
	scores[num] = 100;

	for (int i = 0; i <= num; ++i) {
		cout << scores[i] << endl;
	}

	delete[] scores;
	delete[] tmpScores;
}