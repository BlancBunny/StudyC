
// ex12-practice.c : �ҹ��ڸ� �޾Ƽ� �빮�ڷ� ����ϴ� ���α׷�

#include <stdio.h>

int main() {
	char ch;
	int dif = 'a' - 'A';

	while (1) {
		printf("���ĺ� �Է�(0 �Է½� ����) : ");
		scanf_s("%c", &ch, sizeof(ch));

		if (ch == '0') {
			printf("���α׷� ����\n");
			break;
		}

		if (ch >= 'A' && ch <= 'Z')
			printf("�빮���Դϴ�. �ҹ��ڷ� ��ȯ -> %c\n", ch + dif);
		else if (ch >= 'a' && ch <= 'z')
			printf("�ҹ����Դϴ�. �빮�ڷ� ��ȯ -> %c\n", ch - dif);
		else printf("���ĺ��� �ƴմϴ�.\n");

		while (getchar() != '\n');
	}
	return 0;
}
