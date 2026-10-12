#include <iostream>
#include "nilaiMahasiswa.h"

using namespace std;

int main() {
    mahasiswa Mhs[10];
    int n;
    cout << "Masukkan Jumlah Mahasiswa : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Data Mahasiswa ke-" << i+1 << endl;
        inputMahasiswa(Mhs[i]);
        Mhs[i].nilaiAkhir = Nilai_Akhir(Mhs[i]);        
    }
    
    cout << "Data Nilai Akhir Mahasiswa :\n" ;
    
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". ";
        tampilDataMahasiswa(Mhs[i]);
    }
    
    return 0;

}