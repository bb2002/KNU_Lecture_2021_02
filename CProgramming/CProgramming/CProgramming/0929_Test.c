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
		printf("학생 이름을 입력하세요: ");
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

		printf("%s 학생의 과목 점수\n", name);
		for (int j = 0; j < cSize; ++j) {
			printf("과목 %d의 점수는 %d입니다.\n", j + 1, score[i][j]);

			if (score[i][j] >= 90) {
				printf("***** 참 잘했어요~~~ *****\n");
			}
			else if (score[i][j] <= 70) {
				printf("ㅠㅠㅠㅠ 참 못했어요.... ㅠㅠㅠㅠ\n");
			}
		}

		printf("총점: %d", total);
		printf("평균: %.2f", avg);
		printf("\n\n");
	}
}