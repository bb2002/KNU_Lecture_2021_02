/* ���� ���� */
// �̸�: hypotenuse.c
// C���α׷��� ��ġ�� ����#2-1
// �Լ� ���� �� ���̺귯�� ��� �ǽ�

/* ���α׷� ���� */
// ���� �ﰢ���� ������ �ƴ� �� ���� ���̸� �Է� �޾�
// ������ ���̸� ����ϴ� ���α׷�.
// �� ���� ���̴� ������ �Է� �ް�, ������ ���̴� �Ǽ��� ��µȴ�.

#include <stdio.h>
#include <math.h>

double calcHyp(int, int);
long long power(int, int);

int main(void) {
	int x, y;
	double result;
	printf("������ �ƴ� �� ���� ���̸� �Է��ϼ���: ");
	scanf_s("%d %d", &x, &y);
	
	printf("������ ����: %.3f", calcHyp(x, y));

	return 0;
}

// ������ ����ϴ� �Լ�
// �����: �� ���� ���̰� �־����� ������ ���̸� �Ǽ��� ��ȯ�Ѵ�.
double calcHyp(int a, int b)
{
	return sqrt(power(a, 2) + power(b, 2));
}

// a���� ����ϴ� �Լ�
// �����: ���� a�� n�� ������ ���� ��ȯ�Ѵ�.
long long power(int a, int n)
{
	long long result = a;
	for (int i = 1; i < n; ++i) {
		result *= a;
	}

	return result;
}