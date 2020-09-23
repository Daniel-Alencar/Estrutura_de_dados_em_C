#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int linhas;
    int colunas;
    int *elementos;
}DIAGONAL_MATRIX;

void criarDiagonalMatrix(int linhas, int colunas, DIAGONAL_MATRIX *matriz);
void inicializarDiagonalMatrix(DIAGONAL_MATRIX *matriz);
void imprimirDiagonalMatrix(DIAGONAL_MATRIX *matriz);
int consultarElementoDaDiagonalMatrix(int linha, int coluna, DIAGONAL_MATRIX *matriz);

int main() {
    int i, linha, coluna;
    DIAGONAL_MATRIX matriz;

    criarDiagonalMatrix(5, 5, &matriz);
    inicializarDiagonalMatrix(&matriz);
    imprimirDiagonalMatrix(&matriz);

    for(i=0; i<10; i++) {
        int valor;

        printf("Índice i da matriz: ");
        scanf("%i", &linha);
        printf("Índice j da matriz: ");
        scanf("%i", &coluna);
        valor = consultarElementoDaDiagonalMatrix(linha, coluna, &matriz);

        printf("Valor da posição escolhida: %i\n\n", valor);
    }
}

void criarDiagonalMatrix(int linhas, int colunas, DIAGONAL_MATRIX *matriz) {
    if(linhas == colunas) {
        matriz->elementos = (int *) calloc(linhas * colunas, sizeof(int));
        if(!matriz->elementos) {
            printf("Não foi possível alocar espaço para a matriz diagonal\n");
            exit(0);
        }
        matriz->colunas = colunas;
        matriz->linhas = linhas;
    } else {
        printf("É preciso que seja o mesmo número de linhas e de colunas\n");
    }
}

void inicializarDiagonalMatrix(DIAGONAL_MATRIX *matriz) {
    int i;
    for(i=0; i<matriz->linhas; i++) {
        printf("matriz[%i][%i]: ", i+1, i+1);
        scanf("%i", matriz->elementos + i);
    }
}

void imprimirDiagonalMatrix(DIAGONAL_MATRIX *matriz) {
    int i, j;

    for(i=0; i<matriz->linhas; i++) {
        printf("| ");
        for(j=0; j<matriz->colunas; j++) {
            if(i != j) {
                printf("%03i ", 0);
            } else {
                printf("%03i ", matriz->elementos[i]);
            }
        }
        printf("|\n");
    }
}

int consultarElementoDaDiagonalMatrix(int linha, int coluna, DIAGONAL_MATRIX *matriz) {

    if(linha != coluna) {
        return 0;
    } else {
        return (matriz->elementos[linha - 1]);
    }
}