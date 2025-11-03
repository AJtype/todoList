#ifndef PAIR_H
#define PAIR_H

#include "../list/list.h"

typedef struct pairSToL pairSToL;

struct pairSToL {
    string first;
    taskList second;
};

pairSToL copyPair(const string first);
pairSToL createPair(const char* first);
void deletePair(pairSToL* p);

#endif