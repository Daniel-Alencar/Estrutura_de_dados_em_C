#include"Árvore binária de busca.h"
typedef struct node {
    BINARY_TREE tree;
    struct node * next;
}NODE;
typedef struct {
    NODE *firstNode;
    NODE *lastNode;
    int length;
}HEAD_NODE;
typedef HEAD_NODE *LINKED_LINE ;

void createLine(LINKED_LINE *line);
int lineIsEmpty(LINKED_LINE line);
void insertElementIntoLine(LINKED_LINE line, BINARY_TREE tree);
BINARY_TREE returnElementFromLine(LINKED_LINE line);
void deleteElementFromLine(LINKED_LINE line);
BINARY_TREE returnAndDeleteElementFromLine(LINKED_LINE line);
void destroyLine1(LINKED_LINE line);
void destroyLine2(LINKED_LINE line);
int lengthOfLine(LINKED_LINE line);
void printLine(LINKED_LINE line);
