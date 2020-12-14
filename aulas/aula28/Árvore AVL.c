#include<stdio.h>
#include<stdlib.h>
#include"Árvore AVL.h"

int main() {
    AVL_TREE tree;
    insertElement(&tree, 8);
    insertElement(&tree, 4);
    insertElement(&tree, 10);
    insertElement(&tree, 2);
    insertElement(&tree, 6);
    printf("In-ordem: ");
    inOrdem(tree);
    printf("\n");

    insertElement(&tree, 3);
    printf("In-ordem: ");
    inOrdem(tree);
    printf("\n");
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

    printf("1\n");
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
            printf("2\n");
            FB_do_filho = ((*tree)->left->heightOfRight - (*tree)->left->heightOfLeft);
            if(FB_do_filho <= 0) {
                // classe 1
                // -2 e (-1 ou 0)(direito)
                printf("3\n");
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
                    father = father->left;
                    break;
                }
            } else {
                if(father->right) {
                    father = father->right;
                } else {
                    setRight(father, value);
                    father = father->right;
                    break; 
                }
            }
        } while(TRUE);

        // Recalcular valores das alturas das subárvores direita e esquerda para cada nó (partindo do valor que foi inserido até o nó raiz ou até encontrar um FB inválido(-2 ou +2))
        while(father != (*tree)) {
            int FB;
            if(isLeft(father)) {
                if(father->heightOfRight > father->heightOfLeft) {
                    father->father->heightOfLeft = father->heightOfRight + 1;
                } else {
                    father->father->heightOfLeft = father->heightOfLeft + 1;
                }
            }
            if(isRight(father)) {
                if(father->heightOfRight > father->heightOfLeft) {
                    father->father->heightOfRight = father->heightOfRight + 1;
                } else {
                    father->father->heightOfRight = father->heightOfLeft + 1;
                }
            }
            father = father->father;

            FB = father->heightOfRight - father->heightOfLeft;
            if(FB == 2 || FB == -2) {
                balanceamento(&father);
                break;
            }
        }
    }
}
