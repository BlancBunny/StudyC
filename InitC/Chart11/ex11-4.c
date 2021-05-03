#include <stdio.h>

int main() {
	char ch; 
	int i;

	for (i = 0; i < 6; i++) {
		scanf_s("%c", &ch, sizeof(ch));
		printf("%c", ch);
	}
}