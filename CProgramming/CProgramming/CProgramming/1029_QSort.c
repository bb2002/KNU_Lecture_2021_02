#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int values[] = { 0,3,8,6,5,2,9,7,3,5,4,2,2,5,9,6,8,1 };

	qsort(values, sizeof(values) / sizeof(values[0]), sizeof(values[0]), compare);

	printf("정렬한 후 배열: ");
	for (int n = 0; n < sizeof(values) / sizeof(values[0]); n++) printf("%d ", values[n]);
	printf("\n");
}