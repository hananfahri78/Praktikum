#include <iostream>
#include "pelajaran.h"

using namespace std;
int main() {
    string namapel = "Analisis Kompleksitas Algoritma";
    string kodepel = "AKA";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
}