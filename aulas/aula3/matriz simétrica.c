#include<stdio.h>
#include<stdlib.h>

typedef struct{
    unsigned int ordem;
    char *elementos;
}MATRIZ_SIMETRICA;

void criarMatriz(int ordem, MATRIZ_SIMETRICA *matriz);
void inicializarMatriz(MATRIZ_SIMETRICA *matriz);
void imprimirMatriz(MATRIZ_SIMETRICA *matriz);
char consultaDeElementoDaMatriz(int linha, int coluna, MATRIZ_SIMETRICA *matriz);
int conversaoParaIndice(int linha, int coluna);

int main() {
    MATRIZ_SIMETRICA matriz;
    int linha, coluna, i;

    criarMatriz(4, &matriz);
    inicializarMatriz(&matriz);
    imprimirMatriz(&matriz);

    for(i=0; i < 10; i++) {
        char valor;

        printf("Linha da matriz: ");
        scanf("%i", &linha);
        printf("Coluna da matriz: ");
        scanf("%i", &coluna);

        valor = consultaDeElementoDaMatriz(linha, coluna, &matriz);
        printf("Valor da posição escolhida: %c\n\n", valor);
    }
}

void criarMatriz(int ordem, MATRIZ_SIMETRICA *matriz)  {
    int quantidadeDeTermos = ((1 + ordem) * ordem)/2;

    matriz->elementos = (char *)malloc(quantidadeDeTermos * sizeof(char));
    if(!matriz->elementos) {
        printf("Não foi possível alocar memória");
        exit(1);
    }
    matriz->ordem = ordem;
}

void inicializarMatriz(MATRIZ_SIMETRICA *matriz) {
    int i,j;

    for(i=0; i < matriz->ordem; i++) {
        for(j=0; j < matriz->ordem; j++) {
            if(i >= j) {
                printf("Matriz[%i][%i]: ", i+1, j+1);
                scanf(" %c", &matriz->elementos[conversaoParaIndice(i+1, j+1)]);
            }
        }
    }
}

void imprimirMatriz(MATRIZ_SIMETRICA *matriz) {
    int i,j;

    for(i=0; i < matriz->ordem; i++) {
        printf("| ");

        for(j=0; j < matriz->ordem; j++) {
            printf("%c ", consultaDeElementoDaMatriz(i+1, j+1, matriz));
        }
        printf("|\n");
    }
}

char consultaDeElementoDaMatriz(int linha, int coluna, MATRIZ_SIMETRICA *matriz) {

    if(linha >= coluna) {
        return matriz->elementos[conversaoParaIndice(linha, coluna)];
    } else {
        return matriz->elementos[conversaoParaIndice(coluna, linha)];
    } 
}

int conversaoParaIndice(int linha, int coluna) { // linha e coluna na visão do usuário
    return (((1 + (linha - 1)) * (linha - 1) / 2) + coluna - 1);
}
