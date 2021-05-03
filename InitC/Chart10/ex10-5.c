// ex10-5.c : 배열 처리 함수 
#include <stdio.h>

void print_arr(int* pa);
int main() {
	int arr[5] = { 10,20,30,40,50 }; 
	printf("size : %d\n", sizeof(arr));
	print_arr(arr);
	return 0;
}

void print_arr(int* pa) { 
	printf("size : %d\n", sizeof(pa));
	for (int i = 0; i < 5; i++) { 
		printf("%d ", pa[i]);
	}
}
