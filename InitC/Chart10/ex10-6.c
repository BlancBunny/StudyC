// ex10-6.c : �迭 ����� ������ �ٸ� �迭 ��� 
#include <stdio.h>

void print_arr(int*, int);
int main() {
	int arr1[5] = { 10,20,30,40,50 };
	int arr2[7] = { 10,20,30,40,50,60,70 };

	print_arr(arr1, 5);
	printf("\n");
	print_arr(arr2, 7);

	return 0;
}

void print_arr(int* pa, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", pa[i]);
	}
}