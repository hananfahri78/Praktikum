#include <iostream>
using namespace std;

int main() {
    int i=1;
    int jum;

    cout<<"masukan banyak baris: ";
    cin>>jum;

    while(i<=jum) {
        cout<<"baris ke-"<<i<<endl;
        i++; 
    }
    return 0;
}