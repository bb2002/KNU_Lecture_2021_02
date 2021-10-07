#include <stdio.h>

int main() {
	int x, y;

	printf("x 좌표를 입력하시오: ");
	scanf("%d", &x);

	printf("y 좌표를 입력하시오: ");
	scanf("%d", &y);

	printf("%d사분면", (x > 0) ? (y > 0 ? 1 : 3) : (y > 0 ? 2 : 4));
}