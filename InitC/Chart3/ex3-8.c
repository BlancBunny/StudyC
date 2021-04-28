#include <stdio.h> 

int main() {
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	// tax_rate = 0.15; const 변수는 변경 제한 
	double* ptr = &tax_rate;

	income = 456;
	tax = income * tax_rate;
	printf("세금은 : %.1lf입니다. %p\n", tax, ptr);

	return 0;
}