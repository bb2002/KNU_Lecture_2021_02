#include<stdio.h>

int main() {
	FILE* fp = fopen("scores.txt", "w");

	if (fp == NULL) {
		fprintf(stderr, "scores.txt ������ �� �� �����ϴ�.");
		exit(1);
		return;
	}

	char cont = 'y';
	char studentId[10];
	char name[10];
	float score = 0;

	do {
		printf("�й�: ");
		scanf("%s", studentId);
		printf("�̸�: ");
		scanf("%s", name);
		printf("����: ");
		scanf("%f", &score);

		fprintf(fp, "%s %s %f", studentId, name, score);
		printf("��� �Ͻðڽ��ϱ�? (Y/n)");
		getchar();
		cont = getchar();
	} while (cont != 'n');

	printf("Finished.");
	fclose(fp);
}