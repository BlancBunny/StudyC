#include <stdio.h>

int main() {
	/*char str[80] = "applejam";

	printf("���� ���ڿ� : %s\n", str);
	printf("���ڿ� �Է� : ");
	scanf_s("%s", str, sizeof(str));
	printf("�Է� �� ���ڿ� : %s\n", str);*/

	// ex8-5.c

	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "tiger");
	strcpy(str2, str1);

	printf("%s %s\n", str1, str2);

	return 0; 
}