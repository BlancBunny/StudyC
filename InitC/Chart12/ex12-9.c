#include <stdio.h>
#include <string.h>

int main() {
	char str[20] = "mango tree";

	// strncpy �Լ��� ���� �� '\0' �� �߰����� �����Ƿ� apple tree�� ��µ�����
	// strncpy_s �� �߰��ϱ� ������ apple �� ��µȴ�. 
	strncpy_s(str, sizeof(str), "apple-pie", 5);

	printf("%s\n", str);

	return 0;

}