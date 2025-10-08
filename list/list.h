#ifndef LIST_H
#define LIST_H

#include "../string/myString.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct taskList taskList;

typedef struct node {
    string str;
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

// getters
void print_list(const taskList* list);
string pop_back(taskList* this);
string pop_front(taskList* this);
node* popNode(taskList* this, size_t pos); // pop node from list and return it to main

// setters
void push_front(taskList* this, const char* str);
void push_back(taskList* this, const char* str);

// funcs
string erase(taskList* this, size_t pos);
void clear(taskList* this);

// helper funcs
node* popFront(taskList* this);
node* popBack(taskList* this);
node* getNode(taskList* this, size_t pos);
string pop_by_node(taskList* this, node* popped);

#endif