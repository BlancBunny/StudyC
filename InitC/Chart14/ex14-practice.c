#include <stdio.h>
#include <string.h>
#include "ex14.h"

int main() {
	char word[20];
	char* pw = word;
	int length = 0;

	while (1) {
		input_word(pw, &length);		// �ܾ� �Է�
		palindrome_check(pw, length);	// ȸ�� �˻�
	}
	return 0;
}