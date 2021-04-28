#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() {
	char fruit[20] = "strawberry";
	printf("µþ±â : %s\n", fruit);
	printf("µþ±âÀë : %s %s\n", fruit, "jam");


	// ex3-7.c
	printf("%s\n", fruit);
	strcpy(fruit, "banana");
	printf("%s\n", fruit);
	strcpy_s(fruit, 10 ,"banana");
	printf("%s\n", fruit);

	return 0;

}
