typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;
typedef NODO *CIRCULAR_LIST;

void createList(CIRCULAR_LIST *list);
int isEmpty(CIRCULAR_LIST list);
int lengthOfList(CIRCULAR_LIST list);
void insertElement(CIRCULAR_LIST *list, int value, int position);
int returnElement(CIRCULAR_LIST list, int position);
void deleteElement(CIRCULAR_LIST *list, int position);
void destroyList(CIRCULAR_LIST list);
void printList(CIRCULAR_LIST list);