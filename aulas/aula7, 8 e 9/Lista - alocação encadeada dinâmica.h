typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;
typedef NODO *DYNAMIC_CHAINED_LIST;

void createList(DYNAMIC_CHAINED_LIST *list);
int listIsEmpty(DYNAMIC_CHAINED_LIST list);
void printList(DYNAMIC_CHAINED_LIST *list);

int isOrdered(DYNAMIC_CHAINED_LIST list);
int isOrderedWithRecursion(DYNAMIC_CHAINED_LIST list);

int belongToList(DYNAMIC_CHAINED_LIST list, int value);
int belongToListWithRecursion(DYNAMIC_CHAINED_LIST list, int value);

void insertElementIntoList(DYNAMIC_CHAINED_LIST *list, int position, int value);
void insertElementIntoListWithRecursion(DYNAMIC_CHAINED_LIST *list, int position, int value);

int returnElementWithRecursion(DYNAMIC_CHAINED_LIST list, int position);

void deleteElementFromList(DYNAMIC_CHAINED_LIST *list, int position);
void deleteElementFromListWithRecursion(DYNAMIC_CHAINED_LIST *list, int position);

void brokeList(DYNAMIC_CHAINED_LIST list);
void brokeListWithRecursion(DYNAMIC_CHAINED_LIST list);

int lengthOfList(DYNAMIC_CHAINED_LIST list);
int lengthOfListWithRecursion(DYNAMIC_CHAINED_LIST list);

int generateList(DYNAMIC_CHAINED_LIST *list, int firstElement, int lastElement);
int generateListWithRecursion(DYNAMIC_CHAINED_LIST *list, int firstElement, int lastElement);
