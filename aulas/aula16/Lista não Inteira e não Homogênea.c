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
    union values teste;
    strcpy(teste.stringValue, "14");
    teste.floatValue = 14;
    teste.intValue = 14;
    printf("%d...\n", sizeof(teste));

    printf("%s\n", teste.stringValue);
    printf("%f\n", teste.floatValue);
    printf("%d\n", teste.intValue);
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
    } else if(type == FLT) {
        alocado->VALUE.floatValue = value.floatValue;
    } else if(type == STRING) {
        strcpy(alocado->VALUE.stringValue, value.stringValue);
    } else {
        printf("Error! Type not recognized");
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
    
}