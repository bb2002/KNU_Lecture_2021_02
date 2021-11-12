#include<stdio.h>

void show_digit(int data) {
	if (data < 10) {
		printf("%d ", data);
	} else {
		int value = data / 10;
		int na = data % 10;
		show_digit(value);
		printf("%d ", na);
	}
}

int main() {
	int a;
	printf("정수를 입력하시오: ");
	scanf("%d", &a);
	show_digit(a);
}