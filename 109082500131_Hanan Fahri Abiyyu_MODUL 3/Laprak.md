# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Abstract Data Type Pengertian <br/>
ADT atau Abstract Data Type mendefinisikan kelas objek abstrak yang sepenuhnya dicirikan oleh operasi yang tersedia pada objek-objek tersebut. Ini berarti bahwa tipe data abstrak bisa didefinisikan dengan mendefinisikan operasi-operasi yang menjadi ciri khas dari tipe itu. [1].

#### 1. Array 1 Dimensi
Array satu dimensi mengelompokkan elemen-elemen data bertipe seragam ke dalam satu variabel berformat satu baris. Seluruh nilai yang tersimpan di dalamnya terbagi ke dalam beberapa kolom dan dipanggil menggunakan nomor indeks berbasis nol [2, hal. 29].

#### 2. Array 2 Dimensi
Array dua dimensi merupakan kumpulan alokasi memori bertipe data sama yang disusun dalam bentuk baris dan kolom menyerupai matriks, di mana setiap elemennya diakses menggunakan dua nomor indeks penunjuk [3, hal. 70].

#### 3. Array Multidimensi
Array multidimensi merupakan struktur data yang terbentuk dari penggabungan beberapa array satu dimensi sehingga mampu mengorganisasikan data dalam bentuk baris dan kolom. Karena memiliki tata letak dua arah seperti tabel, struktur ini sering disebut sebagai matriks dan difungsikan untuk menyimpan sekumpulan data berdimensi lebih dari satu [2, hal. 29].

Proses pendeklarasian array multidimensi pada dasarnya mirip dengan array satu dimensi, tetapi membutuhkan dua pasang kurung siku sebagai petunjuk penomoran indeks. Pasangan kurung siku pertama dipakai untuk menentukan alokasi elemen baris, sedangkan kurung siku kedua digunakan untuk mendefinisikan posisi kolom [2, hal. 30].

### B. Pointer dan Reference<br/>

#### 1. Pointer
Pointer merupakan variabel khusus yang digunakan untuk menyimpan alamat memori fisik dari suatu nilai atau variabel lain. Berbeda dengan variabel biasa yang menyimpan nilai secara langsung, pointer bekerja dengan menyimpan alokasi alamat memori sehingga memungkinkan akses dan pengolahan data secara langsung pada memori utama untuk meningkatkan efisiensi eksekusi program [4, hal. 183].

#### 2. Reference
Reference merupakan alias atau nama sekunder yang merujuk secara langsung ke lokasi/alamat memori dari suatu variabel yang sudah dideklarasikan sebelumnya . Penggunaan reference mempermudah manipulasi variabel asli tanpa perlu membuat duplikasi data baru di dalam memori, sehingga penggunaan alokasi memori menjadi lebih efisien [4, hal. 184].

## Guided

### 1. Guided 1

#### mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

#### mahasiswa.cpp
```C++
#include "mahasiswa.h"
#include <iostream>
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> m.nim;
    cout << "input nilai = ";
    cin >> m.nilai1;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}
float rata2(mahasiswa m) {
    return float(m.nilai1+m.nilai2)/2;
}
```

#### main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```

Program ini mengimplementasikan pengolahan array satu dimensi dan dua dimensi secara bersamaan menggunakan konstanta MAX berukuran 5 sebagai batas ukuran data. Program menggunakan variabel i dan j bertipe integer sebagai pemegang indeks perulangan, array nilai bertipe float berukuran 5 untuk menampung input nilai siswa, serta array dua dimensi nilai_tahun bertipe integer statis yang telah diinisialisasi secara langsung dengan data matriks berukuran 5x5. Proses eksekusi dimulai dengan perulangan for dari i = 0 hingga i < MAX yang meminta input lima nilai siswa dari pengguna dan menyimpannya ke dalam array nilai, diikuti dengan perulangan for kedua untuk menampilkan data nilai siswa tersebut kembali ke layar. Terakhir, program memanfaatkan perulangan bersarang (nested loop) di mana perulangan i mengontrol perpindahan baris dan perulangan j mencetak tiap elemen array nilai_tahun per kolom, sehingga seluruh matriks dua dimensi berhasil ditampilkan ke layar dalam struktur baris dan kolom yang rapi.

## Unguided

### 1. Operasi Matematika Dasar (Penjumlahan, Pengurangan, dan Perkalian)

#### nilaiMahasiswa.h

```C++
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
```

#### nilaiMahasiswa.cpp
```C++
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

```

#### main.cpp
```C++
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
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided1.png)


##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided1(1).png)

Penjelasan unguided 1 :
Membuat program untuk mengolah operasi aritmetika matriks berukuran 3x3 yang mencakup penjumlahan, pengurangan, dan perkalian melalui antarmuka menu interaktif. Pada main program, perulangan do-while dipadukan dengan percabangan switch-case untuk mengatur alur pilihan menu. Perulangan do-while berfungsi menjaga agar tampilan menu terus muncul berulang kali dengan mengeksekusi blok program terlebih dahulu baru kemudian mengevaluasi kondisi menu != 0 di akhir, sedangkan switch-case bertugas mengarahkan alur eksekusi program ke prosedur perhitungan yang sesuai berdasarkan nilai angka menu yang diinputkan pengguna. Setelah opsi dipilih, program menjalankan prosedur Input() untuk menerima input angka pada matriks X dan Y, memprosesnya melalui prosedur penjumlahan(), pengurangan(), atau perkalian(), lalu menyimpan hasilnya ke matriks Z sebelum dicetak ke layar lewat prosedur tampilkanOutput().


### 2. Menukar nilai variabel (Pointer dan Reference)

#### pelajaran.h

```C++
#ifndef PELAJARAN
#include <string>
#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran input_pel);

#endif
```

#### pelajaran.cpp
```C++
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

```

#### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;
int main() {
    string namapel = "Analisis Kompleksitas Algoritma";
    string kodepel = "AKA";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
}
```
### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided2.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided2(1).png)

Penjelasan unguided 2 :
Kode program tersebut memanfaatkan prosedur tambahan Pointer() dan Reference() untuk memproses pergeseran nilai variabel, yang masing-masing menerapkan simbol pointer (*) untuk manipulasi alamat memori dan simbol reference (&) sebagai alias variabel. Program dirancang untuk menggeser posisi nilai dari tiga variabel integer secara berurutan menggunakan dua pendekatan pengiriman parameter tersebut. Pada fungsi utama, tiga nilai input dari user disimpan pada variabel x, y, dan z. Pemanggilan prosedur Pointer() dilakukan dengan mengirimkan alamat memori variabel (&x, &y, &z), lalu nilainya diakses dan digeser menggunakan operator *dereference* (*). Selanjutnya, prosedur Reference() dipanggil untuk melakukan pergeseran nilai serupa dengan memanfaatkan parameter reference (&) sehingga variabel dapat dimanipulasi secara langsung tanpa perlu operator khusus, kemudian output dicetak ke layar.  


### 3. (isi dengan soal unguided 3)

#### dlsjf.h

```C++
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided3.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided3(1).png)

Penjelasan unguided 3 :
Pada nomor 3 ini, diminta membuat program array satu dimensi, kemudian menampilkan data berdasarkan banyaknya menu, meliputi pencarian nilai tertinggi, terendah, dan rata-rata nilai array. Program ini menggunakan beberapa function dan procedure tambahan, yaitu searchMax(), searchMin(), rerata(), dan tampilkan().

Pada main program, data disimpan dalam array arrA dan ukurannya dihitung secara otomatis. Perulangan do-while digunakan sebagai pengulangan pilihan menu supaya terus muncul selama nilai menu != 0, sedangkan switch-case bertugas mengarahkan alur ke fungsi atau prosedur sesuai angka menu yang dipilih. Ketika menu dijalankan, prosedur tampilkan() akan mencetak isi array, fungsi searchMax() dan searchMin() mencari nilai paling besar dan kecil pakai iterasi for, lalu prosedur rerata() menghitung rata-ratanya dan menyimpan hasilnya ke variabel rata_rata lewat parameter pointer *hasil.

## Kesimpulan
Berdasarkan materi praktikum Pengenalan Bahasa C++ yang meliputi Array, Array 1 dimensi, Array 2 dimensi, Array Multidimensi, serta Pointer dan Reference, saya belajar bagaimana mengelola alokasi memori dan mengorganisasikan sekumpulan data bertipe seragam secara terstruktur serta modular. Melalui praktikum ini, saya memahami pengelompokan data homogen ke dalam variabel berbasis indeks mulai dari angka nol, baik secara linear pada array satu dimensi maupun berformat matriks baris dan kolom pada array dua dimensi dan multidimensi menggunakan perulangan bersarang (nested loop). Selain itu, saya mempelajari cara mengakses serta memanipulasi alamat memori fisik variabel menggunakan pointer dan reference tanpa duplikasi data, memahami perbedaan pengiriman parameter call by value, call by pointer, serta call by reference, hingga mampu menerapkan fungsi dan prosedur modular dalam menyelesaikan berbagai studi kasus pemrograman.

## Referensi

<br>
[1] B. Liskov and S. Zilles, "Programming with abstract data types," ACM SIGPLAN Notices, vol. 9, no. 4, hal. 50–59, Apr. 1974. 
<br>
[2] N. Tou, Bahan Ajar Dasar-Dasar Pemrograman. Balunijuk: Jurusan Teknologi Informasi, Universitas Bangka Belitung, 2022.
<br>
[3] L. J. E. Dewi, "Media Pembelajaran Bahasa Pemrograman C++," Jurnal Pendidikan Teknologi dan Kejuruan (JPTK) UNDIKSHA, vol. 7, no. 1, pp. 63–72, Jan. 2010.
<br>
[4] G. A. A. D. Indradewi, I. M. O. Widyantara, dan A. A. K. O. Sudana, "Sistem Visualisasi Eksekusi Pointer pada Pemrograman C++," Lontar Komputer: Jurnal Ilmiah Teknologi Informasi, vol. 6, no. 3, pp. 182–191, Des. 2015.