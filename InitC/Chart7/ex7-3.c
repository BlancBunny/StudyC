#include <stdio.h>

void print_char(char, int);
int main() {
	print_char('@', 5);
	return 0;
}

void print_char(char ch, int n) {
	for (int i = 0; i < n; i++) {
		printf("%c", ch);
	}
	printf("\n");
	return;
}
