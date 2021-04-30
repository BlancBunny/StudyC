#include <stdio.h> 

int main() {
	int score[5];
	int i;
	int total = 0;
	double avg;

	for (i = 0; i < 5; i++) {
		printf("%d번째 값 입력 : ", i+1);
		scanf_s("%d", &score[i]);
	}

	for (i = 0; i < 5; i++) {
		total += score[i];
	}
	avg = total / 5.0;

	for (i = 0; i < 5; i++) {
		printf("%5d", score[i]);
	}
	printf("\n");
	printf("평균 : %.1lf", avg);
}

