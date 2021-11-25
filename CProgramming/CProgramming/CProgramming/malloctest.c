#include<stdio.h>
#include <stdlib.h>

int main() {
	int* pi;
	pi = (int*)malloc(5 * sizeof(int));

	if (pi == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}

	*pi = 0;
	*(pi + 1) = 1;
	*(pi + 2) = 2;
	*(pi + 3) = 3;
	*(pi + 4) = 4;

	printf("%d", *pi);
	printf("%d", *(pi + 1));
}