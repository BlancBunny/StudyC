#include <stdio.h>

int main() {
	int res; 
	char ch;

	while (1) {
		res = scanf_s("%c", &ch, sizeof(ch));
		if (res == EOF) break;
		printf("%d ", ch);
	}

	return 0;
}