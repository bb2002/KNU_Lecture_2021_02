#include<stdio.h>

int get_tax(int income) {
	if (income <= 1000) {
		return income * 0.08;
	}
	else {
		return (1000 * 0.08) + ((income - 1000) * 0.1);
	}
}

int main() {
	int income;

	printf("소득을 입력하시오(만원): ");
	scanf("%d", &income);

	printf("소득세는 %d만원 입니다.\n", get_tax(income));
}