#include <stdio.h>
#include <string.h>

char* my_strcpy(char*, char*);

int main() {
	char str[80] = "strawberry";

	printf("바꾸기 전 : %s\n", str);
	my_strcpy(str, "apple"); 
	printf("바꾼 후 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi"));
}

// my_strcpy <- 입력 : 복사 받을 곳 / 복사 할 곳 [포인터] 
//				출력 : 없음 -> 원래 strcpy가 char* 임. 복사된 공간의 시작 주소 반환
// while: '\0' 가 아닐때까지 두 곳의 포인터를 증가시키며 문자 복사 
// 문자열 마지막에 \0 추가

char* my_strcpy(char* pd, char* ps) {
	char* po = pd; // 복사될 공간의 시작주소 저장

	while (*ps != '\0') {
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return po; // 복사된 공간의 시작주소 반환
}

