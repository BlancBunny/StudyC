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

void freeList(HeadNode* h) {
	ListNode* tmp;
	while (h->head != NULL) {
		tmp = h->head;
		h->head = tmp->link;
		free(tmp);
		tmp = NULL;
	}
}

// 정렬된 리스트 -> 대문자 리스트와 소문자 리스트로 분해
void makeList(HeadNode* h, HeadNode* h_upper, HeadNode* h_lower) {
	ListNode* tmp = h->head;
	ListNode* node;
	h_upper->head = h->head;
	while (tmp->link != NULL) {
		if (tmp->data >= 'A' && tmp->data <= 'Z' && tmp->link->data >= 'a' && tmp->link->data <= 'z') { // 대, 소문자 경계 노드 탐색
			h_lower->head = tmp->link;
			tmp->link = NULL;
			return;
		}
		tmp = tmp->link;
	}
}

HeadNode* aryToList(char* ary) {
	HeadNode* h = createLinkedList();
	for (int i = 0; ary[i] != 0; i++) {
		insertLastNode(h, createNode(ary[i]));
	}
	return h;
}

void insertionSort(HeadNode* h) {
	ListNode* node, * tmp;
	node = h->head;
	while (node->link != NULL) {
		if (node->data > node->link->data) 
		{ 
			tmp = node->link;            // 정렬 순서가 틀린 노드를 임시 저장
			node->link = node->link->link;  // 노드 빠진 자리 연결 
			tmp->link = h->head; // 해당 노드를 맨 앞에 삽입 
			h->head = node = tmp; // 헤드 포인터와 검사 포인터 초기화 
			// printList(h)
			continue;
		}
		node = node->link;
	}
}

int main() {
	char input_ary[10];
	HeadNode* list;
	HeadNode* list_upper = createLinkedList(); // 대문자 리스트
	HeadNode* list_lower = createLinkedList(); // 소문자 리스트

	// 문자열 입력
	printf("문자열 : ");
	gets_s(input_ary, 10);
	printf("==================\n");
	
	// 비정렬 리스트 생성
	list = aryToList(input_ary);
	printf("비정렬 ");
	printList(list);

	// 리스트 삽입정렬
	insertionSort(list);
	printList(list);

	// 리스트 -> 대문자, 소문자 리스트로 분해
	makeList(list, list_upper, list_lower);

	// 출력 
	printf("대문자 ");
	printList(list_upper);
	printf("소문자 ");
	printList(list_lower);

	freeList(list_upper);
	freeList(list_lower);

	return 0;
}