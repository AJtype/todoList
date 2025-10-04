#include "list.h"

taskList empty_list() {
    taskList list = {0, 0, 0};
    return list;
}

void print_list(const taskList *list) {
    node* itr = list->head;
    printf("{");
    while (itr != 0) {
        printf("%s, ", itr->task);
        itr = itr->next;
    } printf("}\n");    
}

void push_front(taskList *this, const char *str) {
    node* prevHead = this->head;

    // add a new node at the beginning of the list
    this->head = (node*)malloc(sizeof(node));
    if (NULL == this->head) {
        perror("Memory allocation failed in function push_front");
        exit(EXIT_FAILURE);
    }

    strcpy(this->head->task, str);
    this->head->next = prevHead;
    this->head->prev = NULL;
    this->head->stringLen = strlen(str);

    if (0 == this->length)
        this->end = this->head;
    else
        prevHead->prev = this->head;
    this->length;
}
