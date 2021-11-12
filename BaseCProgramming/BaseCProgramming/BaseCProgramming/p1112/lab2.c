#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void get_dice_face() {
	static int roundCnt = 0;
	static int faceCnt[] = { 0,0,0,0,0,0 };

	++faceCnt[rand() % 6];
	++roundCnt;

	if (roundCnt >= 100) {
		for (int i = 0; i < 6; ++i) {
			printf("%d -> %d\n", i + 1, faceCnt[i]);
		}
	}
}

int main() {
	srand((unsigned)time(NULL));

	for (int i = 0; i < 100; ++i) {
		get_dice_face();
	}
}