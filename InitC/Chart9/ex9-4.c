#include <stdio.h>

int main() {
	int a = 10, b = 20;
	const int* pa = &a; // �����Ͱ� �����ϴ� �����Ͱ� ��� -> ���� ���� 
	int* const pb = &b; // ������ ��ü�� ��� -> �ּҰ��� ���� 

	printf("���� a �� : %d\n", *pa);
	pa = &b; 
	printf("���� b �� : %d\n", *pa);
	pa = &a; 
	a = 20;	// *pa = 20; >> const *pa �� ���� ���� 
	printf("���� a �� : %d\n", *pa);

	return 0;
}