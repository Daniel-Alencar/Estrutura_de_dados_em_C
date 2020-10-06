#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct {
    int value;
    int next;
    
}NODO;

typedef struct{
    int indexOfFirstElement;
    int indexOfFirstFreeNodo;
    NODO list[max];

}LISTA_ENCADEADA_ESTATICA;

void createList(LISTA_ENCADEADA_ESTATICA *list) {
    int i;
    list->indexOfFirstFreeNodo = 0;
    list->indexOfFirstElement = -1;
    
    for(i=0; i<(max-1); i++) {
        list->list[i].next = i+1;
    }
    list->list[i].next = -1;
}

int isEmpty(LISTA_ENCADEADA_ESTATICA *list) {
    return list->indexOfFirstElement == -1;
}

int lengthOfList(LISTA_ENCADEADA_ESTATICA *list) {
    int i, counter = 0;

    for(i = list->indexOfFirstElement; i != -1 ; i = list->list[i].next) {
        counter++;
    }
    return counter;
}

void insertElement(LISTA_ENCADEADA_ESTATICA *list, int value, int position) {
    if(position < 0 || position > lengthOfList(list)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    if(list->indexOfFirstFreeNodo == -1) {
        printf("\nUnfortunately, there is not store enough in list\n\n");
        exit(2);
    }
    
    int i, currentPosition = 0, aux, aux1;

    if(position == 0) {
        list->list[list->indexOfFirstFreeNodo].value = value;

        aux = list->list[list->indexOfFirstFreeNodo].next;
        list->list[list->indexOfFirstFreeNodo].next = list->indexOfFirstElement;
        
        list->indexOfFirstElement = list->indexOfFirstFreeNodo;
        list->indexOfFirstFreeNodo = aux;

    } else {
        list->list[list->indexOfFirstFreeNodo].value = value;

        for(i = list->indexOfFirstElement; 1; i = list->list[i].next, currentPosition++) {
            if(currentPosition == (position - 1)) {
                aux = list->list[list->indexOfFirstFreeNodo].next;
                aux1 = list->list[i].next;

                list->list[i].next = list->indexOfFirstFreeNodo;
                list->list[list->indexOfFirstFreeNodo].next = aux1;
                list->indexOfFirstFreeNodo = aux;

                break;
            }
        }
    }
}

void printList(LISTA_ENCADEADA_ESTATICA *list) {
    int i;
    for(i=list->indexOfFirstElement; 1; i = list->list[i].next) {
        printf("%i...", list->list[i].value);
        if(list->list[i].next == -1) {
            break;
        }
    }
    printf("\n\n");
}

int main() {
    int i;
    LISTA_ENCADEADA_ESTATICA list;
    createList(&list);

    for(i=0; i<10; i++) {
        int value, position;

        printf("Value: ");
        scanf("%i", &value);
        printf("Position: ");
        scanf("%i", &position);
        insertElement(&list, value, position);

        printList(&list);
    }
}