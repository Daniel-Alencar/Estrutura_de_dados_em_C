#include"./Árvore binária.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
    // BINARY_TREE tree;
    // makeTree(&tree, 15);
    // insertElement(&tree, 10);
    // insertElement(&tree, 30);
    // insertElement(&tree, 5);
    // insertElement(&tree, 11);
    // insertElement(&tree, 12);
    // insertElement(&tree, 20);
    // insertElement(&tree, 40);
    
    // preOrdem(tree);
    // printf("\n");
    // inOrdem(tree);
    // printf("\n");
    // posOrdem(tree);
    // printf("\n\n");

    // remocaoPorFusao(&tree);
    // preOrdem(tree);
    // printf("\n");
    // inOrdem(tree);
    // printf("\n");
    // posOrdem(tree);
    // printf("\n");
    int i,j;
    int vetor1[] = {5,1,9,8,7,0,3,4,5};
    int vetor2[] = {9,8,7,6,5,4,3,2,1,0};
    bubbleSort(vetor2, 10);
    for(i = 0; i < 10; i++)
        printf("%d...",vetor2[i]);
    printf("\n\n");
}

void makeTree(BINARY_TREE *tree, int value) {
    *tree = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(*tree)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    (*tree)->value = value;
    (*tree)->left = (*tree)->father = (*tree)->right = NULL;
}

void setLeft(BINARY_TREE tree, int value) {
    tree->left = (BINARY_TREE) malloc (sizeof (NODE));
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
    tree->right = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(tree->right)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    tree->right->value = value;
    tree->right->right = NULL;
    tree->right->left = NULL;
    tree->right->father = tree;
}

int valueOfNode(BINARY_TREE tree) {
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
    NODE *q = father(tree);
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

void percursoEmLargura(BINARY_TREE tree) {

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

void bubbleSort(int *vetor, int length) {
    int i, j;
    for(j = 0; j < (length - 1); j++)
        for(i = 0; i < (length - 1); i++) {
            if(vetor[i] > vetor[i+1]) {
                int aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
}