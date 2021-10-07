#include<stdio.h>

int main() {
	int year;
	printf("연도를 입력하시오: ");
	scanf("%d", &year);

	printf("%d 년은 %s", year, (((year % 4 == 0) && year % 100 != 0) || (year % 400 == 0)) ? "윤년입니다." : "윤년이아닙니다.");
}