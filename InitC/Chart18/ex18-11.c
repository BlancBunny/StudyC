#include <stdio.h>

int main() {
	FILE* afp, * bfp;
	int num = 10;
	int res;
	errno_t err;
	
	err = fopen_s(&afp, "a.txt", "wt");
	if (afp) {
		fprintf(afp, "%d", num);
		fclose(afp);
	}
	err = fopen_s(&bfp, "b.txt", "wb");
	if (bfp) {
		fwrite(&num, sizeof(num), 1, bfp);
		fclose(bfp);
	}

	err = fopen_s(&bfp, "b.txt", "rb");
	if (bfp) {
		fread(&res, sizeof(res), 1, bfp);
		printf("%d", res);
		fclose(bfp);
	}

	return 0;
}