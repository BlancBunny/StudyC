#include <stdio.h>

int main() {
	
	int n;

	printf("몇 단? : ");
	scanf_s("%d", &n);

	for (int i = 1; i <= 9; i++) {
		printf("%d x %d = %d\n", n, i, n * i);
	}

	printf("%d단 출력 완료\n", n);

	return 0;
}


