#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;
typedef NODO *ORDERED_CHAINED_LIST;

void createList(ORDERED_CHAINED_LIST *list);
int isEmpty(ORDERED_CHAINED_LIST list);
int lengthOfList(ORDERED_CHAINED_LIST list);
void insertElement(ORDERED_CHAINED_LIST *list, int value);
int returnElementWithRecursion(ORDERED_CHAINED_LIST list, int position);
void deleteElement(ORDERED_CHAINED_LIST *list, int position);
void printList(ORDERED_CHAINED_LIST *list);
int deleteElementByValue(ORDERED_CHAINED_LIST *list, int value);
int deleteAllElementsByValue(ORDERED_CHAINED_LIST *list, int value);

// Why isn't it a pointer to the list?
void destroyList(ORDERED_CHAINED_LIST list);

int main() {
    int number;
    ORDERED_CHAINED_LIST list;
    createList(&list);
    printf("%s\n", deleteAllElementsByValue(&list, 14) ? "Deu certo deletar": "Não deu certo deletar");

    insertElement(&list, 7);
    insertElement(&list, 7);
    insertElement(&list, 7);
    insertElement(&list, 7);
    insertElement(&list, 7);
    insertElement(&list, 7);
    insertElement(&list, 7);
    insertElement(&list, 7);
    printList(&list);

    for(int i=0;i<3;i++) {
        scanf("%i", &number);
        printf("%s\n", deleteAllElementsByValue(&list, number) ? "Deu certo deletar": "Não deu certo deletar");
        printList(&list);
    }

    ORDERED_CHAINED_LIST list1;
    createList(&list1);
    printf("%s\n", deleteAllElementsByValue(&list1, 3) ? "Deu certo deletar": "Não deu certo deletar");

    insertElement(&list1, 1);
    insertElement(&list1, 1);
    insertElement(&list1, 1);
    insertElement(&list1, 1);
    insertElement(&list1, 5);
    insertElement(&list1, 6);
    insertElement(&list1, 7);
    printList(&list1);

    for(int i=0;i<3;i++) {
        scanf("%i", &number);
        printf("%s\n", deleteAllElementsByValue(&list1, number) ? "Deu certo deletar": "Não deu certo deletar");
        printList(&list1);
    }

    ORDERED_CHAINED_LIST list2;
    createList(&list2);
    printf("%s\n", deleteAllElementsByValue(&list2, 8) ? "Deu certo deletar": "Não deu certo deletar");

    insertElement(&list2, 10);
    insertElement(&list2, 10);
    insertElement(&list2, 10);
    insertElement(&list2, 7);
    insertElement(&list2, 6);
    insertElement(&list2, 5);
    insertElement(&list2, 4);
    printList(&list2);

    for(int i=0;i<3;i++) {
        scanf("%i", &number);
        printf("%s\n", deleteAllElementsByValue(&list2, number) ? "Deu certo deletar": "Não deu certo deletar");
        printList(&list2);
    }
}

void createList(ORDERED_CHAINED_LIST *list) {
    (*list) = NULL;
}

int isEmpty(ORDERED_CHAINED_LIST list) {
    return list == NULL;
}

int lengthOfList(ORDERED_CHAINED_LIST list) {
    int i = 0;
    while(list) {
        i++;
        list = list->next;
    }
    return i;
}

void insertElement(ORDERED_CHAINED_LIST *list, int value) {
    NODO *alocado;
    alocado = (NODO *)malloc(sizeof(NODO));
    if(alocado == NULL) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    
    if(isEmpty(*list)) {
        alocado->value = value;
        alocado->next = NULL;
        (*list) = alocado;
    } else {
        while(*list && (*list)->value < value) {
            list = &((*list)->next);
        }
        alocado->value = value;
        alocado->next = (*list);
        (*list) = alocado;
    }
}

int deleteElementByValue(ORDERED_CHAINED_LIST *list, int value) {
    NODO *aux;
    if(isEmpty(*list)) {
        return 0;
    }
    while(*list && (*list)->value != value) {
        list = &((*list)->next);
    }
    if(*list == NULL) {
        return 0;
    }
    aux = (*list)->next;
    free(*list);
    (*list) = aux;

    return 1;
}

int deleteAllElementsByValue(ORDERED_CHAINED_LIST *list, int value) {
    NODO *aux;
    int counter = 0;

    if(isEmpty(*list)) {
        return 0;
    }
    for(;*list && (*list)->value <= value;) {
        
        if((*list)->value == value) {
            aux = (*list)->next;
            free(*list);
            (*list) = aux;

            counter++;
        } else {
            list = &((*list)->next);
        }
    }
    if(counter) {
        return 1;
    } else {
        return 0;
    }
}

void destroyList(ORDERED_CHAINED_LIST list) {
    NODO *aux;
    while (list) {
        aux = list;
        list = list->next;
        free(aux);
    }
}

void deleteElement(ORDERED_CHAINED_LIST *list, int position) {
    NODO *aux;

    if(position < 1 || position > lengthOfList((*list))) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    if(position == 1) {
        aux = (*list);
        (*list) = (*list)->next;
        free(aux);
    } else {
        NODO *aux2;
        int i=2;
        for(aux = (*list); position > i; aux = aux->next) {
            i++;
        }
        aux2 = aux->next;
        aux->next = (aux->next)->next;
        free(aux2);
    }
}


void printList(ORDERED_CHAINED_LIST *list) {
    NODO *aux;

    for(aux = (*list); aux != NULL; aux = aux->next) {
        printf("%i...", aux->value);
    }
    printf("\n");
}


int returnElementWithRecursion(ORDERED_CHAINED_LIST list, int position) {
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    if(position == 1) {
        return (*list).value;
    } else {
        returnElementWithRecursion(list->next, position - 1);
    }
}

