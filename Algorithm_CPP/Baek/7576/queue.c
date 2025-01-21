#include <stdio.h>
#include "queue.h"

Pair make_pair(int a, int b) {
    Pair ret = { a, b };
    return ret;
}

ListQueue* LQ_CreateQueue(void) {
    ListQueue* temp;
    temp = (ListQueue*)calloc(1, sizeof(ListQueue));
    if (temp == NULL) {
        printf("메모리 부족 1\n");
        return NULL;
    }
    temp->front = NULL;
    temp->rear = NULL;
    temp->count = 0;
    return temp;
}

Node* LQ_CreateNode(ElementType data) {
    Node* temp;
    temp = (Node*)calloc(1, sizeof(Node));
    if (temp == NULL) {
        printf("메모리 부족 2\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void EnQueue(ListQueue* Queue, Node* newNode) {
    if (newNode == NULL) return;

    if (Queue->count == 0) {
        // 큐가 비어있으면 front와 rear가 새 노드를 가리키도록 설정
        Queue->front = newNode;
        Queue->rear = newNode;
    } else {
        // 큐에 노드가 있으면 rear의 next에 새 노드를 연결
        Queue->rear->next = newNode;
        Queue->rear = newNode;  // rear를 새 노드로 갱신
    }

    Queue->count += 1;
}

ElementType DeQueue(ListQueue* Queue) {
    if (Queue->count == 0) {
        printf("Queue Empty!\n");
        return make_pair(0, 0);  // 큐가 비었을 때 기본값 반환
    }

    ElementType temp = Queue->front->data;
    Queue->front = Queue->front->next;
    Queue->count -= 1;

    if (Queue->count == 0) {
        Queue->rear = NULL;  // 큐가 비면 rear도 NULL로 설정
    }

    return temp;
}

void LQ_print(ListQueue* Queue) {
    Node* curr;
    for (curr = Queue->front; curr != NULL; curr = curr->next) {
        printf("%d %d ", curr->data.first, curr->data.second);
    }
    printf("\n");
}
