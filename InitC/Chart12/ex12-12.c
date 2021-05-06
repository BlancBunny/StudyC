#include <stdio.h>
#include <string.h>

int main() {
	char str1[80] = { 0 };
	char str2[80] = { 0 };
	
	strcat_s(str1, sizeof(str1), "pear");
	strcat_s(str2, sizeof(str2), "peach");
	
	if (strcmp(str1, str2) > 0) printf("%s\n", str1);
	else printf("%s\n", str2);

	return 0;
}