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

void retirarElementoDaMatriz(MATRIZ_ESPARSA *matriz, int posicaoNoVetor);
void inserirElemento(MATRIZ_ESPARSA *matriz, int elemento, int linha, int coluna);

int main() {
    int i, linha, coluna;
    MATRIZ_ESPARSA matriz;

    criarMatriz(&matriz, 3, 4);

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
    int i;

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->quantidade = 0;

    matriz->elementos = NULL;
    matriz->indices = (int **) malloc(sizeof(int*) * 2);
    for(i=0; i<2; i++) {
        matriz->indices[i] = NULL;
    }
}

void atribuirElementoNaMatriz(MATRIZ_ESPARSA *matriz, int elemento, int linha, int coluna) {
    int i, pertence = 0, posicaoNoVetor = -1;

    if(linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("\n\nO Indice informado ultrapassa as dimensões da matriz\n\n");
        return;
    }

    for(i=0; i<matriz->quantidade; i++) {
        if((linha == matriz->indices[0][i]) && (coluna == matriz->indices[1][i])) {
            pertence = 1;
            posicaoNoVetor = i;
            break;
        }
    }

    if(pertence) {
        if(elemento) {
            matriz->elementos[posicaoNoVetor] = elemento;
        } else {
            retirarElementoDaMatriz(matriz, posicaoNoVetor);
        }
    } else {
        if(elemento) {
            inserirElemento(matriz, elemento, linha, coluna);
        }
    }
    return;
}

void inserirElemento(MATRIZ_ESPARSA *matriz, int elemento, int linha, int coluna) {
    int i;

    // Tentativa de alocar espaço para o elemento a ser adicionado e seus indices
    matriz->elementos = (int *) realloc(matriz->elementos, (matriz->quantidade + 1) * sizeof(int));
    if(!matriz->elementos) {
        printf("\n\nNão foi possível alocar mais espaço para o elemento da sua matriz\n\n");
        return;
    }
    for(i=0; i < 2; i++) {
        matriz->indices[i] = (int *) realloc(matriz->indices[i], (matriz->quantidade + 1) * sizeof(int));
        if(!matriz->indices[i]) {
            printf("\n\nNão foi possível alocar mais espaço para o elemento da sua matriz\n\n");
            return;
        }
    }

    // Só continua se realmente houver conseguido alocar espaço
    matriz->elementos[matriz->quantidade] = elemento;

    matriz->indices[0][matriz->quantidade] = linha;
    matriz->indices[1][matriz->quantidade] = coluna;

    matriz->quantidade += 1;
}

void retirarElementoDaMatriz(MATRIZ_ESPARSA *matriz, int posicaoNoVetor) {
    int i;
    matriz->quantidade -= 1;

    if(posicaoNoVetor != matriz->quantidade) {
        matriz->elementos[posicaoNoVetor] = matriz->elementos[matriz->quantidade];
        matriz->indices[0][posicaoNoVetor] = matriz->indices[0][matriz->quantidade];
        matriz->indices[1][posicaoNoVetor] = matriz->indices[1][matriz->quantidade];
    }

    // desalocar memória para matriz de indices e para o vetor elementos
    matriz->elementos = (int *) realloc(matriz->elementos, (matriz->quantidade) * sizeof(int));
    for(i=0; i < 2; i++) {
        matriz->indices[i] = (int *) realloc(matriz->indices[i], (matriz->quantidade) * sizeof(int));
    }
}

int consultaDeElementoDaMatriz(MATRIZ_ESPARSA *matriz, int linha, int coluna) {
    int j;
    
    if(linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("\n\nO Indice informado ultrapassa as dimensões da matriz\n\n");
        exit(1);
    }
        
    for(j=0; j < matriz->quantidade; j++) {
        if(matriz->indices[0][j] == linha && matriz->indices[1][j] == coluna) {
            return matriz->elementos[j];
        }
    }
    return 0;
}
