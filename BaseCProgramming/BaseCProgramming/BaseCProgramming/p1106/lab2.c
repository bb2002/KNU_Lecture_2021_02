#include<stdio.h>

int checkAlpha(char c) {
	if (c >= 'a' && c <= 'z') {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	printf("���ڸ� �Է��Ͻÿ�: ");
	char c = getchar();

	if (checkAlpha(c)) {
		printf("%c�� ���ĺ� �����Դϴ�.", c);
	}
	else {
		printf("%c�� ���ĺ� ���ھƴմϴ�.", c);
	}
}