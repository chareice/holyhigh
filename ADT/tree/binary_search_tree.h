#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

struct BinarySearchTreeStruct;
typedef struct BinarySearchTreeStruct *Tree;
typedef struct BinarySearchTreeStruct *Node;
typedef int Item;

Tree CreateEmptyTree();
void PrintTree(Tree t, int depth);
Node Insert(Tree t, Item item);
Node FindMax(Tree t);
Node FinxMin(Tree t);
#endif
