#include<stdio.h>

int main() {
	int buffer[] = { 10, 20, 30, 40, 50 };
	FILE* fp;
	size_t i, size, count;

	fp = fopen("binary.bin", "wb");
	if (fp == NULL) {
		fprintf(stderr, "binary.bin 을 wb 모드로 열기 실패");
		exit(1);
		return;
	}

	size = sizeof(buffer[0]);
	count = sizeof(buffer) / sizeof(buffer[0]);

	i = fwrite(&buffer, size, count, fp);
	return 0;
}