#define TRUE 1
typedef struct nodo {
    struct nodo *left;
    struct nodo *right;
    struct nodo *father;
    int value;
}NODO;
typedef NODO *BINARY_TREE_BUSCA;

void makeTree(BINARY_TREE_BUSCA *tree, int value);
void setLeft(BINARY_TREE_BUSCA tree, int value);
void setRight(BINARY_TREE_BUSCA tree, int value);
int valueOfNodo(BINARY_TREE_BUSCA tree);
BINARY_TREE_BUSCA left(BINARY_TREE_BUSCA tree);
BINARY_TREE_BUSCA right(BINARY_TREE_BUSCA tree);
BINARY_TREE_BUSCA father(BINARY_TREE_BUSCA tree);
BINARY_TREE_BUSCA brother(BINARY_TREE_BUSCA tree);
int isLeft(BINARY_TREE_BUSCA tree);
int isRight(BINARY_TREE_BUSCA tree);

void percursoEmLargura(BINARY_TREE_BUSCA tree);
void preOrdem(BINARY_TREE_BUSCA tree);
void inOrdem(BINARY_TREE_BUSCA tree);
void posOrdem(BINARY_TREE_BUSCA tree);

void insertElement(BINARY_TREE_BUSCA *tree, int value);
void remocaoPorFusao(BINARY_TREE_BUSCA *tree);
void remocaoPorCopia(BINARY_TREE_BUSCA *tree);

void percursoEmLarguraArmazenadoEmVetor(BINARY_TREE_BUSCA tree, int *vetor, int *length);
void bubbleSort(int *vetor, int length);
void balancearArvoreBinariaAux(BINARY_TREE_BUSCA *tree, int vetor[], int inicio, int final);
void balancearArvoreBinaria(BINARY_TREE_BUSCA *tree);
