#include <stdio.h>

void add_ten(int);
void add_ten_p(int*);
int main() {
	int a = 10;

	add_ten(a);
	printf("a : %d\n", a);
	
	add_ten_p(&a);
	printf("a : %d\n", a);
	
	return 0;
}

void add_ten(int a) {
	a += 10;
}

void add_ten_p(int* pa) {
	*pa += 10;
}