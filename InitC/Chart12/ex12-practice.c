
// ex12-practice.c : 소문자를 받아서 대문자로 출력하는 프로그램

#include <stdio.h>

int main() {
	char ch;
	int dif = 'a' - 'A';

	while (1) {
		printf("알파벳 입력(0 입력시 종료) : ");
		scanf_s("%c", &ch, sizeof(ch));

		if (ch == '0') {
			printf("프로그램 종료\n");
			break;
		}

		if (ch >= 'A' && ch <= 'Z')
			printf("대문자입니다. 소문자로 변환 -> %c\n", ch + dif);
		else if (ch >= 'a' && ch <= 'z')
			printf("소문자입니다. 대문자로 변환 -> %c\n", ch - dif);
		else printf("알파벳이 아닙니다.\n");

		while (getchar() != '\n');
	}
	return 0;
}
