/*
	1. 5명 학생의 국어, 영어, 수학, 체육 점수 입력 (2차원 배열 사용)
	2. 개인별 총점과 평균
	3. 과목별의 총점과 평균 
*/

#include <stdio.h>

int main() {
	int grade[5][4] = { 0 };
	int sum = 0;
	int total[4] = { 0 };
	double avg = 0.0;

	for (int i = 0; i < 5; i++) { // 5로 바꾸기 
		printf("===%d번 학생의 성적 입력===\n", i+1);
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &grade[i][j]);
		}
	}

	printf("학번 |%8s%8s%8s%8s%8s%8s\n", "국어", "영어", "수학", "체육", "총점", "평균");
	for (int i = 0; i < 5; i++) {
		sum = 0;
		printf("%d번  |", i+1);
		for (int j = 0; j < 4; j++) {
			printf("%8d", grade[i][j]);
			sum += grade[i][j];
		}
		// 개인 총점
		printf("%8d", sum);
		// 개인 평균 
		avg = sum / 4.0;
		printf("%8.2lf", avg);
		printf("\n");
	}
	for (int i = 0; i < 54; i++) {
		printf("=");
	}
	printf("\n총점 |");
	// 과목 총점 
	for (int i = 0; i < 4; i++) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += grade[j][i];
		}
		total[i] = sum;
		printf("%8d", total[i]);
	}
	printf("\n평균 |");
	for (int i = 0; i < 4; i++) {
		printf("%8.2lf", total[i] / 5.0);
	}

	return 0;
}