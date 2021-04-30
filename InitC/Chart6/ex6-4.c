#include <stdio.h>

int main() {
	int i, j;
	/*for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			printf("*");
		}
		printf("\n");
	}*/

	// 피라미드형 
	for (i = 0; i <= 5; i++) {
		for (j = 5; j > i; j--) {
			printf(" ");
		}
		for (j = 0; j < 2*i+1; j++) {
			printf("*");
		}
		printf("\n");
	}

	// 역피라미드형 
	for (i = 0; i <= 5; i++) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = 0; j < 11-2*i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

//i 0 1 2 3 4 5 
//x 5 4 3 2 1 0 
//y 1 3 5 7 9 11 i