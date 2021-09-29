#include <stdio.h>

int main() {
	int lts, rts;
	printf("2개의 정수를 입력하시오: ");
	scanf("%d %d", &lts, &rts);

	printf("몫: %d, 나머지: %d", lts / rts, lts % rts);
}