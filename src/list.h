#include <stdio.h>

#define create_list() createList()

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List {
    int size;
    Node *head;
    int n;
} List;

List *createList(void);
void displayList(List *list);
void push(List *list, Node *node, void *k);
Node *pop(List *list, Node *node);
Node *createNode(void *data);
int isEmpty(List *list);
