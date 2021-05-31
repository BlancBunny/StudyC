#include <stdio.h>
#include <stdlib.h>

// ���� ����Ʈ �ڷ��� ����
typedef char element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// ���� �Լ�
void error() {
	exit(EXIT_FAILURE);
}

// ���� ����Ʈ ��� ���� �Լ�
// p : ���Ե� ����� ���� ���
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) { // ��尡 ������ ���
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { // ù ��° ���� ����
		new_node->link = *phead;
		*phead = new_node;
	}
	else { // p ������ ����
		new_node->link = p->link;
		p->link = new_node;
	}
}

//// ���� ����Ʈ ��� ���� �Լ�
//// p : ������ ����� ���� ���
//void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
//	if (!(*phead))
//		return;
//
//	if (p == NULL) // ù ��° ��� ����
//		*phead = (*phead)->link;
//	else // p ������ ����
//		p->link = removed->link;
//
//	free(removed->data);
//	free(removed);
//}

// ���� ����Ʈ ��� �Լ�
void display(ListNode** phead) {
	ListNode* p = *phead;
	while (p) {
		printf("%c", p->data);
		p = p->link;
		if (p)
			printf("->");
	}
	printf("\n");
}

// ���� ����Ʈ�� ��� ���� �Լ�
ListNode* create_node(element data, ListNode* link) {

	ListNode* new_node;

	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (!new_node)
		error();

	new_node->data = data;
	new_node->link = link;

	return new_node;
}

// ���� ����Ʈ�� �ε���(at) ��ȣ�� �̿��� ��� ���� �Լ�
ListNode* node_at(ListNode** phead, int index) {

	ListNode* p = *phead;
	int i;
	for (i = 0; i < index && p; i++)
		p = p->link;

	if (p)
		return p;
	else
		return NULL;
}

// ��� ������ swap �Լ�
void swap_node_data(ListNode* n1, ListNode* n2) {

	element tmp;

	tmp = n1->data;
	n1->data = n2->data;
	n2->data = tmp;
}

// ���� ����Ʈ ���� �Լ�
int length(ListNode** phead) {

	ListNode* p = *phead;
	int count = 0;
	while (p) {
		count++;
		p = p->link;
	}

	return count;
}

// ���� ����Ʈ�� ���� ���� �Լ�
void insert_list_sort(ListNode** phead, int n) {
	for (int i = 1; i < n; i++)
	{
		element new_element = node_at(phead, i)->data;
		int j;

		for (j = i; j >= 1 && node_at(phead, j - 1)->data > new_element; j--)
			node_at(phead, j)->data = node_at(phead, j - 1)->data;

		node_at(phead, j)->data = new_element;
	}
}

// ���� ���� �Լ�
void insert_sort(char list[], int n) {
	for (int i = 1; i < n; i++)
	{
		char new_element = list[i];
		int j;

		for (j = i; j >= 1 && list[j - 1] > new_element; j--)
			list[j] = list[j - 1];

		list[j] = new_element;
	}
}

// ���Ḯ��Ʈ ���� �籸�� �Լ�
ListNode* reverse(ListNode** phead) {

	ListNode* p, * q, * tmp;
	p = *phead;
	q = NULL;

	while (p) {
		tmp = q;
		q = p;
		p = p->link;
		q->link = tmp; // q ��ũ ���� �ٲ� (��ȯ)
	}

	return q;
}

// ���α׷� ������
int main(int argc, char* argv[]) {

	ListNode* list_ary = NULL; // NULL �ʼ�
	char input_ary[10];
	char tmp;

	int i;

	for (i = 0; i < 10; i++) {
		printf("[No.%2d] ���ĺ� �Է� : ", i + 1);
		scanf_s("%c", &tmp, sizeof(char));
		while (getchar() != '\n'); // ���� ���� ����
		insert_node(&list_ary, NULL, create_node(tmp, NULL));
		input_ary[i] = tmp;
	}

	printf("[���� �� �迭]\n");
	for (i = 0; i < 10; i++)
		printf("%c ", input_ary[i]);
	printf("\n");
	insert_sort(input_ary, 10);
	printf("[���� �� �迭]\n");
	for (i = 0; i < 10; i++)
		printf("%c ", input_ary[i]);
	printf("\n");

	list_ary = reverse(&list_ary);
	printf("[���� �� ����Ʈ]\n");
	display(&list_ary);
	insert_list_sort(&list_ary, 10);
	printf("[���� �� ����Ʈ]\n");
	display(&list_ary);

	return 0;
}