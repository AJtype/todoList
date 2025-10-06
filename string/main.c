#include "myString.h"

int main() {
    string str = createString("Hello");
    string copy = copyString(&str);

    printf("%s", copy.str);

    return 0;
}