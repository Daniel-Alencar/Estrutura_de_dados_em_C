#include<stdio.h>
#include<stdlib.h>
typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;
typedef NODO *CIRCULAR_LIST;

void createList(CIRCULAR_LIST *list);
int isEmpty(CIRCULAR_LIST list);
int lengthOfList(CIRCULAR_LIST list);
void insertElement(CIRCULAR_LIST *list, int value, int position);
int returnElement(CIRCULAR_LIST list, int position);
void deleteElement(CIRCULAR_LIST *list, int position);
void destroyList(CIRCULAR_LIST list);
void printList(CIRCULAR_LIST list);

int main() {
    CIRCULAR_LIST list;
    createList(&list);
    insertElement(&list, 5, 1);
    insertElement(&list, 6, 1);
    insertElement(&list, 10, 1);
    insertElement(&list, 1, 1);
    insertElement(&list, 4, 1);

    printList(list);
    printf("Length: %d\n%s\n", lengthOfList(list), isEmpty(list) ? "Is empty" : "Isn't empty");

    printf("Return Element: %i\n", returnElement(list, 2));
    printf("Return Element: %i\n", returnElement(list, 5));
    printf("Return Element: %i\n", returnElement(list, 1));
    printf("Return Element: %i\n", returnElement(list, 3));
    printf("Return Element: %i\n", returnElement(list, 4));
    printf("Return Element: %i\n", returnElement(list, 6));
}

void createList(CIRCULAR_LIST *list) {
    (*list) = NULL;
}

int isEmpty(CIRCULAR_LIST list) {
    return !list;
}

int lengthOfList(CIRCULAR_LIST list) {
    if(list) {
        NODO *aux;
        int length;

        for(length = 1, aux = list->next; aux != list; length++)
            aux = aux->next;
        return length;
    } else {
        return 0;
    }
}

void insertElement(CIRCULAR_LIST *list, int value, int position) {
    NODO *aux, *alocado;
    int length = lengthOfList(*list);

    if(position < 1 || position > (length + 1)) {
        printf("\nPosition isn't valid\n");
        exit(2);
    }
    alocado = (NODO *)malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    alocado->value = value;
    
    if((*list) == NULL) {
        alocado->next = alocado;
        (*list) = alocado;

    } else if (position == (length + 1)) {
        alocado->next = (*list)->next;
        (*list)->next = alocado;
        (*list) = alocado;
    } else {
        int i;
        for(i=1, aux = (*list); i<position; i++) {
            aux = aux->next;
        }
        alocado->next = aux->next;
        aux->next = alocado;
    }
}

void printList(CIRCULAR_LIST list) {
    if(list) {
        NODO *aux = list->next;
        printf("%i...", aux->value);
        for(aux = aux->next; aux != list->next; aux = aux->next) {
            printf("%i...", aux->value);
        }
    }
    printf("\n\n");
}

int returnElement(CIRCULAR_LIST list, int position) {
    int length = lengthOfList(list);
    if(position < 1 || position > length) {
        printf("\nPosition isn't valid\n");
        exit(2);
    }
    if(position == length) {
        return list->value;
    } else {
        int i;
        for(list = list->next, i=1; position > i; list = list->next, i++);
        return list->value;
    }
}