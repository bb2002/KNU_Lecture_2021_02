#include<stdio.h>

int main() {
	unsigned int data;
	char in;

	printf("ù��° ���ڸ� �Է��Ͻÿ�: ");
	scanf("%c", &in);
	data = in;
	getchar();

	printf("�ι�° ���ڸ� �Է��Ͻÿ�: ");
	scanf("%c", &in);
	data = data | in << 8;
	getchar();

	printf("����° ���ڸ� �Է��Ͻÿ�: ");
	scanf("%c", &in);
	data = data | in << 16;
	getchar();

	printf("�׹�° ���ڸ� �Է��Ͻÿ�: ");
	scanf("%c", &in);
	data = data | in << 24;
	getchar();

	printf("�����: %0X", data);
}