#include <stdio.h>
#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")


int main() {
	double radius, area;
	printf("반지름 입력 : ");
	scanf_s("%lf", &radius);
	area = PI * radius * radius;
	if (area > LIMIT) ERR_PRN; 
	else printf("원의 면적 : %.2lf (%s)\n", area, MSG);

	return 0;
}