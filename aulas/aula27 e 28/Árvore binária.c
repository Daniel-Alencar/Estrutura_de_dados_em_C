#include"./Árvore binária.h"
#include"Fila encadeada.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
    BINARY_TREE tree;
}

void makeTree(BINARY_TREE *tree, int value) {
    *tree = (BINARY_TREE) malloc (sizeof (NODO));
    if (!(*tree)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    (*tree)->value = value;
    (*tree)->left = (*tree)->father = (*tree)->right = NULL;
}

void setLeft(BINARY_TREE tree, int value) {
    tree->left = (BINARY_TREE) malloc (sizeof (NODO));
    if (!(tree->left)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    tree->left->value = value;
    tree->left->left = NULL;
    tree->left->right = NULL;
    tree->left->father = tree;
}

void setRight(BINARY_TREE tree, int value) {
    tree->right = (BINARY_TREE) malloc (sizeof (NODO));
    if (!(tree->right)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    tree->right->value = value;
    tree->right->right = NULL;
    tree->right->left = NULL;
    tree->right->father = tree;
}

int valueOfNodo(BINARY_TREE tree) {
    if(tree == NULL) {
        printf("\nThe tree is empty!\n\n");
        exit(2);
    }
    return tree->value;
}

BINARY_TREE left(BINARY_TREE tree) {
    return tree->left;
}

BINARY_TREE right(BINARY_TREE tree) {
    return tree->right;
}

BINARY_TREE father(BINARY_TREE tree) {
    return tree->father;
}

BINARY_TREE brother(BINARY_TREE tree) {
    if (father(tree))
        if (isLeft(tree))
            return right(father(tree));
        else
            return left(father(tree));
    return NULL;
}

int isLeft(BINARY_TREE tree) {
    NODO *q = father(tree);
    if (!q)
        return (0);
    if (left(q) == tree)
        return (1);
    return (0);
}

int isRight(BINARY_TREE tree) {
    if (father(tree))
        return (!isLeft(tree));
    return (0);
}

void preOrdem(BINARY_TREE tree) {
    if(tree) {
        printf("%d...", tree->value);
        preOrdem(left(tree));
        preOrdem(right(tree));
    }
}

void inOrdem(BINARY_TREE tree) {
    if(tree) {
        inOrdem(left(tree));
        printf("%d...", tree->value);
        inOrdem(right(tree));
    }
}

void posOrdem(BINARY_TREE tree) {
    if(tree) {
        posOrdem(left(tree));
        posOrdem(right(tree));
        printf("%d...", tree->value);
    }
}

void insertElement(BINARY_TREE *tree, int value) {
    if(!(*tree)) {
        makeTree(tree, value);
    } else {
        BINARY_TREE father = (*tree);
        do {
            if(value < father->value) {
                if(father->left) {
                    father = father->left;
                } else {
                    setLeft(father, value);
                    break;
                }
            } else {
                if(father->right) {
                    father = father->right;
                } else {
                    setRight(father, value);
                    break; 
                }
            }
        } while(TRUE);
    }
}

void remocaoPorFusao(BINARY_TREE *tree) {
    if (*tree) {
        BINARY_TREE aux = *tree;
        if (!((*tree)->right))
            *tree = (*tree)->left;
        else
            if ((*tree)->left == NULL)
                *tree = (*tree)->right;
            else {
                aux = (*tree)->left;
                while (aux->right)
                    aux = aux->right;
                aux->right = (*tree)->right;
                aux->right->father= aux;
                aux = *tree;
                *tree = (*tree)->left;
            }
        free(aux);
    }
}

void remocaoPorCopia(BINARY_TREE *tree) {
    if (*tree) {
        BINARY_TREE aux = *tree;
        if((*tree)->right == NULL) {
            if((*tree)->left) {
                (*tree)->left->father = (*tree)->father;
            }
            *tree = (*tree)->left;
        } else
            if((*tree)->left == NULL) {
                (*tree)->right->father = (*tree)->father;
                *tree = (*tree)->right;
            } else {
                aux = (*tree)->right;
                while(aux->left)
                    aux = aux->left;

                (*tree)->value = aux->value;

                if (aux->father == *tree) {
                    aux->father->right = aux->right;
                    aux->father->right->father = aux->father;
                } else {
                    aux->father->left = aux->right;
                    aux->father->left->father = aux->father;
                }
            }
        free(aux);
    }
}

void percursoEmLargura(BINARY_TREE tree) {
    LINKED_LINE fila;
    createLine(&fila);

    if(tree) {
        insertElementIntoLine(fila, tree);
    }
    while(lineIsEmpty(fila) == 0) {
        printf("%d...", valueOfNodo(returnElementFromLine(fila)));

        if(left(returnElementFromLine(fila))) {
            insertElementIntoLine(fila, left(returnElementFromLine(fila)));
        }
        if(right(returnElementFromLine(fila))) {
            insertElementIntoLine(fila, right(returnElementFromLine(fila)));
        }
        deleteElementFromLine(fila);
    }
}

void percursoEmLarguraArmazenadoEmVetor(BINARY_TREE tree, int *vetor, int *length) {
    LINKED_LINE line;
    createLine(&line);

    if(tree) {
        insertElementIntoLine(line, tree);
        *length = 0;
        vetor = NULL;
    }
    while(lineIsEmpty(line) == 0) {
        vetor = (int *)realloc(vetor, (++(*length) * sizeof(int)));
        if(vetor == NULL) {
            printf("\nNão há espaço suficiente\n");
            exit(1);
        }
        BINARY_TREE aux = returnElementFromLine(line);
        vetor[(*length) - 1] = valueOfNodo(aux);
        
        if(left(aux)) {
            insertElementIntoLine(line, left(aux));
        }
        if(right(aux)) {
            insertElementIntoLine(line, right(aux));
        }
        deleteElementFromLine(line);
    }
}

void bubbleSort(int *vetor, int length) {
    int i, j;
    for(j = 0; j < (length - 1); j++) {
        for(i = 0; i < (length - 1); i++) {
            if(vetor[i] > vetor[i+1]) {
                int aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}

void balancearArvoreBinariaAux(BINARY_TREE *tree, int vetor[], int inicio, int final) {
    if(inicio <= final) {
        int meio = (inicio + final) / 2;
        insertElement(tree, vetor[meio]);
        balancearArvoreBinariaAux(tree, vetor, inicio, meio - 1);
        balancearArvoreBinariaAux(tree, vetor, meio + 1, final);
    }
}

void balancearArvoreBinaria(BINARY_TREE *tree) {
    int *vetor, length;
    percursoEmLarguraArmazenadoEmVetor(*tree, vetor, &length);
    bubbleSort(vetor, length);
    while(*tree) {
        remocaoPorCopia(tree);
    }
    balancearArvoreBinariaAux(tree, vetor, 0, length - 1);
    free(vetor);
}