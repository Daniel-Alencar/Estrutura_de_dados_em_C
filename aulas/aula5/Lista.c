#include<stdio.h>
#include<stdlib.h>
#define max 20

typedef struct {
    int length;
    int values[max];
}LIST;

void createList(LIST *list);
int isEmpty(LIST *list);
int lengthOfList(LIST *list);
int insertElement(LIST *list, int position, int value);
int returnElement(LIST *list, int position);
int deleteElement(LIST *list, int position);
void printList(LIST *list);
int findInList(LIST *list, int value);
int isOrdered(LIST *list);
int generateList(LIST *list, int firstNumber, int lastNumber);

int main() {
    LIST list;
    createList(&list);
    generateList(&list, -3, 5);
    printList(&list);

    deleteElement(&list, 1);
    printList(&list);
    deleteElement(&list, 2);
    printList(&list);
}

void createList(LIST *list) {
    list->length = 0;
}

int isEmpty(LIST *list) {
    return (!list->length);
}

int lengthOfList(LIST *list) {
    return list->length;
}

int insertElement(LIST *list, int position, int value) {
    
    if(lengthOfList(list) == max) {
        printf("\nThere is not store enough in list\n\n");
        return 0;
    }
    if(position < 0 || position > list->length) {
        printf("\nPosition isn't valid\n\n");
        return 0;
    }

    if(position != lengthOfList(list)) {
        int i;
        for(i=(lengthOfList(list) - 1); i >= position; i--) {
            *(list->values + i + 1) = *(list->values + i);
        }
    }
    *(list->values + position) = value;
    list->length += 1;

    return 1;
}

int returnElement(LIST *list, int position) {

    if(position < 0 || position >= list->length) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    return list->values[position];
}

int deleteElement(LIST *list, int position) {

    if(isEmpty(list)) {
        printf("\nList is empty\n\n");
        return 0;
    }
    if(position < 0 || position >= list->length) {
        printf("\nPosition isn't valid\n\n");
        return 0;
    }
    
    int i;
    for(i=(position + 1); i < lengthOfList(list); i++) {
        *(list->values + i - 1) = *(list->values + i);
    }
    list->length -= 1;
}

void printList(LIST *list) {
    int i;

    for(i=0; i < lengthOfList(list); i++) {
        printf("%i...", list->values[i]);
    }
    printf("\n");
}

int findInList(LIST *list, int value) {
    int i;
    for(i=0; i < lengthOfList(list); i++) {
        if(*(list->values + i) == value) {
            return 1;
        }
    }
    return 0;
}

int isOrdered(LIST *list) {
    int i, previous = list->values[0];

    for(i=1; i<lengthOfList(list); i++) {
        if(list->values[i] < previous) {
            return 0;
        }
        previous = list->values[i];
    }
    return 1;
}

int generateList(LIST *list, int firstNumber, int lastNumber) {

    if(firstNumber > lastNumber) {
        printf("\nError! Invalid range\n\n");
        return 0;
    } else {
        if(lastNumber == firstNumber) {
            createList(list);
            insertElement(list, 0, firstNumber);
            return 1;
        } else {
            generateList(list, firstNumber + 1, lastNumber);
            insertElement(list, 0, firstNumber);
        }
    }
}