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
	배열 -> 리스트 변환 함수
	문자열로부터 각 문자를 데이터로 가지는 
	노드를 생성하고 리스트를 생성 
*/
HeadNode* aryToList(char* ary) {
	HeadNode* h = createLinkedList();
	for (int i = 0; ary[i] != 0; i++) {
		insertLastNode(h, createNode(ary[i]));
	}
	return h;
}

/*
	- 삽입 시 정렬 함수 - 
	parameter : 리스트 헤드 포인터 h, 삽입할 노드 newNode
	노드 데이터의 크기를 비교하며 적절한 위치에 노드 삽입
*/
void sortedInsert(HeadNode* h, ListNode* newNode) {
	ListNode* curr; 
	// 헤드 포인터에 삽입될 때
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
	- 리스트 삽입 정렬 - 
	비정렬 리스트로부터 노드 하나씩 이동하며 
	sorted 리스트에 정렬하면서 삽입 
	완성된 sorted 리스트를 새로운 리스트로 저장 
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

// 정렬된 리스트 -> 대문자 리스트와 소문자 리스트로 분해
void makeList(HeadNode* h, HeadNode* h_upper, HeadNode* h_lower) {
	ListNode* tmp = h->head;
	ListNode* node;
	h_upper->head = h->head;
	while (tmp->link != NULL) {
		// 대, 소문자 경계 노드 탐색
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
	
	// 메모리 반환 
	freeList(list_upper);
	freeList(list_lower);
	return 0;
}