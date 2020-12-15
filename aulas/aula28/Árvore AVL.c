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
    insertElement(&tree, 3);

    inOrdem(tree);
    printf("\n\n");
}

void makeTree(AVL_TREE *tree, int value) {
    *tree = (AVL_TREE)malloc(sizeof(NODE));
    if ((*tree) == NULL) {
        printf("Erro! Nao existe memoria disponivel!");
        exit(1);
    }
    (*tree)->value = value;
    (*tree)->left = (*tree)->right = NULL;
    (*tree)->heightOfLeft = (*tree)->heightOfRight = 0;
}

void setLeft(AVL_TREE tree, int value) {
    tree->left = (AVL_TREE)malloc(sizeof(NODE));
    if ((tree->left) == NULL) {
        printf("Erro! Nao existe memoria disponivel!");
        exit(1);
    }
    tree->left->value = value;
    tree->left->left = NULL;
    tree->left->right = NULL;
    tree->left->heightOfLeft = tree->left->heightOfRight = 0;
}

void setRight(AVL_TREE tree, int value) {
    tree->right = (AVL_TREE)malloc(sizeof(NODE));
    if ((tree->right) == NULL) {
        printf("Erro! Nao existe memoria disponivel!");
        exit(1);
    }
    tree->right->value = value;
    tree->right->right = NULL;
    tree->right->left = NULL;
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
    if((*tree) == NULL) {
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
        setNewAlturas(tree, &father);
    }
}

void setNewAlturas(AVL_TREE *raiz, AVL_TREE *noInserido) {
    AVL_TREE root = (*raiz);
    AVL_TREE father = (*noInserido);
    int FB;

    if(father->value < root->value) {
        root = root->left;
        setNewAlturas(&root, noInserido);
    } else if(father->value > root->value) {
        root = root->right;
        setNewAlturas(&root, noInserido);
    }
        
    if(root->right == NULL && root->left == NULL) {
        root->heightOfLeft = root->heightOfRight = 0;
    } else {
        if(root->right) {
            if(root->right->heightOfRight > root->right->heightOfLeft) {
                root->heightOfRight = root->right->heightOfRight + 1;
            } else {
                root->heightOfRight = root->right->heightOfLeft + 1;
            }
        }
        if(root->left) {
            if(root->left->heightOfRight > root->left->heightOfLeft) {
                root->heightOfLeft = root->left->heightOfRight + 1;
            } else {
                root->heightOfLeft = root->left->heightOfLeft + 1;
            }
        }
    }

    FB = root->heightOfRight - root->heightOfLeft;
    if(FB == 2 || FB == -2) {
        balanceamento(&root);
        return;
    }
}