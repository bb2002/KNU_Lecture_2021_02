#include<stdio.h>
//#define DEBUG

int main() {
#ifdef DEBUG
	printf("DEBUG ��ũ�ΰ� �ִ�.");
#endif
	printf("main() �P");
}