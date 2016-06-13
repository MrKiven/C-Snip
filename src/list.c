#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

List *createList(void)
{
    List *list = (List *)malloc(sizeof(List));
    assert(list != NULL);
    list->head = createNode(NULL);
    list->head->prev = list->head->next = list->head;
    list->n = 0;

    return list;
}

Node *createNode(void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    assert(node != NULL);
    if (data != NULL) {
        node->prev = node->next = NULL;
        node->data = data;
    }

    return node;
}

int isEmpty(List *list) { return list->head->next == list->head; }
void displayList(List *list)
{
    Node *x = list->head->next;
    while (x != list->head) {
        void *data = x->data;
        printf("%s\n", data);
        x = x->next;
    }
}

// push Node **k** after Node **node**
void push(List *list, Node *node, void *k)
{
    Node *x = createNode(k), *b = node->prev;
    list->head->next = node;
    list->n += 1;
    x->next = node;
    node->prev = b;
    node->prev = b->next = x;
}

Node *pop(List *list, Node *node)
{
    if (list->n == 0) {
        printf("List is empty!!!");
        return NULL;
    }
    Node *a = node->next, *b = node->prev;
    b->next = a;
    a->prev = b;
    list->n -= 1;

    return node;
}
