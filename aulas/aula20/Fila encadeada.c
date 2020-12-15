#include<stdio.h>
#include<stdlib.h>
#include"./Fila encadeada.h"

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
    NODE *aux;
    for(aux = line->firstNode; aux; aux = aux->next) {
        printf("%d...", aux->value);
    }
    printf("\n\n");
}

void sortByDistribution(LINKED_LINE line) {
    int i,acumulate, base = 10, digitos = 4;
    LINKED_LINE filas[base];
    for(i=0;i<base;i++) {
        createLine(&filas[i]);
    }

    for(acumulate = 1; digitos; acumulate *= 10, digitos--) {
        while(lengthOfLine(line)) {
            int value = returnAndDeleteElement(line);
            int index = (value / acumulate) % 10;
            insertElement(*(filas + index), value);
        }
        for(i=0;i<base;i++) {
            while(lengthOfLine(*(filas + i))) {
                insertElement(line, returnAndDeleteElement(*(filas + i)));
            }
        }
    }
}
