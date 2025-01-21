#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"
#define MAX 600001
#define _CRT_SECURE_NO_WARNINGS

char editor[MAX];
int N, M;
DLLNode* cursor;
DLLNode head = { NULL };
DLLNode tail = { NULL };

void init_editor();
void print_editor();
void solution();

int main(void) {
	//(void)freopen("input.txt", "r", stdin);
	init_editor();
	solution();
	DLL_print(&head);
	return 0;
}

void init_editor() {
	DLL_Init(&head, &tail);
	(void)scanf("%s", editor);
	(void)scanf("%d", &M);
	int len = strlen(editor);
	for (int i = 0; i < len; ++i){
		DLL_InsertBefore(&tail, DLL_CreateNode(editor[i]));
	}
	cursor = &tail;
	return;
}

void solution() {
	char C, input_char;
	for (int i = 0; i < M; ++i) {
		//printf("%d %d\n", cursor, N_size);
		(void)scanf(" %c", &C);
		//printf("%c\n", C);
		if (C == 'L' && cursor->prev != &head ){
			cursor = cursor->prev;
		}
		else if (C == 'D' && cursor != &tail) {
			cursor = cursor->next;
		}
		else if (C == 'B' && cursor->prev != &head) {
			DLLNode* temp = cursor->prev;
			DLL_RemoveNode(temp);
			DLL_DestroyNode(&temp);
		}
		else if (C == 'P') {
			(void) scanf(" %c", &input_char);
			DLL_InsertBefore(cursor, DLL_CreateNode(input_char));
		}
	}
}