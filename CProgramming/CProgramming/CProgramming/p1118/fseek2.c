#include<stdio.h>

int main() {
	FILE* fp;
	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("data.txt ������ �� �� �����ϴ�.");
		exit(1);
	}

	fputs("�̰͵� ������ ������~", fp);
	fseek(fp, 7, SEEK_SET);
	fputs("������ ��", fp);
	fclose(fp);

}