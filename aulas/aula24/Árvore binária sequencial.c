#include<string.h>
#include<stdio.h>
#define MAXIMUM_NODES 100
typedef struct {
    int value;
    int left;
    int father;
    int right;
}NODE;
typedef struct {
    int root;
    int freeNode;
    NODE nodes[MAXIMUM_NODES];
}SEQUENTIAL_BINARY_TREE;

void maketree(SEQUENTIAL_BINARY_TREE *tree, int value);
int getFreeNode(SEQUENTIAL_BINARY_TREE *tree);
void liberateNode(SEQUENTIAL_BINARY_TREE *tree, int position);
void setLeft(SEQUENTIAL_BINARY_TREE *tree, int position, int value);
void setRight(SEQUENTIAL_BINARY_TREE *tree, int father, int value);
int valueOfNode(SEQUENTIAL_BINARY_TREE *tree, int position);
int left(SEQUENTIAL_BINARY_TREE *tree, int position);
int right(SEQUENTIAL_BINARY_TREE *tree, int position);
int father(SEQUENTIAL_BINARY_TREE *tree, int position);
int brother(SEQUENTIAL_BINARY_TREE *tree, int position);
int isLeft(SEQUENTIAL_BINARY_TREE *tree, int position);
int isRight(SEQUENTIAL_BINARY_TREE *tree, int position);

int main()  {

}

void maketree(SEQUENTIAL_BINARY_TREE *tree, int value) {
    int i, index;
    for(i=0;i<(MAXIMUM_NODES - 1);i++) {
        (*tree).nodes[i].left = i + 1;
    }
    (*tree).nodes[i].left = -1;
    (*tree).freeNode = 0;

    index = getFreeNode(tree);
    if(index != -1) {
        (*tree).nodes[0].father = -1;
        (*tree).nodes[0].right = -1;
        (*tree).nodes[0].left = -1;
        (*tree).nodes[0].value = value;
        (*tree).root = index;
    } else {
        printf("Not is possible to built this tree\n");
        exit(1);
    }
    
}

int getFreeNode(SEQUENTIAL_BINARY_TREE *tree) {
    if(tree->freeNode != -1) {
        int index = tree->freeNode;
        tree->freeNode = tree->nodes[tree->freeNode].left; 
        return index;   
    } else 
        return -1;
}

void liberateNode(SEQUENTIAL_BINARY_TREE *tree, int position) {
    tree->nodes[position].left = tree->freeNode;
    tree->freeNode = position;
}

void setLeft(SEQUENTIAL_BINARY_TREE *tree, int father, int value) {
    int child = getFreeNode(tree);
    if(child != -1) {
        tree->nodes[father].left = child;

        tree->nodes[child].father = father;
        tree->nodes[child].left = -1;
        tree->nodes[child].right = -1;
        tree->nodes[child].value = value;
    } else {
        printf("There is not storage enough\n");
        exit(2);
    }
}

void setRight(SEQUENTIAL_BINARY_TREE *tree, int father, int value) {
    int child = getFreeNode(tree);
    if(child != -1) {
        tree->nodes[father].right = child;

        tree->nodes[child].father = father;
        tree->nodes[child].left = -1;
        tree->nodes[child].right = -1;
        tree->nodes[child].value = value;
    } else {
        printf("There is not storage enough\n");
        exit(2);
    }
}

int valueOfNode(SEQUENTIAL_BINARY_TREE *tree, int position) {
    return tree->nodes[position].value;
}

int left(SEQUENTIAL_BINARY_TREE *tree, int position) {
    return tree->nodes[position].left;
}

int right(SEQUENTIAL_BINARY_TREE *tree, int position) {
    return tree->nodes[position].right;
}

int father(SEQUENTIAL_BINARY_TREE *tree, int position) {
    return tree->nodes[position].father;
}

int brother(SEQUENTIAL_BINARY_TREE *tree, int position) {
    if(father(tree, position) != -1) {
        if(isLeft(tree, position)) {
            return right(tree, father(tree, position));
        } else {
            return tree->nodes[tree->nodes[position].father].left;
        }
    } else {
        return -1;
    }
}

int isLeft(SEQUENTIAL_BINARY_TREE *tree, int position) {
    
}