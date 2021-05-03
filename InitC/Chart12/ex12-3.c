#include <stdio.h>

int main() {
	char str[80];

	// scanf : 공백이 포함된 문자열을 처리할 수 없음
	printf("문자열 입력 : ");
	scanf_s("%s", str, sizeof(str));
	printf("첫 번째 단어 : %s\n", str);
	scanf_s("%s", str, sizeof(str));
	printf("버퍼에 남아있는 두 번째 단어 : %s\n", str);

	int t = getchar();
	printf("==============\n");

	// gets : 개행 문자를 널 문자('\0')로 변환 
	printf("공백이 포함된 문자열 입력 : ");
	gets_s(str, sizeof(str));
	printf("입력한 문자열은 %s입니다.\n", str);

	return 0;
}