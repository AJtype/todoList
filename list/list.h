#ifndef LIST_H
#define LIST_H

#include "../string/myString.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct taskList taskList;
// currently doesnt free any strings
typedef struct node {
    string str;
    node* next;
    node* prev;
} node;

typedef struct taskList {
    unsigned int length;
    node* head;
    node* end;
} taskList;

// constructor
/** Creates and empty list
 * @return: an empty list
 * Memory: 12/16 bytes
 */
taskList empty_list();

taskList copyList(const taskList* other);

// getters
/** Print the given list
 * @param this: the printed list
 * #efficiency: On (always)
 * #memory: 8/12 bytes
 */
void print_list(const taskList* this);

/** Deleting the end of the list, and returning the string it holds
 * @param this: the list
 * @return: the string the end holds
 * #efficiency O1
 * #memory 20 bytes
 */
string pop_back(taskList* this);

/** Deleting the front of the list, and returning the string it holds
 * @param this: the list
 * @return: the string the front holds
 * #efficiency: O1
 * #memory: 20/32 bytes
 */
string pop_front(taskList* this);

/** Pop node from list and return it to main
 * @param this: the list
 * @param pos: the position of the node to be popped
 * @return: the popped node
 * @note: whoever calls this func must free the popped node
 * #efficiency: On
 * #memory: 12 bytes
 */
node* popNode(taskList* this, size_t pos);

// setters
/** Push a new node to the front of the list
 * @param this: the list
 * @param str: string the new node will hold
 * #efficiency: O1 + strcpy
 * #memory: 20 bytes
 */
void push_front(taskList* this, const char* str);

/** Push a new node to the back of the  list
 * @param this: the list
 * @param str: string the new node will hold
 * #efficiency: O1 + strcpy
 * #memory: 20 bytes
 */
void push_back(taskList* this, const char* str);

// funcs

/** pop and delete a node of specific position
 * @param this: the list
 * @param pos: the position of the node that needs to be popped
 * @return: the string the node held
 * #efficiency: Opos
 * #memory: 48
 */
string erase(taskList* this, size_t pos);

/** pop and delete a node of specific position
 * @param this: the list
 * @param pos: the position of the node that needs to be popped
 * @return: the string the node held
 * #efficiency: On (always)
 * #memory: 48
 */
void clear(taskList* this);

// helper funcs
node* popFront(taskList* this);
node* popBack(taskList* this);
node* getNode(taskList* this, size_t pos);
string pop_by_node(taskList* this, node* popped);

#endif