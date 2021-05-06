#include <stdio.h>
#include <string.h>

int main() {
	char str[20] = "mango tree";

	// strncpy 함수는 복사 후 '\0' 를 추가하지 않으므로 apple tree가 출력되지만
	// strncpy_s 는 추가하기 때문에 apple 만 출력된다. 
	strncpy_s(str, sizeof(str), "apple-pie", 5);

	printf("%s\n", str);

	return 0;

}