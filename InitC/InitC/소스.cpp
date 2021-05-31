#include <stdio.h>
#include <stdlib.h>

// 연결 리스트 자료형 선언
typedef char element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// 에러 함수
void error() {
	exit(EXIT_FAILURE);
}

// 연결 리스트 노드 삽입 함수
// p : 삽입될 노드의 선행 노드
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) { // 헤드가 공백인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { // 첫 번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else { // p 다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
}

//// 연결 리스트 노드 제거 함수
//// p : 삭제될 노드의 선행 노드
//void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
//	if (!(*phead))
//		return;
//
//	if (p == NULL) // 첫 번째 노드 삭제
//		*phead = (*phead)->link;
//	else // p 다음에 삭제
//		p->link = removed->link;
//
//	free(removed->data);
//	free(removed);
//}

// 연결 리스트 출력 함수
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

// 연결 리스트용 노드 생성 함수
ListNode* create_node(element data, ListNode* link) {

	ListNode* new_node;

	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (!new_node)
		error();

	new_node->data = data;
	new_node->link = link;

	return new_node;
}

// 연결 리스트의 인덱스(at) 번호를 이용한 노드 접근 함수
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

// 노드 값끼리 swap 함수
void swap_node_data(ListNode* n1, ListNode* n2) {

	element tmp;

	tmp = n1->data;
	n1->data = n2->data;
	n2->data = tmp;
}

// 연결 리스트 길이 함수
int length(ListNode** phead) {

	ListNode* p = *phead;
	int count = 0;
	while (p) {
		count++;
		p = p->link;
	}

	return count;
}

// 연결 리스트의 삽입 정렬 함수
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

// 삽입 정렬 함수
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

// 연결리스트 역순 재구성 함수
ListNode* reverse(ListNode** phead) {

	ListNode* p, * q, * tmp;
	p = *phead;
	q = NULL;

	while (p) {
		tmp = q;
		q = p;
		p = p->link;
		q->link = tmp; // q 링크 방향 바꿈 (전환)
	}

	return q;
}

// 프로그램 시작점
int main(int argc, char* argv[]) {

	ListNode* list_ary = NULL; // NULL 필수
	char input_ary[10];
	char tmp;

	int i;

	for (i = 0; i < 10; i++) {
		printf("[No.%2d] 알파벳 입력 : ", i + 1);
		scanf_s("%c", &tmp, sizeof(char));
		while (getchar() != '\n'); // 버퍼 엔터 제거
		insert_node(&list_ary, NULL, create_node(tmp, NULL));
		input_ary[i] = tmp;
	}

	printf("[정렬 전 배열]\n");
	for (i = 0; i < 10; i++)
		printf("%c ", input_ary[i]);
	printf("\n");
	insert_sort(input_ary, 10);
	printf("[정렬 후 배열]\n");
	for (i = 0; i < 10; i++)
		printf("%c ", input_ary[i]);
	printf("\n");

	list_ary = reverse(&list_ary);
	printf("[정렬 전 리스트]\n");
	display(&list_ary);
	insert_list_sort(&list_ary, 10);
	printf("[정렬 후 리스트]\n");
	display(&list_ary);

	return 0;
}