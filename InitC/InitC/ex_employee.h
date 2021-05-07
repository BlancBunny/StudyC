#define _SIZE 2

typedef struct employee {
	int id;
	char* name;
	int salary;
}Employee;

void print_line(char);
int main();

void input_Employee(Employee* list) {
	char tmp[80];

	for (int i = 0; i < _SIZE; i++) {
		printf("%d�� ���̵� : ", i + 1);
		scanf_s("%d", &list[i].id);
		char t = getchar(); // '\n' ���� ����
		printf("%d�� �̸� : ", i + 1);
		gets_s(tmp, sizeof(tmp));					   // ���ڿ� �ӽ� ����
		list[i].name = (char*)malloc(strlen(tmp) + 1); // �̸� �޸� ���� �Ҵ� 
		if (list[i].name != NULL)
			strcpy_s(list[i].name, strlen(tmp) + 1, tmp);
		printf("%d�� �޿� : ", i + 1);
		scanf_s("%d", &list[i].salary);
		print_line('=');
	}
}

void print_Employee(Employee* list) {
	printf("\n%4s%12s%10s%14s\n", "����", "�����ȣ", "�̸�", "�޿�(����)");
	print_line('=');
	for (int i = 0; i < _SIZE; i++) {
		// printf("%4d%12d%10s%14d\n", i + 1, list[i].id, list[i].name, list[i].salary);
		printf("%4d%12d%10s%14d\n", i + 1, list->id, list->name, list->salary);
		list++;
	}
}

void print_salary(Employee* list) {
	int total = 0;
	for (int i = 0; i < _SIZE; i++) {
		total += list[i].salary;
	}
	print_line('=');
	printf("\n��� �޿� �Ѿ� : %d(����)\n", total);
	printf("��� �޿� ��� : %.1lf(����)\n", total / (double)_SIZE);
}

void print_line(char ch) {
	for (int i = 0; i < 40; i++) {
		printf("%c", ch);
	}
	printf("\n");
}
