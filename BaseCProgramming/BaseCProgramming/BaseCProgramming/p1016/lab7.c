#include<stdio.h>

int main() {
	int weight, height, stdWeight;

	printf("체중과 키를 입력하세요: ");
	scanf("%d%d", &weight, &height);
	stdWeight = (height - 100) * 0.9;

	if (weight < stdWeight) {
		printf("저체중 입니다.\n");
	}
	else if(weight > stdWeight) {
		printf("과체중 입니다.\n");
	}
	else {
		printf("정상체중 입니다.\n");
	}
}