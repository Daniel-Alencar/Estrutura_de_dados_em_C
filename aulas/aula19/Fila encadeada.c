#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value;
    struct node * next;
}NODE;
typedef struct {
    NODE *firstNode;
    NODE *lastNode;
    int length;
}HEAD_NODE;
typedef HEAD_NODE *LINKED_LINE ;

void createLine(LINKED_LINE *line);
int isEmpty(LINKED_LINE line);
void insertElement(LINKED_LINE line, int value);
int returnFirstElement(LINKED_LINE line);
void deleteFirstElement(LINKED_LINE line);
int returnAndDeleteElement(LINKED_LINE line);
void destroyLine1(LINKED_LINE line);
void destroyLine2(LINKED_LINE line);

void printLine(LINKED_LINE line);
int lengthOfLine(LINKED_LINE line);

int main() {
    LINKED_LINE line;
}

void createLine(LINKED_LINE *line) {
    (*line) = (HEAD_NODE *) malloc(sizeof(HEAD_NODE));
    if(!(*line)) {
        printf("\nNot storage enough\n\n");
        exit(1);
    }
    (*line)->firstNode = (*line)->lastNode = NULL;
    (*line)->length = 0;
}

int isEmpty(LINKED_LINE line) {
    return (line->firstNode == NULL);
}

void insertElement(LINKED_LINE line, int value) {
    NODE *alocado = (NODE *)malloc(sizeof(NODE));
    if(!alocado) {
        printf("\nNot storage enough\n\n");
        exit(1);
    }
    alocado->value = value;
    alocado->next = NULL;

    if(line->lastNode == NULL) {
        line->firstNode = alocado;
    } else  {
        line->lastNode->next = alocado;
    }
    line->lastNode = alocado;
    line->length++;
}

int returnFirstElement(LINKED_LINE line) {
    if(isEmpty(line)) {
        printf("\nThe line is empty\n\n");
        exit(2);
    }
    return line->firstNode->value;
}

void deleteFirstElement(LINKED_LINE line) {
    if(isEmpty(line)) {
        printf("\nThe line is empty\n\n");
        exit(2);
    } else {
        NODE *aux = line->firstNode;
        line->firstNode = line->firstNode->next;
        if(aux == line->lastNode)
            line->lastNode = line->firstNode;
        free(aux);
    }
    line->length--;
}

int returnAndDeleteElement(LINKED_LINE line) {
    int value;
    if(isEmpty(line)) {
        printf("\nThe line is empty\n\n");
        exit(2);
    } else {
        value = line->firstNode->value;
        NODE *aux = line->firstNode;
        line->firstNode = line->firstNode->next;
        if(aux == line->lastNode)
            line->lastNode = line->firstNode;
        free(aux);
    }
    line->length--;
    return value;
}

void destroyLine1(LINKED_LINE line) {
    if(!line->firstNode) {
        printf("\nThe line is empty\n\n");
        exit(2);
    } else {
        line->lastNode = line->firstNode;
        while(line->lastNode) {
            line->firstNode = line->lastNode->next;
            free(line->lastNode);
            line->lastNode = line->firstNode;
        }
        free(line);
    }
}

void destroyLine2(LINKED_LINE line) {
    if(!line->firstNode) {
        printf("\nThe line is empty\n\n");
        exit(2);
    } else {
        NODE *aux = line->firstNode;
        while(aux) {
            line->firstNode = aux->next;
            free(aux);
            aux = line->firstNode;
        }
        free(line);
    }
}

int lengthOfLine(LINKED_LINE line) {
    return line->length;
}