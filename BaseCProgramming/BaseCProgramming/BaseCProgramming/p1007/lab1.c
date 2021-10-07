#include <stdio.h>

int main() {
	printf("정수를 입력하시오: ");

	int a;
	scanf("%d", &a);

	printf("2의 보수: %d", ~a + 1);
}