#include "list.h"
#include <stdio.h>

List list_new(void) {
    List list = (List)malloc(sizeof(struct _list));
    if (list != NULL) {
        list->head = NULL;
        list->last = NULL;
        list->total = 0;
    }

    return list;
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

void list_add(List list, void* value) {
    Node* head = list->head;
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->value = value;
    p->local = p;
    if (head == NULL) {
        list->head = p;
        list->last = p;
        list->total = 1;
        list->head->previous = NULL;
    } else {
        list->last->next = p;
        list->last = p;
        list->last->previous = list_node_get(list, -1)->local;
        list->total += 1;
    }
}

void list_add_after(List list, long long int number, void* value); //-1 for ERR 0 for OK
void list_add_before(List list, long long int number, void* value); //-1 for ERR 0 for OK
void list_overwrite(List list, long long int number, char* value); //-1 for ERR 0 for OK

void list_clran_all(List list);
void list_clean_at(List list, long long int number);
void list_clean_from(List list, long long int number);
void list_clean_to(List list, long long int number);
void list_clean_from_to(List list, long long int number1, long long int number2);

List list_copy(List list) {
    List a = list_new();
    for (long long int i = 0; i < list->total; i++) {
        list_add(a, list_value_get(list, i));
    }
    return a;
}

void* list_value_get(List list, long long int number) {
    return list_node_get(list, number)->value;
}

Node* list_node_get(List list, long long int number) {
    long long int a;
    Node* p = list->head;
    while (number < 0) {
        number += list->total;
    }

    for (a = 0; a < number; a++) {
        if (p->next == NULL) {
            return NULL;
        } else {
            p = p->next;
        }
    }
    return p;
}

