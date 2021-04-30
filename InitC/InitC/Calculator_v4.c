//Calculator_v4.c
//
//Created : 2021-04-28
//Author : 김현수

#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"

int main() {
	int a, b;
	char ch;
	int result = 0;
	double result_d = 0.0;

	while (1) {
		// 0. 실행 여부 검사
		ch = input_char("계산기 실행? (y/n) : "); 
		if(exit_check(ch) == -1) continue;
		
		// 1. 두 값을 입력을 받는다.
		printf("값 2개 입력 : ");
		if (scanf_s("%d %d", &a, &b) != 2) {  // 정상적으로 정수 2개가 입력되지 않았을 경우
			wrong_input();
			continue;
		}

		// 2. 연산 기호를 입력받는다.
		ch = input_char("연산 기호 입력(+, -, *, /, q(종료)) : ");

		// 3. 연산을 수행한다. 
		switch (ch) {
		case 'q':
			func_exit();
		case '+':
			result = add(a, b);
			break;
		case '-':
			result = sub(a, b);
			break;
		case '*':
			result = mul(a, b);
			break;
		case '/':
			result_d = divide(a, b); // 나눗셈 결과 -> 실수
			break;
		default:
			wrong_input();
			continue;
		}

		// 4. 연산 결과를 출력한다. 
		print_res(a, b, ch, result, result_d);
	}
	return 0;
}


