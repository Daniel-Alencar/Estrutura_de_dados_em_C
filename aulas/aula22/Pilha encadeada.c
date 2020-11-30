#include<stdio.h>
#include<stdlib.h>
#include"./Pilha encadeada.h"

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