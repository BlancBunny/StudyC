#include <stdio.h>

int* sum(int, int);

int main() {
	int* resp;
	resp = sum(10, 20);

	printf("�� ������ �� : %d\n", *resp);
	
	return 0;
}

int* sum(int a, int b) {
	static int res; // static ������ data ������ �����ϹǷ� 
					// �Լ��� ������ �޸𸮰� ȸ������ ���� 
	res = a + b;
	return &res;
}

