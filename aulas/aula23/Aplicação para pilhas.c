#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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
int resultOfPostFixedExpression(char *expression);

int main() {
    char posFixed[20] = "85+3-";
    printf("%s = %d%c", posFixed, resultOfPostFixedExpression(posFixed), '\n');
    strcpy(posFixed, "871+*93-*2*");
    printf("%s = %d%c", posFixed, resultOfPostFixedExpression(posFixed), '\n');
}

void createStack(LINKED_STACK *stack) {
    *stack = NULL;
}

int stackIsEmpty(LINKED_STACK stack) {
    return !stack;
}

void pushOfStack(LINKED_STACK *stack, int value) {
    NODE *alocado = (NODE *)malloc(sizeof(NODE));
    if(!alocado) {
        printf("\nIt's impossible to push into stack\n");
        exit(1);
    }
    alocado->value = value;
    alocado->next = *stack;
    *stack = alocado;
}

int topOfStack(LINKED_STACK stack) {
    if(!stack) {
        printf("\nThe stack is empty\n");
        exit(2);
    }
    return stack->value;
}

void popOfStack(LINKED_STACK *stack) {
    if(!(*stack)) {
        printf("\nThe stack is empty\n");
        exit(2);
    } else {
        NODE *aux = *stack;
        (*stack) = (*stack)->next;
        free(aux);
    }
}

int topAndPopOfStack(LINKED_STACK *stack) {
    int value;
    if(!(*stack)) {
        printf("\nThe stack is empty\n");
        exit(2);
    } else {
        NODE *aux = *stack;
        (*stack) = (*stack)->next;
        value = aux->value;

        free(aux);
    }
    return value;
}

void destroyStack(LINKED_STACK stack) {
    NODE *aux = stack;
    while(aux) {
        stack = stack->next;
        free(aux);
        aux = stack;
    }
}

int resultOfPostFixedExpression(char *expression) {
    int i, length = strlen(expression), value;
    LINKED_STACK pilha;
    createStack(&pilha);
    for(i=0; i<length; i++) {
        if(48 <= (int)expression[i] && (int)expression[i] <= 57) {
            pushOfStack(&pilha, (int)expression[i] - 48);
        } else {
            switch (expression[i]) {
                case '+':
                    value = (topAndPopOfStack(&pilha) + topAndPopOfStack(&pilha));
                    pushOfStack(&pilha, value);
                    break;
                case '-':
                    value = (topAndPopOfStack(&pilha) - topAndPopOfStack(&pilha));
                    pushOfStack(&pilha, value);
                    break;
                case '*':
                    value = (topAndPopOfStack(&pilha) * topAndPopOfStack(&pilha));
                    pushOfStack(&pilha, value);
                    break;
                case '/':
                    value = topAndPopOfStack(&pilha);
                    if(!topOfStack(pilha)) {
                        printf("Invalid  arithmetic expression\n");
                        return 0;
                    }
                    value = value / topAndPopOfStack(&pilha);
                    pushOfStack(&pilha, value);
                    break;
                case '^':
                    value = (int) pow(topAndPopOfStack(&pilha), topAndPopOfStack(&pilha));
                    pushOfStack(&pilha, value);
                    break;
                default:
                    printf("Invalid  arithmetic expression\n");
                    return 0;
            }
        }
    }
    return topOfStack(pilha);
}