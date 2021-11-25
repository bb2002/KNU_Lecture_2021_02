#include<stdio.h>

void get_sum_diff(int x, int y, int* p_sum, int* p_diff) {
	*p_sum = x + y;
	*p_diff = x - y;
}

int main() {
	int sum, diff;
	get_sum_diff(200, 300, &sum, &diff);
	printf("두 수의 합은: %d\n", sum);
	printf("두 수의 차는: %d\n", diff);

}