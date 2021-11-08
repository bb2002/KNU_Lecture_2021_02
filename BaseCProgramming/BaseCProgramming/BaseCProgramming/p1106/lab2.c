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
	printf("문자를 입력하시오: ");
	char c = getchar();

	if (checkAlpha(c)) {
		printf("%c는 알파벳 문자입니다.", c);
	}
	else {
		printf("%c는 알파벳 문자아닙니다.", c);
	}
}