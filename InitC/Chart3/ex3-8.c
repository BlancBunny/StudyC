#include <stdio.h> 

int main() {
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	// tax_rate = 0.15; const ������ ���� ���� 
	double* ptr = &tax_rate;

	income = 456;
	tax = income * tax_rate;
	printf("������ : %.1lf�Դϴ�. %p\n", tax, ptr);

	return 0;
}