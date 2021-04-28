#include <stdio.h>

int main() {
	int a = 10, b = 20, c = 10;
	int res;

	printf("a : 10, b : 20, c : 10\n");

	res = (a > b);
	printf("a > b : %d\n", res);
	res = (a < b);
	printf("a < b : %d\n", res);
	res = (a >= b);
	printf("a >= b : %d\n", res);
	res = (a <= b);
	printf("a <= b : %d\n", res);
	res = (a == c);
	printf("a == c : %d\n", res);
	res = (a == b);
	printf("a == b : %d\n", res);
	res = (a != c);
	printf("a != c : %d\n", res);

	return 0;
	
}