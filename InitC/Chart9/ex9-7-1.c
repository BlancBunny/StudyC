#include <stdio.h>

void swap();
void swap_v(int, int);
void swap_p(int*, int*);

// int a = 10, b = 20; ���������ε� swap ����(��õ���� ����)

int main() {
	int a = 10, b = 20;
	int* pa = &a;
	int* pb = &b;

	printf("a = %d, b = %d\n", a, b);
	swap_v(a, b);  // Call by Value
	printf("a = %d, b = %d\n", a, b);
	swap_p(pa, pb); // Call by Address 
	printf("a = %d, b = %d\n", a, b);
//	swap();
//	printf("a = %d, b = %d\n", a, b);
	return 0;
}

void swap_v(int a, int b) {
	int tmp;
	printf("swap_v �Լ� ȣ�� (Call by Value) \n");
	tmp = a;
	a = b;
	b = tmp; 
}

void swap_p(int* pa, int* pb) {
	int tmp;
	printf("swap_p �Լ� ȣ�� (Call by Address) \n");
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//void swap() {
//	int tmp;
//	printf("swap �Լ� ȣ�� (Call by Address) \n");
//	tmp = a;
//	a = b;
//	b = tmp;
//}