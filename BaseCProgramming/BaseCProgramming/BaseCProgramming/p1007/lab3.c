#include<stdio.h>

int main() {
	unsigned int data;
	char in;

	printf("첫번째 문자를 입력하시오: ");
	scanf("%c", &in);
	data = in;
	getchar();

	printf("두번째 문자를 입력하시오: ");
	scanf("%c", &in);
	data = data | in << 8;
	getchar();

	printf("세번째 문자를 입력하시오: ");
	scanf("%c", &in);
	data = data | in << 16;
	getchar();

	printf("네번째 문자를 입력하시오: ");
	scanf("%c", &in);
	data = data | in << 24;
	getchar();

	printf("결과값: %0X", data);
}