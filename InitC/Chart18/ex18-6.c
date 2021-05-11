#include <stdio.h>

int main() {
	FILE* fp;
	int ary[10] = { 13, 10, 13, 11, 13, 26 , 13 ,10 ,10 ,13 };

	int res;
	errno_t err;
	err = fopen_s(&fp, "a.txt", "wb");
	if (fp) {
		for (int i = 0; i < 10; i++) {
			fputc(ary[i], fp);
		}
		fclose(fp);
	}
	
	err = fopen_s(&fp, "a.txt", "rt");
	if (fp) {
		while (1) {
			res = fgetc(fp);
			if (res == EOF) break;
			printf("%4d", res);
		}
		fclose(fp);
	}
	
	return 0;
}