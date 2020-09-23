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

    criarMatriz(4, &matriz);
    inicializarMatriz(&matriz);
    imprimirMatriz(&matriz);

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
                scanf(" %c", &matriz->elementos[conversaoParaIndice(i, j)]);
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

int conversaoParaIndice(int linha, int coluna) {
    int indice;
    indice = (coluna + (((1 + (linha - 1)) * (linha - 1)) / 2)) - 1;
    return indice;
}