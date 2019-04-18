#include "list.h"
#include <stdio.h>

void list_add(List list, char* str) {
    Node* head = list->head;
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->value = str;
    if (head == 0) {
        list->head = p;
        list->last = p;
        list->total = 1;
    } else {
        list->last->next = p;
        list->last = p;
        list->total += 1;
    }
}

void list_free(List list) {
    Node* p = list->head;
    Node* next = NULL;
    while (p) {
        next = p->next;
        free(p);
        p = next;
    }
    free(list);
}

List list_new(void) {
    List list = (List)malloc(sizeof(struct _list));
    if (list != NULL) {
        list->head = NULL;
        list->last = NULL;
        list->total = 0;
    }

    return list;
}

char* list_at(List list, int n) {
    if (n > list->total) {
        return NULL;
    }

    Node* p = list->head;
    Node* next = NULL;
    int i = 1;
    while (i != n) {
        next = p->next;
        p = next;
        i++;
    }

    return p->value;
}

void list_clean(List list) {
    list_free(list);
    list = list_new();
}
