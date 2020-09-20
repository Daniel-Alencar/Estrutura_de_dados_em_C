#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int linhas;
    int colunas;
    int **elementos;
}MATRIZ;

void criar_matriz(int, int, MATRIZ *);
void imprimir_matriz(MATRIZ *);
void inicializar_matriz(MATRIZ *);
void somar_matrizes(MATRIZ *, MATRIZ *, MATRIZ *);
void subtrair_matrizes(MATRIZ *, MATRIZ *, MATRIZ *);
void multiplicacao_matrizes(MATRIZ *, MATRIZ *, MATRIZ *);

int main() {
    MATRIZ matriz, m1, m2;
    criar_matriz(2, 2, &m1);
}

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
    printf("\n\n");
}

void inicializar_matriz(MATRIZ *matriz) {
    int i,j;

    for(i=0; i<matriz->linhas; i++) {
        for(j=0; j<matriz->colunas; j++) {
            printf("matriz[%i][%i]: ", i+1, j+1);
            scanf("%i", &(matriz->elementos[i][j]));
        }
    }
}

void somar_matrizes(MATRIZ *matriz1, MATRIZ *matriz2, MATRIZ *matriz3) {
    int i,j;

    if((matriz1->linhas == matriz2->linhas) && (matriz1->colunas == matriz2->colunas)) {
        criar_matriz(matriz1->linhas, matriz1->colunas, matriz3);

        for(i=0; i<matriz1->linhas; i++) {
            for(j=0; j<matriz1->colunas; j++) {
                matriz3->elementos[i][j] = matriz1->elementos[i][j] + matriz2->elementos[i][j];
            }
        }
    } else {
        printf("Não pode haver a soma das matrizes\n");
    }
}

void subtrair_matrizes(MATRIZ *matriz1, MATRIZ *matriz2, MATRIZ *matriz3) {
    int i,j;

    if((matriz1->linhas == matriz2->linhas) && (matriz1->colunas == matriz2->colunas)) {
        criar_matriz(matriz1->linhas, matriz1->colunas, matriz3);

        for(i=0; i<matriz1->linhas; i++) {
            for(j=0; j<matriz1->colunas; j++) {
                matriz3->elementos[i][j] = matriz1->elementos[i][j] - matriz2->elementos[i][j];
            }
        }
    } else {
        printf("Não pode haver a subtração das matrizes\n");
    }
}

void multiplicacao_matrizes(MATRIZ *matriz1, MATRIZ *matriz2, MATRIZ *matriz3) {
    int i,j,z;

    if(matriz1->colunas == matriz2->linhas) {
        criar_matriz(matriz1->linhas, matriz2->colunas, matriz3);

        for(i=0; i<matriz3->linhas; i++) {
            for(j=0; j<matriz3->colunas; j++) {
                matriz3->elementos[i][j] = 0;

                for(z=0; z<matriz1->colunas; z++) {
                    matriz3->elementos[i][j] += matriz1->elementos[i][z] * matriz2->elementos[z][j];
                }
            }
        }
    } else {
        printf("Não pode haver a multiplicação de matrizes\n");
    }
}
