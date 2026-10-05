# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Pengertian Struktur Data<br/>
Dalam pengertian paling dasarnya, struktur data adalah cara sistematis untuk mengorganisir dan menyimpan data di dalam memori komputer sehingga operasi tertentu—seperti pencarian, penyisipan, penghapusan, atau pengurutan—dapat dilakukan dengan cara yang paling efisien [1].

#### 1. Definisi Array
Secara konseptual, array adalah kumpulan elemen dengan tipe yang sama yang disimpan dalam lokasi memori yang berurutan dan contigu (berdekatan). Karakteristik paling penting dari array adalah random access: kemampuan untuk mengakses elemen mana pun secara langsung dengan menggunakan indeksnya, dalam waktu konstan [1].

#### 2. Linked List
Linked list adalah koleksi node yang masing-masing menyimpan nilai data dan satu atau lebih pointer yang menunjuk ke node berikutnya (atau sebelumnya, dalam kasus doubly linked list) [1].

#### 3. Perbedaan Stack dan Queue
Stack mengimplementasikan semantik LIFO (Last In, First Out): elemen yang terakhir dimasukkan adalah yang pertama dikeluarkan. Queue, sebaliknya, mengimplementasikan semantik FIFO (First In, First Out): elemen yang pertama dimasukkan adalah yang pertama dikeluarkan [1].

### B. Pengenalan Bahasa C++<br/>
Bahasa Pemrograman C++ adalah bahasa pemrograman tingkat tinggi yang biasa digunakan untuk pengembangan perangkat lunak, mulai dari aplikasi dekstop hingga permainan di komputer dan sistem operasi [2].

#### 1. Elemen Dasar, Tipe Data, dan Operator C++
C++ menyediakan berbagai tipe data dasar seperti `int`, `float`, `double`, dan `char` untuk menampung nilai di memori. Selain itu, C++ mendukung berbagai operator untuk manipulasi data, termasuk operator aritmatika serta operator *increment/decrement* baik berupa *pre-increment* (`++r`) maupun *post-increment* (`r++`) [2].

#### 2. Struktur Kontrol Percabangan dan Perulangan
Logika eksekusi program C++ diatur menggunakan struktur percabangan (`if`, `if-else`, dan `switch-case`) untuk pengambilan keputusan berdasarkan kondisi tertentu. Selain itu, C++ menyediakan struktur perulangan (`for`, `while`, dan `do-while`) untuk mengeksekusi blok kode secara berulang . Perbedaan utamanya terletak pada alur evaluasi syarat, seperti perulangan `do-while` yang selalu mengevaluasi kondisi di akhir sehingga minimal dieksekusi satu kali [2].

#### 3. Tipe Data Terstruktur dan Fungsi (Array, Struct, & Function)
Untuk pengelolaan data yang lebih kompleks, C++ mendukung pengelompokan data sejenis menggunakan `array` serta pengelompokan variabel dengan tipe data berbeda menggunakan `struct`. Selain itu, C++ memanfaatkan Fungsi (*Function*) untuk membagi program menjadi blok-blok modular yang dapat dipanggil kembali (*reusable*), baik melalui deklarasi prototipe maupun definisi fungsi [2].

## Guided

### 1. Guided 1

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main(){
    int i,j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX] =
    {   {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };

    for (i=0; i<MAX; i++){
        cout<<"masukkan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    cout<<"\ndata nilai siswa :\n";

    for (i=0; i<MAX; i++){
        cout<<"nilai k-"<<i+1<<"=" <<nilai[i]<<endl;
    }
    cout<<"\n nilai tahunan : \n";

    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++)
            cout<<nilai_tahun[i][j];
        cout<<"\n";
    }
    return 0;
}
```
Program ini mengimplementasikan pengolahan array satu dimensi dan dua dimensi secara bersamaan menggunakan konstanta MAX berukuran 5 sebagai batas ukuran data. Program menggunakan variabel i dan j bertipe integer sebagai pemegang indeks perulangan, array nilai bertipe float berukuran 5 untuk menampung input nilai siswa, serta array dua dimensi nilai_tahun bertipe integer statis yang telah diinisialisasi secara langsung dengan data matriks berukuran 5x5. Proses eksekusi dimulai dengan perulangan for dari i = 0 hingga i < MAX yang meminta input lima nilai siswa dari pengguna dan menyimpannya ke dalam array nilai, diikuti dengan perulangan for kedua untuk menampilkan data nilai siswa tersebut kembali ke layar. Terakhir, program memanfaatkan perulangan bersarang (nested loop) di mana perulangan i mengontrol perpindahan baris dan perulangan j mencetak tiap elemen array nilai_tahun per kolom, sehingga seluruh matriks dua dimensi berhasil ditampilkan ke layar dalam struktur baris dan kolom yang rapi.

### 2. Guided 2

```C++
#include <iostream>
using namespace std;

int main(){
    int x, y; 
    int *px; 

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x = " << &x << endl;
    cout << "Isi px = " << px << endl;
    cout << "Isi X = " << x << endl;
    cout << "Nilai yang ditunjuk px = " << *px << endl;
    cout << "Nilai y = " << y << endl;

    return 0;
}
```
Kode program ini memperlihatkan alur kerja pointer dalam mengakses alamat memori dan nilai dari suatu variabel. Variabel x bertipe data integer diisi dengan nilai 87, lalu pointer px diatur untuk menyimpan lokasi alamat memori x menggunakan simbol &x. Selanjutnya, nilai pada variabel y diambil dari lokasi yang ditunjuk oleh px menggunakan operator dereference (*px). Di bagian akhir, baris perintah cout mencetak alamat memori x, isi dari pointer px, nilai variabel x, serta nilai yang diambil dari *px dan y untuk memperlihatkan bahwa isi dari px memang berupa alamat memori x, sehingga *px dan y menghasilkan nilai angka yang sama.

Contoh Output : Alamat x = 0x90384fdse
                Isi px = 0x90384fdse
                Isi x = 87
                Nilai yang ditunjuk px = 87 (Isi nilai dari variabel x)
                Nilai y = 87 (*px)

### 3. Guided 3

```C++
#include <iostream>
using namespace std;
int maks3(int a, int b, int c);

int main(){
    int x,y,z;

    cout<<"masukkan nilai bilangan ke-1 = ";
    cin>>x;

    cout<<"masukkan nilai bilangan ke-2 = ";
    cin>>y;

    cout<<"masukkan nilai bilangan ke-3 = ";
    cin>>z;

    cout<<"nilai maksimumnya adalah = " <<maks3(x,y,z);

    return 0;
}

int maks3(int a, int b, int c){
    
    int temp_max = a;
    if(b > temp_max){
        temp_max = b;
    }

    if(c > temp_max){
        temp_max = c;
    }
    return (temp_max);
}
```
Program tersebut dirancang untuk membandingkan tiga nilai bulat dari input pengguna, untuk menentukan angka terbesar menggunakan fungsi kustom maks3(). Pada main program, tiga angka yang dimasukkan disimpan dalam variabel x, y, dan z sebelum dikirimkan sebagai parameter ke fungsi pembanding. Dalam function maks3, variabel temp_max diisi dengan nilai awal a sebagai patokan, lalu diperiksa secara berurutan terhadap nilai b dan c melalui dua pengondisian if. Jika ditemukan nilai yang lebih besar, temp_max akan memperbarui isinya hingga mendapatkan nilai tertinggi, yang kemudian dikembalikan menggunakan return untuk langsung dicetak pada output.

### 4. Guided 4

```C++
#include <iostream>
using namespace std;

void tulis(int x);

int main() {
    int jum;
    cout << "jumlah baris kata=";
    cin >> jum;
    tulis(jum);
    return 0;
}
   

void tulis(int x){
    for (int i=0;i<x;i++)
        cout<<"baris ke-" << i+1 << endl;
}
```
Program ini menerapkan pemanggilan prosedur tambahan tulis() untuk mencetak penomoran baris secara berulang sesuai jumlah yang ditentukan pengguna. Nilai masukan ditampung oleh variabel jum bertipe integer di dalam main program, lalu diteruskan ke dalam variabel x saat prosedur tulis() dipanggil. Di dalam prosedur tulis(), instruksi perulangan for mengeksekusi mulai dari i = 0 selama nilai i lebih kecil dari x. Pada setiap iterasi, program mencetak string "baris ke-" yang dirangkai dengan penambahan i + 1, sehingga penomoran di layar dapat tercetak runtut mulai dari angka satu hingga mencapai batas jumlah yang diinputkan.

### 5. Guided 5

```C++
#include <iostream>
using namespace std;

void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y =temp;
}

void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4, b = 6;

    tukarValue(a, b);
    cout << "Setelah Call by Value      -> a = " << a << ", b = " << b << " (Tetap)" << endl;

    tukarPointer(&a, &b);
    cout << "Setelah Call by Pointer      -> a = " << a << ", b = " << b << " (Berubah!)" << endl;

    tukarReference(a, b);
    cout << "Setelah Call by Reference     -> a = " << a << ", b = " << b << " (Berubah lagi!)" << endl;

    return 0;

}
```
Membuat program untuk membandingkan tiga metode pengiriman parameter dalam C++ melalui proses penukaran nilai dua variabel integer. Pada main program, variabel a dan b diinisialisasi dengan nilai 4 dan 6 sebelum diproses oleh masing-masing prosedur. Pemanggilan prosedur tukarValue() tidak mengubah nilai asli di dalam main() karena hanya mengolah salinan datanya. Perubahan nilai baru terjadi saat prosedur tukarPointer() dipanggil menggunakan alamat memori &a dan &b, yang menukar isi variabel secara langsung sehingga a menjadi 6 dan b menjadi 4. Selanjutnya, prosedur tukarReference() memanfaatkan alias variabel untuk menukar kembali nilainya ke posisi awal, sekaligus membuktikan bahwa manipulasi nilai variabel utama hanya dapat terjadi jika menggunakan pengiriman parameter berbasis pointer atau reference.

## Unguided

### 1. Operasi Matematika Dasar (Penjumlahan, Pengurangan, dan Perkalian)

```C++
#include <iostream>
using namespace std;

const int MAX = 3;

void penjumlahan (int X[MAX][MAX], int Y[MAX][MAX], int Z[MAX][MAX]) {
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++) {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
}

void pengurangan (int X[MAX][MAX], int Y[MAX][MAX], int Z[MAX][MAX]) {
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++) {
            Z[i][j] = X[i][j] - Y[i][j];
        }
    }
}

void perkalian (int X[MAX][MAX], int Y[MAX][MAX], int Z[MAX][MAX]) {
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++) {
            Z[i][j] = 0;
            for (int k = 0; k < MAX; k++) {
                Z[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
}

void Input(int in[MAX][MAX], char alphabet) {

    cout << "Masukkan matriks " << alphabet << endl;
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            cout << alphabet << "[" << i << "]" << "[" << j << "]" << " = ";
            cin >> in[i][j];
        }
    }
}


void tampilkanOutput(int out[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << out[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int X[MAX][MAX], Y[MAX][MAX], Z[MAX][MAX];
    int menu;
    
    do {
    cout << endl;
    cout << "--- Menu Program Array ---" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "0. Exit\n" << endl;
    

    cout << "Pilih: ";
    cin >> menu;

    
        switch (menu) {
            
            case 1:
                cout << "Penjumlahan dipilih!" << endl;
                Input(X, 'X');
                cout << endl;
                Input(Y, 'Y');
                penjumlahan(X, Y, Z);
                cout << "Hasil penjumlahan X dan Y = " << endl;
                tampilkanOutput(Z);
                break;

            case 2:
                cout << "Pengurangan dipilih!" << endl;
                Input(X, 'X');
                cout << endl;
                Input(Y, 'Y');
                pengurangan(X, Y, Z);
                cout << "Hasil pengurangan X dan Y = " << endl;
                tampilkanOutput(Z);
                break;

            case 3:
                cout << "Perkalian dipilih!" << endl;
                Input(X, 'X');
                cout << endl;
                Input(Y, 'Y');
                perkalian(X, Y, Z);
                cout << "Hasil perkalian X dan Y = " << endl;
                tampilkanOutput(Z);
                break;

            case 0:
                cout << "Terima Kasih Telah Menggunakan Aplikasi Kami" << endl;
                break;

        default:
            cout << "Input menu tidak valid! Silakan coba lagi!" << endl;
            break;
        }

    } while(menu != 0);

    return 0;    
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided1.png)


##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided1(1).png)

Penjelasan unguided 1 :
Membuat program menghitung operasi dasar, penjumlahan, pengurangan, perkalian, dan pembagian. Terdapat dua variabel yang ditentukan yaitu x dan y, bertipe data integer. Dua variabel tersebut akan dieksekusi berdasarkan setiap perintah operasi dasar matematika. Contoh x = 10, y = 5. Output : 10 + 5 = 15, 10 - 5 = 5, 10 * 5 = 50, 10 / 5 = 2. 


### 2. Menukar nilai variabel (Pointer dan Reference)

```C++
#include <iostream>
using namespace std;

void Pointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void Reference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int x, y, z;

    cout << "Masukkan bilangan : ";
    cin >> x >> y >> z; 
    

    Pointer(&x, &y, &z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << " (Metode Pointer)" << endl;

    Reference(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << " (Metode Reference)" << endl;

    return 0;

}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided2.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%202/Output%20Latihan/Output_UnGuided2(1).png)

Penjelasan unguided 2 :
Program digunakan untuk konversi angka 0 sampai 100 yang dimasukkan pengguna menjadi tulisan, berdasarkan angkanya. Terdapat dua array string: sKecil untuk kata angka 0 sampai 11, dan sKapital untuk kata satu sampai sembilan dengan huruf awal kapital. Setelah angka dibaca pada variabel bilangan, program mencetaknya melalui kondisi if-else. Pada angka 0 sampai 11 diambil dari sKecil sesuai indeksnya. Angka 12 sampai 19 diambil dari digit satuannya (bilangan % 10) dan ditambah kata "belas". Angka 20 sampai 99 ditulis dari digit puluhannya (bilangan / 10) ditambah kata "puluh", dan jika satuannya bukan nol, kata satuan diambil dari sKapital, sehingga 47 tampil sebagai "empat puluh Tujuh". Angka 100 dicetak sebagai "seratus", sedangkan angka di luar rentang 0 sampai 100 menampilkan pesan bahwa input tidak valid.


### 3. (isi dengan soal unguided 3)

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

![Screenshot Output Unguided 3_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%201/Output%20Latihan/Output3.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%201/Output%20Latihan/Output3(1).png)

Penjelasan unguided 3 :
Program ini mencetak pola segitiga terbalik simetris yang tersusun dari bilangan asli dan tanda bintang. Pada baris pertama, angka menurun dari nilai input hingga 1, diikuti tanda bintang, lalu angka menaik dari 1 kembali ke nilai input. Baris-baris berikutnya memakai pola yang sama dengan angka yang makin sedikit dan posisi yang makin menjorok ke kanan, hingga baris terakhir hanya berisi bintang. Secara teknis, perulangan luar dengan variabel i berjalan dari a sampai 0 untuk menentukan jumlah baris. Di dalamnya, perulangan pertama mencetak spasi sebanyak a - i sebagai indentasi, perulangan kedua mencetak angka menurun dari i ke 1 lalu tanda bintang, dan perulangan ketiga mencetak angka menaik dari 1 ke i.

## Kesimpulan
Dari praktikum ini, saya memperoleh pemahaman awal mengenai dasar-dasar bahasa C++, seperti operator aritmatika, percabangan, perulangan, struct, array, dan fungsi. Karena pada semester sebelumnya saya menggunakan bahasa Go, saya masih memerlukan waktu untuk menyesuaikan diri, terutama pada aturan penulisan sintaks dan penggunaan operator yang berbeda. Meskipun demikian, setelah mengerjakan latihan pada modul ini, pemahaman saya terhadap cara kerja C++ menjadi lebih baik.

## Referensi

[1] Satriani, S., Andriany, D., Rusmawati, R., Mima, M., Masnur, M., S, S., & Rinayanti Manullang, K. (2026). Pengenalan Struktur Data dan Perannya dalam Pemrograman. Jejak Digital: Jurnal Ilmiah Multidisiplin, 2(3), 4835-4848.
<br>
[2] Ritonga, A., & Yahfizham. (2023). Studi Literatur Perbandingan Bahasa Pemrograman C++ Dan Bahasa Pemrograman Python Pada Algoritma Pemrograman. Jurnal Teknik Informatika dan Teknologi Informasi (JUTITI), 3(3), 56–63.
<br>