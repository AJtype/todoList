#include "myString.h"

void dropEOL(char *line) {
    if ('\n' == line[strlen(line)-1])
        line[strlen(line)-1] = '\0';
}

string empty_string() {
    string str = {10, 0, NULL};

    str.str = (char*)malloc(str.arrSize * sizeof(char));

    return str;
}

string copyString(const string* other) {
    string str = {other->arrSize, other->stringLen, NULL};

    str.str = (char*)malloc(other->arrSize * sizeof(char));
    strcpy(str.str, other->str);

    return str;
}

string createString(const char *other) {
    string this = {10, 0, NULL};
    unsigned int strLen = strlen(other);

    if (strLen >= this.arrSize) {
        this.str = (char*)malloc((strLen+1) * sizeof(char));
        this.arrSize = strLen + 1;
    } else
        this.str = (char*)malloc(this.arrSize * sizeof(char));

    strcpy(this.str, other);
    this.stringLen = strLen;

    return this;
}

void deleteString(string *s) {
    free(s->str);
}
