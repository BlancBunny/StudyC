#include <stdio.h>

int main() {
	int arr[5] = { 10,20,30,40,50 };
	int* pa = arr;   // [0]
	int* pb = pa + 3; // [3]

	printf("pa : %p\n", pa);
	printf("pb : %p\n", pb);
	pa++;

	printf("pb - pa : %d\n", pb - pa);
	// pb - pa = (�ּ� �� ����) / sizeof(int) = 2

	printf("�տ� �ִ� �迭 ����� �� ��� : ");
	if (pa < pb) printf("%d\n", *pb);
	else printf("%d\n", *pa);

	return 0;

}