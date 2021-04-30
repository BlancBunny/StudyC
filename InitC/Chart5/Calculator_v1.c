//Calculator_v1.c
//
//Created : 2021-04-28
//Author : 김현수

#include <stdio.h>

int main() {
	int a, b;
	int add, sub, mul;
	double div;

	// 1. 두 값을 입력을 받는다.
	printf("값 2개 입력 : ");
	scanf_s("%d %d", &a, &b);
	
	// 2. 사칙연산을 수행한다.
	add = a + b;
	sub = a - b;
	mul = a * b;
	div = (b != 0) ? (double)a / (double)b : -1;

	// 3. 연산 결과를 출력한다. 
	printf("%d + %d = %d\n", a, b, add);
	printf("%d - %d = %d\n", a, b, sub);
	printf("%d x %d = %d\n", a, b, mul);
	printf("%d / %d = %.2lf\n", a, b, div);

	return 0;
}
