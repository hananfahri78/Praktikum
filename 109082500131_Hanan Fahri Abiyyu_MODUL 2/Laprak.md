# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Array <br/>
Array didefinisikan sebagai sekumpulan alokasi memori untuk menyimpan data bertipe seragam yang diakses melalui penomoran indeks berbasis nol [1, hal. 70].

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
Membuat program untuk mengolah operasi aritmetika matriks berukuran 3x3 yang mencakup penjumlahan, pengurangan, dan perkalian melalui antarmuka menu interaktif. Pada main program, perulangan do-while dipadukan dengan percabangan switch-case untuk mengatur alur pilihan menu. Perulangan do-while berfungsi menjaga agar tampilan menu terus muncul berulang kali dengan mengeksekusi blok program terlebih dahulu baru kemudian mengevaluasi kondisi menu != 0 di akhir, sedangkan switch-case bertugas mengarahkan alur eksekusi program ke prosedur perhitungan yang sesuai berdasarkan nilai angka menu yang diinputkan pengguna. Setelah opsi dipilih, program menjalankan prosedur Input() untuk menerima input angka pada matriks X dan Y, memprosesnya melalui prosedur penjumlahan(), pengurangan(), atau perkalian(), lalu menyimpan hasilnya ke matriks Z sebelum dicetak ke layar lewat prosedur tampilkanOutput().


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
Kode program tersebut memanfaatkan prosedur tambahan Pointer() dan Reference() untuk memproses pergeseran nilai variabel, yang masing-masing menerapkan simbol pointer (*) untuk manipulasi alamat memori dan simbol reference (&) sebagai alias variabel. Program dirancang untuk menggeser posisi nilai dari tiga variabel integer secara berurutan menggunakan dua pendekatan pengiriman parameter tersebut. Pada fungsi utama, tiga nilai input dari user disimpan pada variabel x, y, dan z. Pemanggilan prosedur Pointer() dilakukan dengan mengirimkan alamat memori variabel (&x, &y, &z), lalu nilainya diakses dan digeser menggunakan operator *dereference* (*). Selanjutnya, prosedur Reference() dipanggil untuk melakukan pergeseran nilai serupa dengan memanfaatkan parameter reference (&) sehingga variabel dapat dimanipulasi secara langsung tanpa perlu operator khusus, kemudian output dicetak ke layar.  


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
[1] L. J. E. Dewi, "Media Pembelajaran Bahasa Pemrograman C++," Jurnal Pendidikan Teknologi dan Kejuruan (JPTK) UNDIKSHA, vol. 7, no. 1, pp. 63–72, Jan. 2010. 
<br>
[2] N. Tou, Bahan Ajar Dasar-Dasar Pemrograman. Balunijuk: Jurusan Teknologi Informasi, Universitas Bangka Belitung, 2022.
<br>
[3] L. J. E. Dewi, "Media Pembelajaran Bahasa Pemrograman C++," Jurnal Pendidikan Teknologi dan Kejuruan (JPTK) UNDIKSHA, vol. 7, no. 1, pp. 63–72, Jan. 2010.
<br>
[4] G. A. A. D. Indradewi, I. M. O. Widyantara, dan A. A. K. O. Sudana, "Sistem Visualisasi Eksekusi Pointer pada Pemrograman C++," Lontar Komputer: Jurnal Ilmiah Teknologi Informasi, vol. 6, no. 3, pp. 182–191, Des. 2015.