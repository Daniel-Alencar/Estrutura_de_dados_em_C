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
        int valor;

        printf("Linha da matriz: ");
        scanf("%i", &linha);
        printf("Coluna da matriz: ");
        scanf("%i", &coluna);

        valor = consultaDeElementoDaMatriz(linha, coluna, &matriz);
        printf("Valor da posição escolhida: %i\n\n", valor);
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
                printf("Matriz[%i][%i]: ", i+1, j+1);
                scanf("%i", &matriz->elementos[conversaoParaIndice(i+1, j+1)]);
            }
        }
    }
}

void imprimirMatriz(MATRIZ_TRIANGULAR_INFERIOR *matriz) {
    int i,j;

    for(i=0; i < matriz->ordem; i++) {
        printf("| ");

        for(j=0; j < matriz->ordem; j++) {
            printf("%05i ", consultaDeElementoDaMatriz(i+1, j+1, matriz));
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

int conversaoParaIndice(int linha, int coluna) { // linha e coluna na visão do usuário
    return (((1 + (linha - 1)) * (linha - 1) / 2) + coluna - 1);
}
