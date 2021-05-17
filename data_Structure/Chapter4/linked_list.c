#include <stdio.h>

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h() {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
} 

void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p=NULL;
	}
}

void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// insert node 
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	
	temp = L->head;
	while(temp->link != NULL) temp = temp->link;
	temp->link = newNode;
}

int main() {
	linkedList_h* L = createLinkedList_h();
	printf("create void list\n");
	printList(L); 
	
	printf("insert node 3\n");
	insertFirstNode(L, "3");
	printList(L);
	
	printf("insert node 5 (Last)\n");
	insertLastNode(L, "5");
	printList(L);
	
	printf("insert node 1 (First)\n");
	insertFirstNode(L, "1");
	printList(L);
	
	printf("free Linked list\n"); 
	freeLinkedList_h(L);
	printList(L);
	
	return 0;
}
