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

    insertElement(list, 7, 1);
    printList(list);

    insertElement(list, -70, 3);
    printList(list);

    insertElement(list, 1200, 6);
    printList(list);

    insertElement(list, -7, 1);
    printList(list);

    // insertElement(list, -14, 7);
    // printList(list);

    // insertElement(list, -21, 7);
    // printList(list);

    // printf("%d%c", returnElement(list, 1), '\n');
    // printf("%d%c", returnElement(list, 2), '\n');
    // printf("%d%c", returnElement(list, 3), '\n');
    // printf("%d%c", returnElement(list, 4), '\n');
    // printf("%d%c", returnElement(list, 5), '\n');
    // printf("%d%c", returnElement(list, 6), '\n');
    // printf("%d%c", returnElement(list, 7), '\n');
    // printf("%d%c", returnElement(list, 8), '\n');
    // printf("%d%c", returnElement(list, 9), '\n');

//     printList(list);

    // printf("\n\n");
    // deleteElement(list, 9);
    // printList(list);

    // deleteElement(list, 8);
    // printList(list);

    // deleteElement(list, 1);
    // printList(list);

    // deleteElement(list, 3);
    // printList(list);

    // deleteElement(list, 4);
    // printList(list);
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
    LIST_WITH_HEADER alocado;
    if(position < 1 || position > (list->values + 1)) {
        printf("\nInvalid position\n\n");
        exit(2);
    }
    alocado = (LIST_WITH_HEADER) malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nerro\n\n");
        exit(3);
    }

    alocado->values = value;
    list->values++;

    for(; position < list->values;list = list->previous, position++ );
    alocado->previous = list->previous;
    alocado->next = list;
    list->previous = alocado;
    (alocado->previous)->next = alocado;
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
    int length = lengthOfList(list);
    if(position < 1 || position > length) {
        printf("\nInvalid position\n\n");
        exit(2);
    }
    if(position <= length / 2) {
        for(; position > 0; list = list->next, position--);
    } else {
        for(; length >= position; list = list->previous, length--);
    }
    return list->values;
}

void deleteElement(LIST_WITH_HEADER list, int position) {
    int length = lengthOfList(list);
    if(position < 1 || position > length) {
        printf("\nInvalid position\n\n");
        exit(2);
    }
    list->values--;

    // if(position <= length / 2)
    //     for(; position > 0; list = list->next, position--);
    // else
    //     for(; length >= position; list = list->previous, length--);
    while(position++ <= length) {
        list = list->previous;
    }

    (list->next)->previous = list->previous;
    (list->previous)->next = list->next;
    free(list);
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