#include "nilaiMahasiswa.h"

void inputMahasiswa(mahasiswa &mhs) {
    cout << "Nama : ";
    cin >> mhs.Nama;

    cout << "NIM : ";
    cin >> mhs.Nim;

    cout << "Nilai Uts : ";
    cin >> mhs.uts;

    cout << "Nilai UAS : ";
    cin >> mhs.uas;

    cout << "Nilai Tugas : ";
    cin >> mhs.tugas;
}

float Nilai_Akhir(mahasiswa &mhs) {

    float NilaiAkhir;
    NilaiAkhir = (0.3 * mhs.uts) + (0.4 * mhs.uas) + (0.3 * mhs.tugas);

    return NilaiAkhir;
}

void tampilDataMahasiswa(mahasiswa mhs) {
    cout << mhs.Nama << " (" << mhs.Nim <<") " << "Nilai Akhir = "<< mhs.nilaiAkhir << endl;
}
