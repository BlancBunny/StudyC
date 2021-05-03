#include <stdio.h> 

int main() {
	int num, grade; 
	int t;
	printf("학번 입력 : ");
	scanf_s("%d", &num);
	t = getchar(); // 버퍼 비우기 
	printf("학점 입력 : ");
	grade = getchar();
	printf("학번 : %d, 학점 : %c\n", num, grade);
	printf("trash_buffer : %d\n", t);

	return 0;
}