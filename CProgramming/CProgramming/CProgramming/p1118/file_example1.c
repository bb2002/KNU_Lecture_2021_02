#include<stdio.h>

int main() {
	FILE* fp = fopen("scores.txt", "w");

	if (fp == NULL) {
		fprintf(stderr, "scores.txt 파일을 쓸 수 없습니다.");
		exit(1);
		return;
	}

	char cont = 'y';
	char studentId[10];
	char name[10];
	float score = 0;

	do {
		printf("학번: ");
		scanf("%s", studentId);
		printf("이름: ");
		scanf("%s", name);
		printf("성적: ");
		scanf("%f", &score);

		fprintf(fp, "%s %s %f", studentId, name, score);
		printf("계속 하시겠습니까? (Y/n)");
		getchar();
		cont = getchar();
	} while (cont != 'n');

	printf("Finished.");
	fclose(fp);
}