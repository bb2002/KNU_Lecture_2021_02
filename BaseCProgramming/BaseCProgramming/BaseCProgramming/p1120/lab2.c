#include<stdio.h>
#include<time.h>

int main() {
	srand((unsigned)time(NULL));

	int data[10] = { 0, };

	for (int i = 0; i < 10; ++i) {
		data[i] = rand();
	}

	int max = data[0];
	int min = data[0];

	for (int i = 1; i < 10; ++i) {
		if (max < data[i]) {
			max = data[i];
		}

		if (min > data[i]) {
			min = data[i];
		}
	}

	printf("�ִ밪�� %d\n�ּҰ��� %d", max, min);
}