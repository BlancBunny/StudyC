#include <stdio.h> 

int main() {
	/*int age; 
	double height;

	printf("���̿� Ű�� �Է��ϼ��� : ");
	scanf_s("%d %lf", &age, &height);
	printf("���� : %d, Ű : %.1lf", age, height);*/

	// ex3-11.c

	/*char grade;
	char name[20];
	printf("���� �Է� : ");
	scanf_s("%c", &grade, sizeof(grade));
	printf("�̸� �Է� : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s�� ������ %c�Դϴ�.", name, grade);

	return 0;*/
	
	//// �̸� ���� �ּ� 
	//char name[20];
	//int age; 
	//char addr[50];

	//printf("�̸� �Է� : ");
	//scanf_s("%s", name, sizeof(name));
	//printf("���� �Է� : ");
	//scanf_s("%d", &age);
	//printf("�ּ� �Է� : ");
	//scanf_s("%s", addr, sizeof(addr));
	//printf("�̸� : %s / ���� : %d / �ּ� : %s\n", name, age, addr);
	
	
	int a;
	char b;

	printf("�����ϳ��� �Է��ϼ��� : $ ");
	scanf_s("%d", &a);
	printf("�����ϳ��� �Է��ϼ��� : $ ");
	// getchar();
	scanf_s(" %c", &b, sizeof(b));
	printf("�Էµ� ���� %d, %c�Դϴ�.\n", a, b);
	return 0;
}




    