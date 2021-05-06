#include <stdio.h>

int* sum(int, int);

int main() {
	int* resp;
	resp = sum(10, 20);

	printf("두 정수의 합 : %d\n", *resp);
	
	return 0;
}

int* sum(int a, int b) {
	static int res; // static 변수는 data 영역에 존재하므로 
					// 함수가 끝나도 메모리가 회수되지 않음 
	res = a + b;
	return &res;
}

