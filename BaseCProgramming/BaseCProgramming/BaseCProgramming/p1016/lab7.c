#include<stdio.h>

int main() {
	int weight, height, stdWeight;

	printf("ü�߰� Ű�� �Է��ϼ���: ");
	scanf("%d%d", &weight, &height);
	stdWeight = (height - 100) * 0.9;

	if (weight < stdWeight) {
		printf("��ü�� �Դϴ�.\n");
	}
	else if(weight > stdWeight) {
		printf("��ü�� �Դϴ�.\n");
	}
	else {
		printf("����ü�� �Դϴ�.\n");
	}
}