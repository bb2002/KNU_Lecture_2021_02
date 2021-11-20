#include<stdio.h>

int main() {
	FILE* fp = NULL;
	int c;

	fp = fopen("alphabet.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "alphabet.txt can not open.");
		exit(1);
		return;
	}

	while ((c = fgetc(fp)) != EOF) {
		putchar(c);
	}

	fclose(fp);
}