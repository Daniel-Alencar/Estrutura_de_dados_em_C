typedef struct node {
    int value;
    struct node * next;
}NODE;
typedef NODE *LINKED_STACK;
void createStack(LINKED_STACK *stack);
int stackIsEmpty(LINKED_STACK stack);
void pushOfStack(LINKED_STACK *stack, int value); 
int topOfStack(LINKED_STACK stack);
void popOfStack(LINKED_STACK *stack);
int topAndPopOfStack(LINKED_STACK *stack);
void destroyStack(LINKED_STACK stack);