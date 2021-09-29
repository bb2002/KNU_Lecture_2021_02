#include <stdio.h>

void buf_clear() {
	while (getchar() != '\n');
}

int main() {
	char cmd;

	while (1) {
		double lts, rts;
		char oper;

		printf("사칙연산 계산기 입니다. 종료를 원한다면 x를 입력하고, 계산을 원한다면 c를 입력하세요: ");
		scanf_s("%c", &cmd, (unsigned int)sizeof(cmd));

		if (cmd == 'x') {
			break;
		} else if (cmd != 'c') {
			printf("\n");
			buf_clear();
			continue;
		}

		printf("\n실수 2개와 연산자 [+ - * /] 중 하나를 입력하세요. (예> 4.2*3.1): ");
		scanf_s("%lf", &lts);
		scanf_s("%c", &oper, (unsigned int)sizeof(oper));
		scanf_s("%lf", &rts);

		printf("%lf %c %lf = ", lts, oper, rts);

		if (oper == '+') {
			printf("%lf", lts + rts);
		}
		else if (oper == '-') {
			printf("%lf", lts - rts);
		}
		else if (oper == '*') {
			printf("%lf", lts * rts);
		}
		else if (oper == '/') {
			printf("%lf", lts / rts);
		}
		else {
			printf("알 수 없는 연산자입니다.");
		}

		buf_clear();
		printf("\n"); printf("\n");
	}	

	printf("종료합니다.");
}