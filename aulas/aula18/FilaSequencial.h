#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct {
    int length;
    int final;
    int began;
    int elements[max];
}LINE;

void createLine(LINE *line);
int isEmpty(LINE *line);
int lengthOfLine(LINE *line);
int insertElement(LINE *line, int value);
int returnFirstElement(LINE *line);
void deleteFirstElement(LINE *line);
int returnAndDeleteElement(LINE *line);
void printLine(LINE *line);

void generateLine1(LINE *line, int first, int last);
void helperToGenerateLine(LINE *line, int first, int last);
void generateLine2(LINE *line, int first, int last);