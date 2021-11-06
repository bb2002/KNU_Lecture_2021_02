#include<stdio.h>

void memzero(void* ptr, size_t len) {
	int* p = (int*)ptr;

	for (int i = 0; i < len; ++i) {
		*p++ = 0;
	}
}

int main() {
	char a[10];
	memzero(a, sizeof(a));
	int b[10];
	memzero(b, sizeof(b));
	double c[10];
	memzero(c, sizeof(c));
	return 0;
}