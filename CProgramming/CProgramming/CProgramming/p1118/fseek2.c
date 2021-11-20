#include<stdio.h>

int main() {
	FILE* fp;
	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("data.txt 파일을 열 수 없습니다.");
		exit(1);
	}

	fputs("이것도 너프해 보시지~", fp);
	fseek(fp, 7, SEEK_SET);
	fputs("버프해 주", fp);
	fclose(fp);

}