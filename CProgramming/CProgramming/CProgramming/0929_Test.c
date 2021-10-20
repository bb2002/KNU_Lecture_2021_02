#include <stdio.h>

int main(void)
{
	int i = 10;
	float* iptr = &i;
	printf("%d", (*iptr));
}
