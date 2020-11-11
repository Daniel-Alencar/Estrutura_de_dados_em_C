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
void reverseList(LIST_WITH_HEADER list);

int main() {
    LIST_WITH_HEADER list;
    createList(&list);
    printList(list);

    insertElement(list, 8, 1);
    printList(list);

    insertElement(list, 9, 1);
    printList(list);

    insertElement(list, 10, 1);
    printList(list);

    insertElement(list, 11, 1);
    printList(list);

    insertElement(list, -70, 3);
    printList(list);

    insertElement(list, 1200, 5);
    printList(list);

    insertElement(list, -7, 7);
    printList(list);




    reverseList(list);
    printList(list);
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
    NODO *alocado = (NODO *) malloc(sizeof(NODO)), *aux;
    int length = lengthOfList(list);

    if(position < 1 || position > (length + 1)) {
        printf("\nInvalid position\n\n");
        exit(2);
    }
    if(!alocado) {
        printf("\nNot storage enough\n\n");
        exit(1);
    }
    alocado->values = value;

    for(aux = list; position > 1; aux = aux->next, --position);
    (aux->next)->previous = alocado;
    alocado->next = aux->next;
    aux->next = alocado;
    alocado->previous = aux;
    
    list->values++;
}

void printList(LIST_WITH_HEADER list) {
    if(list->values) {
        NODO *aux;
        for(aux = list->next; aux != list; aux = aux->next) {
            printf("%d...", aux->values);
        }
    }
    printf("\n");
}

int returnElement(LIST_WITH_HEADER list, int position) {
    int length = lengthOfList(list), count;
    if(position < 1 || position > length) {
        printf("\nInvalid position\n\n");
        exit(2);
    }
    if(position <= length / 2) {
        int count = 1;
        for(list = list->next; position > count; list = list->next, count++);
    } else {
        count = length;
        for(list = list->previous; count > position; list = list->previous, count--);
    }
    return list->values;
}

void deleteElement(LIST_WITH_HEADER list, int position) {
    int length = lengthOfList(list);
    NODO *aux;
    if(position < 1 || position > length) {
        printf("\nInvalid position\n\n");
        exit(2);
    }
    for(aux = list; position > 0; aux = aux->next, --position);

    (aux->next)->previous = aux->previous;
    (aux->previous)->next = aux->next;
    free(aux);

    list->values--;
}

void destroyList(LIST_WITH_HEADER list) {
    NODO *aux;
    int length = lengthOfList(list);
    do {
        aux = list;
        list = list->next;
        free(aux);
    } while(length--);
}

void reverseList(LIST_WITH_HEADER list) {
    NODO *aux;
    int length = lengthOfList(list);
    if(length > 1) {
        do {
            aux = list->next;
            list->next = list->previous;
            list->previous = aux;

            list = aux;
        } while(length--);
    }
}