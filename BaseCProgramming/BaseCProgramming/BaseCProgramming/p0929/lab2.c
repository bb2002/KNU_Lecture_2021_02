#include<stdio.h>

int main() {
	int a, b, c;
	printf("3���� ������ �Է��Ͻÿ�: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("�ִ밪: %d", (a < b ? (b < c ? c : b) : (a < c ? c : a)));
}