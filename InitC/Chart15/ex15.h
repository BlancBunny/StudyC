int main();

void input_grade(int (*grade)[4]) {
	for (int i = 0; i < 5; i++) { // 5·Î ¹Ù²Ù±â 
		printf("==%d¹ø ÇÐ»ýÀÇ 4°³ ¼ºÀû ÀÔ·Â==\n", i + 1);
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
	printf("\nÇÐ¹ø |%8s%8s%8s%8s%8s%8s\n", "±¹¾î", "¿µ¾î", "¼öÇÐ", "Ã¼À°", "ÃÑÁ¡", "Æò±Õ");
	for (int i = 0; i < 5; i++) {
		sum = 0;
		printf("%d¹ø  |", i + 1);

		// °³ÀÎ °³º° ¼ºÀû
		for (int j = 0; j < 4; j++) {
			printf("%8d", grade[i][j]);
		}
		// °³ÀÎ ÃÑÁ¡
		printf("%8d", sum_p[i]);
		// °³ÀÎ Æò±Õ 
		printf("%8.2lf\n", sum_p[i] / 4.0);
	}

	for (int i = 0; i < 54; i++) { // ÇÕ°è °æ°è¼±
		printf("=");
	}

	// °ú¸ñº° ÃÑÁ¡ 
	printf("\nÃÑÁ¡ |");
	for (int i = 0; i < 4; i++) {
		printf("%8d", sum_s[i]);
	}
	// °ú¸ñº° Æò±Õ
	printf("\nÆò±Õ |");
	for (int i = 0; i < 4; i++) {
		printf("%8.2lf", sum_s[i] / 5.0);
	}

	printf("\n");
}