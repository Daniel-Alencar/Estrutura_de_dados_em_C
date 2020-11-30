#define max 10
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
void generateLine(LINE *line, int first, int last);
