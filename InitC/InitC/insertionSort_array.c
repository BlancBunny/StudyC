#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input_ary[10] = { 0 }, lower_ary[10] = { 0 }, upper_ary[10] = { 0 };
void insertionSort(char*);
void div_ul(char*);

int main() {
	printf("���ڿ� �Է� : ");
	gets_s(input_ary, 10);
	printf("===================\n");
	div_ul(input_ary); // ���ڿ� ��ҹ��� �з�

	insertionSort(upper_ary); // ���������� ����
	insertionSort(lower_ary);
	

	printf("�빮�� : %s\n", upper_ary);
	printf("�ҹ��� : %s\n", lower_ary);
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