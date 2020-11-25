#include"./FilaSequencial.h"

int main() {
    LINE line;
    createLine(&line);
    generateLine2(&line, 3, 5);
    printLine(&line);
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

void generateLine1(LINE *line, int first, int last) {
    createLine(line);
    helperToGenerateLine(line, first, last);
}

void helperToGenerateLine(LINE *line, int first, int last) {
    if(first <= last) {
        insertElement(line, first);
        generateLine1(line, first + 1, last);
    }
}

void generateLine2(LINE *line, int first, int last) {
    if(first == last) {
        createLine(line);
        insertElement(line, last);
    } else if(first < last) {
        generateLine2(line, first, last - 1);
        insertElement(line, last);
    } else if(first > last) {
        printf("\nIt's not possible generate line with this range\n\n");
        exit(2);
    }
}