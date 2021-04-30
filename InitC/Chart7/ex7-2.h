#pragma once

int main();

int get_num() {
	int num;

	printf("양수 입력 : ");
	scanf_s("%d", &num);

	return num;
}
