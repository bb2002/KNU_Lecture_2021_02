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

	printf("�ҵ��� �Է��Ͻÿ�(����): ");
	scanf("%d", &income);

	printf("�ҵ漼�� %d���� �Դϴ�.\n", get_tax(income));
}