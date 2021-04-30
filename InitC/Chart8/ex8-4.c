#include <stdio.h>

int main() {
	/*char str[80] = "applejam";

	printf("최초 문자열 : %s\n", str);
	printf("문자열 입력 : ");
	scanf_s("%s", str, sizeof(str));
	printf("입력 후 문자열 : %s\n", str);*/

	// ex8-5.c

	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "tiger");
	strcpy(str2, str1);

	printf("%s %s\n", str1, str2);

	return 0; 
}