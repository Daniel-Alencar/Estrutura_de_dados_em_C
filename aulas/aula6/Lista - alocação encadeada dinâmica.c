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
int lengthOfList(DYNAMIC_CHAINED_LIST list);
void insertElement(DYNAMIC_CHAINED_LIST *list, int position, int value);
void returnElement(DYNAMIC_CHAINED_LIST list, int position);
void deleteElement(DYNAMIC_CHAINED_LIST *list, int position);
void brokeList(DYNAMIC_CHAINED_LIST *list);
void printList(DYNAMIC_CHAINED_LIST *list);

int main() {
    int i;
    DYNAMIC_CHAINED_LIST list;
    createList(&list);
    
    for(i=0; i<10; i++) {
        int value, position;

        printf("Value: ");
        scanf("%i", &value);
        printf("Position: ");
        scanf("%i", &position);
        insertElement(&list, position, value);

        printList(&list);
    }
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
    NODO *aux;
    NODO *Alocado;

    if(position < 0 || position > lengthOfList(*list)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    Alocado = (NODO *) malloc(sizeof(NODO));
    if(Alocado == NULL) {
        printf("\nUnfortunately, there is not store enough in list\n\n");
        exit(2);
    }

    if(!position) {
        aux = (*list);
        (*list) = Alocado;

        (*list)->value = value;
        (*list)->next = aux;
    } else {
        int i=1;
        for(aux = (*list); position > i; aux = (*list)->next) {
            i++;
        }
        Alocado->value = value;
        Alocado->next = aux->next;

        aux->next = Alocado;
    }
}

void printList(DYNAMIC_CHAINED_LIST *list) {
    NODO *aux;

    for(aux = (*list); aux != NULL; aux = aux->next) {
        printf("%i...", aux->value);
    }
    printf("\n");
}