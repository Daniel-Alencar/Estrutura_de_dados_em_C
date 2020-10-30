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

int main() {

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
    NODO *aux,*aux1, *alocado;

    if(position < 1 || position > (lengthOfList(list) + 1)) {
        printf("\nPosition isn't valid\n");
        exit(2);
    }
    alocado = (NODO *)malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    alocado->value = value;
    
    if(position == 1) {
        alocado->next = (*list)->next;
        (*list)->next = alocado;
    } else {
        int i;
        for(i=1, aux = (*list); i<position; i++) {
            aux = aux->next;
        }
        alocado = aux->next;
        aux->next = alocado;
    }
    // falta só a implementação de inserção na última posição
}