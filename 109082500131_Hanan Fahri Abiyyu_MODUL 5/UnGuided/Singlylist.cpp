#include "Singlylist.h"
#include <iostream>
using namespace std;


void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " " << endl;
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}


address findElm(List L, infotype x) {
    address P = L.First;
    while(P != Nil) {
        if (P->info == x) {
            cout << x << " ditemukan dalam list" << endl;
            return P;
        }
        P = P->next;        
    }
    cout << x << " Tidak ditemukan dalam list" << endl;
    return Nil;
}