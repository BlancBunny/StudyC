int main();

void input_lotto(int* lotto, int size) {
	int tmp = 0;
	for (int i = 0; i < size; i++) {
		printf("%d��° ���� �Է� : ", i + 1);
		
		// �ӽ� ����
		scanf_s("%d", &tmp); 

		// ���� �˻�
		if (tmp < 0 || tmp > 45) {
			printf("���� ����(1~45) ��Ż. ���Է�\n");
			i--;
			continue;
		}
		
		// 1�� �Է�
		if (i == 0) lotto[i] = tmp; 

		// �ߺ� �˻�
		for (int j = 0; j < i; j++) {
			if (tmp == lotto[j]) {
				printf("������ ���� �߰�. ���Է�\n");
				i--;
				break;
			}
			else lotto[i] = tmp; 
		}
	}
	while (getchar() != '\n');
}

// �Է� (tmp)		  <-��
// �˻� (���� / �ߺ�)  -��
// ���� 

void print_lotto(int* lotto) {
	printf("�Էµ� ��ȣ : ");
	for (int i = 0; i < 6; i++) {
		printf("%d ", lotto[i]);
	}
}