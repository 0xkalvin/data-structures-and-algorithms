#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
} Node;

typedef struct Tree {
    struct Node* root;

} Tree;

Node* createNode(int data);
Tree* createTree();
void insert(Tree* t, int data);
void printInOrder(Node* root);
void printPostOrder(Node* root);
void printPreOrder(Node* root);


#endif