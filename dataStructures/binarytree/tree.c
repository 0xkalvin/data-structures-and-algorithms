#include "tree.h"



Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)    return NULL;

    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

Tree* createTree(){

    Tree* t = malloc(sizeof(Tree));

    if(t == NULL)   return NULL;

    t->root = NULL;

    return t;
}

void insertAux(Node* n, int data);

void insert(Tree* t, int data){

    if(t->root == NULL){
        t->root = createNode(data);
    }
    else insertAux(t->root, data);

}

void printInOrder(Node* root){

    if(root != NULL){
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

void printPreOrder(Node* root){

    if(root != NULL){
        printf("%d ", root->data);
        printInOrder(root->left);
        printInOrder(root->right);
    }
}

void printPostOrder(Node* root){

    if(root != NULL){
        printInOrder(root->left);
        printInOrder(root->right);
        printf("%d ", root->data);
    }
}

void insertAux(Node* root, int data){
    
    if(root->data > data){
        if(root->left == NULL)
            root->left = createNode(data);
        else
            insertAux(root->left, data);
    }
    else if(root->data < data){
        if(root->right == NULL)
            root->right = createNode(data);
        else
            insertAux(root->right, data);
    }
}