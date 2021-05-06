#include <stdio.h>

void func(int (*fp)(int, int));
int sum(int, int);
int mul(int, int);
int max(int, int);

int main() {
	int sel;

	printf("01 : 두 정수의 합\n");
	printf("02 : 두 정수의 곱\n");
	printf("03 : 두 정수 중에서 큰 수\n");

	printf("연산 입력 : ");
	scanf_s("%d", &sel);

	switch (sel) {
	case 1: func(sum); break;
	case 2: func(mul); break;
	case 3: func(max); break;
	}

	return 0;
}

void func(int (*fp)(int, int)) {
	int a, b;
	int res;
	printf("두 정수 입력 : ");
	scanf_s("%d %d", &a, &b);
	res = fp(a, b);
	printf("결과 : %d", res);
}


int sum(int a, int b) {
	return a + b;
}

int mul(int a, int b) {
	return a * b;
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}