#include<stdio.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }

int main() {
	int (*funcs[4])(int, int) = { add, sub, mul, div };
	int choice, x, y, result;

	printf("=====================\n");
	printf("0. ����\n");
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. ������\n");
	printf("4. ����\n");
	printf("=====================\n");

	scanf("%d", &choice);

	if (choice < 0 || choice >= 4) return;

	printf("2���� ������ �Է��Ͻÿ�:");
	scanf("%d %d", &x, &y);
	result = funcs[choice](x, y);
	printf("���� ��� = %d\n", result);
}