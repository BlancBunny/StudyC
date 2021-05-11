#include <stdio.h>

FILE* fp;

int main() {
	// fp = fopen("a.txt", "r");
	errno_t err = fopen_s(&fp, "a.txt", "r");
	char ch;

	// ��ȯ�� 0 : ���� ����
	// �� �ǿ��� �� : ���� (���� �ڵ� ����) 
	if (err != 0) {
		printf("������ ������ �ʾҽ��ϴ�.\n");
		printf("error code : %d\n", err);
		return 1;
	}
	printf("File Opened!\nFile Contents : ");
	while (1) {
		if (fp != NULL) {
			ch = fgetc(fp);
			if (ch == EOF) break;
			putchar(ch);
		}
	}
	printf("\n");

	
	if (fp != NULL) {
		err = fclose(fp);
		printf("File Closed!\n");
	}

	return 0;
}

