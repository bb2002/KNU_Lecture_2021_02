#include<stdio.h>

int main() {
	int sum = 0, cnt = 0;

	while (1) {
		sum += (++cnt);

		if (sum + cnt >= 10000) {
			break;
		}
	}

	printf("1���� %d������ ���� %d �Դϴ�.", cnt, sum);
}