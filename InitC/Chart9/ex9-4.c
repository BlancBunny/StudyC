#include <stdio.h>

int main() {
	int a = 10, b = 20;
	const int* pa = &a; // 포인터가 참조하는 데이터가 상수 -> 값이 고정 
	int* const pb = &b; // 포인터 자체가 상수 -> 주소값이 고정 

	printf("변수 a 값 : %d\n", *pa);
	pa = &b; 
	printf("변수 b 값 : %d\n", *pa);
	pa = &a; 
	a = 20;	// *pa = 20; >> const *pa 에 의해 오류 
	printf("변수 a 값 : %d\n", *pa);

	return 0;
}