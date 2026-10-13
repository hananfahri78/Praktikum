# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Abstract Data Type Pengertian <br/>
ADT atau Abstract Data Type mendefinisikan kelas objek abstrak yang sepenuhnya dicirikan oleh operasi yang tersedia pada objek-objek tersebut. Ini berarti bahwa tipe data abstrak bisa didefinisikan dengan mendefinisikan operasi-operasi yang menjadi ciri khas dari tipe itu. [1].

#### 2. Array 2 Dimensi
Array dua dimensi merupakan kumpulan alokasi memori bertipe data sama yang disusun dalam bentuk baris dan kolom menyerupai matriks, di mana setiap elemennya diakses menggunakan dua nomor indeks penunjuk [3].

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

Program di atas adalah implementasi pemrograman modular menggunakan konsep Abstract Data Type (ADT) dalam C++ untuk mengelola data mahasiswa secara sederhana. Terdapat tiga file pada pengerjaan praktikum ini, mahasiswa.h berfungsi sebagai cetak biru (blueprint) yang berisi definisi struct mahasiswa (untuk menampung data NIM dan dua buah nilai) serta deklarasi prototipe fungsi dan prosedur agar bisa diakses oleh file lain. Dilengkapi juga dengan header guard (#ifndef) untuk mencegah duplikasi deklarasi, lalu diakhiri (#endif) pada file tersebut.

Selanjutnya, mahasiswa.cpp Berisi penjabaran kode nyata dari fungsi dan prosedur yang sebelumnya dideklarasikan. Di dalamnya terdapat prosedur inputMhs untuk meminta input NIM serta dua nilai dari pengguna, dan fungsi rata2 untuk menghitung serta mengembalikan nilai rata-rata dari kedua nilai tersebut dalam bentuk bilangan desimal (float).

Terkahir, main.cpp Berperan sebagai pusat eksekusi program. Bagian ini membuat sebuah objek mhs dari struct mahasiswa, memanggil prosedur input data, lalu memproses dan menampilkan hasil perhitungan rata-rata ke layar konsol.

## Unguided

### 1. Menghitung Nilai Akhir Mahasiswa Berdasarkan Nilai (UTS, UAS, dan NILAI TUGAS)

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
Pada program penghitungan nilai akhir mahasiswa ini menggunakan konsep Abstract Data Type (ADT) dalam C++ untuk mengelola data mahasiswa secara lebih lengkap menggunakan array of struct. Terdapat tiga file pada pengerjaan program ini, di mana nilaiMahasiswa.h berfungsi sebagai cetak biru (blueprint) yang berisi definisi struct mahasiswa (untuk menampung data Nama, NIM, komponen nilai UTS, UAS, Tugas, serta nilai akhir) dan deklarasi prototipe fungsi serta prosedur agar bisa diakses oleh file lain. File ini juga dilengkapi dengan header guard (#ifndef) untuk mencegah duplikasi deklarasi, lalu diakhiri dengan (#endif) pada file tersebut.

Selanjutnya, nilaiMahasiswa.cpp berisi penjabaran kode nyata dari fungsi dan prosedur yang sebelumnya dideklarasikan. Di dalamnya terdapat prosedur inputMahasiswa yang berfungsi untuk meminta input data diri dan nilai dari pengguna, fungsi Nilai_Akhir untuk menghitung akumulasi nilai berdasarkan bobot yang ditentukan, serta prosedur tampilDataMahasiswa untuk mencetak informasi akhir mahasiswa dengan format yang rapi.

Terakhir, main.cpp berperan sebagai pusat eksekusi program. Bagian ini membuat array of struct berukuran maksimal 10 data untuk menyimpan informasi tentang banyak mahasiswa, meminta jumlah data yang akan dimasukkan, kemudian memanggil prosedur untuk memasukkan data, melaksanakan perhitungan nilai akhir, dan menampilkan ringkasan hasilnya di layar konsol.


### 2. Menyetak Nama Mapel serta Kode Mapel Menggunakan ADT 

#### pelajaran.h

```C++
#ifndef PELAJARAN
#define PELAJARAN
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


### 3. Matriks 3x3

#### array2D.h

```C++
#ifndef ARRAY_2_D
#define ARRAY_2_D
#include <iostream>

void tampilArray(int arr[3][3]);
void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom);
void tukarPointer(int *p1, int *p2);

#endif
```

#### array2D.cpp

```C++
#include "array2D.h"
#include <iostream>

using namespace std;


void tampilArray(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;

}

void tukarPointer(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```

#### main.cpp

```C++
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