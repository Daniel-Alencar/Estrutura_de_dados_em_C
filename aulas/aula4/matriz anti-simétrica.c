#include<stdio.h>
#include<stdlib.h>

typedef struct{
    unsigned int ordem;
    float *elementos;
}MATRIZ_ANTISIMETRICA;

void criarMatriz(int ordem, MATRIZ_ANTISIMETRICA *matriz);
void inicializarMatriz(MATRIZ_ANTISIMETRICA *matriz);
void imprimirMatriz(MATRIZ_ANTISIMETRICA *matriz);
float consultaDeElementoDaMatriz(int linha, int coluna, MATRIZ_ANTISIMETRICA *matriz);
int conversaoParaIndice(int linha, int coluna);

int main() {
    MATRIZ_ANTISIMETRICA matriz;
    int linha, coluna, i;

    criarMatriz(4, &matriz);
    inicializarMatriz(&matriz);
    imprimirMatriz(&matriz);

    for(i=0; i < 10; i++) {
        float valor;

        printf("Linha da matriz: ");
        scanf("%i", &linha);
        printf("Coluna da matriz: ");
        scanf("%i", &coluna);

        valor = consultaDeElementoDaMatriz(linha, coluna, &matriz);
        printf("Valor da posição escolhida: %f\n\n", valor);
    }
}

void criarMatriz(int ordem, MATRIZ_ANTISIMETRICA *matriz)  {
    int quantidadeDeTermos = ((1 + ordem) * ordem)/2;

    matriz->elementos = (float *)malloc(quantidadeDeTermos * sizeof(float));
    if(!matriz->elementos) {
        printf("Não foi possível alocar memória");
        exit(1);
    }
    matriz->ordem = ordem;
}

void inicializarMatriz(MATRIZ_ANTISIMETRICA *matriz) {
    int i,j;

    for(i=0; i < matriz->ordem; i++) {
        for(j=0; j < matriz->ordem; j++) {
            if(i >= j) {
                printf("Matriz[%i][%i]: ", i+1, j+1);
                scanf("%f", &matriz->elementos[conversaoParaIndice(i+1, j+1)]);
            }
        }
    }
}

void imprimirMatriz(MATRIZ_ANTISIMETRICA *matriz) {
    int i,j;

    for(i=0; i < matriz->ordem; i++) {
        printf("| ");

        for(j=0; j < matriz->ordem; j++) {
            printf("%12f ", consultaDeElementoDaMatriz(i+1, j+1, matriz));
        }
        printf("|\n");
    }
}

float consultaDeElementoDaMatriz(int linha, int coluna, MATRIZ_ANTISIMETRICA *matriz) {

    if(linha >= coluna) {
        return matriz->elementos[conversaoParaIndice(linha, coluna)];
    } else {
        return (0 - matriz->elementos[conversaoParaIndice(coluna, linha)]);
    } 
}

int conversaoParaIndice(int linha, int coluna) { // linha e coluna na visão do usuário
    return (((1 + (linha - 1)) * (linha - 1) / 2) + coluna - 1);
}
