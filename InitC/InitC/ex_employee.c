/*
	5���� ������̵�, ����̸�, �Ѵ� �޿��� �Է¹޾� ����� ��
	5�� ����� �޿� �Ѿװ� ��� �޿����� ���Ͻÿ�. 
	(�̸��� �����Ҵ�)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ex_employee.h"


int main() {
	
	Employee list[_SIZE];
	Employee* pl = list;
	
	// 1. ��� 5���� ���̵�/�̸�/�޿� �Է� 
	input_Employee(list);
	// 2. ���
	print_Employee(list);
	// 2.5 �̸� �޸� ��ȯ
	for (int i = 0; i < _SIZE; i++) {
		if (list[i].name != NULL) {
			free(list[i].name);
			list[i].name = NULL;
		}
	}
	// 3. �޿� �Ѿ� / ��� 
	print_salary(list);
	
	return 0;
}


