#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
typedef struct taskList taskList;

typedef struct node {
    unsigned int stringLen;
    char task[10];
    node* next;
    node* prev;
} node; // TODO: add allocated string

typedef struct taskList {
    unsigned int length;
    node* head;
    node* end;
} taskList;

// constructor
taskList empty_list();
taskList copyList(const taskList* other);
void erase(taskList* this);

// getters
void print_list(const taskList* list);

// setters
void push_front(taskList* this, const char* str);
void push_back(taskList* this, const char* str);

#endif