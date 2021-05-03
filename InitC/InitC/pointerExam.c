/*
	date : 2021-04-30
	Author : 김현수
	description 
		1. 10개 정수 입력 -> 배열에 저장
		2. 배열 출력 
		3. 배열에 저장된 값을 swap (9<->0, 8<->1, 7<->2 ... )
		4. 배열 출력
		
		input_arr()
		swap_arr()
		print_arr() 
*/

#include <stdio.h>
#include "pointerExam.h"

int main() {
	int* arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);

	input_arr(arr, size);					// 1. 배열 입력 
	printf("변경 전 : ");
	print_arr(arr, size);					// 2. 원래 배열 출력
	swap_arr(arr, arr + (size - 1), size);  // 3. 배열 swap (입력 : 0번방, 9번방 주소)
	printf("변경 후 : ");
	print_arr(arr, size);					// 4. 바뀐 배열 출력
}