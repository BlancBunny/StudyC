#include <stdio.h>

int main() {
	int score[3][4];
	int total;
	double avg;
	int i, j;

	for (i = 0; i < 3; i++) {
		printf("%d번 학생 4과목의 점수 입력 : ", i+1);
		for (j = 0; j < 4; j++) {
			scanf_s("%d", &score[i][j]);
		}
	}

	for (i = 0; i < 3; i++) {
		total = 0;
		for (j = 0; j < 4; j++) {
			total += score[i][j];
		}
		avg = total / 4.0;
		printf("%d번 학생 총점 : %d, 평균 : %.2lf\n", i+1, total, avg);
	}

}