#include <stdio.h>

FILE* fp;

int main() {
	// fp = fopen("a.txt", "r");
	errno_t err = fopen_s(&fp, "a.txt", "r");
	char ch;

	// 반환값 0 : 에러 없음
	// 그 의외의 값 : 에러 (고유 코드 보유) 
	if (err != 0) {
		printf("파일이 열리지 않았습니다.\n");
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

