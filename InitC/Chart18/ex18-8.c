#include <stdio.h>
#include <string.h>

int main() {
	FILE* ifp, * ofp;
	char str[80];
	char* res;
	errno_t err;

	err = fopen_s(&ifp ,"a.txt", "r");
	if (ifp == NULL) {
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	err = fopen_s(&ofp ,"b.txt", "w");
	if (ofp == NULL) {
		printf("��� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	while (1) {
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL) break;
		str[strlen(str) - 1] = '\0';
		fputs(str, ofp);
		fputs(" ", ofp);
	}

	fclose(ifp);
	fclose(ofp);
}