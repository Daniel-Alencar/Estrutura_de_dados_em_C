#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int ordem;
    int *elementos;
}MATRIZ_DIAGONAL;

void criarMatriz(int ordem, MATRIZ_DIAGONAL *matriz);
void inicializarMatriz(MATRIZ_DIAGONAL *matriz);
void imprimirMatriz(MATRIZ_DIAGONAL *matriz);
int consultaDeElementoDaMatriz(int linha, int coluna, MATRIZ_DIAGONAL *matriz);
int conversaoParaIndice(int linha, int coluna);

int main() {
    int i, linha, coluna;
    MATRIZ_DIAGONAL matriz;

    criarMatriz(5, &matriz);
    inicializarMatriz(&matriz);
    imprimirMatriz(&matriz);

    for(i=0; i<10; i++) {
        int valor;

        printf("Linha da matriz: ");
        scanf("%i", &linha);
        printf("Coluna da matriz: ");
        scanf("%i", &coluna);
        valor = consultaDeElementoDaMatriz(linha, coluna, &matriz);

        printf("Valor da posição escolhida: %i\n\n", valor);
    }
}

void criarMatriz(int ordem, MATRIZ_DIAGONAL *matriz) {

    matriz->elementos = (int *)calloc(ordem, sizeof(int));
    if(!matriz->elementos) {
        printf("Não foi possível alocar espaço para a matriz diagonal\n");
        exit(1);
    }
    matriz->ordem = ordem;
}
void inicializarMatriz(MATRIZ_DIAGONAL *matriz) {
    int i;
    for(i=0; i < matriz->ordem; i++) {
        printf("matriz[%i][%i]: ", i+1, i+1);
        scanf("%i", matriz->elementos + i);
    }
}
void imprimirMatriz(MATRIZ_DIAGONAL *matriz) {
    int i, j;

    for(i=0; i < matriz->ordem; i++) {
        printf("| ");
        for(j=0; j < matriz->ordem; j++) {
            printf("%03i ", consultaDeElementoDaMatriz(i+1, j+1, matriz));
        }
        printf("|\n");
    }
}
int consultaDeElementoDaMatriz(int linha, int coluna, MATRIZ_DIAGONAL *matriz) {
    if(linha != coluna) {
        return 0;
    } else {
        return (matriz->elementos[linha - 1]);
    }
}