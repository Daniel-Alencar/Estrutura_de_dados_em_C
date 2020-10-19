#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;

typedef NODO *DYNAMIC_CHAINED_LIST;
// Guardará o endereço de memória do primeiro nodo da lista

void createList(DYNAMIC_CHAINED_LIST *list);
int isEmpty(DYNAMIC_CHAINED_LIST list);
void printList(DYNAMIC_CHAINED_LIST *list);


int belongToList(DYNAMIC_CHAINED_LIST list, int value);
int belongToListWithRecursion(DYNAMIC_CHAINED_LIST list, int value);
void insertElement(DYNAMIC_CHAINED_LIST *list, int position, int value);
void insertElementWithRecursion(DYNAMIC_CHAINED_LIST *list, int position, int value);

int returnElementWithRecursion(DYNAMIC_CHAINED_LIST list, int position);

void deleteElement(DYNAMIC_CHAINED_LIST *list, int position);
void deleteElementWithRecursion(DYNAMIC_CHAINED_LIST *list, int position);

void brokeList(DYNAMIC_CHAINED_LIST list);
void brokeListWithRecursion(DYNAMIC_CHAINED_LIST list);

int lengthOfList(DYNAMIC_CHAINED_LIST list);
int lengthOfListWithRecursion(DYNAMIC_CHAINED_LIST list);

int main() {
    int i;int position;
    DYNAMIC_CHAINED_LIST list;
    createList(&list);
    insertElementWithRecursion(&list, 1, 20);
    printf("Tamanho: %i\n\n", lengthOfListWithRecursion(list));

    insertElementWithRecursion(&list, 1, 10);
    printf("Tamanho: %i\n\n", lengthOfListWithRecursion(list));

    insertElementWithRecursion(&list, 1, 5);
    printf("Tamanho: %i\n\n", lengthOfListWithRecursion(list));

    insertElementWithRecursion(&list, 1, 2);
    printf("Tamanho: %i\n\n", lengthOfListWithRecursion(list));

    insertElement(&list, 0, 20);
    insertElement(&list, 0, 10);
    insertElement(&list, 0, 5);
    insertElement(&list, 0, 2);
    printf("Tamanho: %i\n\n", lengthOfListWithRecursion(list));
    
    deleteElementWithRecursion(&list, 2);
    printf("Tamanho: %i\n\n", lengthOfListWithRecursion(list));

    printList(&list);
    printf("\n%i\n%i\n%i\n\n", belongToList(list, 1), belongToList(list, 3), belongToList(list, 11));
}

void createList(DYNAMIC_CHAINED_LIST *list) {
    (*list) = NULL;
}

int isEmpty(DYNAMIC_CHAINED_LIST list) {
    return list == NULL;
}

int lengthOfList(DYNAMIC_CHAINED_LIST list) {
    int length;
    for(length = 0; list != NULL; length++) {
        list = list->next;
    }
    return length;
}

void insertElement(DYNAMIC_CHAINED_LIST *list, int position, int value) {
    NODO *alocado;

    if(position < 0 || position > lengthOfList(*list)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    alocado = (NODO *) malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n\n");
        exit(2);
    }

    alocado->value = value;
    if(!position) {
        alocado->next = (*list);
        (*list) = alocado;
    } else {
        NODO *aux;
        int i=1;

        for(aux = (*list); position > i; aux = aux->next) {
            i++;
        }
        alocado->next = aux->next;
        aux->next = alocado;
    }
}

void printList(DYNAMIC_CHAINED_LIST *list) {
    NODO *aux;

    for(aux = (*list); aux != NULL; aux = aux->next) {
        printf("%i...", aux->value);
    }
    printf("\n");
}

void insertElementWithRecursion(DYNAMIC_CHAINED_LIST *list, int position, int value) {
    if(position < 1 || position > (lengthOfList((*list)) + 1)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    if(position == 1) {
        NODO *alocado;

        alocado = (NODO *) malloc(sizeof(NODO));
        if(!alocado) {
            printf("\nUnfortunately, there is not store enough in list\n\n");
            exit(2);
        }
        alocado->value = value;
        alocado->next = (*list);
        
        (*list) = alocado;
    } else {
        insertElementWithRecursion(&((*list)->next), position - 1, value);
    }
}

int returnElementWithRecursion(DYNAMIC_CHAINED_LIST list, int position) {
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

void deleteElementWithRecursion(DYNAMIC_CHAINED_LIST *list, int position) {
    if(position < 1 || position > lengthOfList((*list))) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    if(position == 1) {
        NODO *aux = (*list);
        (*list) = (*list)->next;
        free(aux);
    } else {
        deleteElementWithRecursion(&((*list)->next), position - 1);
    }
}

void deleteElement(DYNAMIC_CHAINED_LIST *list, int position) {
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

void brokeListWithRecursion(DYNAMIC_CHAINED_LIST list) {
    if(!list) {
        brokeListWithRecursion(list->next);
        free(list);
    }
}

void brokeList(DYNAMIC_CHAINED_LIST list) {
    NODO *aux;
    while (list)
    {
        aux = list;
        list = list->next;
        free(aux);
    }
}

int lengthOfListWithRecursion(DYNAMIC_CHAINED_LIST list) {
    int counter = 0;
    if(!list) {
        return counter;
    } else {
        counter = lengthOfListWithRecursion(list->next);
        counter++;
        return counter;
    }
}

int belongToList(DYNAMIC_CHAINED_LIST list, int value) {
    int i;
    int length = lengthOfList(list);
    for(i=0; i<length; i++, list = list->next) {
        if(list->value == value) {
            return 1;
        }
    }
    return 0;
}

int belongToList(DYNAMIC_CHAINED_LIST list, int value) {
    int i;
    int length = lengthOfList(list);
    for(i=0; i<length; i++, list = list->next) {
        if(list->value == value) {
            return 1;
        }
    }
    return 0;
}