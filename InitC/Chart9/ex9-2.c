#include <stdio.h>

int main() {
	int a;
	int* pa;

	
	pa = &a;
	*pa = 10;

	printf("포인터로 a 값 출력 : %d\n", *pa);
	printf("a 값의 주소 출력 : %p\n", &a);
	printf("포인터 변수가 가리키는 주소값 : %p\n", pa);
	printf("변수명으로 a 값 출력 : %d\n", a);

	return 0;
}