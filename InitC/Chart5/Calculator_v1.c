//Calculator_v1.c
//
//Created : 2021-04-28
//Author : ������

#include <stdio.h>

int main() {
	int a, b;
	int add, sub, mul;
	double div;

	// 1. �� ���� �Է��� �޴´�.
	printf("�� 2�� �Է� : ");
	scanf_s("%d %d", &a, &b);
	
	// 2. ��Ģ������ �����Ѵ�.
	add = a + b;
	sub = a - b;
	mul = a * b;
	div = (b != 0) ? (double)a / (double)b : -1;

	// 3. ���� ����� ����Ѵ�. 
	printf("%d + %d = %d\n", a, b, add);
	printf("%d - %d = %d\n", a, b, sub);
	printf("%d x %d = %d\n", a, b, mul);
	printf("%d / %d = %.2lf\n", a, b, div);

	return 0;
}
