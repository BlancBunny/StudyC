#include <stdio.h>

int main() {
	int n[5] = { 1,2,3 };
	char ch[5] = { 'a','b','c' };
	
	for (int i = 0; i < 5; i++) {
		// printf("%d : %d\n", i + 1, n[i]);
		printf("%d : %d\n", i + 1, ch[i]);
	}

	return 0;
}

