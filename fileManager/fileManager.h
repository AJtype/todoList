#ifndef LIST_H
#define LIST_H

#include "../list/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fileManager {
    FILE* fp;
    char* line;
    size_t len;
    size_t read;
} fileManager;


#endif