#include <stdio.h>
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

int exit_check(char ch) {
	if (ch == 'y' || ch == 'Y') return 0;  // 진행
	else if (ch == 'n' || ch == 'N') func_exit(); // 종료
	else {
		wrong_input();
		return -1;
	}
		 // continue
}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

double divide(int a, int b) {
	return (double)a/(double)b;
}

char input_char(char str[100]) {
	char ch;
	printf("%s", str);
	scanf_s(" %c", &ch, sizeof(ch));
	return ch;
}

void print_res(int a, int b, char ch, int result, double result_d) {
	if (ch == '/') {
		if (b == 0) printf("0으로 나눌 수 없습니다. \n");
		else printf("연산 결과 : %d %c %d = %g\n", a, ch, b, result_d);
	}
	else printf("연산 결과 : %d %c %d = %d\n", a, ch, b, result);
	printf("========================\n");
	while (getchar() != '\n');
}