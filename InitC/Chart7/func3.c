#include <stdio.h>
#include "func3.h"

void swap(int, int);
int main() {
	int a, b;
	a = 10, b = 20;
	
	printf("%d\n", func(a,b));
	printf("a : %d, b : %d\n", a, b);
	swap(a, b);
	printf("a : %d, b : %d\n", a, b);

	return 0;
}


void muyaho() {
	printf("¹«¾ßÈ£!");
}

void num() {
	int a = 3; 
	int b = 4; 
	return a + b;
}

void swap(int x, int y) {
	int tmp = x;
	x = y;
	y = tmp;
}

