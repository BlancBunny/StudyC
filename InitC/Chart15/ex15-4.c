#include <stdio.h>

int main() {
	int ary[5];

	printf(" ary�� �� : %u\t", ary);
	printf("ary�� �ּ� : %u\n", &ary);      
	printf("    ary+1: %u\t", ary + 1);  // �迭���� ���� �ּҸ� ����Ű�Ƿ� 1���� �� 4��ŭ ����
	printf("   &ary+1: %u\n", &ary + 1); // &ary�� �迭 ��ü�� ����Ű�Ƿ� 1���� �� 4x5 ��ŭ ���� 

	return 0;
}

