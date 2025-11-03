#include "pairStringToList.h"

pairSToL copyPair(const string first) {
    pairSToL res;
    res.first = copyString(&first);
    res.second = empty_list();
    return res;
}

pairSToL createPair(const char *first) {
    pairSToL res;
    res.first = createString(first);
    res.second = empty_list();
    return res;
}

void deletePair(pairSToL *p) {
    deleteString(&p->first);
    clear(&p->second);
}
