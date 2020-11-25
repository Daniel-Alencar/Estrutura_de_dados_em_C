#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;

typedef NODO *DYNAMIC_CHAINED_LIST;


void createList(DYNAMIC_CHAINED_LIST *list);
int isEmpty(DYNAMIC_CHAINED_LIST list);
void printList(DYNAMIC_CHAINED_LIST *list);
void sortByDistribution(DYNAMIC_CHAINED_LIST *list);



int isOrdered(DYNAMIC_CHAINED_LIST list);
int isOrderedWithRecursion(DYNAMIC_CHAINED_LIST list);

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

int generateList(DYNAMIC_CHAINED_LIST *list, int firstElement, int lastElement);
int generateListWithRecursion(DYNAMIC_CHAINED_LIST *list, int firstElement, int lastElement);

int main() {
    int number, position;
    char option;
    DYNAMIC_CHAINED_LIST list;
    createList(&list);
    insertElement(&list, 0, 1923);
    insertElement(&list, 1, 1314);
    insertElement(&list, 2, 4567);
    insertElement(&list, 3, 2719);
    insertElement(&list, 4, 2718);
    insertElement(&list, 5, 1312);

    printList(&list);
    sortByDistribution(&list);
    printList(&list);
    // printf("Lista criada!!!\n");
    
    // printf("Deseja Adicionar[Y/n]? ");
    // scanf(" %c", &option);

    // if(option == 'Y' || option == 'y') {
    //     do {
    //         printf("Valor para adicionar: ");
    //         scanf("%i", &number);
    //         printf("Posição que quer colocar: ");
    //         scanf("%i", &position);
    //         insertElementWithRecursion(&list, position, number);

    //         printf("Deseja continuar adicionando[Y/n]? ");
    //         setbuf(stdin, NULL);
    //         scanf(" %c", &option);

    //     } while(option == 'Y' || option == 'y');
    // }

    // printf("Deseja remover[Y/n]? ");
    // setbuf(stdin, NULL);
    // scanf(" %c", &option);
    
    // if(option == 'Y' || option == 'y') {
    //     do {
    //         printf("Posição que quer remover: ");
    //         scanf("%i", &position);
    //         deleteElementWithRecursion(&list, position);

    //         printf("Deseja continuar removendo[Y/n]? ");
    //         setbuf(stdin, NULL);
    //         scanf(" %c", &option);

    //     } while(option == 'Y' || option == 'y');
    // }

    // printf("Deseja consultar um elemento[Y/n]? ");
    // setbuf(stdin, NULL);
    // scanf(" %c", &option);

    // if(option == 'Y' || option == 'y') {
    //     do {
    //         printf("Posição que quer consultar: ");
    //         scanf("%i", &position);
    //         printf("Position of your element: %03i\n", returnElementWithRecursion(list, position));

    //         printf("Deseja continuar consultando[Y/n]? ");
    //         setbuf(stdin, NULL);
    //         scanf(" %c", &option);

    //     } while(option == 'Y' || option == 'y');
    // }
    // printf("Aqui está a sua lista!!!\n");
    // printList(&list);
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
    while(list) {
        if(list->value == value) {
            return 1;
        }
        list = list->next;
    }
    return 0;
}

int belongToListWithRecursion(DYNAMIC_CHAINED_LIST list, int value) {
    if(!list) {
        return 0;
    }
    if(list->value == value) {
        return 1;
    }
    return belongToListWithRecursion(list->next, value);
}

int isOrdered(DYNAMIC_CHAINED_LIST list) {
    while(list && list->next) {
        if(list->value > (list->next)->value) {
            return 0;
        }
        list = list->next;
    }
    return 1;
}

int isOrderedWithRecursion(DYNAMIC_CHAINED_LIST list) {
    if(list && list->next) {
        if(list->value > (list->next)->value)
            return 0;
        return isOrderedWithRecursion(list->next);
    } else {
        return 1;
    }
}

int generateList(DYNAMIC_CHAINED_LIST *list, int firstElement, int lastElement) {
    if(firstElement > lastElement) {
        printf("\nError! Invalid range\n\n");
        return 0;
    }
    createList(list);
    while(lastElement >= firstElement) {
        insertElementWithRecursion(list, 1, lastElement);
        lastElement--;
    }
    return 1;
}

int generateListWithRecursion(DYNAMIC_CHAINED_LIST *list, int firstElement, int lastElement) {
    if(firstElement > lastElement) {
        printf("\nError! Invalid range\n\n");
        return 0;
    } else {
        if(firstElement == lastElement) {
            createList(list);
            insertElementWithRecursion(list, 1, firstElement);
        } else {
            generateListWithRecursion(list, firstElement + 1, lastElement);
            insertElementWithRecursion(list, 1, firstElement);
        }
    }
    return 1;
}


void sortByDistribution(DYNAMIC_CHAINED_LIST *list) {
    int i,j,acumulate, base = 10, digitos = 4;
    DYNAMIC_CHAINED_LIST * lists = (DYNAMIC_CHAINED_LIST *) malloc(sizeof(DYNAMIC_CHAINED_LIST) * base);
    for(i=0;i<base;i++) {
        createList(lists + i);
    }

    for(acumulate = 1; digitos; acumulate *= 10, digitos--) {
        for(i=0; lengthOfListWithRecursion(list); i++) {
            int index, value = returnElementWithRecursion(*list, 1);
            deleteElement(list, 1);

            index = (value / acumulate) % 10;
            insertElement((lists + index), i, value);
        }
        j=0;
        for(i=0;i<base;i++) {
            for(; lengthOfListWithRecursion(*(lists + i)); j++) {
                insertElement(list, j, returnElementWithRecursion(*(lists + i), 1));
                deleteElement(lists + i, 1);
            }
        }
    }
    // free(lists);
}