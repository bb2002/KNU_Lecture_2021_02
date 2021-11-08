#include<stdio.h>
#include<math.h>

double sin_degree(double degree) {
	return sin(3.141592 * degree / 180.0);
}

int main() {
	for (int i = 0; i <= 180; i += 10) {
		printf("sin(%lf) ÀÇ °ªÀº %lf\n", (double)i, sin_degree((double)i));
	}
}