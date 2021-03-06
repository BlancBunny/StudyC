int main();

void input_grade(int (*grade)[4]) {
	for (int i = 0; i < 5; i++) { // 5로 바꾸기 
		printf("==%d번 학생의 4개 성적 입력==\n", i + 1);
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &grade[i][j]);
		}
	}
}

void sum_person(int (*grade)[4], int* sum_p) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			sum_p[i] += grade[i][j];
		}
	}
}

void sum_subject(int (*grade)[4], int* sum_s) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			sum_s[i] += grade[j][i];
		}
	}
}

void print_grade(int (*grade)[4], int* sum_p, int* sum_s) {
	int sum;
	double avg;
	int total[4];
	printf("\n학번 |%8s%8s%8s%8s%8s%8s\n", "국어", "영어", "수학", "체육", "총점", "평균");
	for (int i = 0; i < 5; i++) {
		sum = 0;
		printf("%d번  |", i + 1);

		// 개인 개별 성적
		for (int j = 0; j < 4; j++) {
			printf("%8d", grade[i][j]);
		}
		// 개인 총점
		printf("%8d", sum_p[i]);
		// 개인 평균 
		printf("%8.2lf\n", sum_p[i] / 4.0);
	}

	for (int i = 0; i < 54; i++) { // 합계 경계선
		printf("=");
	}

	// 과목별 총점 
	printf("\n총점 |");
	for (int i = 0; i < 4; i++) {
		printf("%8d", sum_s[i]);
	}
	// 과목별 평균
	printf("\n평균 |");
	for (int i = 0; i < 4; i++) {
		printf("%8.2lf", sum_s[i] / 5.0);
	}

	printf("\n");
}