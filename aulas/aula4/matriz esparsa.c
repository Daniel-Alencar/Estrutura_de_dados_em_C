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
    int i, linha, coluna;
    MATRIZ_ESPARSA matriz;

    criarMatriz(&matriz, 3, 4);
    atribuirElementoNaMatriz(&matriz, -14, 1, 1);
    atribuirElementoNaMatriz(&matriz, 55, 0, 3);
    atribuirElementoNaMatriz(&matriz, 2, 2, 0);

    for(i=0; i<10; i++) {
        int valor;

        printf("Linha da matriz: ");
        scanf("%i", &linha);
        printf("Coluna da matriz: ");
        scanf("%i", &coluna);

        valor = consultaDeElementoDaMatriz(&matriz, linha, coluna);
        printf("\nElemento: %i\n\n", valor);
    }
}

void criarMatriz(MATRIZ_ESPARSA *matriz, int linhas, int colunas) {
    int i, linhasDosIndices = 2;

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->quantidade = 0;

    matriz->elementos = NULL;
    matriz->indices = (int **) malloc(sizeof(int*) * linhasDosIndices);
    for(i=0; i<linhasDosIndices; i++) {
        matriz->indices[i] = NULL;
    }
}

void atribuirElementoNaMatriz(MATRIZ_ESPARSA *matriz, int elemento, int linha, int coluna) {
    int i;

    if(linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("\n\nO Indice informado ultrapassa as dimensões da matriz\n\n");
        exit(2);
    }
    
    matriz->elementos = (int *) realloc(matriz->elementos, (matriz->quantidade + 1) * sizeof(int));
    if(!matriz->elementos) {
        printf("\n\nNão foi possível alocar mais espaço para o elemento da sua matriz\n\n");
        exit(1);
    }
    for(i=0; i < 2; i++) {
        matriz->indices[i] = (int*) realloc(matriz->indices[i], (matriz->quantidade + 1) * sizeof(int));
        if(!matriz->indices[i]) {
            printf("\n\nNão foi possível alocar mais espaço para o elemento da sua matriz\n\n");
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
    
    if(linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("\n\nO Indice informado ultrapassa as dimensões da matriz\n\n");
        exit(2);
        
    for(j=0; j < matriz->quantidade; j++) {
        if(matriz->indices[0][j] == linha && matriz->indices[1][j] == coluna) {
            return matriz->elementos[j];
        }
    }
    return 0;
}
