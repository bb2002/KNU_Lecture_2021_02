#include<stdio.h>

int main() {
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	for (int i = 0; i < 12; ++i) {
		printf("%d월은 %d일 까지 있습니다.\n", i + 1, days[i]);
	}
}