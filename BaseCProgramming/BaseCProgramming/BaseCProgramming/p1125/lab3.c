#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void array_fill(int* arr, int size) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < size; ++i) {
		arr[i] = rand();
	}
}

int main() {
	int arr[10], size;

	size = sizeof(arr) / sizeof(int);
	array_fill(arr, size);
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
}