#include <iostream>
#include "list.h"
using namespace std;

int main() {
    linkedlist list;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(list);

    nodeA = alokasi("Dhimas", "001", 20);
    nodeB = alokasi("Budi", "002", 21);
    nodeC = alokasi("Andi", "003", 22);
    nodeD = alokasi("Caca", "004", 23);
    nodeE = alokasi("Dewi", "005", 24);

    insertFirst(list, nodeA);
    insertLast(list, nodeB);
    insertLast(list, nodeC);
    insertAfter(list, nodeD, nodeB);
    insertLast(list, nodeE);

    cout << "Isi List :\n";
    printList(list);
    cout << "Jumlah node: " << nbList(list) << endl;

    deletelist(list);
    return 0;

}