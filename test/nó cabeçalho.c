#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;

typedef struct informacoes {
    int length;
    char message[100];
}INFORMACOES;
typedef struct cabecalho {
    INFORMACOES informacoes;
    NODO *next;
}CABECALHO;

typedef CABECALHO *LIST_WITH_HEADER;