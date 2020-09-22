#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int linhas;
    int colunas;
    int *elementos;
}MATRIZ;

void criar_matriz(int, int, MATRIZ *);
void zerar_matriz(MATRIZ *);
void imprimir_matriz(MATRIZ *);
void inicializar_matriz(MATRIZ *);
void somar_matrizes(MATRIZ *, MATRIZ *, MATRIZ *);
void subtrair_matrizes(MATRIZ *, MATRIZ *, MATRIZ *);
void multiplicar_matrizes(MATRIZ *, MATRIZ *, MATRIZ *);

int main() {
    MATRIZ m1, m2, m3;

    criar_matriz(2, 3, &m1);
    inicializar_matriz(&m1);
    imprimir_matriz(&m1);

    criar_matriz(3, 2, &m2);
    inicializar_matriz(&m2);
    imprimir_matriz(&m2);

    multiplicar_matrizes(&m1, &m2, &m3);
    imprimir_matriz(&m3);
}

void criar_matriz(int linhas, int colunas, MATRIZ *matriz) {
    matriz->elementos = (int *) malloc(sizeof(int) * linhas * colunas);
    if(!matriz->elementos) {
        printf("Não foi possível alocar memória\n");
        exit(1);
    }

    matriz->colunas = colunas;
    matriz->linhas = linhas;

    zerar_matriz(matriz);
}

void zerar_matriz(MATRIZ *matriz) {
    int i;
    int numberOfIndex = matriz->linhas * matriz->colunas;

    for(i=0; i < numberOfIndex; i++) {
        matriz->elementos[i] = 0;
    }
}

void inicializar_matriz(MATRIZ *matriz) {
    int i, j, numberOfIndex = 0;

    for(i=0; i < matriz->linhas; i++) {
        for(j=0; j < matriz->colunas; j++) {

            printf("matriz[%i][%i]: ", i, j);
            scanf("%i", &matriz->elementos[numberOfIndex]);
            numberOfIndex++;
        }
    }
}

void imprimir_matriz(MATRIZ *matriz) {
    int i;
    int numberOfIndex = matriz->linhas * matriz->colunas;

    for(i=0; i < numberOfIndex; i++) {

        if((i + 1) % matriz->colunas) {
            if(i % matriz->colunas == 0) {
                printf("|");
            }
            printf("%5i", matriz->elementos[i]);
        } else {
            printf("%5i|\n", matriz->elementos[i]);
        }
    }
}

void somar_matrizes(MATRIZ *matriz1, MATRIZ *matriz2, MATRIZ *matriz3) {
    int i;

    if((matriz1->linhas == matriz2->linhas) && (matriz1->colunas == matriz2->colunas)) {
        criar_matriz(matriz1->linhas, matriz1->colunas, matriz3);
        for(i=0; i < (matriz3->linhas * matriz3->colunas); i++)
            matriz3->elementos[i] = matriz1->elementos[i] + matriz2->elementos[i];
    } else {
        printf("Não é possível fazer a soma das matrizes\n");
    }
}

void subtrair_matrizes(MATRIZ *matriz1, MATRIZ *matriz2, MATRIZ *matriz3) {
    int i;

    if((matriz1->linhas == matriz2->linhas) && (matriz1->colunas == matriz2->colunas)) {
        criar_matriz(matriz1->linhas, matriz1->colunas, matriz3);
        for(i=0; i < (matriz3->linhas * matriz3->colunas); i++)
            matriz3->elementos[i] = matriz1->elementos[i] - matriz2->elementos[i];
    } else {
        printf("Não é possível fazer a subtração das matrizes\n");
    }
}

void multiplicar_matrizes(MATRIZ *matriz1, MATRIZ *matriz2, MATRIZ *matriz3) {
    int coluna1Atual = 0, linha1Atual = 0;
    int coluna2Atual = 0, linha2Atual = 0;
    int i;

    if(matriz1->colunas == matriz2->linhas) {
        criar_matriz(matriz1->linhas, matriz2->colunas, matriz3);

        i = 0;
        for(linha1Atual=0; linha1Atual < matriz1->linhas; linha1Atual++) {
            for(coluna2Atual=0; coluna2Atual < matriz2->colunas; coluna2Atual++) {
                for(coluna1Atual=0; coluna1Atual < matriz1->colunas; coluna1Atual++) {
                    *(matriz3->elementos + i) += (matriz1->elementos[coluna1Atual + (matriz1->colunas * linha1Atual)] * matriz2->elementos[(coluna1Atual * matriz2->colunas) + coluna2Atual]);
                }
                i++;
            }
        }

    } else {
        printf("Não é possível fazer a multiplicação");
    }

    matriz3->colunas = matriz1->linhas;
    matriz3->linhas = matriz2->colunas;
}