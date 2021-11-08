/* 파일 설명 */
// 이름: hypotenuse.c
// C프로그래밍 박치현 과제#2-1
// 함수 구현 및 라이브러리 사용 실습

/* 프로그램 설명 */
// 직각 삼각형의 빗변이 아닌 두 변의 길이를 입력 받아
// 빗변의 길이를 출력하는 프로그램.
// 두 변의 길이는 정수로 입력 받고, 빗변의 길이는 실수로 출력된다.

#include <stdio.h>
#include <math.h>

double calcHyp(int, int);
long long power(int, int);

int main(void) {
	int x, y;
	double result;
	printf("빗변이 아닌 두 변의 길이를 입력하세요: ");
	scanf_s("%d %d", &x, &y);
	
	printf("빗변의 길이: %.3f", calcHyp(x, y));

	return 0;
}

// 빗변을 계산하는 함수
// 입출력: 두 변의 길이가 주어지면 빗변의 길이를 실수로 반환한다.
double calcHyp(int a, int b)
{
	return sqrt(power(a, 2) + power(b, 2));
}

// aⁿ을 계산하는 함수
// 입출력: 정수 a를 n번 제곱한 값을 반환한다.
long long power(int a, int n)
{
	long long result = a;
	for (int i = 1; i < n; ++i) {
		result *= a;
	}

	return result;
}