
typedef struct node {
    struct node *left;
    struct node *right;
    struct node *father;
    int value;
}NODE;
typedef NODE *BINARY_TREE;

void makeTree(BINARY_TREE *tree, int value);
void setLeft(BINARY_TREE tree, int value);
void setRight(BINARY_TREE tree, int value);
int valueOfNode(BINARY_TREE tree);
BINARY_TREE left(BINARY_TREE tree);
BINARY_TREE right(BINARY_TREE tree);
BINARY_TREE father(BINARY_TREE tree);
BINARY_TREE brother(BINARY_TREE tree);
int isLeft(BINARY_TREE tree);
int isRight(BINARY_TREE tree);