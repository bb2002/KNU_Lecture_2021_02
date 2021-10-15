#include<stdio.h>

int main() {
	double x;
	printf("x의 값을 입력하시오: ");
	scanf("%lf", &x);

	if (x <= 0) {
		printf("f(x)의 값은 %lf", (x * x - 9 * x + 2));
	}
	else {;
		printf("f(x)의 값은 %lf", (7 * x + 2));
	}
	
}