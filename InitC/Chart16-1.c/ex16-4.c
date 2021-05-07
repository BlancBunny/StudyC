#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char tmp[80] = { 0 };
	char* str[3];

	for (int i = 0; i < 3; i++) {
		printf("문자열을 입력하세요 : ");
		gets_s(tmp, sizeof(tmp));
		str[i] = (char*)malloc(strlen(tmp) + 1);
		if (str[i] != NULL)
			strcpy_s(str[i], strlen(tmp)+1, tmp);
	}

	for (int i = 0; i < 3; i++) {
		printf("%s\n", str[i]);
	}

	for (int i = 0; i < 3; i++) {
		free(str[i]);
	}
	return 0;
}