#include <stdio.h>

int main() {
	char a;
	scanf_s("%c", &a, sizeof(a));
	printf("입력된 값 : %c\n", a);

	return 0;
}