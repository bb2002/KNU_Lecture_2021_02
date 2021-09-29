#include<stdio.h>

int main() {
	int a, b, c;
	printf("3개의 정수를 입력하시오: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("최대값: %d", (a < b ? (b < c ? c : b) : (a < c ? c : a)));
}