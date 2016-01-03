#ifndef _QUEUE_H
#define _QUEUE_H

struct Node;
struct QueueStruct;

typedef struct Node *PtrToNode;
typedef struct QueueStruct *Queue;
typedef int Item;

void Enqueue(Queue q, Item item);
Item Dequeue(Queue q);
int IsEmpty(Queue q);
int QueueLength(Queue q);
Queue CreateQueue();
void PrintQueue(Queue q);
#endif
