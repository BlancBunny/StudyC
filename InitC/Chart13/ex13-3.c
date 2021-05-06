#include <stdio.h>

int a;

void assign10();
void assign20();

int main() {

	printf("함수 호출 전 a : %d\n", a); 

	assign10();
	assign20();

	printf("함수 호출 후 a : %d\n", a);

	return 0;
}

void assign10() {
	a = 10;
}

void assign20() {
	int a; 
	a = 20;
}