#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char**);

int main() {
	char tmp[80];
	char* str[21] = { 0 };
	
	int i=0;
	while (i < 20) {
		printf("문자열을 입력하세요 : ");
		gets_s(tmp, sizeof(tmp));
		if (strcmp(tmp, "end") == 0) break;
		str[i] = (char*)malloc(strlen(tmp) + 1);
		if (str[i] != NULL)
			strcpy_s(str[i], strlen(tmp)+1 , tmp);
		i++;
	}

	print_str(str);

	for (i = 0; str[i] != NULL; i++) {
		free(str[i]);
	}
	return 0;
}

void print_str(char** ps) {
	while (*ps != NULL) {
		printf("%s\n", *ps);
		ps++;
	}
}