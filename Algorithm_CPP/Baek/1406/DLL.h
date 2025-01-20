#pragma once
typedef char DLL_ElementType;

typedef struct _dll_node {
	DLL_ElementType data;
	struct _dll_node* prev;
	struct _dll_node* next;
} DLLNode;


void DLL_Init(DLLNode* head, DLLNode* tail);
DLLNode* DLL_CreateNode(DLL_ElementType data);
void DLL_DestroyNode(DLLNode** dnode);
void DLL_print(DLLNode* head);
void DLL_print2(DLLNode* head, DLLNode* tail);
void DLL_AppendNode(DLLNode* head, DLLNode* newNode);
DLLNode* DLL_FindNode(DLLNode* head, DLLNode* tail, DLL_ElementType data);
void DLL_RemoveNode(DLLNode* rNode);
DLLNode* DLL_GetAt(DLLNode* head, DLLNode* tail, int pos);
void DLL_InsertNode(DLLNode* head, DLLNode* tail, DLLNode* newNode, int pos);
void DLL_InsertBefore(DLLNode* targetNode, DLLNode* newNode);
void DLL_InsertAfter(DLLNode* targetNode, DLLNode* newNode);


/*
DLLNode* SLL_CreateNode(DLL_ElementType data);
void SLL_print(DLLNode* node);
//void SLL_print2(Node* node);
//void SLL_print3(Node* node);
void SLL_DestroyNode(DLLNode** node);
void SLL_AppendNode(DLLNode** head, DLLNode* newNode);
void SLL_RemoveNode(DLLNode** head, DLL_ElementType data);
void SLL_InsertNode(DLLNode** head, DLLNode* newNode, int pos);
*/