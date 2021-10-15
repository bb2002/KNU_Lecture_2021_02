#include<stdio.h>

int main() {
	int a, b, c, result;
	printf("3개의 정수를 입력하시오: ");
	scanf("%d%d%d", &a, &b, &c);

	if (a > b) {
		if (b > c)	result = c;
		else		result = b;
	}
	else {
		if (a > c)	result = c;
		else        result = a;
	}

	printf("제일 작은 정수는 %d입니다.", result);
}