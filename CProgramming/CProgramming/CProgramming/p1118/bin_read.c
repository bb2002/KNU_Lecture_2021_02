#include<stdio.h>
#define SIZE 5

int main() {
	int buffer[SIZE];
	FILE* fp = NULL;

	fp = fopen("binary.bin", "rb");
	if (fp == NULL) {
		fprintf(stderr, "binary.bin �� rb ���� ���� ����");
		exit(1);
		return;
	}

	fread(buffer, sizeof(int), SIZE, fp);
	for (int i = 0; i < SIZE; ++i) {
		printf("%d ", buffer[i]);
	}

	fclose(fp);
}