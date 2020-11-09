#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INTGR 1
#define FLT 2
#define STRING 3

typedef struct nodo {
    int type;
    union values {
        int intValue;
        float floatValue;
        char stringValue[20];
    } VALUE;
    struct nodo *next;
    struct nodo *previous;
}NODO;
typedef NODO *HETEROGENEOUS_LIST;

void createList(HETEROGENEOUS_LIST *list);
int insertElement(HETEROGENEOUS_LIST *list, int position, int type, union values value);
int lengthOfList(HETEROGENEOUS_LIST list);
void printList(HETEROGENEOUS_LIST list);

int main() {
    HETEROGENEOUS_LIST list;
    union values Valores;
    Valores.intValue = 22;

    createList(&list);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    insertElement(&list, 1, 1, Valores);
    
    printf("Length: %d%c", lengthOfList(list), '\n');
}

void createList(HETEROGENEOUS_LIST *list) {
    *list = NULL;
}

int lengthOfList(HETEROGENEOUS_LIST list) {
    if(list) {
        NODO *aux;
        int cont = 1;
        for(aux = list; aux != list->next; list = list->next) {
            cont++;
        }
        return cont;
    } else {
        return 0;
    }
}

int insertElement(HETEROGENEOUS_LIST *list, int position, int type, union values value) {
    NODO *alocado, *aux;
    int length = lengthOfList(*list);
    if(position < 1 || position > (length + 1)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    alocado = (NODO *)malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n\n");
        exit(2);
    }

    if(type == INTGR) {
        alocado->VALUE.intValue = value.intValue;
        alocado->type = 1;
    } else if(type == FLT) {
        alocado->VALUE.floatValue = value.floatValue;
        alocado->type = 2;
    } else if(type == STRING) {
        strcpy(alocado->VALUE.stringValue, value.stringValue);
        alocado->type = 3;
    } else {
        printf("Error! Type not recognized\n");
        return 1;
    }

    if((*list) == NULL) {
        alocado->next = alocado;
        alocado->previous = alocado;
        (*list) = alocado;

    } else if (position == (length + 1)) {
        alocado->next = (*list)->next;
        alocado->previous = (*list);

        (*list)->next = alocado;
        (alocado->next)->previous = alocado;

        (*list) = (*list)->next;
    } else {
        int i;
        for(i=1, aux = (*list); i<position; i++) {
            aux = aux->next;
        }
        alocado->next = aux->next;
        alocado->previous = aux;

        aux->next = alocado;
        (alocado->next)->previous = alocado;
    }
}

void printList(HETEROGENEOUS_LIST list) {
    NODO *aux;
    printf("[");
    for(aux = list, list = list->next; aux != list; list = list->next) {
        if(list->type == 1) {
            printf("\n\t%d,", list->VALUE.intValue);
        } else if(list->type == 2) {
            printf("\n\t%f,", list->VALUE.floatValue);
        } else if(list->type == 3) {
            printf("\n\t%s,", list->VALUE.stringValue);
        } else {
            printf("Error! Type not recognized");
            exit(1);
        }
    }
    printf("\b\n]\n");
}