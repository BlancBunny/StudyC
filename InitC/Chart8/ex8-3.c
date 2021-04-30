#include <stdio.h>

int main() {
	int score[5];
	int total = 0;

	double avg;
	int count;

	count = sizeof(score) / sizeof(score[0]);

	for (int i = 0; i < count; i++) {
		printf("%d번째 값 입력 : ", i + 1);
		scanf_s("%d", &score[i]);
		total += score[i];
	}
	avg = total / (double)count;

	for (int i = 0; i < count; i++) {
		printf("%5d", score[i]);
	}
	printf("\n");
	printf("avg : %.1lf", avg);

	return 0;
}