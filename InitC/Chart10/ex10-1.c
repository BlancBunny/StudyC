#include <stdio.h>

int main() {
	int arr[3] = {0};
	int i;

	*(arr + 0) = 10;
	*(arr + 1) = *(arr + 0) + 10;

	printf("세 번째 배열 요소에 입력 : ");
	scanf_s("%d", arr + 2);

	for (i = 0; i < 3; i++) {
		printf("arr[%d] = %d\n",i, *(arr + i));
	}

	return 0;
}