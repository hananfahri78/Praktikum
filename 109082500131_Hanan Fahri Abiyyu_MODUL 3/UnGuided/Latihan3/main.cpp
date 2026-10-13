#include <iostream>
#include "array2D.h"

using namespace std;

int main() {
    int arr1[3][3] = {{10, 11, 12}, {20, 19, 18}, {13, 14, 15}};
    int arr2[3][3] = {{8, 9, 10}, {3, 2, 1}, {4, 5, 6}};

    int x = 5; int y = 10;
    int *p1 = &x;
    int *p2 = &y;

    cout << "Array 1 awal :\n";
    tampilArray(arr1);

    cout << "Array 2 awal :\n";
    tampilArray(arr2);

    tukarPosisi(arr1, arr2, 1, 1);

    cout << "Sesudah Tukar Array" << endl;
    cout << "Array 1 :\n";
    tampilArray(arr1);
    cout << "Array 2 :\n";
    tampilArray(arr2);

    cout << "Sebelum Tukar Nilai Pointer :" << endl;
    cout << "Pointer 1 : " << *p1 << " Pointer 2 : " << *p2 << endl;

    tukarPointer(p1, p2);

    cout << "Sesudah Tukar Nilai Pointer" << endl;
    cout << "Pointer 1 : " << *p1 << " Pointer 2 : " << *p2 << endl;


    return 0;

}