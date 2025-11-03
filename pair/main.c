#include "pairStringToList.h"

int main() {
    pairSToL p = createPair("example");
    printf("First: %s\n", p.first.str);
    deletePair(&p);
    return 0;
}