#include<stdio.h>
#include<stdlib.h>
typedef struct nodo {
    int values;
    struct nodo *next;
    struct nodo *previous;
}NODO;
typedef NODO *LIST_WITH_HEADER;

void createList(LIST_WITH_HEADER *list);
int isEmpty(LIST_WITH_HEADER list);
int lengthOfList(LIST_WITH_HEADER list);
void insertElement(LIST_WITH_HEADER list, int value, int position);
void printList(LIST_WITH_HEADER list);
int returnElement(LIST_WITH_HEADER list, int position);
void deleteElement(LIST_WITH_HEADER list, int position);
void destroyList(LIST_WITH_HEADER list);

int main() {

}

void createList(LIST_WITH_HEADER *list) {
    (*list) = (NODO *)malloc(sizeof(NODO));
    if(!(*list)) {
        printf("\nNot storage enough\n\n");
        exit(1);
    }
    (*list)->previous = (*list)->next = (*list);
    (*list)->values = 0;
}

int isEmpty(LIST_WITH_HEADER list) {
    return !list->values;
}

int lengthOfList(LIST_WITH_HEADER list) {
    return list->values;
}

void insertElement(LIST_WITH_HEADER list, int value, int position) {
    if(position < 1 || position > (lengthOfList(list) + 1)) {
        printf("\nInvalid position\n\n");
        exit(2);
    }
    NODO *alocado = (NODO *) malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nNot storage enough\n\n");
        exit(1);
    }
    alocado->values = value;
    if(list->values == 0) {
        list->next = alocado;
        list->previous = alocado;

        alocado->next = list;
        alocado->previous = list;
    } else if(position == lengthOfList(list) + 1) {
        (list->previous)->next = alocado;
        alocado->previous = (list->previous);

        list->previous = alocado;
        alocado->next = list;
    } else {
        NODO *aux;
        if(position <= lengthOfList(list) / 2)
            for(aux = list; --position; aux = aux->next);
        else
            for(aux = list; position >= 0; aux = aux->previous, position--);
        
        (aux->next)->previous = alocado;
        alocado = aux->next;

        aux->next = alocado;
        alocado->previous = aux;
    }
    list->values++;
}