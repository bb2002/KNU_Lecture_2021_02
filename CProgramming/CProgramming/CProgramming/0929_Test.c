#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define nSize 20
#define rSize 3
#define cSize 5

int main() {
	char name[nSize];
	int score[rSize][cSize];
	int s = 0;
	int total = 0;
	double avg = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < rSize; ++i) {
		printf("�л� �̸��� �Է��ϼ���: ");
		scanf_s("%s", name, sizeof(name));

		for (int j = 0; j < cSize; ++j) {
			s = 60 + (rand() % 41);
			score[i][j] = s;
		}

		total = 0;
		for (int j = 0; j < cSize; ++j) {
			total += score[i][j];
		}
		avg = (double)total / (double)cSize;

		printf("%s �л��� ���� ����\n", name);
		for (int j = 0; j < cSize; ++j) {
			printf("���� %d�� ������ %d�Դϴ�.\n", j + 1, score[i][j]);

			if (score[i][j] >= 90) {
				printf("***** �� ���߾��~~~ *****\n");
			}
			else if (score[i][j] <= 70) {
				printf("�ФФФ� �� ���߾��.... �ФФФ�\n");
			}
		}

		printf("����: %d", total);
		printf("���: %.2f", avg);
		printf("\n\n");
	}
}