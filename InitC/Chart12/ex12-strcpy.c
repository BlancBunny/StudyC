#include <stdio.h>
#include <string.h>

char* my_strcpy(char*, char*);

int main() {
	char str[80] = "strawberry";

	printf("�ٲٱ� �� : %s\n", str);
	my_strcpy(str, "apple"); 
	printf("�ٲ� �� : %s\n", str);
	printf("�ٸ� ���ڿ� ���� : %s\n", my_strcpy(str, "kiwi"));
}

// my_strcpy <- �Է� : ���� ���� �� / ���� �� �� [������] 
//				��� : ���� -> ���� strcpy�� char* ��. ����� ������ ���� �ּ� ��ȯ
// while: '\0' �� �ƴҶ����� �� ���� �����͸� ������Ű�� ���� ���� 
// ���ڿ� �������� \0 �߰�

char* my_strcpy(char* pd, char* ps) {
	char* po = pd; // ����� ������ �����ּ� ����

	while (*ps != '\0') {
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return po; // ����� ������ �����ּ� ��ȯ
}

