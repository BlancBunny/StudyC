#include <stdio.h>

int a;

void assign10();
void assign20();

int main() {

	printf("�Լ� ȣ�� �� a : %d\n", a); 

	assign10();
	assign20();

	printf("�Լ� ȣ�� �� a : %d\n", a);

	return 0;
}

void assign10() {
	a = 10;
}

void assign20() {
	int a; 
	a = 20;
}