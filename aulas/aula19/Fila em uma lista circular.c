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
void destroyLine(LINKED_LINE line);
int lengthOfLine(LINKED_LINE line);
void printLine(LINKED_LINE line);

int main() {
    LINKED_LINE line;
    createLine(&line);
    insertElement(line, 18);
    insertElement(line, 34);
    insertElement(line, 90);
    insertElement(line, 121);
    insertElement(line, 1024);
    insertElement(line, 4096);
    printLine(line);

    deleteFirstElement(line);
    deleteFirstElement(line);
    deleteFirstElement(line);
    printLine(line);

    destroyLine(line);
    printLine(line);
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
    if(isEmpty(line)) {
        alocado->next = alocado;
        line->firstNode = alocado;
    } else {
        alocado->next = line->lastNode->next;
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
        if(line->length > 1) {
            line->firstNode = line->firstNode->next;
            line->lastNode->next = line->firstNode;
        } else {
            line->firstNode = NULL;
        }
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
        NODE *aux = line->firstNode;
        if(line->length > 1) {
            line->firstNode = line->firstNode->next;
            line->lastNode->next = line->firstNode;
        } else {
            line->firstNode = NULL;
        }
        if(aux == line->lastNode)
            line->lastNode = line->firstNode;
        value = aux->value;
        free(aux);
    }
    line->length--;
    return value;
}

void destroyLine(LINKED_LINE line) {
    if(line->firstNode == NULL) {
        printf("\nThe line is empty\n\n");
        exit(2);
    } else {
        line->lastNode = line->firstNode;
        do {
            line->firstNode = line->lastNode->next;
            free(line->lastNode);
            line->lastNode = line->firstNode;

        } while(--line->length);
        free(line);
    }
}

int lengthOfLine(LINKED_LINE line) {
    return line->length;
}

void printLine(LINKED_LINE line) {
    int i;
    NODE *aux;
    for(i=0, aux = line->firstNode;i<line->length;i++) {
        printf("%d...", aux->value);
        aux = aux->next;
    }
    printf("\n\n");
}