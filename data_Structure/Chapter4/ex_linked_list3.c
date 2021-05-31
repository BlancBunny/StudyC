#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
}ListNode;

typedef struct {
    ListNode* head;
}HeadNode; 

HeadNode* createNode() {
    HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
    h->head = NULL;
    return h;
}

void freeList(HeadNode* h) {
   ListNode* tmp;
   while (h->head != NULL) {
       tmp = h->head;
       h->head = h->head->link;
       free(tmp);
       tmp = NULL;
    }   
}
void printList(HeadNode* h) {
    ListNode* tmp; 
    printf("L = (");
    tmp = h->head;
    while (tmp != NULL) {
        printf("%s", tmp->data);
        tmp = tmp->link;
        if (tmp != NULL) printf(", ");
    }
    printf(") \n");
}

void preInsertNode(HeadNode* h, int data) {
    ListNode* newNode;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->link = h->head;
    h->head = newNode;
}

void midInsertNode(HeadNode* h, ListNode* node, int data) {
    // 1. 새 노드 생성
    ListNode* newNode;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data; 
    // 2. 노드 연결 
    if (h->head == NULL) {
        newNode->link = NULL;
        h->head = newNode;
    }
    else if (node == NULL) {
        printf("해당 노드가 존재하지 않습니다\n"); 
    }
    else {
        newNode->link = node->link;
        node->link = newNode;
    }
}

void rearInsertNode(HeadNode* h, int data) {
    ListNode* newNode;
    ListNode* tmp;

    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->link = NULL;
    if (h->head == NULL) {
        h->head = newNode;
        return;
    }

    tmp = h->head;
    while(tmp->link != NULL) tmp = tmp->link;
    tmp->link = newNode;
}

ListNode* searchNode(HeadNode* h, int data) {
    ListNode* tmp = h->head;
    while(tmp != NULL) {
        if (tmp->data == data) return tmp;
        else tmp = tmp->link;
    }
    return tmp;
}

void deleteNode(HeadNode* h, ListNode* node) {
    ListNode* tmp;
    if (h->head == NULL) {
        printf("빈 리스트\n");
        return;
    }

    if (h->head->link == NULL) {
        free(h->head);
        h->head = NULL;
    }
    else if (node == NULL) printf("삭제할 노드 없음\n");
    else {
        tmp = h->head;
        while (tmp->link != node) {
            tmp = tmp->link;
        }
        tmp->link = node->link;
        free(node);
    }       
}


int main() {

    return 0;
}
