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
int postFixedExpression(char *expression);
int isOperating(char character);
int performOperation(int operating1, char operator, int operating2);
int checkPrecedence(char operator1, char operator2);
void convertInOrderExpressionToPostFixed(char *inOrder, char *posFixed);
void convertInOrderExpressionWithParenthesesToPostFixed(char *inOrder, char *posFixed);