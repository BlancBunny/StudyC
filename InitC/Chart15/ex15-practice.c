/*
	1. 5�� �л��� ����, ����, ����, ü�� ���� �Է� (2���� �迭 ���)
	2. ���κ� ������ ���
	3. ������ ������ ���
*/

#include <stdio.h>
#include "ex15.h"

int print() {
	printf("��ȣ!");
	// return 1;
}


int main() {
	int grade[5][4] = { 0 };
	int sum_p[5] = { 0 }; // �л��� �հ�
	int sum_s[4] = { 0 }; // ���� �հ� 
	
	int num = print();
	printf("%d", num);

	// �Է� 
	input_grade(grade);
	// ���� ���
	sum_person(grade, sum_p); 
	sum_subject(grade, sum_s);
	// ��� 
	// print_grade(grade);
	print_grade(grade, sum_p, sum_s);

	return 0;
}



