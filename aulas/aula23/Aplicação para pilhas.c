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
int postFixedExpression(char *expression);
int isOperating(char character);
int performOperation(int operating1, char operator, int operating2);
int checkPrecedence(char operator1, char operator2);

int main() {
    char posFixed[20] = "85+3-";
    int i, j, position = 0;

    printf("%s = %d%c", posFixed, postFixedExpression(posFixed), '\n');
    strcpy(posFixed, "871+*93-*2*");
    printf("%s = %d%c", posFixed, postFixedExpression(posFixed), '\n');

    char operators[] = "^/*-+";
    int length = strlen(operators);
    for (i=0; i < length; i++) {
        for(j=0; j < length; j++) {
            printf("%c e %c => %d%c", operators[i], operators[j], checkPrecedence(operators[i], operators[j]), '\n');
        }
    }
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
        printf("\n dasdaThe stack is empty\n");
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

int postFixedExpression(char *expression) {
    int i, length = strlen(expression);
    LINKED_STACK pilha;
    createStack(&pilha);
    for(i=0; i<length; i++) {
        if(isOperating(expression[i])) {
            pushOfStack(&pilha, (int)expression[i] - '0');
        } else {
            int value1 = topAndPopOfStack(&pilha), value2 = topAndPopOfStack(&pilha);
            pushOfStack(&pilha, performOperation(value1, expression[i], value2));
        }
    }
    return topAndPopOfStack(&pilha);
}

int isOperating(char character) {
    if('0' <= character && character <= '9')
        return 1;
    return 0;
}

int performOperation(int operating1, char operator, int operating2) {
    switch (operator) {
        case '+': return operating1 + operating2;
            break;
        case '-': return operating1 - operating2;
            break;
        case '*': return operating1 * operating2;
            break;
        case '^': return ((int) pow(operating1, operating2));
            break;
        case '/':    
            if(operating2 == 0) {
                printf("Invalid arithmetic expression\n");
                exit(1);
            }
            return operating1 / operating2;
            break;
        default:
            printf("Invalid arithmetic expression\n");
            exit(1);
            break;
    }
}

int checkPrecedence(char operator1, char operator2) {
    if(((operator1 == '+') || (operator1 == '-')) && 
        ((operator2 == '+') || (operator2 == '-')))
        return 1;
    if(((operator1 == '*') || (operator1 == '/')) && 
        ((operator2 == '*') || (operator2 == '/') || (operator2 == '+') || (operator2 == '-')))
        return 1;
    if((operator1 == '^') && 
        ((operator2 == '^') || (operator2 == '*') || (operator2 == '/') || (operator2 == '+') || (operator2 == '-')))
        return 1;
    return 0;
}