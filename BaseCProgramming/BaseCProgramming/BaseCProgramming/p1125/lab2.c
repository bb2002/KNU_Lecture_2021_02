#include<stdio.h>

void get_sum_diff(int x, int y, int* p_sum, int* p_diff) {
	*p_sum = x + y;
	*p_diff = x - y;
}

int main() {
	int sum, diff;
	get_sum_diff(200, 300, &sum, &diff);
	printf("�� ���� ����: %d\n", sum);
	printf("�� ���� ����: %d\n", diff);

}