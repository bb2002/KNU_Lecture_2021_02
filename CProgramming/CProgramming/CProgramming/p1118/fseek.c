#include<stdio.h>

int main() {
	FILE* fp = fopen("C:\\Users\\Ballbot\\Desktop\\dva.jpg", "rb");
	if (fp == NULL) {
		printf("dva.jpg ������ �� �� �����ϴ�.");
		exit(1);
		return;
	}

	fseek(fp, 0, SEEK_END);
	printf("���� ũ��=%dbyte", ftell(fp));
	fclose(fp);
}