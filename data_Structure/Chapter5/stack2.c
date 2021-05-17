#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct stackNode {
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top;

int isEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

void push(element item) {
    stackNode* tmp = (stackNode*)malloc(sizeof(stackNode));
    if (tmp == NULL) {
        printf("memory alloc fail!");
    }
    tmp->data = item;
    tmp->link = top;
    top = tmp;
}

element pop() {
    element item;
    stackNode* tmp = top;

    if (top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    item = tmp->data;
    top = tmp->link;
    free(tmp);
    tmp->link = NULL;
    return item;
}

element peek() {
    if (top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    return top->data;
}

void printStack() {
    stackNode* tmp = top;
    printf("\nStack : [ ");
    while (tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf("] ");
}

int main() {
    element item;
    top = NULL;

    printf("linked-list Stack\n");
    printStack();
    push(1); printStack();
    push(2); printStack();
    push(3); printStack();
    
    item = peek(); printStack();
    printf("peek => %d", item);

    item = pop(); printStack();
    printf("pop => %d", item);

    item = pop(); printStack();
    printf("pop => %d", item);

    item = pop(); printStack();
    printf("pop => %d", item);

    return 0;
}
