#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct StackNode StackNode;

int isEmpty(StackNode* root);
void push(StackNode** root, int data);
void pop(StackNode** root);
int peek(StackNode* root);
void display(StackNode* root);
int compare(StackNode* a, StackNode* b);

int main()
{
	char s[SIZE];
	char t[SIZE];
	StackNode* sStack = NULL;
	StackNode* tStack = NULL;

	printf("s: ");
	scanf("%s", s);
	printf("t: ");
	scanf("%s", t);

	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '#')
			pop(&sStack);
		else
			push(&sStack, s[i]);
	}

	for (int i = 0; i < strlen(t); i++)
	{
		if (t[i] == '#')
			pop(&tStack);
		else
			push(&tStack, t[i]);
	}

	printf("%d\n", compare(sStack, tStack));
}

struct StackNode
{
	int data;
	StackNode* next;
};

int isEmpty(StackNode* root) { return !root; }

void push(StackNode** root, int data)
{
	StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));

	stackNode->data = data;
	stackNode->next = *root;

	*root = stackNode;
}

void pop(StackNode** root)
{
	if (isEmpty(*root))
		return;

	StackNode* temp = *root;
	*root = (*root)->next;
	free(temp);
}

int peek(StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;

	return root->data;
}

void display(StackNode* root)
{
	if (root)
	{
		display(root->next);
		printf("%c", root->data);
	}
	printf("\n");
}

int compare(StackNode* a, StackNode* b)
{
	if (!a && !b)
		return 1;
	if (a->data == b->data)
		return compare(a->next, b->next);
	return 0;
}
