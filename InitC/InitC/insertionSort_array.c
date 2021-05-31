#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input_ary[10] = { 0 }, lower_ary[10] = { 0 }, upper_ary[10] = { 0 };
void insertionSort(char*);
void div_ul(char*);

int main() {
	printf("문자열 입력 : ");
	gets_s(input_ary, 10);
	printf("===================\n");
	div_ul(input_ary); // 문자열 대소문자 분류

	insertionSort(upper_ary); // 사전순으로 정렬
	insertionSort(lower_ary);
	

	printf("대문자 : %s\n", upper_ary);
	printf("소문자 : %s\n", lower_ary);
	return 0;
}

void insertionSort(char* arr) {
	int j, tmp;
	for (int i = 0; arr[i] != 0; i++) {
		j = i - 1;
		while ((arr[j] > arr[j + 1]) && (j >= 0)) {
			tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
			j--;
		}
	}
}
void div_ul(char* arr) {
	int a = 0;
	int b = 0;
	for (int i = 0; arr[i] != 0; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') {
			upper_ary[a++] = arr[i];
		}
		if (arr[i] >= 'a' && arr[i] <= 'z') {
			lower_ary[b++] = arr[i];
		}
	}
}