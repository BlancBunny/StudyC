#include <stdio.h>

void hanoi(int, char, char, char);
int cnt = 0;

int main() {
	int n;
	printf("���� ���� : ");
	scanf_s("%d", &n);

	hanoi(n, 'A', 'B', 'C');

	printf("��� Ƚ�� : %d", cnt);
	return 0;
}

void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		printf("���� �̵� %c -> %c\n", a, c);
		cnt++;
		return;
	}
	hanoi(n - 1, a, c, b);
	printf("���� �̵� %c -> %c\n", a, c);
	cnt++;
	hanoi(n - 1, b, a, c);
}
