#include <stdio.h>

int main() {
	int ch;

	while (1) {
		// 18-4.c
		/*ch = getchar();
		if (ch == EOF) break;
		putchar(ch);*/ 
		
		// 18-5.c
		ch = fgetc(stdin);
		if (ch == EOF) break;
		fputc(ch, stdout); 
	}

	return 0;
}
