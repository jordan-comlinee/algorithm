#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DLL.h"
#define _CRT_SECURE_NO_WARNINGS


void DLL_Init(DLLNode* head, DLLNode* tail) {
	head->next = tail;
	tail->prev = head;
}

DLLNode* DLL_CreateNode(DLL_ElementType data) {
	DLLNode* newNode = NULL;
	newNode = (DLLNode*)calloc(1, sizeof(DLLNode));
	if (newNode == NULL) {
		printf("out of memory\n");
		exit(0);
	}
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void DLL_DestroyNode(DLLNode** dnode) {
	free(*dnode);
	*dnode = NULL;
}

void DLL_print(DLLNode* head) {
	while (head->next->next != NULL) {
		printf("%c", head->next->data);
		head = head->next;
	}
	printf("\n");
	return;
}

void DLL_print2(DLLNode* head, DLLNode* tail) {
	DLLNode* curr = NULL;
	for (curr = head->next; curr != tail; curr = curr->next) {
		printf("%c ", curr->data);
	}
	printf("\n");
	for (curr = tail->prev; curr != head; curr = curr->prev) {
		printf("%c ", curr->data);
	}
	printf("\n");
}



void DLL_AppendNode(DLLNode* tail, DLLNode* newNode) {
	DLLNode* prev = tail->prev;
	newNode->next = tail;
	newNode->prev = prev;
	prev->next = newNode;
	tail->prev = newNode;
}

DLLNode* DLL_FindNode(DLLNode* head, DLLNode* tail, DLL_ElementType data) {
	DLLNode* curr = NULL;
	for (curr = head->next; curr != tail; curr = curr->next) {
		if (curr->data == data) {
			//printf("data '%c' found in prev : %c, next : %c\n", curr->data, (curr->prev->data == NULL)? '-' : curr->prev->data, (curr->next->data == NULL)? '-' : curr->next->data);
			return curr;
		}
	}
	printf("no data found\n");
	return NULL;
}

void DLL_RemoveNode(DLLNode* rNode) {
	if (rNode == NULL) {
		return;
	}
	rNode->prev->next = rNode->next;
	rNode->next->prev = rNode->prev;
	return;
}

DLLNode* DLL_GetAt(DLLNode* head, DLLNode* tail, int pos) {
	if (pos < 0) {
		printf("out of position : head\n");
		return head;
	}
	DLLNode* curr = head->next;
	while ((curr != tail) && (pos-- > 0)) {
		curr = curr->next;
	}
	if ((curr == tail && pos >= 0)) {
		printf("out of position : tail\n");
		return tail;
	}
	return curr;
}

void DLL_InsertNode(DLLNode* head, DLLNode* tail, DLLNode* newNode, int pos) {
	DLLNode* temp;
	temp = DLL_GetAt(head, tail, pos);
	if (temp == head) {
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next->prev = newNode;
		temp->next = newNode;
		return;
	}
	newNode->prev = temp->prev;
	newNode->next = temp;
	temp->prev->next = newNode;
	temp->prev = newNode;
	return;
}

void DLL_InsertBefore(DLLNode* targetNode, DLLNode* newNode) {
	newNode->next = targetNode;
	newNode->prev = targetNode->prev;
	targetNode->prev->next = newNode;
	targetNode->prev = newNode;
}
void DLL_InsertAfter(DLLNode* targetNode, DLLNode* newNode) {
	newNode->next = targetNode->next;
	newNode->prev = targetNode;
	targetNode->next->prev = newNode;
	targetNode->next = newNode;
}
#endif