//Calculator_v3.c
//
//Created : 2021-04-28
//Author : 김현수

#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	char ch;
	int result = 0;
	double result_d = 0.0;

	while (1) {
		// 0. 실행 여부 
		printf("계산기 실행? (y/n) : ");
		scanf_s("%c", &ch, sizeof(ch));
		
		if (ch == 'y' || ch == 'Y') {

		}
		else if (ch == 'n' || ch == 'N') {
			printf("프로그램 종료!");
			exit(0);
		}
		else {
			printf("올바르지 않은 입력\n");
			printf("========================\n");
			while (getchar() != '\n');
			continue;
		}


		// 1. 두 값을 입력을 받는다.
		printf("값 2개 입력 : ");
		if (scanf_s("%d %d", &a, &b) != 2) {  // 정상적으로 정수 2개가 입력되지 않았을 경우
			printf("정수만 입력해야 합니다. 다시 시도해주세요.\n");
			printf("========================\n");
			while (getchar() != '\n');
			continue;
		}

		// 2. 연산 기호를 입력받는다.
		printf("연산 기호 입력(+, -, *, /, q(종료)) : ");
		scanf_s(" %c", &ch, sizeof(ch));

		// 3. 연산을 수행한다. 
		switch (ch) {
		case 'q':
			printf("프로그램 종료!");
			exit(0);
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result_d = (double)a / (double)b; // divide 결과는 double
			break;
		default:
			printf("올바른 연산 기호를 입력하세요.\n");
			printf("========================\n");
			while (getchar() != '\n');
			continue;
		}

		// 4. 연산 결과를 출력한다. 
		if (ch == '/') { // 나눗셈 
			if (b == 0) printf("0으로 나눌 수 없습니다.\n");
			else printf("연산 결과 : %d %c %d = %g\n", a, ch, b, result_d);
		}
		else printf("연산 결과 : %d %c %d = %d\n", a, ch, b, result); // 그 외 
		printf("========================\n");
		while (getchar() != '\n');
	}

	return 0;
}


