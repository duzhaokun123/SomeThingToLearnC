#ifndef __NODE_H__
#define __NODE_H__

#include <stdlib.h>

typedef struct _node {
    char* value;
    struct _node* next;
} Node;

typedef struct _list {
    Node* head;
    Node* last;
    int total;
}* List;

void list_add(List list, char* str);
void list_free(List list);
List list_new(void);
char* list_at(List list, int n);
void list_clean(List list);

#endif
