#pragma once

int main();

void func_exit() {
	printf("���α׷� ����!");
	exit(0);
}

void wrong_input() {
	printf("�ùٸ��� ���� �Է�\n");
	printf("===========================\n");
	while (getchar() != '\n');
}