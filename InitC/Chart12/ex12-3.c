#include <stdio.h>

int main() {
	char str[80];

	// scanf : ������ ���Ե� ���ڿ��� ó���� �� ����
	printf("���ڿ� �Է� : ");
	scanf_s("%s", str, sizeof(str));
	printf("ù ��° �ܾ� : %s\n", str);
	scanf_s("%s", str, sizeof(str));
	printf("���ۿ� �����ִ� �� ��° �ܾ� : %s\n", str);

	int t = getchar();
	printf("==============\n");

	// gets : ���� ���ڸ� �� ����('\0')�� ��ȯ 
	printf("������ ���Ե� ���ڿ� �Է� : ");
	gets_s(str, sizeof(str));
	printf("�Է��� ���ڿ��� %s�Դϴ�.\n", str);

	return 0;
}