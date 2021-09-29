#include <stdio.h>

int main() {
	int a;
	printf("정수를 입력하시오: ");
	scanf("%d", &a);

	printf("십의 자리: %d\n", a / 10);
	printf("일의 자리: %d", a % 10);
}