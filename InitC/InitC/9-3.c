#include <stdio.h> 
int main() {
	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;
	int* pt = &total;
	double* pg = &avg;
	pa = &a;
	pb = &b;
	*pt = *pa + *pb; 
	*pg = *pt / 2.0;

	printf("%f", avg);

	return 0;

}