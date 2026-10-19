# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Singly Linked List <br/>


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

#### list.h

```C++
#ifndef List_h
#define List_h
#define Nil NULL
#include <iostream>
using namespace std;
struct mahasiswa
{
    string nama, nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};
struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string nama, string nim, int umur);
void dealokasi (address &node);
void printList(linkedlist list);
void insertFirst (linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast (linkedlist &list);
void delAfter (linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deletelist (linkedlist &list);
#endif
```

#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist list) {
    if (list.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &list) {
    list.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedlist &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid." << endl;
    }
}

void insertLast(linkedlist &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &list)
{
        address nodeHapus;
        if (!isEmpty(list))
        {
            nodeHapus = list.first;
            list.first = list.first->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "List kosong" << endl;
        }
}

void delLast(linkedlist &list)
{
    address nodeHapus, nodePrev = Nil;
    if (!isEmpty(list))
    {
        nodeHapus = list.first;
        if (nodeHapus->next == Nil)
        {
            list.first = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedlist &list, address nodeHapus, address nodePrev)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deletelist(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus." << endl;
}
```

#### main.cpp
```C++
#include <iostream>
#include "list.h"
using namespace std;

int main() {
    linkedlist list;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(list);

    nodeA = alokasi("Dhimas", "001", 20);
    nodeB = alokasi("Budi", "002", 21);
    nodeC = alokasi("Andi", "003", 22);
    nodeD = alokasi("Caca", "004", 23);
    nodeE = alokasi("Dewi", "005", 24);

    insertFirst(list, nodeA);
    insertLast(list, nodeB);
    insertLast(list, nodeC);
    insertAfter(list, nodeD, nodeB);
    insertLast(list, nodeE);

    cout << "Isi List :\n";
    printList(list);
    cout << "Jumlah node: " << nbList(list) << endl;

    deletelist(list);
    return 0;

}
```

Program di atas adalah implementasi pemrograman modular menggunakan konsep Abstract Data Type (ADT) dalam C++ untuk mengelola data mahasiswa secara sederhana. Terdapat tiga file pada pengerjaan praktikum ini, mahasiswa.h berfungsi sebagai cetak biru (blueprint) yang berisi definisi struct mahasiswa (untuk menampung data NIM dan dua buah nilai) serta deklarasi prototipe fungsi dan prosedur agar bisa diakses oleh file lain. Dilengkapi juga dengan header guard (#ifndef) untuk mencegah duplikasi deklarasi, lalu diakhiri (#endif) pada file tersebut.

Selanjutnya, mahasiswa.cpp Berisi penjabaran kode nyata dari fungsi dan prosedur yang sebelumnya dideklarasikan. Di dalamnya terdapat prosedur inputMhs untuk meminta input NIM serta dua nilai dari pengguna, dan fungsi rata2 untuk menghitung serta mengembalikan nilai rata-rata dari kedua nilai tersebut dalam bentuk bilangan desimal (float).

Terkahir, main.cpp Berperan sebagai pusat eksekusi program. Bagian ini membuat sebuah objek mhs dari struct mahasiswa, memanggil prosedur input data, lalu memproses dan menampilkan hasil perhitungan rata-rata ke layar konsol.

## Unguided

### 1. Latihan 

#### Singlylist.h

```C++
#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H
#include <iostream>
#define Nil NULL
using namespace std;
typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);


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
#include "Singlylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P5 = alokasi(9);
    insertFirst(L,P5);

    printInfo(L);
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

## Kesimpulan
Kesimpulan dari praktikum Modul 3 ini, saya belajar mengenai konsep Abstract Data Type (ADT). Saya menjadi lebih tahu bahwa ADT merupakan konsep dasar yang akan sering digunakan saat praktikum maupun saat membuat real project. Dari modul ADT ini, saya juga berlatih menggunakan array dua dimensi, struct, array satu dimensi secara bersamaan. Serta ilmu baru tentang cara pengerjaan praktikum ini, dengan memisahkan program ke dalam file header (.h), file implementasi (namafile.cpp), dan program utama (main.cpp).

## Referensi

<br>
[1] B. Liskov and S. Zilles, "Programming with abstract data types," ACM SIGPLAN Notices, vol. 9, no. 4, hal. 50–59, Apr. 1974. 
<br>