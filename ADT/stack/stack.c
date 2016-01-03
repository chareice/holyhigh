#include <stdio.h>
#include <stdlib.h>
#include "./stack.h"

struct Node{
  int PayLoad;
  PtrToNode Next;
};

int IsEmpty(Stack s){
  return s->Next == NULL;
}

int StackLength(Stack s){
    int l = 0;
    for(PtrToNode nextNode = s->Next; nextNode != NULL; nextNode = nextNode->Next){
      l++;
    }
    return l;
}

void PrintStack(Stack s){
  for(PtrToNode i = s; i!=NULL; i=i->Next){
    printf("Current Node Address Is %p\n PayLoad Is %d\n Next Item Address Is %p\n", i, i->PayLoad, i->Next);
  }
}

Stack CreateStack(){
  Stack s;
  s = malloc(sizeof(struct Node));
  s->Next = NULL;
  return s;
}

void StackPush(Stack s, Item item) {
  PtrToNode tmpNode;
  tmpNode = malloc(sizeof(struct Node));
  tmpNode->PayLoad = item;
  tmpNode->Next = s->Next;
  s->Next = tmpNode;
}

PtrToNode StackPop(Stack s){
  PtrToNode popItem;
  popItem = s->Next;
  s->Next = popItem->Next;
  return popItem;
}

int main(int argc, char *argv[]){
  Stack s = CreateStack();
  for(int i = 0; i < 10 ; i++){
    StackPush(s, i + 1);
  }
  printf("%d\n", StackLength(s));
  PtrToNode popItem = StackPop(s);
  printf("%d\n", StackLength(s));
  return 0;
}
