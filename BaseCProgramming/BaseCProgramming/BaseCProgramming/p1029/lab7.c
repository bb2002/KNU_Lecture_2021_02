#include<stdio.h>

#define NUMBER 100

int main() {
	for (int i = 2; i <= NUMBER; ++i) {
		int isPrime = 0;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				++isPrime;
				break;
			}
		}

		if (isPrime == 0) {
			printf("%d ", i);
		}
	}
}