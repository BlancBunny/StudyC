#include <stdio.h>

void func(int (*fp)(int, int));
int sum(int, int);
int mul(int, int);
int max(int, int);

int main() {
	int sel;

	printf("01 : �� ������ ��\n");
	printf("02 : �� ������ ��\n");
	printf("03 : �� ���� �߿��� ū ��\n");

	printf("���� �Է� : ");
	scanf_s("%d", &sel);

	switch (sel) {
	case 1: func(sum); break;
	case 2: func(mul); break;
	case 3: func(max); break;
	}

	return 0;
}

void func(int (*fp)(int, int)) {
	int a, b;
	int res;
	printf("�� ���� �Է� : ");
	scanf_s("%d %d", &a, &b);
	res = fp(a, b);
	printf("��� : %d", res);
}


int sum(int a, int b) {
	return a + b;
}

int mul(int a, int b) {
	return a * b;
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}