#include <stdio.h>

int main() {
	
	int n;

	printf("�� ��? : ");
	scanf_s("%d", &n);

	for (int i = 1; i <= 9; i++) {
		printf("%d x %d = %d\n", n, i, n * i);
	}

	printf("%d�� ��� �Ϸ�\n", n);

	return 0;
}


