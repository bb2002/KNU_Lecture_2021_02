#include<stdio.h>

int main() {
	FILE* fp;
	char str[100];
	fp = fopen("file.txt", "w");

	if (fp == NULL) {
		fprintf(stderr, "file.txt 를 쓸 수 없습니다.");
		exit(1);
		return;
	}

	do {
		gets(str);
		fputs(str, fp);
	} while (strlen(str) != 0);

	fclose(fp);
}