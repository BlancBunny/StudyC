//Calculator_v4.c
//
//Created : 2021-04-28
//Author : ������

#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"

int main() {
	int a, b;
	char ch;
	int result = 0;
	double result_d = 0.0;

	while (1) {
		// 0. ���� ���� �˻�
		ch = input_char("���� ����? (y/n) : "); 
		if(exit_check(ch) == -1) continue;
		
		// 1. �� ���� �Է��� �޴´�.
		printf("�� 2�� �Է� : ");
		if (scanf_s("%d %d", &a, &b) != 2) {  // ���������� ���� 2���� �Էµ��� �ʾ��� ���
			wrong_input();
			continue;
		}

		// 2. ���� ��ȣ�� �Է¹޴´�.
		ch = input_char("���� ��ȣ �Է�(+, -, *, /, q(����)) : ");

		// 3. ������ �����Ѵ�. 
		switch (ch) {
		case 'q':
			func_exit();
		case '+':
			result = add(a, b);
			break;
		case '-':
			result = sub(a, b);
			break;
		case '*':
			result = mul(a, b);
			break;
		case '/':
			result_d = divide(a, b); // ������ ��� -> �Ǽ�
			break;
		default:
			wrong_input();
			continue;
		}

		// 4. ���� ����� ����Ѵ�. 
		print_res(a, b, ch, result, result_d);
	}
	return 0;
}


