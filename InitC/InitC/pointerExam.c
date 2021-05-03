/*
	date : 2021-04-30
	Author : ������
	description 
		1. 10�� ���� �Է� -> �迭�� ����
		2. �迭 ��� 
		3. �迭�� ����� ���� swap (9<->0, 8<->1, 7<->2 ... )
		4. �迭 ���
		
		input_arr()
		swap_arr()
		print_arr() 
*/

#include <stdio.h>
#include "pointerExam.h"

int main() {
	int* arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);

	input_arr(arr, size);					// 1. �迭 �Է� 
	printf("���� �� : ");
	print_arr(arr, size);					// 2. ���� �迭 ���
	swap_arr(arr, arr + (size - 1), size);  // 3. �迭 swap (�Է� : 0����, 9���� �ּ�)
	printf("���� �� : ");
	print_arr(arr, size);					// 4. �ٲ� �迭 ���
}