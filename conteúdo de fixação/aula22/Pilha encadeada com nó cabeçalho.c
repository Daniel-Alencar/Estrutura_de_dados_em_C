#include"./Pilha encadeada com nó cabeçalho.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Hello world!\n");
}

void createStack(LINKED_STACK *stack) {
    (*stack) = (NODE *)malloc(sizeof(NODE));
    if(!(*stack)) {
        printf("\nThere is not storage enough\n");
        exit(1);
    }
    (*stack)->value = 0;
    (*stack)->next = NULL;
}

int stackIsEmpty(LINKED_STACK stack) {
    return stack->value == 0;
}

void pushOfStack(LINKED_STACK *stack, int value) {
    NODE *alocado = (NODE *)malloc(sizeof(NODE));
    if(!alocado) {
        printf("\nIt's impossible to push into stack\n");
        exit(1);
    }
    alocado->value = value;
    alocado->next = (*stack)->next;
    (*stack)->next = alocado;

    (*stack)->value++;
}

int topOfStack(LINKED_STACK stack) {
    if(!stack->next) {
        printf("\nThe stack is empty\n");
        exit(2);
    }
    return stack->next->value;
}

void popOfStack(LINKED_STACK *stack) {
    if(stackIsEmpty(*stack)) {
        printf("\nThe stack is empty\n");
        exit(2);
    } else {
        NODE *aux = (*stack)->next;
        (*stack)->next = (*stack)->next->next;
        free(aux);
    }
}

int topAndPopOfStack(LINKED_STACK *stack) {
    if(stackIsEmpty(*stack)) {
        printf("\nThe stack is empty\n");
        exit(2);
    } else {
        NODE *aux = (*stack)->next;
        int value = aux->value;
        (*stack)->next = (*stack)->next->next;
        free(aux);

        return value;
    }
}

void destroyStack(LINKED_STACK stack) {
    NODE *aux = stack;
    while(aux) {
        stack = stack->next;
        free(aux);
        aux = stack;
    }
}