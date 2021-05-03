#include <stdio.h>

int main() {
	char ch1, ch2; 

	scanf_s("%c%c", &ch1, sizeof(ch1), &ch2, sizeof(ch2));
	printf("[%c%c]", ch1, ch2);

	return 0;
}