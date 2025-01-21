#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1001
#if 1
#include "queue.h"
#define RIPE 1
#define UNRIPE 0
#define NONE -1

int M, N, unripped_tomatoes;
int box[MAX][MAX] = {0};
int visit[MAX][MAX] = { 0 };
ListQueue* Queue;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void input_data(void);
void print_box(void);
int bfs(void);

int main(void) {
	(void) freopen("input.txt", "r", stdin);
	Queue = LQ_CreateQueue();
	input_data();
	if (unripped_tomatoes == 0) {
		printf("0");
		return;
	}
	return;
}

void input_data(void) {
	(void)scanf("%d %d", &M, &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			(void)scanf(" %d", &box[i][j]);
			if (box[i][j] == UNRIPE) { unripped_tomatoes++; }
			if (box[i][j] == RIPE){
				EnQueue(Queue, LQ_CreateNode(make_pair(i, j)));
			}
		}
	}
}

void print_box(void) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d ", box[i][j]);
		}
		printf("\n");
	}
}
int bfs(void) {

}
#endif

#if 0
int M, N, unripped_tomatoes;
int** map;
int** visit;
typedef struct _node {
	int row;
	int col;
	int day;
}Node;
Node* Queue;
int rear;	// Node*rear도 사용해보기
int front;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void input_data(void);
void print_data(void);
void destroy_data(void);
void solve_BFS();
void Enqueue(int r, int c, int d);
void Enqueue2(Node data);
void init_Queue(void);
void detroy_Queue(void);
void destroy_data(void);

int main(void) {
	int TC = 5;
	(void)freopen("input.txt", "r", stdin);
	while (TC--) {
		
		input_data();
		print_data();
		solve_BFS();
		destroy_data();
		detroy_Queue();
	}
}

void input_data(void) {
	(void) scanf("%d %d", &M, &N);
	map = (int**)malloc(N * sizeof(int*));
	visit = (int**)malloc(N * sizeof(int*));
	if (!map || !visit) {return;}
	for (int i = 0; i < N; ++i) {
		map[i] = (int*)malloc(M * sizeof(int));
		visit[i] = (int*)malloc(M * sizeof(int));
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			(void) scanf("%d", &map[i][j]);
		}
	}

}

void print_data(void) {
	int i, j;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void init_Queue(void) {
	
}

void destroy_data(void) {
	int i;
	free(map[0]);
	free(visit[0]);
	free(map);
	free(visit);
	map = NULL;
	visit = NULL;
}

void detroy_Queue(void) {

}

void solve_BFS() {
	Queue = (Node*)calloc(M * N, sizeof(Node));
	front = rear = Queue;

	free(Queue);
	Queue = NULL;
}

void Enqueue(int r, int c, int d) {
	if (!Queue | (rear == M * N)) return;
	Queue[rear].row = r;
	Queue[rear].col = c;
	Queue[rear].day = d;
	rear += 1;
}

// Queue의 Full, Empty 상태 점검 없이 작성
void Enqueue2(Node data) {
	Queue[rear++] = data;
}

Node* Dequeue(void) {
	int ret = front;
	// Queue Empty 상태 점검
	if (front == rear) return NULL;
	front += 1;
	return Queue + ret;
}

#endif // 1


#if 1

#endif // 1
