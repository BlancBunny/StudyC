#include <stdio.h>
#include <string.h>

int main() {
	char str1[80] = { 0 }, str2[80] = { 0 };
	char* resp;

	printf("2���� ���� �̸� �Է� : ");
	scanf_s("%s%s", str1, sizeof(str1), str2, sizeof(str2));

	if (strlen(str1) > strlen(str2))
		resp = str1;
	else resp = str2;

	printf("�̸��� �� ������ : %s\n", resp);
}