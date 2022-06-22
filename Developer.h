
//definition of functions and constructors.

#ifndef EX3_DEVELOPER_H
#define EX3_DEVELOPER_H
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define N 20

typedef struct recommender {
    char name[N], familyName[N], email[N];
} Recommender;

typedef struct developer {
    char name[N], familyName[N], learning[N];
    struct developer *dev1, *dev2;
    Recommender *rec1, *rec2;
} Developer;

void printCandidates(Developer *[]);

void printWorkers(Developer *[]);

void insert(Developer *[], Developer *[]);

void acceptCandidate(Developer *[], Developer *[]);
#endif //EX3_DEVELOPER_H
