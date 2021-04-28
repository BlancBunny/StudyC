#include <stdio.h>

int main() {
	int a;
	int* pa;
	pa = &a;
	*pa = 10;

	printf("%d", a);
}
