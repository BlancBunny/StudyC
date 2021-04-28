#include <stdio.h> 

int main() {
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.2le\n", 0.0000314);

	// ex2-7.c 

	printf("%c\n", 'A');
	printf("%s\n", "A");
	printf("%c은 %s입니다.\n", '1', "first");
	
	return 0;
}