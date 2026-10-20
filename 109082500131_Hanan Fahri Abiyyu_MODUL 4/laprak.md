# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Linked List <br/>

Linked list adalah struktur data yang menyimpan elemen dalam node, setiap node memuat isi value beserta alamat memori dari node selanjutnya (next), dan pada doubly linked list juga memuat satu pointer yang berisi alamat memori dari node sebelumnya (prev) [1]. Memori tiap node dialokasikan secara dinamis saat program berjalan, sehingga tidak selalu berurutan dan jumlah elemennya tidak tetap selama memori masih tersedia [1]. Akses ke suatu elemen harus dilakukan secara berurutan dari node awal yang biasa disebut head, sehingga lebih lambat daripada array. Sebaliknya, penambahan dan penghapusan lebih mudah karena cukup mengubah beberapa tautan node tanpa menggeser elemen lain [1].

### B. Singly Linked List<br/>

Singly linked list merupakan model linked list yang hanya memiliki satu arah pointer, dalam satu node hanya memuat isi value dan (next) untuk alamat memori node berikutnya. Sedangkan node terkahir menunjuk ke Nil (NULL) sebagai penanda akhir list [2]. Pointer first atau head digunakan untuk menunjuk elemen pertama list [2]. Karena setiap node hanya menyimpan satu tautan (link) ke node berikutnya, penelusurannya hanya dapat dilakukan satu arah [3]. Pada metode singly linked list, penambahan atau penghapusan node yang berada di tengah list lebih mudah dilakukan [2]. 

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

Program tersebut merupakan bentuk implementasi singly linked list menggunakan konsep Abstract Data Type (ADT) dalam C++ untuk mengelola data mahasiswa yang mencakup nama, NIM, dan umur. Pengerjaannya dibagi menjadi tiga file. File list.h berfungsi sebagai header atau kerangka program yang berisi definisi struct mahasiswa, struct node (menyimpan data mahasiswa dan pointer next), serta struct linkedlist yang memiliki pointer first sebagai penunjuk node pertama. Di dalamnya terdapat deklarasi prototipe fungsi dan prosedur, seperti isEmpty, createList, alokasi, dealokasi, insert, delete, printList, nbList, dan deletelist. Header guard (#ifndef) digunakan agar file tidak terbaca berulang, dan Nil didefinisikan sebagai NULL untuk menandai pointer yang tidak menunjuk ke mana pun.

Selanjutnya, list.cpp memuat implementasi dari setiap fungsi dan prosedur yang telah dideklarasikan. Fungsi alokasi digunakan untuk membuat node baru menggunakan new dan mengisinya dengan data, sedangkan dealokasi membebaskan memori node tersebut. Untuk penambahan node terdapat insertFirst (awal list), insertAfter (setelah node tertentu), dan insertLast (akhir list, dengan melakukan penelusuran list sampai node terakhir). Sisanya, printList berfungsi untuk menampilkan semua isi list, nbList untuk menghitung total node, dan deletelist untuk menghapus semua node satu per satu hingga list menjadi kosong.

Terakhir, main.cpp digunakan sebagai pusat eksekusi program. Pada bagian ini dibuat sebuah list kosong, kemudian dialokasikan lima node berisi data Dhimas, Budi, Andi, Caca, dan Dewi. Kelima node tersebut dimasukkan ke list dengan kombinasi insertFirst, insertLast, dan insertAfter, sehingga urutan akhirnya menjadi Dhimas, Budi, Caca, Andi, lalu Dewi. Isi list ditampilkan bersama jumlah node-nya, yaitu lima, dan program diakhiri dengan deletelist untuk membebaskan seluruh memori yang digunakan.

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

#### Singlylist.cpp
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

![Screenshot Output Unguided 1_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%204/Output%20UnGuided/UnGuided1.png)


##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%204/Output%20UnGuided/UnGuided1(1).png)

Penjelasan unguided 1 :
Program ini mengimplementasikan struktur data singly linked list menggunakan konsep Abstract Data Type (ADT) dalam bahasa C++, dengan tujuan menyimpan dan menampilkan lima buah bilangan bulat. Implementasinya dibagi ke dalam tiga file terpisah agar deklarasi, isi fungsi, dan alur program tidak tercampur. 

File Singlylist.h berfungsi sebagai kerangka dasar program. Di dalamnya terdapat definisi struct Elmlist yang menampung data (info) dan pointer ke node berikutnya (next), serta struct List yang memuat pointer First sebagai penanda node pertama. File ini juga memuat deklarasi prototipe fungsi dan Nil sebagai representasi NULL.

Isi dari fungsi-fungsi yang telah dideklarasikan tersebut ditulis pada file Singlylist.cpp. Prosedur createList menginisialisasi list menjadi kosong, fungsi alokasi membuat node baru menggunakan new, dan prosedur insertFirst menyisipkan node baru di bagian paling depan list. Selain itu, prosedur printInfo menelusuri node dari First sampai Nil sambil mencetak isinya ke layar.

Terakhir, file main.cpp menjadi pusat eksekusi program. Pada bagian ini, angka 2, 0, 8, 12, dan 9 dialokasikan satu per satu lalu dimasukkan menggunakan insertFirst. Karena setiap node baru ditempatkan di depan, urutan datanya berbalik dari urutan pemasukan, sehingga keluaran yang tampil di layar adalah 9 12 8 0 2.

## Kesimpulan
Kesimpulan dari praktikum Modul 4 mengenai Singly Linked List, saya belajar ternyata untuk menyimpan sebuah data tidak hanya dapat disimpan menggunakan array, tetapi bisa juga menggunakan node yang memanfaatkan memori, dan disambung seperti struktur kereta yang saling menyambung. Masih banyak kegagalan dalam membuat alur program SLL ini terutama saat memahami pointer dan cara menyambung antar node. Untuk ke depannya saya perlu lebih banyak latihan supaya lebih paham.

## Referensi

<br>
[1] M. R. Abu Sara, M. F. J. Klaib, dan M. Hasan, “Hybrid array list: An efficient dynamic array with linked list structure,” Indones. J. Comput., vol. 5, no. 3, hlm. 47–62, Des. 2021, doi: 10.34818/indojc.2021.5.3.527.
<br>
[2] Fakultas Informatika, Telkom University, “Modul 4: Singly linked list (bagian pertama),” dalam Modul Praktikum Struktur Data, Bandung, Indonesia: Telkom University, 2026, hlm. 36–46.
<br>
[3] A. O. Akinde, S. O. Okolie, dan S. O. Kuyoro, “The S-linked list—A variant of the linked list data structure,” J. Emerg. Trends Comput. Inf. Sci., vol. 4, no. 6, hlm. 571–576, Jun. 2013.