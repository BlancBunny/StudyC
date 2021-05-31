#include <stdio.h>
#include "ex19.h"
int main() {
	Student a = { 315, "홍길동" };

	printf("학번 : %d, 이름 : %s\n", a.num, a.name);
}