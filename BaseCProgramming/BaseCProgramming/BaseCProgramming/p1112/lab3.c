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
		printf("��й�ȣ: ");
		scanf("%d", &passwdIn);
		
		switch (check(passwdIn)) {
			case 1:
				printf("�α��� �Ǿ����ϴ�.");
				return;
			case 0:
				continue;
			case -1:
				printf("�α��� �õ�Ƚ�� �ʰ�");
				return;
		}
	}
}