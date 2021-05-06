#include <stdio.h>

int main() {
	int ary[5];

	printf(" ary의 값 : %u\t", ary);
	printf("ary의 주소 : %u\n", &ary);      
	printf("    ary+1: %u\t", ary + 1);  // 배열명은 시작 주소를 가리키므로 1증가 시 4만큼 증가
	printf("   &ary+1: %u\n", &ary + 1); // &ary는 배열 전체를 가리키므로 1증가 시 4x5 만큼 증가 

	return 0;
}

