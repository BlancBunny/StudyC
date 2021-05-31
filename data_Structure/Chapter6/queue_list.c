#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct linkedQueue {
    int data;
    struct linkedQueue* link;
} QNode;

typedef struct {
    QNode *front, *rear;
} LQueueType;

LQueueType* createLinkedQueue() {
    LQueueType* LQ;
    LQ = (LQueueType*)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

int isEmpty(LQueueType* LQ) {
    if (LQ->front == NULL) {
        printf("Linked Queue is Empty!\n");
        return 1;
    }
    else return 0;
} // 연결 리스트는 isFull() 이 필요없음

void enQueue(LQueueType* LQ, element item) { // rear 노드에 새 노드 연결
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;

    if (LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {
        LQ->rear->link = newNode; // 원래 마지막 노드를 새 노드에 연결
        LQ->rear = newNode;       // 새로운 노드를 rear로 설정
    } 
}

element deQueue(LQueueType* LQ) { // front로부터 노드 데이터 반환(첫번째 노드 삭제)  
    element item;
    QNode* tmp = LQ->front;

    if (isEmpty(LQ)) return 0;
    
    item = tmp->data;
    LQ->front = tmp->link;
    if (LQ->front == NULL) // 원래 리스트에 노드가 하나뿐 
        LQ->rear == NULL;

    free(tmp);
    tmp->link = NULL;
    return item;   

}

element peek(LQueueType* LQ) {
    if (isEmpty(LQ)) return 0;
    else return LQ->front->data;
}

void printQueue(LQueueType* LQ) {
    QNode* tmp = LQ->front; 
    printf(" Linked-Queue : [ ");
    while(tmp) {
        if (tmp == LQ->front) printf("(front)");
        if (tmp == LQ->rear) printf("(rear)");
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf(" ]\n");
}


int main() {
    // 큐 생성
    LQueueType* LQ = (LQueueType*)malloc(sizeof(LQueueType));
    element data; // deQueue 값 저장
    printf("\n Linked-List Queue\n");

    // 데이터 3개 입력(enQueue)
    printf("\n enQueue 10 >>"); enQueue(LQ, 10); printQueue(LQ);
    printf("\n enQueue 20 >>"); enQueue(LQ, 20); printQueue(LQ);
    printf("\n enQueue 30 >>"); enQueue(LQ, 30); printQueue(LQ);

    // 데이터 출력(peek)
    data = peek(LQ); printf("\n peek %d >>", data); printQueue(LQ);

    // 데이터 삭제(deQueue)
    data = deQueue(LQ); printf("\n deQueue %d >>", data); printQueue(LQ);
    data = deQueue(LQ); printf("\n deQueue %d >>", data); printQueue(LQ);
    data = deQueue(LQ); printf("\n deQueue %d >>", data); printQueue(LQ);

    printf("\n Insert 77 >>"); enQueue(LQ, 77); printQueue(LQ);
    printf("\n Insert 88 >>"); enQueue(LQ, 88); printQueue(LQ);
    
    return 0;
}
