#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}Node;

void addFirstNode(Node* target, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = target->link;
	target->link = newNode;
}

void addLastNode(Node* target, int data) {
        Node* newNode =	(Node*)malloc(sizeof(Node));
	Node* temp;

	newNode->data = data;
	newNode->link = NULL;
	

	temp = target->link;
	// 리스트 공백일떄 
	if (target->link == NULL) {
		target->link = newNode;
		return;
	}

	// 리스트의 마지막까지 탐색
	while(temp->link != NULL) temp = temp->link;
	temp->link = newNode;
}
	
void printNode(Node* target) {
	Node* temp;
	temp = target->link; 
	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->link;
	}

}

void freeNode(Node* target) {
	Node* temp;

	while (target->link != NULL) {
		temp = target->link;
		target->link = temp->link;
		printf("%d free\n", temp->data);
		free(temp);
		temp = NULL;
	}

}
int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->link = NULL;

	addFirstNode(head, 10);
	addFirstNode(head, 20);
	addFirstNode(head, 30);
	addFirstNode(head, 40);
	addFirstNode(head, 50);	
	
	addLastNode(head, 60);
	addLastNode(head, 100); 
	
	
	printNode(head);	
	freeNode(head);
	
	return 0;
}



