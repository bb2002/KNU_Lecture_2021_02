#include<stdio.h>

int main() {
	FILE* fp;
	char str[100];
	fp = fopen("file.txt", "w");

	if (fp == NULL) {
		fprintf(stderr, "file.txt �� �� �� �����ϴ�.");
		exit(1);
		return;
	}

	do {
		gets(str);
		fputs(str, fp);
	} while (strlen(str) != 0);

	fclose(fp);
}