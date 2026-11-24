#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);
    enQueue(Q, "Gilar");
    enQueue(Q, "Aflah");
    enQueue(Q, "Aedil");
    enQueue(Q, "Fathir");
    enQueue(Q, "Kevin");
    enQueue(Q, "Zulfa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---\n";
    viewQueue(Q);
    
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;
    
    cout << "--- Isi Queue Setelah deQueue ---\n";
    viewQueue(Q);

    clearQueue(Q);
    
    return 0;
}