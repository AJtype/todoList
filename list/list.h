#ifndef LIST_H
#define LIST_H

typedef struct node node;
typedef struct taskList taskList;

typedef struct node {
    unsigned int stringLen;
    char task[10];
    node* next;
    node* prev;
} node;

typedef struct taskList {
    node* head;
    node* end;
    unsigned int length;
} taskList;

// constructor
taskList empty_list();
taskList copyList(const taskList* other);
void erase(taskList* this);

// getters

void print_list(const taskList *list);

#endif