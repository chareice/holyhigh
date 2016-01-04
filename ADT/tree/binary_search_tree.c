#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "binary_search_tree.h"

struct BinarySearchTreeStruct{
  Item PayLoad;
  Node Left;
  Node Right;
};

Tree CreateTree(Item rootPayLoad){
  Tree t = malloc(sizeof(struct BinarySearchTreeStruct));
  t->PayLoad = rootPayLoad;
  t->Left = t->Right = NULL;
  return t;
}

void PrintTree(Tree t, int depth){
  for (int i = 0; i < depth; i++) {
    printf("\t");
  }

  printf("%d\n", t->PayLoad);
  if(t->Right != NULL){
    PrintTree(t->Right, depth+1);
  }
  if(t->Left != NULL){
    PrintTree(t->Left, depth+1);
  }
}

Node FindMax(Tree t){
  while (t->Right != NULL) {
    t = t->Right;
  }
  return t;
}

Node FindMin(Tree t){
  if(t->Left != NULL){
    return FindMin(t->Left);
  }else{
    return t;
  }
}

Node Insert(Tree t, Item item){
  if(t == NULL){
    t = malloc(sizeof(struct BinarySearchTreeStruct));
    t->PayLoad = item;
    t->Left = NULL;
    t->Right = NULL;
  }

  if(item > t->PayLoad){
    t->Right = Insert(t->Right, item);
  }else if(item < t->PayLoad){
    t->Left = Insert(t->Left, item);
  }

  return t;
}

int main(int argc, char const *argv[]) {
  Tree t = CreateTree(6);
  PrintTree(t, 0);
  Insert(t, 5);
  PrintTree(t, 0);
  Insert(t, 8);
  PrintTree(t, 0);
  Insert(t, 9);
  PrintTree(t, 0);
  Insert(t, 7);
  PrintTree(t, 0);
  Insert(t, 11);
  PrintTree(t, 0);
  return 0;
}
