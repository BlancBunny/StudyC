#include <stdio.h>

int main() {

	int a = 10, b = 10;
	++a; 
	--b;

	printf("a : %d\n", a);
	printf("b : %d\n", b);

	//ex4-4.c
	a = 5, b = 5;
	int pre, post;

	printf("�ʱⰪ a = %d, b = %d\n", a, b);

	pre = (++a) * 3; // 20 
	post = (b++) * 3; // 15 

	printf("������ ��� : %d, ������ ��� : %d\n", pre, post);
	
	return 0;
}