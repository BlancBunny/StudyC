#include <stdio.h>

int get_num();
int main() {
	int result;

	result = get_num();
	printf("��ȯ�� : %d\n", result);
	return 0;
}

int get_num() {
	int num;

	printf("��� �Է� : ");
	scanf_s("%d", &num);

	return num;
}

