#include <stdio.h>



struct address {
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

void print_list(struct address*);

int main() {
	struct address list[5] = {
		{"ȫ�浿", 23, "111-1111", "�︪�� ����"},
		{"�̼���", 35, "222-2222", "���� ���빮��"},
		{"�庸��", 20, "333-3333", "���� ������"},
		{"������", 15, "444-4444", "�泲 õ�Ƚ�"},
		{"���߱�", 45, "555-5555", "�λ� �ؿ�뱸"}
	};
	struct address* lp = &list[0];
	print_list(lp);
	/*for (int i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n",
			list[i].name, list[i].age, list[i].tel, list[i].addr);
	}*/
	return 0;
}

void print_list(struct address* list) {
	for (int i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n",
			list->name, list->age, list->tel, list->addr);
		list++;
	}
}
