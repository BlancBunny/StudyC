int main();

// �ܾ� �Է�
// 1. �Է� �ܾ exit �϶� ���α׷� ���� 
void input_word(char* word, int* length) {
	printf("�ܾ� �Է�(exit �Է� �� ����) : ");
	gets_s(word, sizeof(*word) * 20);
	*length = strlen(word);
	if (strcmp(word, "exit") == 0) {
		printf("���α׷� ����!\n");
		exit(0);
	}
}

// ȸ�� üũ 
// 1. �ܾ� ���Է� üũ
// 2. ������ �ݸ�ŭ ���鼭 ���� �� 
// 3. ��� ��� 

void palindrome_check(char* pc, int size) {
	char* ps = pc; // �ܾ��� ���� �ּ�
	char* pe = ps + size - 1; // �ܾ��� �� �ּ� 
	
	if (*ps == '\0') {
		printf("�ܾ �Է��ϼ���.\n");
		return;
	}
	for (int i = 0; i < size / 2; i++) {
		if (*(ps + i) != *(pe - i)) {
			printf("ȸ���� �ƴմϴ�.\n");
			return;
		}
	}
	printf("ȸ���Դϴ�.\n");
}

