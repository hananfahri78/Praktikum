#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

void CreateList(List &L){
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x){
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    P->next = Nil;
    P->prev = Nil;
    delete P;
}

void printInfo(List L) {
    address P = L.Last;

    cout << endl;
    cout << "DATA LIST 1" << endl;
    cout << endl;

    while (P != Nil) {
        cout << "no polisi  : " << P->info.nopol << endl;
        cout << "warna      : " << P->info.warna << endl;
        cout << "tahun      : " << P->info.thnBuat << endl;
        P = P->prev;
    }
    cout << endl;

} 

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    }else{
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.Last;
    while(P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->prev;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    }else{
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    }else{
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleterAfter(address Prec, address &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next->prev = Prec;
    P->next = Nil;
    P->prev = Nil;
}