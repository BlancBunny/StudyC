#include <stdio.h> 

int main() {
	/*int age; 
	double height;

	printf("나이와 키를 입력하세요 : ");
	scanf_s("%d %lf", &age, &height);
	printf("나이 : %d, 키 : %.1lf", age, height);*/

	// ex3-11.c

	/*char grade;
	char name[20];
	printf("학점 입력 : ");
	scanf_s("%c", &grade, sizeof(grade));
	printf("이름 입력 : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s의 학점은 %c입니다.", name, grade);

	return 0;*/
	
	//// 이름 나이 주소 
	//char name[20];
	//int age; 
	//char addr[50];

	//printf("이름 입력 : ");
	//scanf_s("%s", name, sizeof(name));
	//printf("나이 입력 : ");
	//scanf_s("%d", &age);
	//printf("주소 입력 : ");
	//scanf_s("%s", addr, sizeof(addr));
	//printf("이름 : %s / 나이 : %d / 주소 : %s\n", name, age, addr);
	
	
	int a;
	char b;

	printf("정수하나를 입력하세요 : $ ");
	scanf_s("%d", &a);
	printf("문자하나를 입력하세요 : $ ");
	// getchar();
	scanf_s(" %c", &b, sizeof(b));
	printf("입력된 값은 %d, %c입니다.\n", a, b);
	return 0;
}




    