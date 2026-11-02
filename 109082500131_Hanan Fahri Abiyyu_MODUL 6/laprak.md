# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>

<p align="center">Hanan Fahri Abiyyu - 109082500131</p>

## Dasar Teori

### A. Doubly Linked List <br/>

Doubly Linked List(DLL) merupakan struktur data dinamis yang terdiri dari sekumpulan node yang saling terhubung. Setiap node memiliki pointer ke node sebelumnya (prev) dan pointer ke node berikutnya (next), berbeda dengan SLL yang hanya memiliki pointer ke node berikutnya (next). Hal ini dapat menjadi keunggulan terutama dalam hal operasi insertion dan deletion yang lebih fleksibel melelui navigasi dua arah [2].

Pada implementasi DLL terdapat dua buah komponen penunjuk utama, yakni meliputi head (atau first) sebagai penanda elemen pertama dan tail (atau last) sebagai penanda elemen terakhir pada list [1]. Setiap node di dalamnya tidak hanya menampung data (info), tetapi juga saling merangkai struktur memori secara dua arah [1], [2]. Berkat efisiensi penelusuran maju dan mundur ini, Doubly Linked List sering kali diaplikasikan dalam sistem nyata, salah satunya pada pengelolaan daftar putar (playlist) musik digital untuk mendukung fitur navigasi perpindahan lagu [3].

#### 1. Insert
Operasi insert adalah proses penambahan node baru ke dalam struktur list. Berdasarkan letak penyisipannya, operasi ini dibagi menjadi beberapa jenis:

##### A. Insert First
Penyisipan dilakukan di awal elemen list. Langkah awalnya dimulai dengan mengalokasikan memori untuk node baru P. Selanjutnya, pointer P->next dihubungkan ke L.first yang lama, lalu pointer prev dari elemen pertama yang lama diatur menunjuk ke P, dan terakhir L.first digeser untuk menunjuk ke node P tersebut.

##### B. Insert Last
Proses ini menambahkan node baru pada posisi paling belakang atau ujung list. Setelah node baru P dialokasikan, pointer P->prev dihubungkan ke L.last, kemudian L.last->next diarahkan ke P, dan posisi L.last diperbarui agar menunjuk ke node P. 

##### C. Insert After
Penyisipan dilakukan tepat setelah node acuan tertentu (biasanya disebut node R). Langkah ini membutuhkan penyesuaian pointer next dan prev antara node R, node baru P, dan node sesudahnya agar rantai keterhubungan tidak terputus.

##### D. Insert Before
Merupakan kebalikan dari insert after, di mana node baru disisipkan tepat sebelum node acuan tertentu. Perbedaan utamanya hanya terletak pada cara penelusuran atau pencarian posisi node acuannya di dalam list.


#### 2. Delete
Operasi delete bertujuan untuk melepaskan suatu node dari struktur list sekaligus membersihkan alokasi memorinya. Berikut adalah pembagian metodenya:

##### A. Delete First
Digunakan untuk menghapus node yang berada di posisi paling depan list. Node pertama yang ditunjuk oleh L.first disimpan sementara ke dalam pointer P, kemudian L.first digeser ke elemen berikutnya, pointer prev pada elemen baru tersebut diatur menjadi Nil, dan node P didealokasi.

##### B. Delete Last
Proses penghapusan node yang terletak di ujung akhir list. Node terakhir yang ditunjuk oleh L.last ditampung ke pointer P, posisi L.last dimundurkan ke node sebelumnya, pointer next pada node terakhir yang baru diubah menjadi Nil, lalu memori node P dibersihkan. 

##### C. Delete After
Menghapus node yang berada tepat setelah node acuan tertentu (R). Keterhubungan antarelemen disesuaikan dengan mengarahkan R->next melewati node yang dihapus menuju ke elemen di depannya, sebelum akhirnya node target didealokasi. 

##### D. Delete Before
Merupakan kebalikan dari delete after, yang berfungsi untuk menghapus node yang terletak tepat sebelum node acuan tertentu dengan mekanisme penyesuaian pointer dua arah yang serupa.

## Guided

### 1. Guided 

#### listmakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct makanan
{
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node
{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

#### listmakanan.cpp
```C++
#include "listmakanan.h"
#include <iostream>
#include <string>
using namespace std;

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

void createList(linkedlist &List)
{
    List.first = Nil;
    List.last = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis;
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodePrev != Nil)
        {
            if (nodePrev == List.last) 
            {
                insertLast(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodeNext != Nil)
        {
            if (nodeNext == List.first)
            {
                insertFirst(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl;
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); // menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); // menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodeNext != Nil && nodeNext->prev != Nil)
        {
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.nama == nama)
        {
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.last;
    while (p != Nil)
    {
        if (p->isidata.jenis == jenis)
        {
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->prev;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.last;
    while (p != Nil)
    {
        if (p->isidata.rating >= minRating)
        {
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->prev;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (Prev == Nil || Prev->next == Nil)
    {
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if (Prev->next == List.last)
    {
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (nodeNext == Nil || nodeNext->prev == Nil)
    {
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if (nodeNext->prev == List.first)
    {
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target)
{
    if (isEmpty(List) == true || target == Nil)
    {
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if (target == List.first)
    {
        deleteFirst(List);
    }
    else if (target == List.last)
    {
        deleteLast(List);
    }
    else
    {
        address L = target->next;
        address R = target->prev;
        R->next = L;
        L->prev = R;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while (target != Nil && target->isidata.nama != nama)
    {
        target = target->next;
    }
    if (target == Nil)
    {
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

#### main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    // D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");
    findByMinRating(List, 9.0);

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl
         << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```

Pada latihan ini saya membuat program untuk mengelola data makanan (nama, jenis, harga, dan rating) menggunakan doubly linked list. Berbeda dengan singly linked list, setiap node di sini memiliki dua pointer, yaitu next ke node sesudahnya dan prev ke node sebelumnya, sehingga list dapat ditelusuri dari dua arah. Karena itu, proses pencarian pada program ini ada yang berjalan maju dari node pertama dan ada yang mundur dari node terakhir. Program dipisah menjadi tiga file, yaitu header untuk deklarasi struktur dan fungsi, file implementasi untuk isi fungsinya, dan main sebagai program utama.

Pada bagian main, saya membuat list kosong dan lima node untuk Nasi Rames, Ayam Geprek, Risol Mayo, Mie Ayam, dan Donat. Mie Ayam ditempatkan lebih dulu menggunakan insertFirst, Donat ditaruh di akhir dengan insertLast, lalu Nasi Rames disisipkan setelah Mie Ayam dengan insertAfter dan Risol Mayo disisipkan sebelum Donat dengan insertBefore. Ayam Geprek ditambahkan di akhir, sehingga urutan list menjadi Mie Ayam, Nasi Rames, Risol Mayo, Donat, Ayam Geprek. Setelah itu, saya menjalankan operasi update pada node pertama, terakhir, serta node di sekitar node tertentu, kemudian mencari data berdasarkan nama dan rating minimum. Terakhir, saya menguji penghapusan dengan deleteByName untuk menghapus node berdasarkan nama, lalu menghapus node dengan deleteFirst dan deleteBefore, dan isi list dicetak pada setiap tahap untuk memastikan hasil tiap operasi sudah sesuai.

## Unguided

### 1. Latihan 

#### Doublylist.h

```C++
#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H
#include <iostream>
#include <string>
#define Nil NULL
using namespace std;



struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address prev;
    address next;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

address findElm(List L, infotype x);


void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleterAfter(address Prec, address &P);

#endif
```

#### Doublylist.cpp
```C++
#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

void CreateList(List &L){
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x){
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    P->next = Nil;
    P->prev = Nil;
    delete P;
}

void printInfo(List L) {
    address P = L.Last;

    cout << endl;
    cout << "DATA LIST 1" << endl;
    cout << endl;

    while (P != Nil) {
        cout << "no polisi  : " << P->info.nopol << endl;
        cout << "warna      : " << P->info.warna << endl;
        cout << "tahun      : " << P->info.thnBuat << endl;
        P = P->prev;
    }
    cout << endl;

} 

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    }else{
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.Last;
    while(P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->prev;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    }else{
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    }else{
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleterAfter(address Prec, address &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next->prev = Prec;
    P->next = Nil;
    P->prev = Nil;
}
```

#### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    infotype x;
    address P;
    CreateList(L);
    for (int i = 0; i < 4; i++){
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        
        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        }else{
            P = alokasi(x);
            insertLast(L, P);
            cout << endl;
        }
    }

    printInfo(L);
    cout << endl;

    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> x.nopol;

    address found = findElm(L, x);
    if (found != Nil) {
        cout << "no polisi  : " << found->info.nopol << endl;
        cout << "warna      : " << found->info.warna << endl;
        cout << "tahun      : " << found->info.thnBuat << endl;
    }else{
        cout << "Nomor Polisi " << x.nopol << " Tidak ditemukan" << endl;
    }

    cout << "Masukkan nomor polisi yang akan dihapus  : ";
    cin >> x.nopol;
    address Delete = findElm(L, x);
    if (Delete == Nil) {
        cout << "Data tidak ditemukan!" << endl;
    }else{
        address X;
        if (Delete == L.First) {
            deleteFirst(L, X);
        }else if (Delete == L.Last){
            deleteLast(L, X);
        }else{
            deleterAfter(Delete->prev, X);
        }
        dealokasi(X);
        cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus" << endl;
        
    }

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1 Alokasi

![Screenshot Output Unguided 1_1](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%206/Output%20UnGuided/OutputInNopol(1).png)

##### Output 2 Find Element 

![Screenshot Output Unguided 1_2](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%206/Output%20UnGuided/OutputCariNopol(2).png)

##### Output 3 Total Value 

![Screenshot Output Unguided 1_3](https://github.com/hananfahri78/Praktikum/blob/main/109082500131_Hanan%20Fahri%20Abiyyu_MODUL%206/Output%20UnGuided/OutputDelNopol(3).png)

Penjelasan unguided 1 :
Membuat program untuk menyimpan data kendaraan (nomor polisi, warna, dan tahun buat) menggunakan doubly linked list. Program dibagi menjadi tiga file: Doublylist.h berisi struktur data dan deklarasi prosedur, Doublylist.cpp berisi isi prosedurnya, dan main.cpp sebagai program utama. Prosedur yang dibuat mencakup CreateList, alokasi, dealokasi, printInfo, insertLast, findElm, serta tiga prosedur hapus, yaitu deleteFirst, deleteLast, dan deleteAfter.

Pada program main.cpp, program meminta input data kendaraan sebanyak empat kali. Setiap kali input, nomor polisi dicek lebih dulu dengan findElm. Jika nomor sudah ada di list, ditampilkan pesan bahwa nomor polisi sudah terdaftar. Jika belum, node baru dibuat dengan alokasi dan ditambahkan ke akhir list dengan insertLast. Isi list dicetak oleh printInfo yang menelusuri dari node terakhir ke node pertama, sehingga datanya tampil dengan urutan terbalik dari urutan input. Setelah itu, program mencari kendaraan berdasarkan nomor polisi yang dimasukkan, lalu menampilkan datanya jika ditemukan. Pada bagian penghapusan, nomor polisi yang dimasukkan dicari terlebih dahulu dengan findElm untuk menentukan posisinya. Jika berada di awal list, dipakai deleteFirst. Jika di akhir, dipakai deleteLast. Jika di tengah, dipakai deleteAfter dengan node sebelumnya sebagai acuan. Node yang sudah dilepas dari list kemudian dibebaskan memorinya dengan dealokasi, dan isi list dicetak kembali untuk memastikan data sudah terhapus.

## Kesimpulan
Berdasarkan praktikum Modul 6 tentang Doubly Linked List bagian pertama, saya mempelajari bagaimana sistem navigasi dua arah bekerja. Pada metode DLL ini setiap node memiliki dua pointer, yaitu next yang menunjuk ke node selanjutnya dan prev yang menunjuk ke node sebelumnya, sehingga list dapat ditelusuri maju maupun mundur. Hal ini sering digunakan pada sistem pemutar musik digital.

## Referensi

<br>
[1] Fakultas Informatika, Telkom University, “Modul 6: Doubly linked list (bagian pertama),” dalam Modul Praktikum Struktur Data, Bandung, Indonesia: Telkom University, 2026, hlm. 51–58.
[2] A. Wijoyo et al., "Penggunaan Algoritma Doubly Linked List Untuk Insertion dan Deletion," JRIIN: Jurnal Riset Informatika dan Inovasi, vol. 1, no. 12, pp. 1329-1331, May. 2024.
[3] T. R. Y. Saketang, G. R. Pandiangan, F. A. Matondang, and R. I. Situmorang, "Implementasi Struktur Data Stack pada Sistem Recently Played Music Streaming Berbasis Prinsip Lifo," JPIM: Jurnal Penelitian Ilmiah Multidisipliner, vol. 2, no. 3, pp. 1192-1197, Oct. 2025.