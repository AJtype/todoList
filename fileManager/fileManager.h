#ifndef FILEMANAGER_H
#define FILEMANAGER_H

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