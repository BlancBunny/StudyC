#include <stdio.h>

void hanoi(int, char, char, char);
int cnt = 0;

int main() {
    	int n;
	printf("insert number : ");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	printf("count : %d\n", cnt);

	return 0;
}

void hanoi(int n, char a, char b, char c) {
	if (n<=1) {
		printf("move %d : %c -> %c\n", n, a, c);
		cnt++;
	}
	else {
		hanoi(n-1, a, c, b);
		printf("move %d : %c -> %c\n", n, a, c);
		cnt++;
		hanoi(n-1, b, a, c);
	}
}
