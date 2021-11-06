#include<stdio.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }

int main() {
	int (*funcs[4])(int, int) = { add, sub, mul, div };
	int choice, x, y, result;

	printf("=====================\n");
	printf("0. µ¡¼À\n");
	printf("1. »¬¼À\n");
	printf("2. °ö¼À\n");
	printf("3. ³ª´°¼À\n");
	printf("4. Á¾·á\n");
	printf("=====================\n");

	scanf("%d", &choice);

	if (choice < 0 || choice >= 4) return;

	printf("2°³ÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ½Ã¿À:");
	scanf("%d %d", &x, &y);
	result = funcs[choice](x, y);
	printf("¿¬»ê °á°ú = %d\n", result);
}