#include <iostream>
using namespace std;
int main() {
    int i = 0;
    int jum;

    cin >> jum;
    do {
        cout << "baris ke-" <<(i+1)<<endl;
        i++;
    } while(i<jum);
    return 0;
}