#include "list.h"

taskList empty_list() {
    taskList list = {0, 0, 0};
    return list;
}

void print_list(const taskList *list) {
    node* itr = list->head;
    printf("{");
    while (itr != 0) {
        printf("%s, ", itr->str.str);
        itr = itr->next;
    } printf("}\n");    
}

string pop_front(taskList* this) {
    if (this->length == 0) {
        printf("pop_front() called on empty list\n");
        return createString("-1");
    }

    node* popped = this->head;
    string val = popped->str; // does this work?

    this->head = popped->next;
    if (this->head) {
        this->head->prev = NULL;
    } else {
        this->end = NULL;
    }

    free(popped);
    this->length--;

    return val;
}

void push_front(taskList *this, const char *str) {
    node* prevHead = this->head;

    // add a new node at the beginning of the list
    this->head = (node*)malloc(sizeof(node));
    if (NULL == this->head) {
        perror("Memory allocation failed in function push_front");
        exit(EXIT_FAILURE);
    }

    this->head->str = createString(str);
    this->head->next = prevHead;
    this->head->prev = NULL;

    if (0 == this->length)
        this->end = this->head;
    else
        prevHead->prev = this->head;
    this->length++;
}

void push_back(taskList *this, const char *str) {
    node* temp = (node*)malloc(sizeof(node));
    if (NULL == temp) {
        perror("Memory allocation failed in function push_front");
        exit(EXIT_FAILURE);
    }

    temp->str = createString(str);
    temp->next = NULL;

    if (0 == this->length) {
        this->head = temp;
        this->head->prev = NULL;
        this->end = this->head;
    } else {
        temp->prev = this->end;
        this->end->next = temp;
        this->end = this->end->next;
    } this->length++;    
}
