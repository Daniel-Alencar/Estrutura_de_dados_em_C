#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"./Aplicação para pilhas.h"
#define MAXIMUM_EXPRESSION 100

int main() {
    char expressaoInfixada[MAXIMUM_EXPRESSION];
    char expressaoPosFixada[MAXIMUM_EXPRESSION];
    scanf("%[^\n]", expressaoInfixada);
    
    convertInOrderExpressionWithParenthesesToPostFixed(expressaoInfixada, expressaoPosFixada);
    printf("%s = %s = %d%c", expressaoInfixada, expressaoPosFixada, postFixedExpression(expressaoPosFixada), '\n');
    return 0;
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
            int value2 = topAndPopOfStack(&pilha), value1 = topAndPopOfStack(&pilha);
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

void convertInOrderExpressionToPostFixed(char *inOrder, char *posFixed) {
    int i, j;
    LINKED_STACK operadores;
    createStack(&operadores);

    j = 0;
    for (i = 0; inOrder[i] != '\0'; i++) {
        if(isOperating(inOrder[i])) {
            posFixed[j] = inOrder[i];
            j++;
        } else {
            if(stackIsEmpty(operadores)) {
                pushOfStack(&operadores, (int)inOrder[i]);
            } else {
                while(checkPrecedence((char) topOfStack(operadores), inOrder[i])) {
                    posFixed[j] = (char) topAndPopOfStack(&operadores);
                    j++;
                    if(stackIsEmpty(operadores))
                        break;
                }
                pushOfStack(&operadores, (int)inOrder[i]);
            }
        }
    }
    while(!stackIsEmpty(operadores)) {
        posFixed[j] = (char) topAndPopOfStack(&operadores);
        j++;
    }
    posFixed[j] = '\0';
}

void convertInOrderExpressionWithParenthesesToPostFixed(char *inOrder, char *posFixed) {
    int i, j;
    LINKED_STACK operadores;
    createStack(&operadores);

    j = 0;
    for (i = 0; inOrder[i] != '\0'; i++) {
        if(isOperating(inOrder[i])) {
            posFixed[j] = inOrder[i];
            j++;
        } else {
            if(inOrder[i] == ')') {
                while((char)topOfStack(operadores) != '(') {
                    posFixed[j++] = (char) topAndPopOfStack(&operadores);
                }
                popOfStack(&operadores);
            } else {
                if(stackIsEmpty(operadores) || inOrder[i] == '(') {
                    pushOfStack(&operadores, (int)inOrder[i]);
                } else {
                    while(checkPrecedence((char) topOfStack(operadores), inOrder[i])) {
                        posFixed[j] = (char) topAndPopOfStack(&operadores);
                        j++;
                        if(stackIsEmpty(operadores))
                            break;
                    }
                    pushOfStack(&operadores, (int)inOrder[i]);
                }
            }
        }
    }
    while(!stackIsEmpty(operadores)) {
        posFixed[j] = (char) topAndPopOfStack(&operadores);
        j++;
    }
    posFixed[j] = '\0';
}