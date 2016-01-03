#include <stdio.h>
#include <stdlib.h>
#include "./queue.h"

struct Node{
  Item PayLoad;
  PtrToNode Next;
};

struct QueueStruct{
  PtrToNode First;
  //避免判断队列是否为空时需要遍历整个队列
  PtrToNode Last;
};

Queue CreateQueue(){
  Queue q;
  q = malloc(sizeof(struct QueueStruct));
  q->First = NULL;
  q->Last = NULL;
  return q;
}

int IsEmpty(Queue q){
  //队首和队尾都为空
  return q->First == NULL && q->Last == NULL;
}

int QueueLength(Queue q){
  int l = 0;
  for(PtrToNode i = q->First; i != NULL; i = i->Next){
    l++;
  }
  return l;
}

void Enqueue(Queue q, Item item){
  PtrToNode tmpNode;
  tmpNode = malloc(sizeof(struct Node));
  tmpNode->PayLoad = item;
  tmpNode->Next = NULL;

  //如果当前队列为空
  if(IsEmpty(q)){
    q->First = tmpNode;
    q->Last = tmpNode;
  }else{
    //如果队列中有一个元素
    q->Last->Next = tmpNode;
    q->Last = tmpNode;
  }
}

Item Dequeue(Queue q){
  if(q->First == NULL){
    printf("Queue Is Empty\n");
    return 0;
  }else{
    PtrToNode node = q->First;
    q->First = q->First->Next;
    //如果是队列中的最后一个元素
    if(q->First ==  NULL){
      q->Last = NULL;
    }
    Item item = node->PayLoad;
    free(node);
    return item;
  }
}

void PrintQueue(Queue q){
  if(IsEmpty(q)){
    printf("Current Queue Is Empty");
  }else{
    for(PtrToNode i = q->First; i != NULL; i = i->Next){
      printf("%d ", i->PayLoad);
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  Queue q;
  q = CreateQueue();
  PrintQueue(q);
  Enqueue(q, 1);
  PrintQueue(q);
  Enqueue(q, 2);
  PrintQueue(q);
  Enqueue(q, 3);
  PrintQueue(q);
  Dequeue(q);
  PrintQueue(q);
  Enqueue(q, 4);
  PrintQueue(q);
  return 0;
}
