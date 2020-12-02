#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../aula22/Pilha encadeada.h"
int resultOfPostFixedExpression(char *expression);

int main() {
    printf("%d", resultOfPostFixedExpression("35+"));
}

int resultOfPostFixedExpression(char *expression) {
    int i, j, length = strlen(expression), value;
    LINKED_STACK pilha;
    createStack(&pilha);
    for(i=0; i<length; i++) {
        if(48 <= (int) expression[i] <= 57) {
            pushOfStack(&pilha, (int) expression[i] - 48);
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
                value = (topAndPopOfStack(&pilha) / topAndPopOfStack(&pilha));
                pushOfStack(&pilha, value);
                break;
            default:
                break;
            }
        }
    }
    return topOfStack(pilha);
}