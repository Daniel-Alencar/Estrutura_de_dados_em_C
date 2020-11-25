#include"../aula18/FilaSequencial.h"
typedef struct {
    int elements[max];
    int top;
}SEQUENTIAL_STACK;

void createStack(SEQUENTIAL_STACK *stack);
int stackIsEmpty(SEQUENTIAL_STACK *stack);
void pushIntoStack(SEQUENTIAL_STACK *stack, int value);
int topOfStack(SEQUENTIAL_STACK *stack);
void popIntoStack(SEQUENTIAL_STACK *stack);
int topOfStackAndPopIntoStack(SEQUENTIAL_STACK *stack);
void reverseStack(LINE *line);

int main() {

}

void createStack(SEQUENTIAL_STACK *stack) {
    stack->top = -1;
}

int stackIsEmpty(SEQUENTIAL_STACK *stack) {
    return stack->top == -1;
}

void pushIntoStack(SEQUENTIAL_STACK *stack, int value) {
    if(stack->top == (max - 1)) {
        printf("\nNot is possible insert any element into stack\n\n");
        return;
    }
    stack->elements[++stack->top] = value;
}

int topOfStack(SEQUENTIAL_STACK *stack) {
    if(stackIsEmpty(stack)) {
        printf("\nThe stack is empty, therefore not exist any element\n\n");
        exit(1);
    }
    return stack->elements[stack->top];
}

void popIntoStack(SEQUENTIAL_STACK *stack) {
    if(stack->top == -1) {
        printf("\nThe stack is empty, therefore not exist any element to delete\n\n");
        return;
    }
    stack->top--;
}

int topOfStackAndPopIntoStack(SEQUENTIAL_STACK *stack) {
    if(stack->top == -1) {
        printf("\nThe stack is empty, therefore not exist any element to delete\n\n");
        exit(2);
    }
    return stack->elements[stack->top--];
}

void reverseStack(LINE *line) {
    if(line->length > 1) {
        SEQUENTIAL_STACK stack;
        createStack(&stack);
        
        while(!isEmpty(line)) {
            pushIntoStack(&stack, returnAndDeleteElement(line));
        }
        while(!stackIsEmpty(&stack)) {
            insertElement(line, topOfStackAndPopIntoStack(&stack));
        }
    }
}