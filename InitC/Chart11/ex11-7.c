#include <stdio.h> 

int main() {
	int num, grade; 
	int t;
	printf("�й� �Է� : ");
	scanf_s("%d", &num);
	t = getchar(); // ���� ���� 
	printf("���� �Է� : ");
	grade = getchar();
	printf("�й� : %d, ���� : %c\n", num, grade);
	printf("trash_buffer : %d\n", t);

	return 0;
}