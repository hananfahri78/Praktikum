#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P5 = alokasi(9);
    insertFirst(L,P5);

    // infotype x;
    // cout << "Masukkan nilai yang dicari : ";
    // cin >> x;

    // address hasil = findElm(L, x);
    
    int total = 0;
    address P = L.First;
    while (P != Nil){
        total = total + P->info;
        P = P->next;
    }
    cout << "Total info dari kelima elemen adalah " << total << endl;

    // printInfo(L);
    return 0;
}