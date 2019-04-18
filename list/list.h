#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

typedef struct _node {
    void* value;
    struct _node* next;
    struct _node* previous;
    struct _node* local;
} Node;

typedef struct _list {
    Node* head;
    Node* last;
    long long int total;
}* List;

List list_new(void);
void list_free(List list);

void list_add(List list, void* value);
void list_add_after(List list, long long int number, void* value); 
void list_add_before(List list, long long int number, void* value); 
void list_overwrite(List list, long long int number, char* value);

void list_clran_all(List list);
void list_clean_at(List list, long long int number);
void list_clean_from(List list, long long int number);
void list_clean_to(List list, long long int number);
void list_clean_from_to(List list, long long int number1, long long int number2);

List list_copy(List list);
void* list_value_get(List list, long long int number);
Node* list_node_get(List list, long long int number);

#endif
