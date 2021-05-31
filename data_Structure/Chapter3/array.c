#include <stdio.h>

int main() {
	int i, n = 0, *ptr;
	int sale[2][4] = {{63, 84, 140, 130} , {157, 209, 251, 312}};
	
	// pointer array
	int (*pptr)[4] = sale;
	ptr = &sale[0][0];

	
	for (i = 0; i < 8; i++) {
		printf("address : %u sale %d = %d\n", ptr, i, *ptr);
		ptr++;
	}
	printf("pointer array (1,1) : %d\n", pptr[1][1]);
	printf("pointer array address : %u\n", pptr);
	printf("pointer array address : %u\n", pptr+1);
	return 0;
}

