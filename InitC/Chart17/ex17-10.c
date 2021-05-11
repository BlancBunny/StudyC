#include <stdio.h>

union student {
	int num;
	double grade;
};

struct student1
{
	int num;
	double grade;
};


int main() {
	union student s1 = { 315 };
	struct student1 s2;

	printf("s1 size : %d\n", sizeof(s1));
	printf("s2 size : %d\n", sizeof(s2));


	return 0;
}

