#include<stdio.h>
//#define DEBUG

int main() {
#ifdef DEBUG
	printf("DEBUG 메크로가 있다.");
#endif
	printf("main() 긑");
}