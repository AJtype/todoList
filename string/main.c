#include "myString.h"

int main() {
    string str = createString("Hello");
    string copy = copyString(&str);
    appendChars(&copy, " World!");

    printf("%s", copy.str);

    deleteString(&str);
    deleteString(&copy);

    return 0;
}