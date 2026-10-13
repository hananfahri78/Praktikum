# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Abstract Data Type Pengertian <br/>
ADT atau Abstract Data Type mendefinisikan kelas objek abstrak yang sepenuhnya dicirikan oleh operasi yang tersedia pada objek-objek tersebut. Ini berarti bahwa tipe data abstrak bisa didefinisikan dengan mendefinisikan operasi-operasi yang menjadi ciri khas dari tipe itu. [1].

### B. Primitif pada ADT<br/>
Tipe data Primitif pada ADT diterjemahkan pada beberapa jenis fungsi dan prosedur, antara lain:

#### 1. Konstruktor/Kreator
Pembentuk nilai tipe. Semua objek (variabel) bertipe tersebut harus melalui konstruktor. Biasanya namanya diawali Make.

#### 2. Selector
Berfungsi untuk mengakses komponen tipe (biasanya namanya diawali Get).

#### 3. Prosedur Pengubah 
Digunakan untuk mengubah nilai komponen pada suatu ADT.

#### 4. Tipe Validator Komponen 
Dipakai untuk menguji apakah dapat membentuk tipe sesuai dengan batasan.

#### 5. Destruktor
Berfungsi untuk menghancurkan nilai variabel (sekaligus memori penyimpanannya).

#### 6. Baca/Tulis
Sebagai antarmuka (interface) dengan perangkat masukan/keluaran (input/output).

#### 7. Operator relasional
Mendefinisikan lebih besar, lebih kecil, sama dengan, dan sebagainya.

#### 8. Aritmetika
Biasanya aritmetika dalalm bahasa C hanya terdefinisi untuk bilangan numerik.

#### 9. Konversi dari tipe tersebut ke tipe dasar dan sebaliknya.

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

![Screenshot Output Unguided 1_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%203/Output_UnGuided/Output_UnGuided1.png)


##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%203/Output_UnGuided/Output_UnGuided1(1).png)

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

![Screenshot Output Unguided 2_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%203/Output_UnGuided/Output_UnGuided2.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%203/Output_UnGuided/Output_UnGuided2(1).png)

Penjelasan unguided 2 :
Program ini menerapkan konsep Abstract Data Type (ADT) pada C++ untuk mengelola data mata pelajaran, dan terdiri dari tiga file. File pelajaran.h memuat struct pelajaran yang menyimpan nama dan kode mata pelajaran, beserta prototipe fungsi dan prosedurnya. Di file ini juga terdapat header guard (#ifndef, #define, dan #endif) agar deklarasi tidak terduplikasi ketika file di-include lebih dari satu kali.

File pelajaran.cpp berisi implementasi dari fungsi dan prosedur yang sudah dideklarasikan. Fungsi create_pelajaran menerima parameter nama dan kode mata pelajaran, lalu mengembalikan struct pelajaran yang berisi kedua data itu. Prosedur tampil_pelajaran digunakan untuk menampilkan isinya ke layar.

File main.cpp berisi program utama. Nama mata pelajaran “Analisis Kompleksitas Algoritma” dan kode “AKA” dikirim ke fungsi create_pelajaran, kemudian hasilnya ditampilkan melalui prosedur tampil_pelajaran.

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

![Screenshot Output Unguided 3_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%203/Output_UnGuided/Output_UnGuided3.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%203/Output_UnGuided/Output_UnGuided3%7B1%7D.png)

Penjelasan unguided 3 :
Program ini menerapkan array dua dimensi dan pointer pada C++ yang dibagi menjadi tiga file. File array2D.h memuat deklarasi tiga fungsi, yaitu tampilArray, tukarPosisi, dan tukarPointer. Di file ini juga terdapat header guard (#ifndef, #define, dan #endif) agar deklarasi tidak terduplikasi ketika file di-include lebih dari satu kali.

File array2D.cpp berisi implementasi dari ketiga fungsi tersebut. Fungsi tampilArray mencetak isi array berukuran 3x3 menggunakan perulangan bersarang. Fungsi tukarPosisi menukar elemen pada baris dan kolom tertentu antara dua array dengan bantuan variabel temp. Fungsi tukarPointer menukar nilai dari dua variabel melalui pointer, yaitu dengan mengakses nilainya menggunakan operator dereferensi (*).

File main.cpp berisi program utama. Di sini dibuat dua array 3x3 (arr1 dan arr2) serta dua variabel, x bernilai 5 dan y bernilai 10, yang alamatnya disimpan pada pointer p1 dan p2. Kedua array ditampilkan terlebih dahulu, lalu elemen pada baris 1 kolom 1 ditukar sehingga nilai 19 pada arr1 berpindah ke arr2, dan nilai 2 pada arr2 berpindah ke arr1. Setelah itu nilai pada p1 dan p2 ditukar, sehingga p1 menjadi 10 dan p2 menjadi 5, lalu hasilnya ditampilkan ke layar.

## Kesimpulan
Kesimpulan dari praktikum Modul 3 ini, saya belajar mengenai konsep Abstract Data Type (ADT). Saya menjadi lebih tahu bahwa ADT merupakan konsep dasar yang akan sering digunakan saat praktikum maupun saat membuat real project. Dari modul ADT ini, saya juga berlatih menggunakan array dua dimensi, struct, array satu dimensi secara bersamaan. Serta ilmu baru tentang cara pengerjaan praktikum ini, dengan memisahkan program ke dalam file header (.h), file implementasi (namafile.cpp), dan program utama (main.cpp).

## Referensi

<br>
[1] B. Liskov and S. Zilles, "Programming with abstract data types," ACM SIGPLAN Notices, vol. 9, no. 4, hal. 50–59, Apr. 1974. 
<br>