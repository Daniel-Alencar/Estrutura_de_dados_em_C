#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *left;
    struct node *right;
    int value;
    int heightOfRight, heightOfLeft;
}NODE;
typedef NODE * AVL_TREE;

void makeTree(AVL_TREE *tree, int value);
void setLeft(AVL_TREE tree, int value);
void setRight(AVL_TREE tree, int value);

int valueOfNode(AVL_TREE tree);
AVL_TREE left(AVL_TREE tree);
AVL_TREE right(AVL_TREE tree);
int heightOfRight(AVL_TREE tree);
int heightOfLeft(AVL_TREE tree);

void preOrdem(AVL_TREE tree);
void inOrdem(AVL_TREE tree);
void posOrdem(AVL_TREE tree);

void rotateToRight(AVL_TREE *tree);
void rotacaoParaDireita(AVL_TREE *tree);
void rotacaoParaEsquerda(AVL_TREE *tree);