#include <stdio.h>

int main() {

	// 문자
	int ch; 
	
	ch = getchar();
	printf("입력한 문자 : ");
	putchar(ch);
	putchar('\n');

	// 문자열
	char c[20];

	gets_s(c, 20);
	printf("입력한 문자열 : ");
	puts(c);


	return 0;
}