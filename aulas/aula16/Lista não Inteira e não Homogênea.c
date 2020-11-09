#include<stdio.h>
#include<stdlib.h>
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
void insertElement(HETEROGENEOUS_LIST *list, int position, int type, union values value);
int lengthOfList(HETEROGENEOUS_LIST list);

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

}

void insertElement(HETEROGENEOUS_LIST *list, int position, int type, union values value) {
    NODO *alocado;
    if(position < 1 || position > (lengthOfList(*list) + 1)) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    alocado = (NODO *)malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n\n");
        exit(2);
    }

    if(type == INTGR) {
    
    } else if(type == FLT) {

    } else if(type == STRING) {

    } else {
        printf("Error! Type not recognized");
    } 
}