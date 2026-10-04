#include <iostream>
using namespace std;

void Pointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void Reference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int x, y, z;

    cout << "Masukkan bilangan : ";
    cin >> x >> y >> z; 
    

    Pointer(&x, &y, &z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << " (Metode Pointer)" << endl;

    Reference(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << " (Metode Reference)" << endl;

    return 0;

}