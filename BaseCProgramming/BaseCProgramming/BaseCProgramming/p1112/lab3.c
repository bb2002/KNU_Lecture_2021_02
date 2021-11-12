#include<stdio.h>

int check(int passIn) {
	static int failCnt = 0;

	if (passIn == 1234) {
		return 1;
	}
	else {
		++failCnt;
		if (failCnt >= 3) {
			return -1;
		}

		return 0;
	}
}

int main() {
	int passwdIn = 0;
	while (1) {
		printf("비밀번호: ");
		scanf("%d", &passwdIn);
		
		switch (check(passwdIn)) {
			case 1:
				printf("로그인 되었습니다.");
				return;
			case 0:
				continue;
			case -1:
				printf("로그인 시도횟수 초과");
				return;
		}
	}
}