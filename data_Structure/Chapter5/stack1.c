#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 4

typedef int element; // element의 자료형을 int로 정의 

element stack[STACK_SIZE];
int top = -1;

int isEmpty() {
    if (top == -1) return 1;
    else return 0;
}

int isFull() {
    if (top == STACK_SIZE - 1) return 1;
    else return 0;
}

void push(element item) {
    if (isFull()) {
        printf("\n\n Stack is Full! \n");
        return;
    }

    else stack[++top] = item; 
}

element pop() { // top 원소 출력(삭제)
    if (isEmpty()) {
        printf("\n\n Stack is Empty!\n");
        return 0;
    }
    else return stack[top--];
}

element peek() { // top 원소 출력(삭제x)
    if (isEmpty()) {
        printf("\n\n Stack is Empty!\n");
        return 0;
    }
    else return stack[top];
}

void printStack() {
    int i;
    printf("\n Stack [ ");
    for (i = 0; i <= top; i++) 
        printf("%d ", stack[i]);
    printf("] ");
}

int main() {
    element item;
    printf("Stack EX\n");
    printStack();
    push(1); printStack();
    push(2); printStack();
    push(3); printStack();

    item = peek(); printStack();
    printf("peek => %d", item);

    item = pop(); printStack();
    printf("pop => %d", item);

    item = pop(); printStack();
    printf("pop => %d\n", item);
    
    

    return 0;
}
