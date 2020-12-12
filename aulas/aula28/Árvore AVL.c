#include<stdio.h>
#include<stdlib.h>
#include"Árvore AVL.h"

int main() {
    AVL_TREE tree;
    makeTree(&tree, 8);
    setLeft(tree, 4);
    setRight(tree, 10);

    setLeft(tree->left, 2);
    setRight(tree->left, 6);

    setRight(tree->left->left, 3);

    inOrdem(tree);
    printf("\n\n");
    rotateToRight(&tree);
    inOrdem(tree);
    printf("\n\n");
}

void makeTree(AVL_TREE *tree, int value) {
    *tree = (AVL_TREE) malloc (sizeof (NODE));
    if (!(*tree)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    (*tree)->value = value;
    (*tree)->left = (*tree)->right = NULL;
    (*tree)->heightOfLeft = (*tree)->heightOfRight = 0;
}

void setLeft(AVL_TREE tree, int value) {
    tree->left = (AVL_TREE) malloc (sizeof (NODE));
    if (!(tree->left)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    tree->left->value = value;
    tree->left->left = NULL;
    tree->left->right = NULL;
    tree->heightOfLeft = 1;
}

void setRight(AVL_TREE tree, int value) {
    tree->right = (AVL_TREE) malloc (sizeof (NODE));
    if (!(tree->right)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    tree->right->value = value;
    tree->right->right = NULL;
    tree->right->left = NULL;
    tree->heightOfRight = 1;
}





int valueOfNode(AVL_TREE tree) {
    if(tree == NULL) {
        printf("\nThe tree is empty!\n\n");
        exit(2);
    }
    return tree->value;
}

AVL_TREE left(AVL_TREE tree) {
    return tree->left;
}

AVL_TREE right(AVL_TREE tree) {
    return tree->right;
}

int heightOfRight(AVL_TREE tree) {
    return tree->heightOfRight;
}

int heightOfLeft(AVL_TREE tree) {
    return tree->heightOfLeft;
}






void preOrdem(AVL_TREE tree) {
    if(tree) {
        printf("%d...", valueOfNode(tree));
        preOrdem(left(tree));
        preOrdem(right(tree));
    }
}

void inOrdem(AVL_TREE tree) {
    if(tree) {
        inOrdem(left(tree));
        printf("%d...", valueOfNode(tree));
        inOrdem(right(tree));
    }
}

void posOrdem(AVL_TREE tree) {
    if(tree) {
        posOrdem(left(tree));
        posOrdem(right(tree));
        printf("%d...", valueOfNode(tree));
    }
}

void rotateToRight(AVL_TREE *tree) {

    // Realizando as alterações
    NODE *aux = (*tree)->left;
    if(aux->right) {
        (*tree)->left = aux->right;
    } else {
        (*tree)->left = NULL;
    }
    aux->right = (*tree);

    // Mudando valores para o nó com o FB inválido
    if((*tree)->left) {
        if((*tree)->left->heightOfLeft > (*tree)->left->heightOfRight) {
            (*tree)->heightOfLeft = (*tree)->left->heightOfLeft + 1;
        } else {
            (*tree)->heightOfLeft = (*tree)->left->heightOfRight + 1;
        }
    } else {
        (*tree)->heightOfLeft = 0;
    }

    // Mudando valores para o filho do nó com o FB inválido
    if((*tree)->heightOfLeft > (*tree)->heightOfRight) {
        aux->heightOfRight = (*tree)->heightOfLeft + 1;
    } else {
        aux->heightOfRight = (*tree)->heightOfRight + 1;
    }

    (*tree) = aux;
}
