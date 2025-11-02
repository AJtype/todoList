#include "list.h"

taskList empty_list() {
    taskList list = {0, NULL, NULL};
    return list;
}

void print_list(const taskList *this) {
    node* itr = this->head;
    printf("{");
    while (itr != 0) {
        printf("%s, ", itr->str.str);
        itr = itr->next;
    } printf("}\n");    
}

string pop_back(taskList* this) {
    node* popped = popFront(this);

    if (!popped) {
        printf("pop_front() called on empty list\n");
        return createString("-1");
    }

    string val = popped->str;    

    deleteNode(popped);

    return val;
}

string pop_front(taskList* this) {
    node* popped = popFront(this);

    if (!popped) {
        printf("pop_front() called on empty list\n");
        return createString("-1");
    }

    string val = popped->str;    

    deleteNode(popped);

    return val;
}

node *popNode(taskList *this, size_t pos) {
    if (!this->length) {
        printf("Called pop on empty list\n");
        return NULL;
    }
    
    if (0 == pos) {
        return popFront(this); 
    } if (this->length-1 == pos) {
        printf("popping back\n");
        return popBack(this);
    }

    node* popped = getNode(this, pos);    
    
    popped->prev->next = popped->next;
    popped->next->prev = popped->prev;
    this->length--;

    popped->next = NULL;
    popped->prev = NULL;

    return popped;
}

void push_front(taskList *this, const char *str) {
    node* prevHead = this->head;

    // add a new node at the beginning of the list
    this->head = (node*)malloc(sizeof(node));
    if (NULL == this->head) { // TODO: change to return
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

string erase(taskList *this, size_t pos) {
    node* popped = getNode(this, pos);
    if (!popped)
        return createString("-1");
    
    return pop_by_node(this, popped);
}

void clear(taskList *this) {
    while (0 != this->head) {
        pop_front(this);
    }
}

node* popFront(taskList* this) {
    if (this->length == 0)
        return NULL;

    node* popped = this->head;
    string val = popped->str;

    this->head = popped->next;
    if (this->head)
        this->head->prev = NULL;
    else
        this->end = NULL;
    this->length--;
    popped->next = NULL;

    return popped;
}

node* popBack(taskList* this) {
    if (this->length == 0)
        return NULL;

    node* popped = this->end;
    string val = popped->str;

    this->end = popped->prev;
    if(this->end)
        this->end->next = NULL;
    else
        this->head = NULL;
    this->length--;
    popped->prev = NULL;

    return popped;
}

node *getNode(taskList *this, size_t pos) {
    if (pos >= this->length) {
        printf("Out of Bounds in func getNode\n");
        return NULL;
    }
    
    node* itr = this->head;
    for (size_t i = 0; i < pos; i++) {
        itr = itr->next;
    }    
    
    return itr;
}

string pop_by_node(taskList* this, node* popped) {
    if (this->head == popped) { // erase beginning
        return pop_front(this);
    } if (this->end == popped) { // erase end
        return pop_back(this);
    }
    string val = popped->str;
    
    popped->prev->next = popped->next;
    popped->next->prev = popped->prev;

    deleteNode(popped);
    this->length--;

    return val;
}

void deleteNode(node *n) {
    deleteString(&n->str);
    free(n);
}
