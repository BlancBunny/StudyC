#include <stdio.h>

int main() {
	//int a = 10;
	//double b = 3.4;

	//printf("sizeof int : %d\n", sizeof(a));
	//printf("sizeof double : %d\n", sizeof(b));
	//printf("sizeof const int : %d\n", sizeof(3));
	//printf("sizeof result(double) : %d\n", sizeof(1.2 + 3.4));
	//printf("sizeof char : %d\n", sizeof(char));
	//printf("sizeof string \"A\" : %d\n", sizeof("A")); // 널문자 (\0) 포함 2바이트 

	// ex4-10.c
	int a = 10, b = 20;
	int res = 2;

	a += 20;
	res *= b + 10;

	printf("a = %d, b = %d\n", a, b);
	printf("res = %d", res);



	return 0;

	
}