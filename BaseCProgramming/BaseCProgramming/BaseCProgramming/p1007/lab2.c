#include <stdio.h>

int main() {
	int x, y;

	printf("x ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d", &x);

	printf("y ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d", &y);

	printf("%d��и�", (x > 0) ? (y > 0 ? 1 : 3) : (y > 0 ? 2 : 4));
}