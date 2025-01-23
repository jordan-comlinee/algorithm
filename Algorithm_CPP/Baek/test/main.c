#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// CreateNode, DestroyNode
#if 0
#include "DLL.h"

int main(void) {
	DLLNode head = { 'A' };
	DLLNode tail = { 'B' };
	DLL_Init(&head, &tail);

	DLLNode* a;
	DLLNode* b;
	DLLNode* c;
	a = DLL_CreateNode('A');
	b = DLL_CreateNode('B');
	c = DLL_CreateNode('C');
	a->next = b; b->next = c;
	b->prev = a; c->prev = b;
	printf("%c %c %c\n", a->data, a->next->data, a->next->next->data);
	// b�� ����ؼ� A B C ���
	printf("%c %c %c\n", b->prev->data, b->data, b->next->data);

	return 0;
}
#endif

// InsertBefore ~ INsertAfter
#if 0
#include "DLL.h"
int main(void) {
	DLLNode head = { 0 };
	DLLNode tail = { 0 };
	DLLNode* temp = NULL;
	DLL_Init(&head, &tail);

	DLL_InsertAfter(&tail, DLL_CreateNode('A'));
	DLL_InsertAfter(&tail, DLL_CreateNode('B'));
	DLL_InsertAfter(&tail, DLL_CreateNode('C'));
	DLL_InsertAfter(&tail, DLL_CreateNode('D'));
	DLL_print(&head, &tail);
	temp = DLL_GetAt(&head, &tail, 0);
	DLL_InsertAfter(temp, DLL_CreateNode('0'));
	DLL_print(&head, &tail);
	/*
	temp = DLL_GetAt(&head, &tail, 4);
	if (temp) printf("  %c\n", temp->data);
	temp = DLL_GetAt(&head, &tail, 3);
	if (temp) printf("  %c\n", temp->data);
	temp = DLL_GetAt(&head, &tail, 2);
	if (temp) printf("  %c\n", temp->data);
	*/
	/*
	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'A'));
	DLL_print(&head, &tail);
	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'C'));
	DLL_print(&head, &tail);
	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'D'));
	DLL_print(&head, &tail);
	*/
	/*
	temp = DLL_FindNode(&head, &tail, 'F');
	if (temp) printf("%c\n", temp->data);
	temp = DLL_FindNode(&head, &tail, 'B');
	if (temp) printf("%c\n", temp->data);
	temp = DLL_FindNode(&head, &tail, 'C');
	if (temp) printf("%c\n", temp->data);
	*/
	return 0;
}
#endif

// 2���� ��ȯ�� ����� 2���� ���
#if 0
int N;
// num�� �Է¹޾� 2������ ��ȯ�� ��� (nums�� ����)
void to_binary(int num) {
	// 2���� ���
	for (int i = N - 1; i >= 0; i--) {
		printf("%d ", (num >> i) & 1); // 
	}
	printf("\n");
}
int main(void) {

	int i;
	int fnum;
	(void)scanf("%d", &N);

	fnum = 1 << N;  // 2�� N�� 

	for (i = 0; i < fnum; i++) {
		to_binary(i);
	}
	return 0;
}
#endif

// ��͸� ����� 2���� ���
#if 0
int N;  // 2 ~ 10�� �Է�
int nums[10];

void print_nums(void) {
	for (int i = 0; i < N; ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}
// num�� �Է¹޾� 2������ ��ȯ�� ��� (nums�� ����)
void make_nums(int L) {
	if (L >= N) {
		print_nums();
		return;
	}
	nums[L] = 0;
	make_nums(L + 1);

	nums[L] = 1;
	make_nums(L + 1);
}
int main(void) {
	(void)scanf("%d", &N);
	make_nums(0);
	return 0;
}
#endif

// ť(Queue) �����
#if 0
typedef int ElementType;
#define SIZE (5)
ElementType Queue[SIZE];
int front, rear;

// ���� ����
void EnQueue(ElementType data) {
	// Queue�� ������ ���(Full)
	if (rear == SIZE) {
		printf("Full Queue\n");
		return;
	}
	Queue[rear++] = data;
}
// ���� ����
ElementType DeQueue() {
	//Queue�� ����ִ� ���(Empty)
	if (front == rear) {
		printf("Empty Queue\n");
		return NULL;
	}
	return Queue[front++];
}
void printQueue(void) {
	for (int i = front; i < rear; ++i) {
		printf("%d ", Queue[i]);
	}
	printf("\n");
}
int main(void) {
	// Queue�� ��� �غ�
	front = rear = 0;
	printf("DeQueue: %d\n", DeQueue());
	EnQueue(1); printQueue();
	EnQueue(2); printQueue();
	printf("DeQueue: %d\n", DeQueue());
	EnQueue(3); printQueue();
	EnQueue(4); printQueue();
	printf("DeQueue: %d\n", DeQueue());
	printQueue();
	EnQueue(5); printQueue();
	EnQueue(6); printQueue();
	EnQueue(7); printQueue();
	EnQueue(8); printQueue();

	return 0;
}
#endif

// ȯ��ť(Queue) �����
#if 0
typedef int ElementType;
#define SIZE (6)
ElementType Queue[SIZE];  // 5���� data����, 1���� dummy
int front, rear;

// ���� ����
void EnQueue(ElementType data) {
	// Queue�� ������ ���(Full)
	if ((rear + 1) % SIZE == front) {
		printf("Full Queue\n");
		return;
	}
	Queue[rear] = data;
	rear = (rear + 1) % SIZE;
}
// ���� ����
ElementType DeQueue() {
	ElementType ret;
	//Queue�� ����ִ� ���(Empty)
	if (front == rear) {
		printf("Empty Queue\n");
		return NULL;  // 0, '\0', NULL
	}
	ret = Queue[front];
	Queue[front] = 0;  // Ȯ���� ���� �� �ʼ� �ƴ�
	front = (front + 1) % SIZE;
	return ret;
}
void printQueue(void) {
	for (int i = 0; i < SIZE; ++i) {
		printf("%d ", Queue[i]);
	}
	printf("\n");
}
int main(void) {
	// Queue�� ��� �غ�
	front = rear = 0;
	printf("DeQueue: %d\n", DeQueue());
	EnQueue(1); printQueue();
	EnQueue(2); printQueue();
	printf("DeQueue: %d\n", DeQueue());
	EnQueue(3); printQueue();
	EnQueue(4); printQueue();
	printf("DeQueue: %d\n", DeQueue());
	printQueue();
	EnQueue(5); printQueue();
	EnQueue(6); printQueue();
	EnQueue(7); printQueue();
	EnQueue(8); printQueue();

	return 0;
}
#endif

// ����ü�� Ȱ���� ȯ��ť(Queue) �����
#if 0
typedef int ElementType;
typedef struct _node {
	ElementType data;
}Node;

typedef struct _cq {
	int capacity;
	int front;
	int rear;
	Node* node;
}CircularQueue;

CircularQueue* CQ_CreatQueue(int capacity) {
	CircularQueue* temp;
	temp = (CircularQueue*)calloc(1, sizeof(CircularQueue));
	if (temp == NULL) {
		printf("�޸� ���� 1\n");
		return NULL;
	}
	temp->node = (Node*)calloc(capacity + 1, sizeof(Node));
	if (temp->node == NULL) {
		printf("�޸� ���� 2\n");
		return NULL;
	}
	temp->capacity = capacity;
	temp->front = 0;
	temp->rear = 0;
	return temp;
}
// Queue->front, Queue->rear, Queue->capacity
// ���� ����
void EnQueue(CircularQueue* Queue, ElementType data) {

	// Queue�� ������ ���(Full)
	if ((Queue->rear + 1) % (Queue->capacity + 1) == Queue->front) {
		printf("Full Queue\n");
		return;
	}
	Queue->node[Queue->rear].data = data;
	//(Queue->node + Queue->rear)->data = data;
	Queue->rear = (Queue->rear + 1) % (Queue->capacity + 1);
}

// ���� ����
ElementType DeQueue(CircularQueue* Queue) {
	ElementType ret;
	//Queue�� ����ִ� ���(Empty)
	if (Queue->front == Queue->rear) {
		printf("Empty Queue\n");
		return NULL;  // 0, '\0', NULL
	}
	ret = Queue->node[Queue->front].data;
	//Queue->node[Queue->front].data = 0;  // Ȯ���� ���� �� �ʼ� �ƴ�
	Queue->front = (Queue->front + 1) % (Queue->capacity + 1);
	return ret;
}


int main(void) {
	CircularQueue* Queue;
	Queue = CQ_CreatQueue(5);
	EnQueue(Queue, 10);
	EnQueue(Queue, 20);
	printf("DeQueue: %d\n", DeQueue(Queue));
	EnQueue(Queue, 30);
	EnQueue(Queue, 40);
	printf("DeQueue: %d\n", DeQueue(Queue));
	EnQueue(Queue, 50);
	EnQueue(Queue, 60);
	EnQueue(Queue, 70);
	EnQueue(Queue, 80);
	return 0;
}


#endif

// ��ũ�帮��Ʈ�� Ȱ���� ť(Queue) ����� (���̾���)
#if 0
typedef int ElementType;
typedef struct _node {
	ElementType data;
	struct _node* next;
}Node;

typedef struct _queue {
	Node* front;
	Node* rear;
	int Count;
}ListQueue;

ListQueue* LQ_CreateQueue(void) {
	ListQueue* temp;
	temp = (ListQueue*)calloc(1, sizeof(ListQueue));
	if (temp == NULL) {
		printf("�޸� ���� 1\n");
		return NULL;
	}
	temp->front = NULL;
	temp->rear = NULL;
	temp->Count = 0;
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

// rear�� �ڿ� �߰�
// �ʱ⿡�� rear�� NULL
void LQ_EnQueue(ListQueue* Queue, Node* newnode) {
	if (newnode == NULL) return;

	if (Queue->Count == 0)  // Queue->rear == NULL, Queue->front == NULL	
		Queue->front = newnode;
	else
		Queue->rear->next = newnode;

	//Node** temp = (Queue->Count) ? &Queue->rear->next : &Queue->front;
	//*temp = newnode;

	Queue->rear = newnode;
	Queue->Count += 1;
}
ElementType LQ_DeQueue(ListQueue* Queue) {
	if (Queue->Count == 0) {
		printf("Queue Empty!\n");
		return NULL;
	}
	ElementType temp = Queue->front->data;
	Queue->front = Queue->front->next;
	Queue->Count -= 1;
	if (!Queue->Count) Queue->rear = NULL;
	return temp;
}
void LQ_print(ListQueue* Queue) {
	Node* curr;
	for (curr = Queue->front; curr != NULL; curr = curr->next) {
		printf("%d ", curr->data);
	}
	printf("\n");
}
int main(void) {
	ListQueue* Queue = LQ_CreateQueue();
	LQ_EnQueue(Queue, LQ_CreateNode(100));
	LQ_EnQueue(Queue, LQ_CreateNode(200));
	LQ_EnQueue(Queue, LQ_CreateNode(300));
	LQ_EnQueue(Queue, LQ_CreateNode(400));
	LQ_print(Queue);
	printf("%d\n", LQ_DeQueue(Queue));
	printf("%d\n", LQ_DeQueue(Queue));
	LQ_print(Queue);
	LQ_EnQueue(Queue, LQ_CreateNode(500));
	LQ_print(Queue);
	return 0;
}
#endif
