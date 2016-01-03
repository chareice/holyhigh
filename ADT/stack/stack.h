#ifndef _STACK_H
#define _STACK_H

struct Node;
typedef struct Node *PtrToStack;
typedef struct Node *PtrToNode;
typedef PtrToStack Stack;
typedef int Item;

int IsEmpty(Stack s);
int StackLength(Stack s);
void StackPush(Stack s, Item item);
PtrToNode StackPop(Stack s);
Stack CreateStack();
void PrintStack(Stack s);
#endif
