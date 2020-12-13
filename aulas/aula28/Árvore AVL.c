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

    AVL_TREE tree2;
    makeTree(&tree2, 8);
    setLeft(tree2, 2);
    setRight(tree2, 12);

    setLeft(tree2->right, 9);
    setRight(tree2->right, 21);

    setLeft(tree2->right->right, 18);

    inOrdem(tree2);
    printf("\n\n");
    rotateToLeft(&tree2);
    inOrdem(tree2);
    printf("\n\n");
}

void makeTree(AVL_TREE *tree, int value) {
    *tree = (AVL_TREE) malloc (sizeof (NODE));
    if (!(*tree)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    (*tree)->value = value;
    (*tree)->left = (*tree)->right = (*tree)->father = NULL;
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
    tree->left->father = tree;

    tree->left->heightOfLeft = tree->left->heightOfRight = 0;
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
    tree->right->father = tree;

    tree->right->heightOfLeft = tree->right->heightOfRight = 0;
    tree->heightOfRight = 1;
}





int valueOfNode(AVL_TREE tree) {
    return tree->value;
}

AVL_TREE left(AVL_TREE tree) {
    return tree->left;
}

AVL_TREE right(AVL_TREE tree) {
    return tree->right;
}

AVL_TREE father(AVL_TREE tree) {
    return tree->father;
}

AVL_TREE brother(AVL_TREE tree) {
    if (father(tree))
        if (isLeft(tree))
            return right(father(tree));
        else
            return left(father(tree));
    return NULL;
}

int isLeft(AVL_TREE tree) {
    NODE *q = father(tree);
    if (!q)
        return (0);
    if (left(q) == tree)
        return (1);
    return (0);
}

int isRight(AVL_TREE tree) {
    if (father(tree))
        return (!isLeft(tree));
    return (0);
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
    (*tree)->left = aux->right;
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

void rotateToLeft(AVL_TREE *tree) {

    // Realizando as alterações
    NODE *aux = (*tree)->right;
    (*tree)->right = aux->left;
    aux->left = (*tree);

    // Mudando valores para o nó com o FB inválido
    if((*tree)->right) {
        if((*tree)->right->heightOfLeft > (*tree)->right->heightOfRight) {
            (*tree)->heightOfRight = (*tree)->right->heightOfLeft + 1;
        } else {
            (*tree)->heightOfRight = (*tree)->right->heightOfRight + 1;
        }
    } else {
        (*tree)->heightOfRight = 0;
    }

    // Mudando valores para o filho do nó com o FB inválido
    if((*tree)->heightOfLeft > (*tree)->heightOfRight) {
        aux->heightOfLeft = (*tree)->heightOfLeft + 1;
    } else {
        aux->heightOfLeft = (*tree)->heightOfRight + 1;
    }
    (*tree) = aux;
}

void balanceamento(AVL_TREE *tree) {
    int FB_do_no = ((*tree)->heightOfRight - (*tree)->heightOfLeft);
    int FB_do_filho;

    if(FB_do_no == 2) {
        FB_do_filho = ((*tree)->right->heightOfRight - (*tree)->right->heightOfLeft);

        if(FB_do_filho >= 0) {
            // classe 1
            // +2 e (+1 ou 0)(direito)
            rotateToLeft(tree);
        } else {
            // classe 2
            // +2 e -1 (direito)
            rotateToRight(&((*tree)->right));
            rotateToLeft(tree);
        }
    } else {
        if(FB_do_no == -2) {
            FB_do_filho = ((*tree)->left->heightOfRight - (*tree)->left->heightOfLeft);
            if(FB_do_filho <= 0) {
                // classe 1
                // -2 e (-1 ou 0)(direito)
                rotateToRight(tree);
            } else {
                // classe 2
                // -2 e +1 (direito)
                rotateToLeft(&((*tree)->left));
                rotateToRight(tree);
            }
        }
    }
}

void insertElement(AVL_TREE *tree, int value) {
    if(!(*tree)) {
        makeTree(tree, value);
    } else {
        AVL_TREE father = (*tree);
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
    // setar novos valores para as alturas


    // depois de encontrado o nó errado
    balanceamento(tree);
}

void setAlturas(AVL_TREE tree) {

}