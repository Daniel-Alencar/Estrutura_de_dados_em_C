#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int linhas;
    int colunas;
    int **elementos;
} MATRIZ;

void criar_matriz(int linhas, int colunas, MATRIZ *matriz) {
    int i,j;

    matriz->elementos = (int **) malloc(sizeof(int *) * linhas);
    if(!matriz->elementos) {
        printf("Não foi possível alocar memória\n");
        exit(1);
    }

    for(i=0; i < matriz->linhas; i++) {
        matriz->elementos[i] = (int *) malloc(sizeof(int) * colunas);
        if(!(matriz->elementos[i])) {
            printf("Não foi possível alocar memória\n");
            exit(2);
        }
    }
    matriz->colunas = colunas;
    matriz->linhas = linhas;

    for(i=0; i<linhas; i++) {
        for(j=0; j<colunas; j++) {
            matriz->elementos[i][j] = 0;
        }
    }
}

void imprimir_matriz(MATRIZ *matriz) {
    int i,j;

    for(i=0; i<matriz->linhas; i++) {
        printf("\n|");
        for(j=0; j<matriz->colunas; j++) {
            printf("%5i", matriz->elementos[i][j]);
        }
        printf("|");
    }
}

int main() {
    MATRIZ matriz;

    criar_matriz(2, 2, &matriz);
    imprimir_matriz(&matriz);
}