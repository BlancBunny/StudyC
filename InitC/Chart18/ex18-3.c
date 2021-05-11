#include <stdio.h>

int main() {
	FILE* fp;
	char str[] = "banana";
	errno_t err = fopen_s(&fp, "b.txt", "w");

	if (fp == NULL) {
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}

	int i = 0;
	while (str[i] != '\0') {
		fputc(str[i], fp);
		i++;
	}

	fputc('\n', fp);
	if (fp) fclose(fp);

	return 0;
}