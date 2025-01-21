#pragma once

typedef struct _pair {
	int first;
	int second;
}Pair;

typedef Pair ElementType;
typedef struct _node {
	ElementType data;
	struct _node* next;
}Node;

typedef struct _queue {
	Node* front;
	Node* rear;
	int count;
}ListQueue;



Pair make_pair(int a, int b);
ListQueue* LQ_CreateQueue(void);
Node* LQ_CreateNode(ElementType data);
void EnQueue(ListQueue* Queue, Node* newNode);
ElementType DeQueue(ListQueue* Queue);
void LQ_print(ListQueue* Queue);