#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;

typedef NODO *LINKED_LIST;

void createList(LINKED_LIST *list);
int isEmpty(LINKED_LIST list);
int lengthOfList(LINKED_LIST list);
void insertElement(LINKED_LIST list, int value, int position);
void printList(LINKED_LIST list);
int returnElement(LINKED_LIST list, int position);
void deleteElement(LINKED_LIST list, int position);
void destroyList(LINKED_LIST list);


int main() {
    LINKED_LIST list;
    int position, i;
    
    createList(&list);
    insertElement(list, 14, 1);
    insertElement(list, 10, 1);
    insertElement(list, 7, 1);
    insertElement(list, 7, 1);
    insertElement(list, 12, 3);
    insertElement(list, 22, 5);
    insertElement(list, 31, 7);
    insertElement(list, 56, 8);
    insertElement(list, 30, 2);
    insertElement(list, 14, 1);
    insertElement(list, -67, 3);

    printList(list);

    for(i=0; i<3; i++) {
        scanf("%i", &position);
        deleteElement(list, position);
        printList(list);
    }
    destroyList(list);
    printList(list);
}

void createList(LINKED_LIST *list) {
    (*list) = (NODO *)malloc(sizeof(NODO));
    if(!(*list)) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    (*list)->next = NULL;
    (*list)->value = 0;
}

int isEmpty(LINKED_LIST list) {
    return (list->value) == 0;
}

int lengthOfList(LINKED_LIST list) {
    return list->value;
}

void insertElement(LINKED_LIST list, int value, int position) {
    NODO *aux;
    NODO *alocado;

    if(position < 1 || position > (lengthOfList(list) + 1)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    for(aux = list; --position; aux = aux->next);

    alocado = (NODO *)malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    alocado->value = value;
    alocado->next = aux->next;
    aux->next = alocado;

    list->value++;
}

void printList(LINKED_LIST list) {
    for(list = list->next; list; list = list->next) {
        printf("%i...", list->value);
    }
    printf("\n\n");
}

int returnElement(LINKED_LIST list, int position) {
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    for(; position--; list = list->next);
    return list->value;
}

void deleteElement(LINKED_LIST list, int position) {
    NODO *aux, *originalList;
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    for(originalList = list; --position; list = list->next);

    aux = (list->next)->next;
    free(list->next);
    list->next = aux;

    originalList->value--;
}

void destroyList(LINKED_LIST list) {
    while(list) {
        free(list);
        list = list->next;
    }
}
