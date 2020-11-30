#include<stdio.h>
#include<stdlib.h>
#include"./FilaSequencial.h"

int main() {
    LINE line, line2;
    
    createLine(&line);
    insertElement(&line, 16);
    insertElement(&line, 32);
    insertElement(&line, 64);
    insertElement(&line, 128);
    insertElement(&line, 256);
    printLine(&line);

    printf("%d...", returnAndDeleteElement(&line));
    printf("%d...", returnAndDeleteElement(&line));
    printf("%d...", returnAndDeleteElement(&line));
    printf("%d...", returnAndDeleteElement(&line));
    printf("%d...", returnAndDeleteElement(&line));
    printf("\n\n");



    createLine(&line2);
    generateLine(&line2, -2, 6);
    printLine(&line2);
}

void createLine(LINE *line) {
    line->length = line->began = 0;
    line->final = -1;
}

int isEmpty(LINE *line) {
    return line->length == 0;
}

int lengthOfLine(LINE *line) {
    return line->length;
}

int insertElement(LINE *line, int value) {
    if(line->length < max) {
        line->final = ++line->final % max;
        line->elements[line->final] = value;
        line->length++;
        return 0;
    } else {
        printf("\nIt's impossible insert more one element\n\n");
        return 1;
    }
}

void printLine(LINE *line) {
    if(line->length) {
        int i, count = 0;
        for(i = line->began; count < line->length ;count++, i = ++i % max) {
            printf("%d...", *(line->elements + i));
        }
    }
    printf("\n\n");
}

int returnFirstElement(LINE *line) {
    if(line->length) {
        return line->elements[line->began];
    } else {
        printf("\nLine is empty\n\n");
        exit(1);
    }
}

void deleteFirstElement(LINE *line) {
    if(isEmpty(line)) {
        printf("\nLine is empty\n\n");
        exit(1);
    }
    line->began = ++line->began % max;
    line->length--;
}

int returnAndDeleteElement(LINE *line) {
    if(isEmpty(line)) {
        printf("\nLine is empty\n\n");
        exit(1);
    }
    line->began = ++line->began % max;
    line->length--;
    return line->elements[ line->began % max == 0 ? max-1 : line->began - 1];
}

void generateLine(LINE *line, int first, int last) {
    if(first > last) {
        printf("\nIt's not possible generate line with this range\n\n");
        exit(2);
    } else {
        if(first == last) {
        createLine(line);
        insertElement(line, last);
        } else {
            generateLine(line, first, last - 1);
            insertElement(line, last);
        }
    }
}