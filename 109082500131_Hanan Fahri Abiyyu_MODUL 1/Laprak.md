# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. ...<br/>

...

#### 1. ...


#### 2. ...


#### 3. ...

### B. Pengenalan Bahasa C++<br/>
Bahasa Pemrograman C++ adalah bahasa pemrograman tingkat tinggi yang biasa digunakan untuk pengembangan perangkat lunak, mulai dari aplikasi dekstop hingga permainan di komputer dan sistem operasi.[2]
...

#### 1. Elemen Dasar, Tipe Data, dan Operator C++
C++ menyediakan berbagai tipe data dasar seperti `int`, `float`, `double`, dan `char` untuk menampung nilai di memori [2][cite: 4]. Selain itu, C++ mendukung berbagai operator untuk manipulasi data, termasuk operator aritmatika serta operator *increment/decrement* baik berupa *pre-increment* (`++r`) maupun *post-increment* (`r++`).[2]

#### 2. Struktur Kontrol Percabangan dan Perulangan
Logika eksekusi program C++ diatur menggunakan struktur percabangan (`if`, `if-else`, dan `switch-case`) untuk pengambilan keputusan berdasarkan kondisi tertentu [2][cite: 4]. Selain itu, C++ menyediakan struktur perulangan (`for`, `while`, dan `do-while`) untuk mengeksekusi blok kode secara berulang [2][cite: 4]. Perbedaan utamanya terletak pada alur evaluasi syarat, seperti perulangan `do-while` yang selalu mengevaluasi kondisi di akhir sehingga minimal dieksekusi satu kali.[2]

#### 3. Tipe Data Terstruktur dan Fungsi (Array, Struct, & Function)
Untuk pengelolaan data yang lebih kompleks, C++ mendukung pengelompokan data sejenis menggunakan `array` serta pengelompokan variabel dengan tipe data berbeda menggunakan `struct` [2][cite: 4]. Selain itu, C++ memanfaatkan Fungsi (*Function*) untuk membagi program menjadi blok-blok modular yang dapat dipanggil kembali (*reusable*), baik melalui deklarasi prototipe maupun definisi fungsi.[2]

## Guided

### 1. ...

```C++
#include <iostream>

using namespace std;

int main(){
    int W, X, Y; float Z;

    X = 7; Y = 3; W = 1;
    Z = (X + Y)/(Y + W);
    
    cout<< "Nilai z = " << Z << endl;
    return 0;
}
```
Program tersebut menghitung operasi matematika (7 + 3) / (3 + 1) atau 10 / 4. Ketiga variabel tersebut, X, Y, dan W dideklarasikan sebagai integer (bilangan bulat), proses pembagian dilakukan antar-integer terlebih dahulu. Karena operasi pembagian dilakukan antar-variabel integer, hasil operasinya bernilai 2 (bukan 2.5). Hasil 2 tersebut baru dimasukkan ke dalam variabel Z, kemudian dicetak pada output program.
### 2. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int r = 10;
    int s;
    
    s=10 + ++r;
    cout<< "Nilai r= "<<r<<endl;
    cout<< "Nilai s= "<<s<<endl;
    return 0;
}
```
Program tersebut diawali dengan deklarasi variabel r bernilai 10 dan variabel s yang belum diisi. Selanjutnya, s dihitung lewat pernyataan s = 10 + ++r. Tanda ++ yang diletakkan sebelum r disebut pre-increment, yang berarti nilai r ditambah 1 terlebih dahulu sebelum digunakannya dalam perhitungan. Jadi r berubah dari 10 menjadi 11, lalu 11 itulah yang dijumlahkan dengan 10, sehingga s bernilai 21. Perubahan tadi tersimpan di variabel r, sehingga setelah baris tersebut, nilai r tetap 11, bukan kembali ke 10. Pada bagian akhir, program mencetak dua baris, yaitu Nilai r= 11 dan Nilai s= 21.

### 3. ...

```C++
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int r = 10;
    int s;
    
    s=10 + r++;
    cout<< "Nilai r= "<<r<<endl;
    cout<< "Nilai s= "<<s<<endl;
    return 0;
}
```
Program ini menggunakan post-increment (r++), sehingga nilai awal r (10) digunakan terlebih dahulu untuk penjumlahan. Hal ini membuat s bernilai 20 (10 + 10). Setelah operasi selesai, nilai r bertambah menjadi 11, sehingga output yang dihasilkan adalah Nilai r = 11 dan Nilai s = 20. Perbedaannya dengan pre-increment hanya terletak pada variabel s. Pada pre-increment (++r), nilai r bertambah sebelum penjumlahan sehingga s bernilai 21. Sedangkan pada post-increment, penjumlahan menggunakan nilai awal r sehingga s bernilai 20. Nilai akhir r pada kedua kasus tetap sama-sama 11.

### 4. ...

```C++
#include <iostream>
using namespace std;
int main(){
    double tot_pembelian, diskon;

    cout<<"total pembelian: Rp";
    cin>>tot_pembelian;
    diskon = 0;

    if(tot_pembelian >= 100000)
    diskon = 0.05*tot_pembelian;
    cout<<"besar diskon = Rp" <<diskon;
}
```
Program di atas menggunakan dua variabel bertipe data double, yaitu tot_pembelian untuk menyimpan input total belanja dari pengguna dan diskon yang bernilai 0 untuk menyimpan besaran potongan harga. Setelah menerima nilai tot_pembelian, program mengecek kondisi if apakah belanjaan mencapai Rp100000 atau lebih. Jika kondisi terpenuhi, nilai diskon dihitung sebesar 5% dari total belanja (0.05 * tot_pembelian), sedangkan jika kurang dari nominal tersebut, nilainya tetap 0. Pada akhir program, nilai diskon yang diperoleh akan dicetak pada output.

### 5. ...

```C++
#include <iostream>
using namespace std;

int main() {
    double tot_pembelian, diskon;

    cout<<"total pembelian: Rp";
    cin>>tot_pembelian;
    diskon = 0;

    if(tot_pembelian >= 100000){
        diskon = 0.05*tot_pembelian;
    }else{
        diskon = 0;
    }
    cout<<"besar diskon = Rp" <<diskon;
}
```
Program pada nomor 5 menggunakan dua variabel bertipe data double, yaitu tot_pembelian untuk menyimpan input total belanja dari pengguna dan diskon bernilai 0, berfungsi untuk menyimpan besaran potongan harga. Berbeda dari contoh sebelumnya, kode ini menambahkan kondisi else untuk pengondisian saat if tidak terpenuhi. jika tot_pembelian mencapai Rp100000 atau lebih, kondisi if terpenuhi sehingga diskon dihitung sebesar 5% (0.05 * tot_pembelian), sedangkan jika kurang dari nominal tersebut, alur berpindah ke blok else yang memastikan nilai diskon tetap 0. Pada akhir program, nilai diskon yang diperoleh dicetak pada output program.

### 6. ...

```C++
#include <iostream>

using namespace std;

int main(){
    int kode_hari;
    puts("Menentukan hari kerja/libur\n");
    puts("1=Senin 3=Rabu 5=Jumat 7=Minggu ");
    puts("2=Selasa 4=Kamis 6=Sabtu ");
    
    cin>>kode_hari;
    switch(kode_hari) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout<<"Hari Kerja"<<endl;
            break;
        case 6:
        case 7:
            cout<<"Hari Libur"<<endl;
            break;
    default:
        cout<<"Kode masukan salah!!!"<<endl;
    }
    return 0;
}
```
Program ini menggunakan satu variabel bertipe data integer, yaitu kode_hari, yang digunakan untuk menyimpan input angka pilihan hari dari pengguna (1–7). Setelah menampilkan daftar kode, program memanfaatkan struktur switch dengan sifat fall-through untuk mengevaluasi input tersebut. Jika kode_hari bernilai 1 hingga 5, program akan mengeksekusi blok yang mencetak "Hari Kerja" lalu dihentikan oleh perintah break. Jika bernilai 6 atau 7, program mencetak "Hari Libur". Apabila angka yang dimasukkan berada di luar rentang 1–7, bagian default akan dijalankan untuk menampilkan pesan "Kode masukan salah!!!".

### 7. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int jum;
    cout<<"jumlah perulangan: ";
    cin>>jum;

    for(int i=0; i<jum; i++) {
        cout<<"saya pintar\n";
    }
    
    return 0;
}
```
Program ini memanfaatkan perulangan for untuk mencetak kalimat "saya pintar" sesuai dengan input yang dimasukkan pengguna. Program menggunakan variabel jum bertipe data integer untuk menyimpan input jumlah perulangan, serta variabel i bertipe data integer sebagai penghitung perulangan. Setelah menerima input nilai jum, program mengeksekusi struktur perulangan for yang dimulai dari i = 0 selama i kurang dari jum. Pada setiap iterasi, nilai i bertambah 1 dan program mencetak teks "saya pintar" ke layar, sehingga kalimat tersebut akan muncul berulang kali sebanyak angka yang dimasukkan oleh pengguna.

### 8. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int i=1;
    int jum;

    cout<<"masukan banyak baris: ";
    cin>>jum;

    while(i<=jum) {
        cout<<"baris ke-"<<i<<endl;
        i++; 
    }
    return 0;
}
```
Kode berikut dirancang untuk menampilkan urutan baris secara otomatis dengan memanfaatkan perulangan while. Pada bagian awal program, variabel jum bertipe data integer digunakan untuk menyimpan input batas baris dari pengguna, sementara variabel i bertipe data integer yang diinisialisasi nilai 1 bertindak sebagai penghitung. Selama kondisi i <= jum terpenuhi, kode akan mencetak teks "baris ke-" diikuti nilai i, lalu memperbarui nilai i dengan menambah 1 (i++) hingga seluruh baris berhasil ditampilkan.

### 9. ...

```C++
#include <iostream>
using namespace std;
int main() {
    int i = 0;
    int jum;

    cin >> jum;
    do {
        cout << "baris ke-" <<(i+1)<<endl;
        i++;
    } while(i<jum);
    return 0;
}
```
Eksekusi pada kode ini memanfaatkan perulangan do-while, dengan variabel jum bertipe data integer untuk menampung input batas baris dan variabel i bertipe data integer yang diinisialisasi nilai 0 sebagai penghitung. Kode akan langsung mencetak teks "baris ke-" diikuti nilai (i + 1) dan menambah nilai i (i++), baru kemudian mengevaluasi kondisi i < jum di akhir. Perbedaannya dengan perulangan while pada nomor sebelumnya terletak pada waktu pengecekan kondisi, do-while mengevaluasi syarat di akhir sehingga blok kode pasti dijalankan minimal satu kali meskipun input bernilai 0 atau negatif, sedangkan perulangan while memeriksa syarat di awal sehingga tidak akan dieksekusi sama sekali jika syarat tidak terpenuhi.

### 10. ...

```C++
#include <iostream>
#define MAX 5
using namespace std;
int main(){
    int i;

    struct data {
        char nama[40];
        int nilai;
    };
    data siswa[MAX];

    for(i=0; i<MAX; i++) {
        cout<<"masukkan data ke-"<<i+1<<endl;
        cout<<"nama = ";
        cin>>siswa[i].nama;
        cout<<"nilai = ";
        cin>>siswa[i].nilai;
    }

    cout<<"\ndata siswa\n";
    cout<<"=======";

    for(i=0; i<MAX; i++){
        cout<<"\n\ndata ke-"<<i+1;
        cout<<"\n\nnama="<<siswa[i].nama;
        cout<<"\n\nnilai="<<siswa[i].nilai;
    }
    return 0;
}
```
Pengelolaan sejumlah data siswa secara terstruktur pada kode ini dilakukan dengan menggabungkan konsep struct dan array. Terdapat variabel i bertipe data integer sebagai variabel penghitung, serta struct bernama data yang memuat nama bertipe data character dan nilai bertipe data integer. Struktur tersebut kemudian dijadikan array siswa berkapasitas 5 elemen berdasarkan konstanta MAX. Melalui perulangan for pertama, kode meminta pengguna memasukkan nama serta nilai tiap siswa hingga array terisi penuh, lalu perulangan for kedua dijalankan untuk menampilkan kembali seluruh daftar data yang telah tersimpan ke layar.

### 11. ...

```C++
#include <iostream>
using namespace std;

float ctof(float celcius);

int main() {
    float celcius, fahrenheit;
    cout <<"nilai Celcius? ";
    cin >> celcius;
    fahrenheit = ctof(celcius);
    cout<<celcius<<" Celcius adalah "<<fahrenheit<<" Fahrenheit"<<endl;
    return 0;
    }

    float ctof(float celcius){
    return (celcius * 1.8) + 32;
}
```
Melalui penerapan fungsi buatan ctof, kode ini memproses perhitungan konversi suhu dari unit Celcius ke Fahrenheit secara terpisah dari fungsi utama main. Dalam main program, terdapat dua variabel bertipe data float (bilangan real presisi-tunggal), yakni celcius untuk menampung input suhu dari pengguna dan fahrenheit untuk menyimpan hasil konversinya. Sebelum dipanggil, fungsi ctof dideklarasikan terlebih dahulu sebagai prototipe di bagian atas, lalu didefinisikan di bagian bawah menggunakan rumus (celcius * 1.8) + 32. Begitu pengguna memasukkan angka, nilai celcius dikirim sebagai argumen ke fungsi ctof, kemudian nilai kembaliannya (return value) ditampung oleh variabel fahrenheit untuk dicetak ke layar.

## Unguided

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan

...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Ritonga, A., & Yahfizham. (2023). Studi Literatur Perbandingan Bahasa Pemrograman C++ Dan Bahasa Pemrograman Python Pada Algoritma Pemrograman. Jurnal Teknik Informatika dan Teknologi Informasi (JUTITI), 3(3), 56–63.
<br>...