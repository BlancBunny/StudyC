/*
	LottaryProgram.c 
	1. 로또 번호를 저장할 수 있는 배열 선언 (lotto[6]) 
	2. 로또 번호 입력 
	(동일한 번호 입력 시 에러 메시지 출력 후 다시 입력 받기)
	
	input_lotto(), print_lotto() 
*/

#include <stdio.h> 
#include "LottaryProgram.h"

int main() {
	int lotto[6];
	int size = sizeof(lotto) / sizeof(lotto[0]);

	input_lotto(lotto, size); // 입력
	print_lotto(lotto, size); // 출력
	
	return 0; 
}