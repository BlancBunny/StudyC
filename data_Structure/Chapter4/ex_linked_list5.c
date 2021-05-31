#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int data;
    struct listNode* link;
}ListNode;

typedef struct {
    ListNode* head;
}HeadNode;

HeadNode* createList() {
    HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
    if (h != NULL) h->head = NULL;
    return h;
}

ListNode* createNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("memory alloc fail\n");
        return;
    }

    newNode->data = data;
    newNode->link = NULL;

    return newNode;
}

void insertNodeFirst(HeadNode* h, ListNode* node) {
    if (h->head == NULL) {
        h->head = node;
        node->link = node;
        return;
    }
    
    ListNode* tmp = h->head;
    while(tmp->link != h->head) tmp = tmp->link;
    node->link = tmp->link;
    tmp->link = node;
    h->head = node;    
}

void insertNodeMiddle(HeadNode* h, ListNode* preNode, ListNode* newNode) {
    if (h->head == NULL) { // 빈 리스트
        h->head = newNode;
        newNode->link = newNode;
        return;
    }

    newNode->link = preNode->link;
    preNode->link = newNode;
}

void insertNodeLast(HeadNode* h, ListNode* newNode) {
    if (h->head == NULL) {
        h->head = newNode;
        newNode->link = newNode;
        return;
    }

    // 마지막 노드 탐색 
    ListNode* tmp;
    while (tmp->link != h->head) tmp = tmp->link;
    tmp->link = newNode;
    newNode->link = h->head;

}

void printList(HeadNode* h) {
    if (h->head == NULL) {
        printf("List : ()\n");
        return;
    }

    ListNode* tmp = h->head;
    printf("List : (");
    do {
        printf("%d", tmp->data);
        tmp = tmp->link;
        if (tmp != h->head) printf(", ");
    } while (tmp != h->head);
    printf(")\n");
}

ListNode* searchNode(HeadNode* h, int data) {
    ListNode* tmp;
    tmp = h->head;
    if (tmp == NULL) return NULL;
    do {
        if (tmp->data == data) return tmp;
        tmp = tmp->link;
    } while(tmp != h->head);
    return tmp;
}

void deleteNode(HeadNode* h, ListNode* node) {
    ListNode* tmp;
    if (h->head == NULL) return;
    if (h->head->link == h->head) { // 리스트에 노드가 1개
        free(h->head);
        h->head = NULL;
    }
    else if (node == NULL) return; // 노드가 NULL
    else {
        tmp = h->head;
        while (tmp->link != node) tmp = tmp->link;
        tmp->link = node->link; 
        if (node == h->head) // 삭제될 노드가 head 일 경우 head 재설정
            h->head = tmp->link; 
        free(node);
    }
}

void freeNode(HeadNode* h) {
    ListNode* tmp;
    // 마지막 노드 링크를 끊어서 단방향 리스트로
    while (tmp->link != h->head) tmp = tmp->link;
    tmp->link = NULL; 

    // 단방향 리스트 메모리 반환
    while(h->head != NULL) {
        tmp = h->head;
        h->head = tmp->link;
        printf("%d memory free\n", tmp->data);
        free(tmp);
    }    
}

int main() {
    HeadNode* h = createList();
    ListNode* node = createNode(20);
    printList(h);
    insertNodeFirst(h, node);
    printList(h);
    insertNodeMiddle(h, node, createNode(30));
    printList(h);
    insertNodeFirst(h, createNode(70));
    printList(h);
    insertNodeFirst(h, createNode(50));
    printList(h);
    insertNodeLast(h, createNode(120));
    printList(h);


    ListNode* s_node = searchNode(h, 70); // 가운데 노드 탐색
    deleteNode(h, s_node);                // 삭제
    printList(h);

    s_node = searchNode(h, 50);           // 첫번째 노드 탐색
    deleteNode(h, s_node);                // 삭제
    printList(h);

    freeNode(h);                          // 전체 메모리 반환

    return 0;
}
