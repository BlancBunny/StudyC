#include <stdio.h>

int main() {
	FILE* fp;
	int age;
	char name[20];
	errno_t err;

	err = fopen_s(&fp, "a.txt", "r");
	if (fp) {
		fscanf_s(fp, "%d", &age);
		while (fgetc(fp) != '\n');
		fgets(name, sizeof(name), fp);
		printf("나이 : %d, 이름 : %s", age, name);
		fclose(fp);
	}

	return 0;
}