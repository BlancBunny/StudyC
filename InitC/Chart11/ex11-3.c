#include <stdio.h>

int main() {

	// ����
	int ch; 
	
	ch = getchar();
	printf("�Է��� ���� : ");
	putchar(ch);
	putchar('\n');

	// ���ڿ�
	char c[20];

	gets_s(c, 20);
	printf("�Է��� ���ڿ� : ");
	puts(c);


	return 0;
}