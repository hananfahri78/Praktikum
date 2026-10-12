#ifndef NILAI_MAHASISWA_H
#define NILAI_MAHASISWA_H
#include <iostream>
#include <string>

using namespace std;

struct mahasiswa{
    string Nama;
    string Nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

void inputMahasiswa(mahasiswa &mhs);
float Nilai_Akhir(mahasiswa &mhs);
void tampilDataMahasiswa(mahasiswa mhs);

#endif