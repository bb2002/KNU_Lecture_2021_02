#include <stdio.h>

int main() {
	const double PI = 3.141592;

	double r;
	printf("구의 반지름을 입력하시오: ");
	scanf("%lf", &r);
	printf("표면적은 %lf 입니다.\n", (4. * PI * r * r));
	printf("체적은 %lf 입니다.", (4. / 3. * PI * r * r * r));
}