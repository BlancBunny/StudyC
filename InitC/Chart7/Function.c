#include <stdio.h>

int sum(int a, int b);
int main() {
	int x = 3;
	int y = 4;
	int res = sum(x, y);
	return 0;
}

int sum(int a, int b) {
	printf("%d", a + b);
	return a + b;
}

