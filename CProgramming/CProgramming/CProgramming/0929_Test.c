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
		printf("俳持 戚硯聖 脊径馬室推: ");
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

		printf("%s 俳持税 引鯉 繊呪\n", name);
		for (int j = 0; j < cSize; ++j) {
			printf("引鯉 %d税 繊呪澗 %d脊艦陥.\n", j + 1, score[i][j]);

			if (score[i][j] >= 90) {
				printf("***** 凧 設梅嬢推~~~ *****\n");
			}
			else if (score[i][j] <= 70) {
				printf("ばばばば 凧 公梅嬢推.... ばばばば\n");
			}
		}

		printf("恥繊: %d", total);
		printf("汝液: %.2f", avg);
		printf("\n\n");
	}
}