/* 파일 설명 */
// 이름: clawcrane_game.c
// C프로그래밍 박치현 과제#2-2
// 함수 구현 및 라이브러리 사용 실습

/* 프로그램 설명 */
// 인형 뽑기 기계 시스템 구현
// 돈을 입력받고 크레인 조작 후 결과 출력까지
// 인형 뽑기 기계의 전반적인 시뮬레이션을 구현한다.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getCoin();
void resetMachine();
void viewMachine();
int getCommand();
void craneDrop();

int crane, prize;

int main(void)
{
	srand((unsigned) time(NULL));

	while (1)
	{
		int coin = getCoin();

		// getCoin의 반환값이 -1이면 무한루프를 종료한다.
		if (coin == -1) break;

		resetMachine();	// 뽑기 기계 상태 초기화
		for (; coin > 0; --coin)	// 코인의 개수만큼 반복. 코인의 개수는 점점 줄어들어야 한다. coin 변수만을 이용하시오.
		{
			int i;
			printf("현재 코인 수: %d\n", coin);

			for (i=0; i<10; i++)
			{
				printf("남은 시간: %d\n", 10-i);
				viewMachine();
				if (getCommand())	// 조작을 입력받고 반환값이 true이면 시간 종료
					break;
			}

			craneDrop();	// 시간 종료 시 크레인을 떨어뜨린다.
			crane = 0;		// 크레인 초기화
		}
	}
}


// 돈을 입력 받는 함수
// 500원당 코인 1개가 지급되도록 계산하고 거스름돈을 돌려줘야 한다.
// 이때 음수가 입력되면 무한 루프가 종료되도록 -1을 반환해준다.
// 입출력: 돈의 금액이 주어지면 코인 개수를 반환한다. 거스름돈은 콘솔에 출력한다.
int getCoin()
{
	int money;
	int coin, change;

	printf("투입할 금액을 입력하세요 (1회당 500원): ");
	scanf_s("%d", &money);

	if (money < 0) {
		return -1;
	}

	change = money % 500;
	coin = money / 500;

	if (change != 0) {
		printf("거스름돈을 받으세오: %d\n\n", change);
	}

	return coin;
	// 금액이 음수면 -1을 반환. 그렇지 않으면 코인과 거스름돈 계산
	// 이때 거스름돈이 존재하면 출력
}


// 기계의 상태를 초기화하는 함수
// 크레인의 위치를 처음으로 이동시키고, 상품의 위치를 랜덤으로 옮긴다.
// 입출력: 없음
void resetMachine()
{
	// 크레인의 위치를 배출구가 있는 0으로 이동
	// 상품의 위치를 1~5의 난수로 지정
	crane = 0;
	prize = rand() % 5 + 1;
}


// 기계의 상태를 보여주는 함수
// 입출력: 현재 크레인 상태와 상품의 위치를 출력한다.
void viewMachine()
{
	int i;

	printf("========\n ");
	for (i=0; i<=5; i++)
	{
		if (crane == i)
			printf("A");
		else
			printf(" ");
	}
	printf("\n ");

	printf("U");
	for (i=1; i<=5; i++)
	{
		if (prize == i)
			printf("o");
		else
			printf("_");
	}
	printf("\n");
	printf("========\n");
}


// 사용자로부터 조작을 입력받는 함수
// l와 r로 크레인을 좌우로 이동하고, d로 크레인을 내린다.
// 입출력: 크레인을 내릴 시 반복문을 종료하기 위해 true를 정수로 반환한다. 그 외에는 false를 정수로 반환한다.
int getCommand()
{
	char cmd;
	printf("시행할 조작을 입력하세요(r, l, d): ");
	scanf_s("%*[\n]%c", &cmd, 1);	// 개행 문자 무시 (9/27 공지에 게시돼있음)

	// 각 문자에 대해 switch-case문을 통하여 크레인을 조작하는 구문을 작성
	// 크레인이 기계 밖을 넘어가지 않게 조건문을 통해 통제할 것
	// l, r, d 외의 문자를 입력했을 때는 오류 메세지를 출력
	switch (cmd) {
	case 'l':
		if (crane - 1 >= 1) --crane;
		return 0;
	case 'r':
		if (crane + 1 <= 5) ++crane;
		return 0;
	case 'd':
		return 1;
	default:
		printf("유효하지 않은 조작입니다.\n");
		return 0;
	}
}


// 크레인을 내려 상품을 잡는 함수
// 크레인의 위치와 상품의 위치가 같으면 상품을 잡을 수 있다.
// 그러나 일정 확률로 잡은 상품을 놓친다.
// 놓치게 되면 배출구 앞에서부터 상품이 있는 곳 사이의 무작위 위치에 떨어진다.
// 입출력: 크레인을 내린 후 결과를 출력한다.
void craneDrop()
{
	printf("\n");
	
	if (prize == crane) {
		// 0~99의 난수가 50보다 작으면 상품을 뽑고
		// 그렇지 않으면 상품을 놓친다.
		// 예를 들어 원래 위치가 3 이었다면 1~3의 위치에 떨어진다.
		int isDrop = rand() % 100 < 50 ? 0 : 1;

		if (isDrop) {
			printf("집게가 상품을 놓쳤습니다!\n\n");
			prize = rand() % (prize + 1) + 1;
		}
		else {
			printf("축하합니다! 상품을 뽑았습니다\n\n");
			prize = rand() % 5 + 1;
		}
	}
	else {
		printf("그곳에는 상품이 없습니다.\n\n");
	}
	

	printf("\n");
}