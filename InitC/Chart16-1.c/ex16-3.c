#include <stdio.h>
#include <stdlib.h>

int main() {
	int* pi, tmp;
	int size = 5;
	int count = 0;

	int num;

	pi = (int*)calloc(size, sizeof(int));
	if (pi == NULL) {
		printf("# �޸𸮰� �����մϴ�"); 
		exit(1);
	}

	while (1) {
		printf("����� �Է��ϼ��� => ");
		scanf_s("%d", &num);
		if (num <= 0) break;
		if (count == size) {
			size += 5;
			if (pi != NULL) {
				tmp = (int*)realloc(pi, size * sizeof(int));
				if (tmp != NULL) {
					pi = tmp;
				}
			}
		}
		pi[count++] = num;
	}
	for (int i = 0; i < count; i++) {
		printf("%5d", pi[i]);
	}
	free(pi);

	printf("%p", pi);

	return 0;
}