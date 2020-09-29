#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int *elementos;
    int **indices;

    int linhas, colunas;
    int quantidade;
}MATRIZ_ESPARSA;

void criarMatriz(MATRIZ_ESPARSA *matriz, int linhas, int colunas);
void atribuirElementoNaMatriz(MATRIZ_ESPARSA *matriz, int elemento, int linha, int coluna);
int consultaDeElementoDaMatriz(MATRIZ_ESPARSA *matriz, int linha, int coluna);

int main() {

}

void criarMatriz(MATRIZ_ESPARSA *matriz, int linhas, int colunas) {
    int i, linhasDosIndices = 2;

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->quantidade = 0;

    matriz->elementos = NULL;
    matriz->indices = (int **)malloc(sizeof(int*) * linhasDosIndices);
    for(i=0; i<linhasDosIndices; i++) {
        matriz->indices[i] = NULL;
    }
}

void atribuirElementoNaMatriz(MATRIZ_ESPARSA *matriz, int elemento, int linha, int coluna) {
    int i, linhasDosIndices = 2;

    matriz->elementos = (int *) realloc(matriz->elementos, (matriz->quantidade + 1) * sizeof(int));
    if(!matriz->elementos) {
        printf("Não foi possível alocar mais espaço para o elemento da sua matriz");
        exit(1);
    }
    for(i=0; i<linhasDosIndices; i++) {
        matriz->indices[i] = (int) realloc(matriz->indices[i], (matriz->quantidade + 1) * sizeof(int));
        if(!matriz->indices[i]) {
            printf("Não foi possível alocar mais espaço para o elemento da sua matriz");
            exit(1);
        }
    }
    matriz->elementos[matriz->quantidade] = elemento;

    matriz->indices[0][matriz->quantidade] = linha;
    matriz->indices[1][matriz->quantidade] = coluna;

    matriz->quantidade += 1;
}

int consultaDeElementoDaMatriz(MATRIZ_ESPARSA *matriz, int linha, int coluna) {
    int j;
    
    if(linha <= 0 || linha > matriz->linhas || coluna <= 0 || coluna > matriz->colunas) {
        printf("O índice informado ultrapassa as dimensões da matriz");
        exit(2);
    } else {
        
        for(j=0; j < matriz->quantidade; j++) {
            if(matriz->indices[0][j] == linha) {
                if(matriz->indices[1][j] == coluna) {
                    return matriz->elementos[j];
                }
            }
        }
        return 0;
    }
}