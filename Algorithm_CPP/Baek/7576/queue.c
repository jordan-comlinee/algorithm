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
        printf("�޸� ���� 1\n");
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
        printf("�޸� ���� 2\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void EnQueue(ListQueue* Queue, Node* newNode) {
    if (newNode == NULL) return;

    if (Queue->count == 0) {
        // ť�� ��������� front�� rear�� �� ��带 ����Ű���� ����
        Queue->front = newNode;
        Queue->rear = newNode;
    } else {
        // ť�� ��尡 ������ rear�� next�� �� ��带 ����
        Queue->rear->next = newNode;
        Queue->rear = newNode;  // rear�� �� ���� ����
    }

    Queue->count += 1;
}

ElementType DeQueue(ListQueue* Queue) {
    if (Queue->count == 0) {
        printf("Queue Empty!\n");
        return make_pair(0, 0);  // ť�� ����� �� �⺻�� ��ȯ
    }

    ElementType temp = Queue->front->data;
    Queue->front = Queue->front->next;
    Queue->count -= 1;

    if (Queue->count == 0) {
        Queue->rear = NULL;  // ť�� ��� rear�� NULL�� ����
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
