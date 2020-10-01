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
void insertElement(LIST *list, int position, int value);
int returnElement(LIST *list, int position);
void deleteElement(LIST *list, int position);
void printList(LIST *list);

int main() {
    LIST list;
    createList(&list);

    insertElement(&list, 0, 14);
    printList(&list);
    insertElement(&list, 0, 13);
    printList(&list);
    insertElement(&list, 0, 12);
    printList(&list);
    insertElement(&list, 0, 11);
    printList(&list);
    insertElement(&list, 0, 10);
    printList(&list);

    printf("\n\n");
    deleteElement(&list, 1);
    printList(&list);
    deleteElement(&list, 2);
    printList(&list);
}

void createList(LIST *list) {
    list->length = 0;
}

int isEmpty(LIST *list) {
    return list->length == 0;
}

int lengthOfList(LIST *list) {
    return list->length;
}

void insertElement(LIST *list, int position, int value) {
    
    if(lengthOfList(list) == max) {
        printf("\nThere is not store enough in list\n\n");
        return;
    }
    if(position < 0 || position > list->length) {
        printf("\nPosition isn't valid\n\n");
        return;
    }

    if(position != lengthOfList(list)) {
        int i;

        for(i=(lengthOfList(list) - 1); i >= position; i--) {
            *(list->values + i + 1) = *(list->values + i);
        }
    }
    *(list->values + position) = value;
    list->length += 1;
}

int returnElement(LIST *list, int position) {

    if(position < 0 || position >= list->length) {
        printf("\nPosition isn't valid\n\n");
        exit(1);
    }
    return list->values[position];
}

void deleteElement(LIST *list, int position) {

    if(isEmpty(list)) {
        printf("\nList is empty\n\n");
        return;
    }
    if(position < 0 || position >= list->length) {
        printf("\nPosition isn't valid\n\n");
        return;
    }
    if(position == (lengthOfList(list) - 1)) {
        list->length -= 1;
    } else {
        int i;

        for(i=(position + 1); i < lengthOfList(list); i++) {
            *(list->values + i - 1) = *(list->values + i);
        }
        list->length -= 1;
    }
}

void printList(LIST *list) {
    int i;

    for(i=0; i < lengthOfList(list); i++) {
        printf("%i...", list->values[i]);
    }
    printf("\n");
}