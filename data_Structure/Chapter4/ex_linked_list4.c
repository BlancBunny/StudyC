#include <stdio.h>
#include <stdlib.h>

typedef struct dListNode {
    int data;
    struct dListNode* r_link;
    struct dListNode* l_link;
}dListNode;

typedef struct {
    dListNode* head;
}HeadNode;

HeadNode* createList() {
    HeadNode* h;
    h = (HeadNode*)malloc(sizeof(HeadNode));
    h->head = NULL;
    printf("create Double-Linked-List\n");
    return h;
}

void printList(HeadNode* h) {
    dListNode* tmp;
    printf("list : (");
    tmp = h->head;
    if (h->head == NULL) {
        printf(")\n");
        return;
    }
    while(tmp->r_link != NULL) {
        printf("%d", tmp->data);
        tmp = tmp->r_link;
        printf(", ");
    }
    printf("%d", tmp->data);
    printf(")\n");

    /* 역순 출력
        printf("DL(left) = (");
    while(tmp->l_link != NULL) {
        printf("%d", tmp->data);
        tmp = tmp->l_link;
        printf(", ");
    }
    printf("%d", tmp->data);
    printf(")\n");
    */
}

dListNode* createNode(int data) {
    dListNode* node;
    node = (dListNode*)malloc(sizeof(dListNode));
    node->data = data;
    node->l_link = NULL;
    node->r_link = NULL;
    return node;
}

void insertNode(HeadNode* h, dListNode* preNode, dListNode* newNode) {
    if (h->head == NULL) {
        h->head = newNode;
        return;
    }

  
    if (preNode == NULL) { // 첫번째 
        newNode->r_link = h->head;
        h->head->l_link = newNode;
        h->head = newNode;
    }
    else { 
    newNode->l_link = preNode;
    newNode->r_link = preNode->r_link;
    if (preNode->r_link != NULL) preNode->r_link->l_link = newNode;
    preNode->r_link = newNode;
    }
  
}

void insertNodeFirst(HeadNode* h, dListNode* newNode) {
    if (h->head == NULL) h->head = newNode;
    else {
        newNode->r_link = h->head;
        h->head->l_link = newNode;
        h->head = newNode;
    }
}

void insertNodeLast(HeadNode* h, dListNode* newNode) {
    dListNode* tmp;
    if (h->head == NULL) h->head = newNode;
    else {
        tmp = h->head;
        while (tmp->r_link != NULL) tmp = tmp->r_link;
        tmp->r_link = newNode;
        newNode->l_link = tmp;
        // newNode->r_link = NULL;
    }
}

dListNode* searchNode(HeadNode* h, int data) {
    dListNode* tmp = h->head;
    while (tmp != NULL) {
        if (tmp->data == data) {
            return tmp;
        }
        tmp = tmp->r_link;
    }
    return tmp;
}

void deleteNode(HeadNode* h, dListNode* node) {
    if (h->head == NULL) {
        printf("빈 리스트\n");
        return;
    }

    if (h->head == node) {
        h->head = node->r_link;
        free(node);
        node->r_link = NULL;
    }
    else if (node->r_link == NULL) {
        node->l_link->r_link = NULL;
        free(node);
        node->l_link = NULL;
    }
    else {
    node->l_link->r_link = node->r_link;
    node->r_link->l_link = node->l_link;
    free(node);
    node->l_link = NULL;
    node->r_link = NULL;
    }
}

void freeNode(HeadNode* h) {
    dListNode* tmp;
    while(h->head != NULL) {
        tmp = h->head;
        h->head = tmp->r_link;
        printf("free %d memory\n", tmp->data); 
        free(tmp);
        tmp->l_link = NULL;
        tmp->r_link = NULL;
    }
    
}
    
int main() {
    HeadNode* h = createList();
    printList(h);
    insertNode(h, NULL, createNode(20));
    printList(h);
    insertNode(h, NULL, createNode(40));
    printList(h);
    insertNodeLast(h, createNode(70)); 
    printList(h);

    dListNode* s_node = searchNode(h, 20);
    insertNode(h, s_node, createNode(110));
    printList(h);
    insertNodeLast(h, createNode(60));
    printList(h);
    // 탐색 삭제 (첫번째) 
    s_node = searchNode(h, 40);
    deleteNode(h, s_node);
    printList(h);
    // 탐색 삭제 (마지막)
    s_node = searchNode(h, 60);
    deleteNode(h, s_node);
    printList(h);
    // 탐색 삭제 (가운데)
    s_node = searchNode(h, 110);
    deleteNode(h, s_node);
    printList(h);

    freeNode(h);
    printList(h);

    printf("delete Double-Linked-List\n");
    free(h);
    return 0;
}
