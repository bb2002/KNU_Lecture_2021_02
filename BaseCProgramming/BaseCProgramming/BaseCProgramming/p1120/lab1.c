#include<stdio.h>

int main() {
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	for (int i = 0; i < 12; ++i) {
		printf("%d���� %d�� ���� �ֽ��ϴ�.\n", i + 1, days[i]);
	}
}