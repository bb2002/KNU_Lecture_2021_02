#include <stdio.h>

int main() {
	const double PI = 3.141592;

	double r;
	printf("���� �������� �Է��Ͻÿ�: ");
	scanf("%lf", &r);
	printf("ǥ������ %lf �Դϴ�.\n", (4. * PI * r * r));
	printf("ü���� %lf �Դϴ�.", (4. / 3. * PI * r * r * r));
}