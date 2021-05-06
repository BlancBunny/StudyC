#include <stdio.h>

void auto_func();
void static_func();

int main() {
	int i;

	printf("일반 지역 변수를 사용한 함수\n");
	for (i = 0; i < 3; i++) {
		auto_func();
	}

	printf("정적 지역변수 (static)을 사용한 함수\n");
	for (i = 0; i < 3; i++) {
		static_func();
	}

	return 0;
}

// 일반 지역 변수 
void auto_func() {
	auto int a = 0;
	a++;
	printf("%d\n", a);
}
// 정적 지역 변수 
void static_func() {
	static int a = 0;
	a++;
	printf("%d\n", a);
}

