#include<stdio.h>

int main() {
	FILE* fp = fopen("C:\\Users\\Ballbot\\Desktop\\dva.jpg", "rb");
	if (fp == NULL) {
		printf("dva.jpg 파일을 열 수 없습니다.");
		exit(1);
		return;
	}

	fseek(fp, 0, SEEK_END);
	printf("파일 크기=%dbyte", ftell(fp));
	fclose(fp);
}