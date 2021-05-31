#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode {
	char data;
	struct listNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}HeadNode;

HeadNode* createLinkedList() {
	HeadNode* h;
	h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

ListNode* createNode(char ch) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		printf("memory alloc fail!\n");
		return NULL;
	}
	newNode->data = ch;
	newNode->link = NULL;

	return newNode;
}

void insertLastNode(HeadNode* h, ListNode* newNode) {
	ListNode* tmp = h->head;
	if (h->head == NULL) {
		h->head = newNode;
		return;
	}
	while (tmp->link != NULL) {
		tmp = tmp->link;
	}
	tmp->link = newNode;
}

void printList(HeadNode* h) {
	if (h->head == NULL) {
		printf("List : ()\n");
		return;
	}
	ListNode* tmp = h->head;
	printf("List : (");
	while (tmp != NULL) {
		printf("%c", tmp->data);
		if (tmp->link != NULL) printf(" -> ");
		tmp = tmp->link;
	}
	printf(")\n");
}
/*
	�迭 -> ����Ʈ ��ȯ �Լ�
	���ڿ��κ��� �� ���ڸ� �����ͷ� ������ 
	��带 �����ϰ� ����Ʈ�� ���� 
*/
HeadNode* aryToList(char* ary) {
	HeadNode* h = createLinkedList();
	for (int i = 0; ary[i] != 0; i++) {
		insertLastNode(h, createNode(ary[i]));
	}
	return h;
}

/*
	- ���� �� ���� �Լ� - 
	parameter : ����Ʈ ��� ������ h, ������ ��� newNode
	��� �������� ũ�⸦ ���ϸ� ������ ��ġ�� ��� ����
*/
void sortedInsert(HeadNode* h, ListNode* newNode) {
	ListNode* curr; 
	// ��� �����Ϳ� ���Ե� ��
	if (h->head == NULL || h->head->data >= newNode->data) {
		newNode->link = h->head;
		h->head = newNode;
		return;
	}
	curr = h->head;
	while (curr->link != NULL && curr->link->data < newNode->data) {
		curr = curr->link;
	}
	newNode->link = curr->link;
	curr->link = newNode;
}
/*
	- ����Ʈ ���� ���� - 
	������ ����Ʈ�κ��� ��� �ϳ��� �̵��ϸ� 
	sorted ����Ʈ�� �����ϸ鼭 ���� 
	�ϼ��� sorted ����Ʈ�� ���ο� ����Ʈ�� ���� 
*/
void insertionSort(HeadNode* h) {
	HeadNode* sorted = createLinkedList();
	ListNode* curr = h->head;
	while (curr != NULL) {
		ListNode* tmp = curr->link;
		sortedInsert(sorted, curr);
		curr = tmp;
	}
	h->head = sorted->head;
}

// ���ĵ� ����Ʈ -> �빮�� ����Ʈ�� �ҹ��� ����Ʈ�� ����
void makeList(HeadNode* h, HeadNode* h_upper, HeadNode* h_lower) {
	ListNode* tmp = h->head;
	ListNode* node;
	h_upper->head = h->head;
	while (tmp->link != NULL) {
		// ��, �ҹ��� ��� ��� Ž��
		if (tmp->data >= 'A' && tmp->data <= 'Z' && tmp->link->data >= 'a' && tmp->link->data <= 'z') { 
			h_lower->head = tmp->link;
			tmp->link = NULL;
			return;
		}
		tmp = tmp->link;
	}
}

void freeList(HeadNode* h) {
	ListNode* tmp;
	while (h->head != NULL) {
		tmp = h->head;
		h->head = tmp->link;
		free(tmp);
		tmp = NULL;
	}
}

int main() {
	char input_ary[10];
	HeadNode* list;
	HeadNode* list_upper = createLinkedList(); // �빮�� ����Ʈ
	HeadNode* list_lower = createLinkedList(); // �ҹ��� ����Ʈ

	// ���ڿ� �Է�
	printf("���ڿ� : ");
	gets_s(input_ary, 10);
	printf("==================\n");
	
	// ������ ����Ʈ ����
	list = aryToList(input_ary);
	printf("������ ");
	printList(list);

	// ����Ʈ ��������
	insertionSort(list);
	printList(list);

	// ����Ʈ -> �빮��, �ҹ��� ����Ʈ�� ����
	makeList(list, list_upper, list_lower);

	// ��� 
	printf("�빮�� ");
	printList(list_upper);
	printf("�ҹ��� ");
	printList(list_lower);
	
	// �޸� ��ȯ 
	freeList(list_upper);
	freeList(list_lower);
	return 0;
}