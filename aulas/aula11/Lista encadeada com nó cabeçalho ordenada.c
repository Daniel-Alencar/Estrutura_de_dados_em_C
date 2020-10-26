#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;

typedef NODO *ORDERED_LINKED_LIST;
void insertElement(ORDERED_LINKED_LIST list, int value);
void insertElement2(ORDERED_LINKED_LIST list, int value);
void insertElementWithRecursion(ORDERED_LINKED_LIST list, int value);
int returnElement(ORDERED_LINKED_LIST list, int position);
int returnElementWithRecursion(ORDERED_LINKED_LIST list, int position);
void deleteElement(ORDERED_LINKED_LIST list, int position);
void destroyList(ORDERED_LINKED_LIST list);

void createList(ORDERED_LINKED_LIST *list);
int isEmpty(ORDERED_LINKED_LIST list);
int lengthOfList(ORDERED_LINKED_LIST list);
void printList(ORDERED_LINKED_LIST list);

ORDERED_LINKED_LIST concatenateList(ORDERED_LINKED_LIST list1, ORDERED_LINKED_LIST list2);
void deleteRepeated(ORDERED_LINKED_LIST list);
ORDERED_LINKED_LIST concatenateList2(ORDERED_LINKED_LIST list1, ORDERED_LINKED_LIST list2);


int main() {
    ORDERED_LINKED_LIST list1, list2;
    
    createList(&list1);
    insertElement(list1, 10);
    insertElement(list1, 7);
    insertElement(list1, 56);
    insertElement(list1, 12);
    insertElement(list1, 22);
    insertElement(list1, 31);
    insertElement(list1, 56);
    insertElement(list1, 56);
    insertElement(list1, 14);
    insertElement(list1, -67);
    printList(list1);

    for(int i=1; i<=10; i++) {
        printf("%i\n", returnElement(list1, i));
    }
}

void createList(ORDERED_LINKED_LIST *list) {
    (*list) = (NODO *)malloc(sizeof(NODO));
    if(!(*list)) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    (*list)->next = NULL;
    (*list)->value = 0;
}

int isEmpty(ORDERED_LINKED_LIST list) {
    return (list->value) == 0;
}

int lengthOfList(ORDERED_LINKED_LIST list) {
    return list->value;
}

void insertElement(ORDERED_LINKED_LIST list, int value) {
    NODO *alocado;
    alocado = (NODO *)malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    list->value++;

    while((list->next) && (list->next)->value < value) {
        list = list->next;
    }
    alocado->value = value;
    alocado->next = list->next;
    list->next = alocado;
}

void printList(ORDERED_LINKED_LIST list) {
    for(list = list->next; list; list = list->next) {
        printf("%i...", list->value);
    }
    printf("\n\n");
}

int returnElement(ORDERED_LINKED_LIST list, int position) {
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    for(; position--; list = list->next);
    return list->value;
}

void deleteElement(ORDERED_LINKED_LIST list, int position) {
    NODO *aux;
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    list->value--;
    for(; --position; list = list->next);

    aux = (list->next)->next;
    free(list->next);
    list->next = aux;
}

void destroyList(ORDERED_LINKED_LIST list) {
    while(list) {
        free(list);
        list = list->next;
    }
}

void deleteRepeated(ORDERED_LINKED_LIST list) {
    NODO *aux;
    
    for(list = list->next;list && list->next;) {
        if(list->value == (list->next)->value) {
            // deletar um dos elementos
            aux = (list->next)->next;
            free(list->next);
            list->next = aux;
        } else {
            list = list->next;
        }
    }
}

ORDERED_LINKED_LIST concatenateList(ORDERED_LINKED_LIST list1, ORDERED_LINKED_LIST list2) {
    NODO *aux;
    int i, length2 = lengthOfList(list2);
    for(i=1; i<=length2; i++) {
        insertElement(list1, returnElement(list2, i));
    }
    deleteRepeated(list1);
    return list1;
}

ORDERED_LINKED_LIST concatenateList2(ORDERED_LINKED_LIST list1, ORDERED_LINKED_LIST list2) {
    NODO *aux;
    ORDERED_LINKED_LIST newList;
    int element1, element2;
    createList(&newList);

    for(int i=1; i<=lengthOfList(list1); i++) {
        insertElement(newList, returnElement(list1, i));
    }
    for(int i=1; i<=lengthOfList(list2); i++) {
        insertElement(newList, returnElement(list2, i));
    }
    deleteRepeated(newList);
    return newList;
}

void insertElementWithRecursion(ORDERED_LINKED_LIST list, int value) {

    if((list->next) && (list->next)->value < value) {
        insertElementWithRecursion(list->next, value);
    } else {
        NODO *alocado;
        alocado = (NODO *)malloc(sizeof(NODO));
        if(!alocado) {
            printf("\nUnfortunately, there is not store enough in list\n");
            exit(1);
        }
        alocado->value = value;
        alocado->next = list->next;
        list->next = alocado;
    }
}

void insertElement2(ORDERED_LINKED_LIST list, int value) {
    insertElementWithRecursion(list, value);
    list->value++;
}

int returnElementWithRecursion(ORDERED_LINKED_LIST list, int position) {
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    if(position == 1) {
        return (list->next)->value;
    } else {
        returnElementWithRecursion(list->next, position-1);
    }
}
