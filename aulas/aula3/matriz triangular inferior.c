#include<stdio.h>
#include<stdlib.h>

typedef struct{
    unsigned int ordem;
    int *elementos;
}MATRIZ_TRIANGULAR_INFERIOR;

void criarMatriz(int ordem, MATRIZ_TRIANGULAR_INFERIOR *matriz);
void inicializarMatriz(MATRIZ_TRIANGULAR_INFERIOR *matriz);
void imprimirMatriz(MATRIZ_TRIANGULAR_INFERIOR *matriz);
int consultaDeElementoDaMatriz(int linha, int coluna, MATRIZ_TRIANGULAR_INFERIOR *matriz);
int conversaoParaIndice(int linha, int coluna);

int main() {
    MATRIZ_TRIANGULAR_INFERIOR matriz;
    int linha, coluna, i;

    criarMatriz(4, &matriz);
    inicializarMatriz(&matriz);
    imprimirMatriz(&matriz);

    for(i=0; i < 10; i++) {
        printf("Linha da matriz: ");
        scanf("%i", &linha);
        printf("Coluna da matriz: ");
        scanf("%i", &coluna);

        printf("matriz[%i][%i]: %i\n\n\n", linha, coluna, consultaDeElementoDaMatriz(linha, coluna, &matriz));
    }
}

void criarMatriz(int ordem, MATRIZ_TRIANGULAR_INFERIOR *matriz)  {
    int quantidadeDeTermos = ((1 + ordem) * ordem)/2;

    matriz->elementos = (int *)calloc(quantidadeDeTermos, sizeof(int));
    if(!matriz->elementos) {
        printf("Não foi possível alocar memória");
        exit(1);
    }
    matriz->ordem = ordem;
}

void inicializarMatriz(MATRIZ_TRIANGULAR_INFERIOR *matriz) {
    int i,j;

    for(i=0; i < matriz->ordem; i++) {
        for(j=0; j < matriz->ordem; j++) {
            if(i >= j) {
                printf("Matriz[%i][%i]: ", i, j);
                scanf("%i", &matriz->elementos[conversaoParaIndice(i, j)]);
            }
        }
    }
}

void imprimirMatriz(MATRIZ_TRIANGULAR_INFERIOR *matriz) {
    int i,j;

    for(i=0; i < matriz->ordem; i++) {
        printf("| ");

        for(j=0; j < matriz->ordem; j++) {
            printf("%05i ", consultaDeElementoDaMatriz(i, j, matriz));
        }
        printf("|\n");
    }
}

int consultaDeElementoDaMatriz(int linha, int coluna, MATRIZ_TRIANGULAR_INFERIOR *matriz) {

    if(linha >= coluna) {
        return matriz->elementos[conversaoParaIndice(linha, coluna)];
    } else {
        return 0;
    } 
    
}

int conversaoParaIndice(int linha, int coluna) {
    int indice;
    indice = (coluna + (((1 + (linha - 1)) * (linha - 1)) / 2)) - 1;
    return indice;
}