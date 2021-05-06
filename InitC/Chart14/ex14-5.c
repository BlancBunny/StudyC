#include <stdio.h>

int main() {
	int score[2][3][4] = {
		{{72, 80, 95 ,60}, {68, 98, 83, 90}, {75, 51, 66, 45}},
		{{66, 95, 55, 72}, {41, 66, 74, 91}, {47, 61, 95, 81}}
	};

	for (int i = 0; i < 2; i++) {
		printf("    - %d반 점수 -\n", i+1);
		for (int j = 0; j < 3; j++) {
			printf("%d번 학생 점수 : ", j + 1);
			for (int k = 0; k < 4; k++) {
				printf("%5d", score[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

