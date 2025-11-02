#include "myString.h"

int main() {
    string str = createString("Hello");
    string copy = copyString(&str);

    printf("%s", copy.str);

    deleteString(&str);
    deleteString(&copy);

    return 0;
}