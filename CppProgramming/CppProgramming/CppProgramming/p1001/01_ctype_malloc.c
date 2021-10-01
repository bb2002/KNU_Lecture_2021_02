#include<stdio.h>
#include<stdlib.h>

int main() {
	int num = 5;

	int* scores = (int*)malloc(num * sizeof(int));

	for (int i = 0; i < num; ++i) {
		*(scores + i) = 99;
	}

	scores = (int*)realloc(scores, (num + 1) * sizeof(int));
	scores[5] = 100;

	for (int i = 0; i < num + 1; ++i) {
		printf("%d\n", scores[i]);
	}

	free(scores);
}