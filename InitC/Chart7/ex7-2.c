#include <stdio.h>

int get_num();
int main() {
	int result;

	result = get_num();
	printf("반환값 : %d\n", result);
	return 0;
}

int get_num() {
	int num;

	printf("양수 입력 : ");
	scanf_s("%d", &num);

	return num;
}

