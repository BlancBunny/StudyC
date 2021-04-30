//Calculator_v3.c
//
//Created : 2021-04-28
//Author : ������

#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	char ch;
	int result = 0;
	double result_d = 0.0;

	while (1) {
		// 0. ���� ���� 
		printf("���� ����? (y/n) : ");
		scanf_s("%c", &ch, sizeof(ch));
		
		if (ch == 'y' || ch == 'Y') {

		}
		else if (ch == 'n' || ch == 'N') {
			printf("���α׷� ����!");
			exit(0);
		}
		else {
			printf("�ùٸ��� ���� �Է�\n");
			printf("========================\n");
			while (getchar() != '\n');
			continue;
		}


		// 1. �� ���� �Է��� �޴´�.
		printf("�� 2�� �Է� : ");
		if (scanf_s("%d %d", &a, &b) != 2) {  // ���������� ���� 2���� �Էµ��� �ʾ��� ���
			printf("������ �Է��ؾ� �մϴ�. �ٽ� �õ����ּ���.\n");
			printf("========================\n");
			while (getchar() != '\n');
			continue;
		}

		// 2. ���� ��ȣ�� �Է¹޴´�.
		printf("���� ��ȣ �Է�(+, -, *, /, q(����)) : ");
		scanf_s(" %c", &ch, sizeof(ch));

		// 3. ������ �����Ѵ�. 
		switch (ch) {
		case 'q':
			printf("���α׷� ����!");
			exit(0);
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result_d = (double)a / (double)b; // divide ����� double
			break;
		default:
			printf("�ùٸ� ���� ��ȣ�� �Է��ϼ���.\n");
			printf("========================\n");
			while (getchar() != '\n');
			continue;
		}

		// 4. ���� ����� ����Ѵ�. 
		if (ch == '/') { // ������ 
			if (b == 0) printf("0���� ���� �� �����ϴ�.\n");
			else printf("���� ��� : %d %c %d = %g\n", a, ch, b, result_d);
		}
		else printf("���� ��� : %d %c %d = %d\n", a, ch, b, result); // �� �� 
		printf("========================\n");
		while (getchar() != '\n');
	}

	return 0;
}


