#include <stdio.h>

void buf_clear() {
	while (getchar() != '\n');
}

int main() {
	char cmd;

	while (1) {
		double lts, rts;
		char oper;

		printf("��Ģ���� ���� �Դϴ�. ���Ḧ ���Ѵٸ� x�� �Է��ϰ�, ����� ���Ѵٸ� c�� �Է��ϼ���: ");
		scanf_s("%c", &cmd, (unsigned int)sizeof(cmd));

		if (cmd == 'x') {
			break;
		} else if (cmd != 'c') {
			printf("\n");
			buf_clear();
			continue;
		}

		printf("\n�Ǽ� 2���� ������ [+ - * /] �� �ϳ��� �Է��ϼ���. (��> 4.2*3.1): ");
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
			printf("�� �� ���� �������Դϴ�.");
		}

		buf_clear();
		printf("\n"); printf("\n");
	}	

	printf("�����մϴ�.");
}