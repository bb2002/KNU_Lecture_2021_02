#include<stdio.h>

int main() {
	int a, b, c, result;
	printf("3���� ������ �Է��Ͻÿ�: ");
	scanf("%d%d%d", &a, &b, &c);

	if (a > b) {
		if (b > c)	result = c;
		else		result = b;
	}
	else {
		if (a > c)	result = c;
		else        result = a;
	}

	printf("���� ���� ������ %d�Դϴ�.", result);
}