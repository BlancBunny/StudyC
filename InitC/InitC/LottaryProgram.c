/*
	LottaryProgram.c 
	1. �ζ� ��ȣ�� ������ �� �ִ� �迭 ���� (lotto[6]) 
	2. �ζ� ��ȣ �Է� 
	(������ ��ȣ �Է� �� ���� �޽��� ��� �� �ٽ� �Է� �ޱ�)
	
	input_lotto(), print_lotto() 
*/

#include <stdio.h> 
#include "LottaryProgram.h"

int main() {
	int lotto[6];
	int size = sizeof(lotto) / sizeof(lotto[0]);

	input_lotto(lotto, size); // �Է�
	print_lotto(lotto, size); // ���
	
	return 0; 
}