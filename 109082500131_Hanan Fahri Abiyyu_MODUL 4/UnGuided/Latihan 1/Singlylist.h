#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H
#include <iostream>
#define Nil NULL
using namespace std;
typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);


#endif