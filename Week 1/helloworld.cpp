#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "Masukan nilai = " ;
    cin >> a;

    switch(a){
        case 5:
            cout << "Betul itu 5" << endl;
        case 10:
            cout << "Betul itu 10" << endl;
        case 15:
            cout << "Betul itu 15" << endl;
    }

    cout << "endprog" << endl;
    return 0;
}
