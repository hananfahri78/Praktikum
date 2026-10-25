# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Linked List <br/>

Linked list adalah struktur data yang menyimpan elemen dalam node, setiap node memuat isi value beserta alamat memori dari node selanjutnya (next), dan pada doubly linked list juga memuat satu pointer yang berisi alamat memori dari node sebelumnya (prev) [1]. Memori tiap node dialokasikan secara dinamis saat program berjalan, sehingga tidak selalu berurutan dan jumlah elemennya tidak tetap selama memori masih tersedia [1]. Akses ke suatu elemen harus dilakukan secara berurutan dari node awal yang biasa disebut head, sehingga lebih lambat daripada array. Sebaliknya, penambahan dan penghapusan lebih mudah karena cukup mengubah beberapa tautan node tanpa menggeser elemen lain [1].

### B. Singly Linked List<br/>

Singly linked list merupakan model linked list yang hanya memiliki satu arah pointer, dalam satu node hanya memuat isi value dan (next) untuk alamat memori node berikutnya. Sedangkan node terkahir menunjuk ke Nil (NULL) sebagai penanda akhir list [2]. Pointer first atau head digunakan untuk menunjuk elemen pertama list [2]. Karena setiap node hanya menyimpan satu tautan (link) ke node berikutnya, penelusurannya hanya dapat dilakukan satu arah [3]. Pada metode singly linked list, penambahan atau penghapusan node yang berada di tengah list lebih mudah dilakukan [2]. 

## Guided

### 1. Guided 

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

address FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, int nilaiAwal, int nilaiAkhir);

void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist &list, address &prev);
void updateByNim(linkedlist &list, string nim);

#endif
```

#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
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
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
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

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    }else{
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;
        list.first-> isidata = newData;
    }
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    }else{
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedlist &list, address &prev)
{
    if (isEmpty(list)){
        cout << "List kosong!" << endl;
    }else{
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        prev->next->isidata = newData;
    }
}

void updateByNim(linkedlist &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = FindNodeByData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;


            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address FindNodeByData(linkedlist List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found = false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedlist List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur >= nilaiAwal && umur <= nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```

#### main.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
	linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    // updateLast(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    // printList(List);

    // updateAfter(List, nodeC);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER NODE B ---" << endl;
    // printList(List);
    
    updateByNim(List, "2211110014");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);
    
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
#define Nil NULL
#include <iostream>
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

address findElm(List L, infotype x);

#endif
```

#### Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;


void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " " << endl;
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}


address findElm(List L, infotype x) {
    address P = L.First;
    while(P != Nil) {
        if (P->info == x) {
            cout << x << " ditemukan dalam list" << endl;
            return P;
        }
        P = P->next;        
    }
    cout << x << " Tidak ditemukan dalam list" << endl;
    return Nil;
}
```

#### main.cpp
```C++
#include <iostream>
#include "Singlylist.h"
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

    // infotype x;
    // cout << "Masukkan nilai yang dicari : ";
    // cin >> x;

    // address hasil = findElm(L, x);
    
    int total = 0;
    address P = L.First;
    while (P != Nil){
        total = total + P->info;
        P = P->next;
    }
    cout << "Total info dari kelima elemen adalah " << total << endl;

    // printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1 Alokasi

![Screenshot Output Unguided 1_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%204/Output%20UnGuided/UnGuided1.png)


##### Output 2 Find Element 

![Screenshot Output Unguided 1_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%204/Output%20UnGuided/UnGuided1(1).png)

##### Output 3 Total Value 

![Screenshot Output Unguided 1_3](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%204/Output%20UnGuided/UnGuided1(1).png)

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