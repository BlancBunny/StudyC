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
		printf("%d번 아이디 : ", i + 1);
		scanf_s("%d", &list[i].id);
		char t = getchar(); // '\n' 버퍼 제거
		printf("%d번 이름 : ", i + 1);
		gets_s(tmp, sizeof(tmp));					   // 문자열 임시 저장
		list[i].name = (char*)malloc(strlen(tmp) + 1); // 이름 메모리 동적 할당 
		if (list[i].name != NULL)
			strcpy_s(list[i].name, strlen(tmp) + 1, tmp);
		printf("%d번 급여 : ", i + 1);
		scanf_s("%d", &list[i].salary);
		print_line('=');
	}
}

void print_Employee(Employee* list) {
	printf("\n%4s%12s%10s%14s\n", "순번", "사원번호", "이름", "급여(만원)");
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
	printf("\n사원 급여 총액 : %d(만원)\n", total);
	printf("사원 급여 평균 : %.1lf(만원)\n", total / (double)_SIZE);
}

void print_line(char ch) {
	for (int i = 0; i < 40; i++) {
		printf("%c", ch);
	}
	printf("\n");
}
