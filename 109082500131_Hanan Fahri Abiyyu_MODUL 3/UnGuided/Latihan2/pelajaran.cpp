#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran mapelBaru;
    mapelBaru.namaMapel = namapel;
    mapelBaru.kodeMapel = kodepel; 
    return mapelBaru;
}

void tampil_pelajaran(pelajaran input_pel) {
    cout << "nama pelajaran : " << input_pel.namaMapel << endl;
    cout << "nilai : " << input_pel.kodeMapel << endl;
}
