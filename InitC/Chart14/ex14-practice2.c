/*
	1. 5�� �л��� ����, ����, ����, ü�� ���� �Է� (2���� �迭 ���)
	2. ���κ� ������ ���
	3. ������ ������ ��� 
*/

#include <stdio.h>

int main() {
	int grade[5][4] = { 0 };
	int sum = 0;
	int total[4] = { 0 };
	double avg = 0.0;

	for (int i = 0; i < 5; i++) { // 5�� �ٲٱ� 
		printf("===%d�� �л��� ���� �Է�===\n", i+1);
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &grade[i][j]);
		}
	}

	printf("�й� |%8s%8s%8s%8s%8s%8s\n", "����", "����", "����", "ü��", "����", "���");
	for (int i = 0; i < 5; i++) {
		sum = 0;
		printf("%d��  |", i+1);
		for (int j = 0; j < 4; j++) {
			printf("%8d", grade[i][j]);
			sum += grade[i][j];
		}
		// ���� ����
		printf("%8d", sum);
		// ���� ��� 
		avg = sum / 4.0;
		printf("%8.2lf", avg);
		printf("\n");
	}
	for (int i = 0; i < 54; i++) {
		printf("=");
	}
	printf("\n���� |");
	// ���� ���� 
	for (int i = 0; i < 4; i++) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += grade[j][i];
		}
		total[i] = sum;
		printf("%8d", total[i]);
	}
	printf("\n��� |");
	for (int i = 0; i < 4; i++) {
		printf("%8.2lf", total[i] / 5.0);
	}

	return 0;
}