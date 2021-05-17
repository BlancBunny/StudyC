#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}Node;

int main() {

	Node* head = (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node));
	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1;
	
	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->data = 20;
	node2->link = NULL;
	node1->link = node2;
	
	Node* node3 = (Node*)malloc(sizeof(Node));
	node3->data = 30;
	node3->link = NULL;
	node2->link = node3;
	
	Node* node4 = (Node*)malloc(sizeof(Node));
	node4->data = 40;
	node4->link = NULL;
	node3->link = node4;
	
	Node* node5 = (Node*)malloc(sizeof(Node));
	node5->data = 50;
	node5->link = NULL;
	node4->link = node5;

	Node* curr = head->link;
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->link;
	}	
	
	free(head);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);

	return 0;
}
