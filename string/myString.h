#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dropEOL(char* line);

typedef struct string string;

// mem = 12
typedef struct string {
    unsigned int arrSize;
    unsigned int stringLen;
    char* str;
} string;

// constructor
string empty_string();
string copyString(const string* other);
string createString(const char* other);

// setters
void appendChars(string* this, const char* str);
void appendStrings(string* this, string* other);

#endif