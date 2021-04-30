#pragma once

int main();

void func_exit() {
	printf("프로그램 종료!");
	exit(0);
}

void wrong_input() {
	printf("올바르지 않은 입력\n");
	printf("===========================\n");
	while (getchar() != '\n');
}