#define max 30
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