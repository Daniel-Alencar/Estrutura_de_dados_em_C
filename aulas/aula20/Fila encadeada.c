#include<stdio.h>
#include<stdlib.h>
#include"../aula7, 8 e 9/Lista - alocação encadeada dinâmica.h"
#define BASE 10
#define MAXIMUM_DIGITS 4

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
void sortByDistribution(LINKED_LINE line);
void printLine(LINKED_LINE line);
int lengthOfLine(LINKED_LINE line);

int main() {
    LINKED_LINE line;
    createLine(&line);
    insertElement(line, 1923);
    insertElement(line, 1314);
    insertElement(line, 4567);
    insertElement(line, 2719);
    insertElement(line, 2718);
    insertElement(line, 1312);
    printLine(line);
    
    sortByDistribution(line);
    printLine(line);

    printf("%d...", returnAndDeleteElement(line));
    printf("%d...", returnAndDeleteElement(line));
    printf("%d...", returnAndDeleteElement(line));
    printf("\n\n");
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
        return;
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

void printLine(LINKED_LINE line) {
    int i;
    NODE *aux;
    for(aux = line->firstNode; aux; aux = aux->next) {
        printf("%d...", aux->value);
    }
    printf("\n\n");
}

void sortLinkedListByDistribution(DYNAMIC_CHAINED_LIST *list) {
    int c1, c2;
    LINKED_LINE lines[BASE];
    for(c2=0; c2<BASE; c2++) {
        createLine(&lines[c2]);
    }
    for(c1=0; c1<MAXIMUM_DIGITS; c1++) {
        while(!isEmpty(*list)) {
            int i, value = returnElementWithRecursion(*list, 1);
            i = (value / (int) (pow(BASE, c1))) % BASE;
            insertElement(lines[i], value);
            deleteElement(list, 1);
        }
        for(c2=0; c2<BASE; c2++) {
            while(!isEmpty(lines[c2])) {
                insertElementWithRecursion(list, returnAndDeleteElement(lines[c2]), lengthOfListWithRecursion(*list) + 1);
            }
        }
    }
}