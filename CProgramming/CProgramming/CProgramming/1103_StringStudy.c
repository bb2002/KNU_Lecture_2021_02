#include<stdio.h>

int main() {
	char a[20];
	char b[20];
	gets(a, 19);
	gets(b, 19);

	int result = strcmp(a, b);
	if (result == 0) {
		printf("Equal!!");
	}
	else if (result > 0) {
		printf("a �� �ڿ� �ִ�.");
	}
	else {
		printf("a �� �տ� �ִ�.");
	}
}