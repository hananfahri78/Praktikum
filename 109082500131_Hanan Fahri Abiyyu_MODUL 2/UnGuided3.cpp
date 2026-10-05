#include <iostream>
using namespace std;

int searchMax(int arr[], int n) { 
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int searchMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;

}

void rerata(int arr[], int n, double *hasil) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    *hasil = total / n;
}

void tampilkan(int arr[], int n) {
    cout << "Isi Array : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main() {
    int arrA[] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int menu;
    int n = sizeof(arrA) / sizeof(arrA[0]);
    double rata_rata;
    
    do {
    cout << "--- Menu Program Array ---" << endl;
    cout << "1. Tampilkan isi array" << endl;
    cout << "2. Cari nilai maksimum" << endl;
    cout << "3. Cari nilai minimum" << endl;
    cout << "4. Hitung nilai rata-rata" << endl;
    cout << "0. Exit\n" << endl;
    
    cout << "Pilih menu : ";
    cin >> menu;

    switch (menu){
        case 1:
            tampilkan(arrA, n);
            break;
        case 2:
            cout << "Nilai Maksimum array = " << searchMax(arrA, n) << endl;
            break;
        case 3:
            cout << "Nilai Minimum array = " << searchMin(arrA, n) << endl;
            break;
        case 4:
            rerata(arrA, n, &rata_rata);
            cout << "Nilai Rata-rata = " << rata_rata << endl; 
            break;
        case 0:
            cout << "Terima kasih telah menggunakan aplikasi kami" << endl;
            break;
    
    default:
        cout << "Input menu tidak valid! Silakan coba lagi!" << endl;
        break;
    }

    } while(menu != 0);

    return 0;
}