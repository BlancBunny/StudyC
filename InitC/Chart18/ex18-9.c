#include <stdio.h>

int main() {
	FILE* ifp, * ofp;

	char name[20];
	int kor, eng, mat;
	int total;
	double avg;
	int res;
	errno_t err;

	err = fopen_s(&ifp, "a.txt", "r");
	if (ifp == NULL) {
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	err = fopen_s(&ofp, "b.txt", "w");
	if (ofp == NULL) {
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1) {
		res = fscanf_s(ifp, "%s%d%d%d", name, sizeof(name), &kor, &eng, &mat);
		if (res == EOF) break;
		total = kor + eng + mat;
		avg = total / 3.0;
		fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
	}

	fclose(ifp);
	fclose(ofp);

	return 0;

}