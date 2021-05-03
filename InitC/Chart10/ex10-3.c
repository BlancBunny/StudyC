#include <stdio.h>

int main() {
	int arr[3] = { 10,20,30 };
	int* pa = arr;
	int i;

	printf("배열의 값 : ");
	for (i = 0; i < 3; i++) {
		printf("%d ", *pa);
		pa++;
	}


	return 0;
}