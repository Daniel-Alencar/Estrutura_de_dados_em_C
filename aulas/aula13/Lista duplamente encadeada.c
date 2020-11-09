#include<stdio.h>
#include<stdlib.h>
typedef struct nodo {
    int value;
    struct nodo *next;
    struct nodo *previous;
}NODO;
typedef NODO *DOUBLY_LINKED_LIST;

void createList(DOUBLY_LINKED_LIST *list);
int isEmpty(DOUBLY_LINKED_LIST list);
int lengthOfList(DOUBLY_LINKED_LIST list);
void insertElement(DOUBLY_LINKED_LIST *list, int value, int position);
void printList(DOUBLY_LINKED_LIST list);
int returnElement(DOUBLY_LINKED_LIST list, int position);
void deleteElement(DOUBLY_LINKED_LIST *list, int position);
void destroyList(DOUBLY_LINKED_LIST list);
void reverseList(DOUBLY_LINKED_LIST *list);

int main() {
    DOUBLY_LINKED_LIST list;
    createList(&list);
    insertElement(&list, 34, 1);
    insertElement(&list, 12, 1);
    insertElement(&list, 42, 3);
    insertElement(&list, 82, 4);
    insertElement(&list, -2, 2);
    printList(list);

    printf("%d\n", returnElement(list, 3));
    printf("%d\n", returnElement(list, 1));
    printf("%d\n", returnElement(list, 6));

    deleteElement(&list, 6);
    printList(list);
    deleteElement(&list, 1);
    printList(list);
    deleteElement(&list, 4);
    printList(list);
    deleteElement(&list, 2);
    printList(list);

    reverseList(&list);
    printList(list);
}

void createList(DOUBLY_LINKED_LIST *list) {
    *list = NULL;
}

int isEmpty(DOUBLY_LINKED_LIST list) {
    return !list;
}

int lengthOfList(DOUBLY_LINKED_LIST list) {
    int length;
    for(length = 0; list; length++) {
        list = list->next;
    }
    return length;
}

void insertElement(DOUBLY_LINKED_LIST *list, int value, int position) {
    NODO *alocado;

    if(position < 1 || position > (lengthOfList(*list) + 1)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    alocado = (NODO *) malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n\n");
        exit(2);
    }

    alocado->value = value;
    if(position == 1) {
        alocado->next = (*list);

        if(*list)
            (*list)->previous = alocado;

        alocado->previous = NULL;
        (*list) = alocado;
    } else {
        NODO *aux;
        for(aux = (*list), position--; --position; aux = aux->next);
        alocado->next = aux->next;

        if(aux->next)
            (aux->next)->previous = alocado;
        
        alocado->previous = aux;
        aux->next = alocado;
    }
}

void printList(DOUBLY_LINKED_LIST list) {
    printf("[");
    for(; list; list = list->next) {
        printf("%d, ", list->value);
    }
    printf("\b\b]\n");
}

int returnElement(DOUBLY_LINKED_LIST list, int position) {
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    for(;--position; list = list->next);
    return list->value;
}

void deleteElement(DOUBLY_LINKED_LIST *list, int position) {
    NODO *aux;
    if(position < 1 || position > lengthOfList(*list)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    
    if(position == 1) {
        aux = (*list)->next;
        free(*list);
        (*list) = aux;
        if(aux)
            aux->previous = NULL;
    } else {
        NODO *aux1;
        for(aux = (*list), position--; --position; aux = aux->next);

        aux1 = aux->next;
        aux->next = aux1->next;
        free(aux1);
        if(aux->next)
            (aux->next)->previous = aux;
    }
}

void destroyList(DOUBLY_LINKED_LIST list) {
    NODO *aux;
    while(list) {
        aux = list->next;
        free(list);
        list = aux;
    }
}

void reverseList(DOUBLY_LINKED_LIST *list) {
    NODO *aux, *aux1;
    int atual = 0;

    for(aux = (*list); aux->next; aux = aux->next);
    aux1 = (*list);
    
    while(atual < lengthOfList(*list) / 2) {
        int value = aux1->value;
        aux1->value = aux->value;
        aux->value = value;

        aux1 = aux1->next;
        aux = aux->previous;
        atual++;
    }
}